#include "PsStreamDecoder.h"
#include <fstream>

using namespace std;

#define MAX_BUFFER_SIZE (800*1024)

int main(int argc, char* argv[])
{
    char* ps_filename = "E://tmp1.ps";

    FILE* pf_ps_file;

    int buffer_size = MAX_BUFFER_SIZE;
    int processed_size = 0;             //已经解析完的缓存数据大小
    int read_buffer_left_size = 0;          //缓存区剩余大小

    //unsigned char stream_data_buf[MAX_BUFFER_SIZE] = { 0 };
    //unsigned char tmp_data_buf[MAX_BUFFER_SIZE] = { 0 };

    unsigned char* stream_data_buf = NULL;
    unsigned char* tmp_data_buf = NULL;

    stream_data_buf = (unsigned char*)malloc(MAX_BUFFER_SIZE);
    memset(stream_data_buf, 0x00, MAX_BUFFER_SIZE);

    tmp_data_buf = (unsigned char*)malloc(MAX_BUFFER_SIZE);
    memset(tmp_data_buf, 0x00, MAX_BUFFER_SIZE);

    errno_t err;

    //open ps file
    err = ::fopen_s(&pf_ps_file, ps_filename, "rb");
    if (err == 0)
    {
        printf("The file '%s' was opened\n", ps_filename);
    }
    else
    {
        printf("The file '%s' was not opened\n", ps_filename);
    }

    // do job
    int read_size = 0;
    //read_size = ::fread_s(stream_data_buf, MAX_BUFFER_SIZE, 1, MAX_BUFFER_SIZE, pf_ps_file);
    //if (14 == read_size)
    //{
    //    printf("first read successful. \n");
    //}

    //int e0_offset = 0;
    //int iret_value = find_next_pes_packet(stream_data_buf, MAX_BUFFER_SIZE, &common_pes, &e0_offset);

    unsigned char ps_packet_start_code[4];
    ps_packet_start_code[0] = 0x00;
    ps_packet_start_code[1] = 0x00;
    ps_packet_start_code[2] = 0x01;
    ps_packet_start_code[3] = 0xba;

    int ps_packet_length = 0;
    int return_value = -1;

    int next_ps_packet_offset = 0;

    //bool is_end_of_file = false;

    //do {
    //    read_size = ::fread_s(stream_data_buf, MAX_BUFFER_SIZE, 1, MAX_BUFFER_SIZE, pf_ps_file);
    //    if (MAX_BUFFER_SIZE == read_size)
    //    {
    //        //read success.
    //    }
    //    else
    //    {
    //        //read left part, because file have be read all.
    //        //只读取了部分数据，因为文件已经被读取完了。
    //        is_end_of_file = true;
    //    }

    //
    //} while (is_end_of_file);

    read_buffer_left_size = MAX_BUFFER_SIZE;

    do {
        return_value = find_next_hx_str(stream_data_buf  + next_ps_packet_offset,
            MAX_BUFFER_SIZE - next_ps_packet_offset,
            ps_packet_start_code, 4, &ps_packet_length);
        
        if (0 == return_value)
        {
            //查找成功
            processed_size += deal_ps_packet(stream_data_buf + next_ps_packet_offset, ps_packet_length);
            next_ps_packet_offset += ps_packet_length;
        }
        else
        {
            //read_buffer_left_size = MAX_BUFFER_SIZE - processed_size;

            //未查找到，原因有3种情况
            //第一种：全部缓存中的数据没有组成一个完整的PS包，说明当前缓存中的数据都是同一个PS包，对当前缓存中的所有数据进行PS拆包处理
            //第二种：缓存中的数据已经处理了部分，从剩下的部分中没有找到下一个PS包
            //第三种：缓存中没有数据
            //以上两种情况的区分标志是processed_size是否为0，如果为0则表明为第一种情况，如果大于0则说明为第二种情况

            //第三种情况，缓存中没有数据，解决办法——读入文件数据到缓存。
            if (MAX_BUFFER_SIZE == read_buffer_left_size)
            {
                read_size = ::fread_s(stream_data_buf, MAX_BUFFER_SIZE, 1, MAX_BUFFER_SIZE, pf_ps_file);
                read_buffer_left_size = MAX_BUFFER_SIZE - read_size;

                if (MAX_BUFFER_SIZE > read_size)
                {
                    //已读到文件尾
                    //处理缓存中的剩余数据
                    processed_size += deal_ps_packet(stream_data_buf + next_ps_packet_offset, read_size);
                    break;
                    //is_end_of_file = true;
                }
                else
                {
                    continue;
                }
            }


            if (0 == processed_size)
            {
                //第一种情况, 全部缓存中的数据没有组成一个完整的PS包
                processed_size += deal_ps_packet(stream_data_buf, MAX_BUFFER_SIZE);
            }
            else
            {
                //第二种情况，需要继续读入文件数据，然后处理，分两步处理
                //第一步：将缓存中剩余数据移动到缓存最前端；
                //第二步：读取文件数据将缓存区填满。

                //第一步：将缓存中剩余数据移动到缓存最前端；
                memset(tmp_data_buf, 0x00, MAX_BUFFER_SIZE);
                memcpy(tmp_data_buf, stream_data_buf + processed_size , MAX_BUFFER_SIZE - processed_size);

                memset(stream_data_buf, 0x00, MAX_BUFFER_SIZE);
                memcpy(stream_data_buf, tmp_data_buf, MAX_BUFFER_SIZE - processed_size);

                read_buffer_left_size = processed_size;

                processed_size = 0;

                //第二步：读取文件数据将缓存区填满。
                read_size = ::fread_s(stream_data_buf + (MAX_BUFFER_SIZE - read_buffer_left_size), read_buffer_left_size, 1, read_buffer_left_size, pf_ps_file);
                if (read_buffer_left_size > read_size)
                {
                    //已读到文件尾, 处理缓存中剩余的数据。
                    processed_size += deal_ps_packet(stream_data_buf + next_ps_packet_offset, read_size);
                    //is_end_of_file = true;
                    break;
                }
            }  
        }
    } while (true);

    //end job

    //release memory
    if (NULL != stream_data_buf)
    {
        free(stream_data_buf);
    }

    if (NULL != tmp_data_buf)
    {
        free(tmp_data_buf);
    }

    // close ps file 
    if (pf_ps_file)
    {
        err = fclose(pf_ps_file);
        if (err == 0)
        {
            printf("The file '%s' was closed\n", ps_filename);
        }
        else
        {
            printf("The file '%s' was not closed\n", ps_filename);
        }
    }
    return 0;
}
#include "PsStreamDecoder.h"
#include <fstream>

using namespace std;

#define MAX_BUFFER_SIZE (800*1024)

int main(int argc, char* argv[])
{
    char* ps_filename = "E://tmp1.ps";

    FILE* pf_ps_file;

    int buffer_size = MAX_BUFFER_SIZE;
    int processed_size = 0;             //�Ѿ�������Ļ������ݴ�С
    int read_buffer_left_size = 0;          //������ʣ���С

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
    //        //ֻ��ȡ�˲������ݣ���Ϊ�ļ��Ѿ�����ȡ���ˡ�
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
            //���ҳɹ�
            processed_size += deal_ps_packet(stream_data_buf + next_ps_packet_offset, ps_packet_length);
            next_ps_packet_offset += ps_packet_length;
        }
        else
        {
            //read_buffer_left_size = MAX_BUFFER_SIZE - processed_size;

            //δ���ҵ���ԭ����3�����
            //��һ�֣�ȫ�������е�����û�����һ��������PS����˵����ǰ�����е����ݶ���ͬһ��PS�����Ե�ǰ�����е��������ݽ���PS�������
            //�ڶ��֣������е������Ѿ������˲��֣���ʣ�µĲ�����û���ҵ���һ��PS��
            //�����֣�������û������
            //����������������ֱ�־��processed_size�Ƿ�Ϊ0�����Ϊ0�����Ϊ��һ��������������0��˵��Ϊ�ڶ������

            //�����������������û�����ݣ�����취���������ļ����ݵ����档
            if (MAX_BUFFER_SIZE == read_buffer_left_size)
            {
                read_size = ::fread_s(stream_data_buf, MAX_BUFFER_SIZE, 1, MAX_BUFFER_SIZE, pf_ps_file);
                read_buffer_left_size = MAX_BUFFER_SIZE - read_size;

                if (MAX_BUFFER_SIZE > read_size)
                {
                    //�Ѷ����ļ�β
                    //�������е�ʣ������
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
                //��һ�����, ȫ�������е�����û�����һ��������PS��
                processed_size += deal_ps_packet(stream_data_buf, MAX_BUFFER_SIZE);
            }
            else
            {
                //�ڶ����������Ҫ���������ļ����ݣ�Ȼ��������������
                //��һ������������ʣ�������ƶ���������ǰ�ˣ�
                //�ڶ�������ȡ�ļ����ݽ�������������

                //��һ������������ʣ�������ƶ���������ǰ�ˣ�
                memset(tmp_data_buf, 0x00, MAX_BUFFER_SIZE);
                memcpy(tmp_data_buf, stream_data_buf + processed_size , MAX_BUFFER_SIZE - processed_size);

                memset(stream_data_buf, 0x00, MAX_BUFFER_SIZE);
                memcpy(stream_data_buf, tmp_data_buf, MAX_BUFFER_SIZE - processed_size);

                read_buffer_left_size = processed_size;

                processed_size = 0;

                //�ڶ�������ȡ�ļ����ݽ�������������
                read_size = ::fread_s(stream_data_buf + (MAX_BUFFER_SIZE - read_buffer_left_size), read_buffer_left_size, 1, read_buffer_left_size, pf_ps_file);
                if (read_buffer_left_size > read_size)
                {
                    //�Ѷ����ļ�β, ��������ʣ������ݡ�
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
#include "PsDemuxer.h"
#include <fstream>

int CPsDemuxer::find_next_hx_str(unsigned char* source, int source_length, unsigned char* seed, int seed_length, int* offset)
{
    if (source && seed)
    {
    }
    else
    {
        //failure
        return -1;
    }

    unsigned char* pHeader = source + seed_length;

    int total_length = source_length;
    int processed_length = 0;

    int src_offset = 0;
    while (total_length - processed_length >= seed_length)
    {
        for (int i = 0; i < seed_length && (pHeader[i] == seed[i]); i++)
        {
            if (seed_length - 1 == i)
            {
                //find ok
                *offset = seed_length + processed_length;
                return 0;
            }
        }

        processed_length++;
        pHeader = source + seed_length + processed_length;
    }

    return -1;
}


int CPsDemuxer::deal_ps_packet(unsigned char * packet, int length)
{
    int ps_packet_header_size;
    int ps_packet_header_stuffed_size;

    int pes_system_header_header_length;
    int pes_program_stream_map_length;
    int pes_video_h264_packet_size;
    int pes_video_h264_packet_stuffed_size;

    int pes_packet_header_size;
    int pes_packet_header_stuffed_size;

    int packet_total_length = length;
    int packet_processed_length = 0;

    int next_h264_pes_offset = 0;
    int find_h264_return_value = -1;

    int next_ps_header_return_value = 0;
    int find_ps_header_return_value = -1;

    char* out_put_filename = "E://tmp1.h264";

    unsigned char pes_packet_start_code[4];
    pes_packet_start_code[0] = 0x00;
    pes_packet_start_code[1] = 0x00;
    pes_packet_start_code[2] = 0x01;
    pes_packet_start_code[3] = 0xe0;


    ps_packet_header* ps_head = NULL;
    pes_system_header_packet_header_t* pes_system_header;
    pes_program_stream_map_packet_header_t* pes_psm_header;
    pes_video_h264_packet_header_t* pes_video_h264_packet_header;
    pes_audio_packet_header_t* pes_audio_packet_header;
    //pes_packet_header_t* pes_pack_header;

    unsigned char* next_pes_packet = NULL;

    // deal with ps packet header.
    if (packet)
    {
        ps_head = (ps_packet_header*)packet;

        ps_packet_header_size = sizeof(ps_packet_header);
        ps_packet_header_stuffed_size = ps_head->Buf2 & 0x07;

        packet_processed_length += sizeof(ps_packet_header) + ps_packet_header_stuffed_size;

        next_pes_packet = packet + packet_processed_length;
    }

    while (next_pes_packet && (packet_total_length - packet_processed_length >= 0))
    {
        if (next_pes_packet
            && next_pes_packet[0] == 0x00
            && next_pes_packet[1] == 0x00
            && next_pes_packet[2] == 0x01
            && next_pes_packet[3] == 0xbb)
        {
            //this pes packet is system_header or psm, which data is not usefull for es_h264
            pes_system_header = (pes_system_header_packet_header_t*)next_pes_packet;

            littel_endian_size_u tmp_size;
            tmp_size.byte[0] = pes_system_header->header_length.byte[1];
            tmp_size.byte[1] = pes_system_header->header_length.byte[0];

            pes_system_header_header_length = tmp_size.length;

            // +6��ԭ����pes_packet_header_t�г����ֽ�֮ǰ����6���ֽ�
            packet_processed_length += (6 + pes_system_header_header_length);

            next_pes_packet = packet + packet_processed_length;
        }
        else if (next_pes_packet
            && next_pes_packet[0] == 0x00
            && next_pes_packet[1] == 0x00
            && next_pes_packet[2] == 0x01
            && next_pes_packet[3] == 0xbc)
        {
            //this pes packet is program stream map, which data is not usefull for es_h264
            pes_psm_header = (pes_program_stream_map_packet_header_t*)next_pes_packet;

            littel_endian_size_u tmp_size;
            tmp_size.byte[0] = pes_psm_header->program_stream_map_length.byte[1];
            tmp_size.byte[1] = pes_psm_header->program_stream_map_length.byte[0];

            pes_program_stream_map_length = tmp_size.length;
            pes_packet_header_size = sizeof(pes_program_stream_map_packet_header_t);

            // -6��ԭ����pes_packet_header_t��Ϊ�˻�ȡpes��ͷ�Ĵ�С�ͷ�ֹ�ṹ���Զ���䣬�������6���ֽڵĿռ�
            // +2��ԭ���ǴӺ������񴦻�ȡ��ps������stream_map_lengthָ���Ĵ�С֮�󻹶���2���ֽڲŵ���Ƶ��pes��
            packet_processed_length += pes_packet_header_size - 6 + pes_program_stream_map_length;

            next_pes_packet = packet + packet_processed_length;
        }

        else if (next_pes_packet
            && next_pes_packet[0] == 0x00
            && next_pes_packet[1] == 0x00
            && next_pes_packet[2] == 0x01
            && next_pes_packet[3] == 0xe0)
        {
            //contain video es stream
            pes_video_h264_packet_header = (pes_video_h264_packet_header_t*)next_pes_packet;

            littel_endian_size_u tmp_size;
            tmp_size.byte[0] = pes_video_h264_packet_header->packet_size.byte[1];
            tmp_size.byte[1] = pes_video_h264_packet_header->packet_size.byte[0];

            pes_video_h264_packet_size = tmp_size.length;
            pes_video_h264_packet_stuffed_size = pes_video_h264_packet_header->pes_packet_header_stuff_size;

            // +9 ��ԭ����pes_video_h264_packet_stuffed_size֮ǰ����9���ֽڵ�ͷ������
            // -5 ��ԭ������pes_video_h264_packet����packet_size�ֽ�֮��ĵ������ֽ�˵����ͷ��ʣ�������ֽ���
            //writeLog("E://new_mediaplay.h264", 
            //    next_pes_packet + 9 +pes_video_h264_packet_stuffed_size,
            //    pes_video_h264_packet_size - pes_video_h264_packet_stuffed_size - 3);

            //������һ��������Ƶ���ݵ�pes����stream_idΪ'e0'��pes������
            find_h264_return_value = find_next_hx_str(next_pes_packet,
                packet_total_length - packet_processed_length,
                pes_packet_start_code,
                4,
                &next_h264_pes_offset);

            //packet_processed_length += (6+pes_video_h264_packet_size);
            if (0 == find_h264_return_value)
            {
                //���ҳɹ�
                writeLog(out_put_filename,
                    next_pes_packet + 9 + pes_video_h264_packet_stuffed_size,
                    next_h264_pes_offset - 9 - pes_video_h264_packet_stuffed_size);

                packet_processed_length += next_h264_pes_offset;
                next_pes_packet = packet + packet_processed_length;
            }
            else
            {
                //��PS����ʣ�����һ������h264��PES���ݰ�����ʣ�������Ҳд���ļ���
                writeLog(out_put_filename,
                    next_pes_packet + 9 + pes_video_h264_packet_stuffed_size,
                    packet_total_length - packet_processed_length - 9 - pes_video_h264_packet_stuffed_size);
                packet_processed_length = packet_total_length;
                break;
            }
        }

        else if (next_pes_packet
            && next_pes_packet[0] == 0x00
            && next_pes_packet[1] == 0x00
            && next_pes_packet[2] == 0x01
            && next_pes_packet[3] == 0xc0)
        {
            //contain audio es stream
            pes_audio_packet_header = (pes_audio_packet_header_t*)next_pes_packet;
        }

        // next ps packet, return.
        else if (next_pes_packet
            && next_pes_packet[0] == 0x00
            && next_pes_packet[1] == 0x00
            && next_pes_packet[2] == 0x01
            && next_pes_packet[3] == 0xba)
        {
            //next ps stream, return , not continue deal
            break;
        }
        else
        {
            // bad data
            break;
        }
    }

    return packet_processed_length;
}

void CPsDemuxer::writeLog(char* file_name, void* pLog, int nLen)
{
    FILE* m_pLogFile = NULL;
    if (pLog != NULL && nLen > 0)
    {
        if (NULL == m_pLogFile && strlen(file_name) > 0)
        {
            ::fopen_s(&m_pLogFile, file_name, "a+");
        }

        if (m_pLogFile != NULL)
        {
            ::fwrite(pLog, nLen, 1, m_pLogFile);
            ::fclose(m_pLogFile);
            m_pLogFile = NULL;
        }
    }
}

int CPsDemuxer::do_prase()
{
    char* ps_filename = "E://tmp1.ps";

    FILE* pf_ps_file;

    int buffer_size = MAX_BUFFER_SIZE;
    int processed_size = 0;             //�Ѿ�������Ļ������ݴ�С
    int read_buffer_left_size = 0;          //������ʣ���С

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

    int read_size = 0;

    unsigned char ps_packet_start_code[4];
    ps_packet_start_code[0] = 0x00;
    ps_packet_start_code[1] = 0x00;
    ps_packet_start_code[2] = 0x01;
    ps_packet_start_code[3] = 0xba;

    int ps_packet_length = 0;
    int return_value = -1;

    int next_ps_packet_offset = 0;

    read_buffer_left_size = MAX_BUFFER_SIZE;

    do {
        return_value = find_next_hx_str(stream_data_buf + next_ps_packet_offset,
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
                memcpy(tmp_data_buf, stream_data_buf + processed_size, MAX_BUFFER_SIZE - processed_size);

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

void CPsDemuxer::setup_src_ps_file(char* filename) 
{
    memset(src_ps_filename, 0x00, MAX_FILENAME_LENGTH);
    if (strlen(filename) > 0)
    {
        sprintf_s(src_ps_filename, MAX_FILENAME_LENGTH, "%s", filename);
    }
}

void CPsDemuxer::setup_dst_es_video_file(char* filename)
{
    memset(dst_es_video_filename, 0x00, MAX_FILENAME_LENGTH);
    if (strlen(filename) > 0)
    {
        sprintf_s(dst_es_video_filename, MAX_FILENAME_LENGTH, "%s", filename);
    }
}

void CPsDemuxer::setup_dst_es_audio_file(char* filename)
{
    memset(dst_es_audio_filename, 0x00, MAX_FILENAME_LENGTH);
    if (strlen(filename) > 0)
    {
        sprintf_s(dst_es_audio_filename, MAX_FILENAME_LENGTH, "%s", filename);
    }
}
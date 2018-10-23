
#include "PsStreamDecoder.h"

void writeLog(char* file_name, void* pLog, int nLen)
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

int find_next_hx_str(unsigned char* source, int source_length, unsigned char* seed, int seed_length, int* offset)
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
    while (total_length - processed_length >= seed_length )
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

int deal_ps_packet(unsigned char * packet, int length)
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
            packet_processed_length += pes_packet_header_size - 6 + pes_program_stream_map_length ;

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
                packet_total_length - packet_processed_length , 
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

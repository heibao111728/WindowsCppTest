#ifndef __PSSTREAMDECODER_H__
#define __PSSTREAMDECODER_H__

#include <stdio.h>
#include <string.h>

// PES ��stream_id ֮��������ֽ��д�Ÿ�PES���ĳ���
typedef union littel_endian_size
{
    unsigned short int  length;
    unsigned char       byte[2];
}littel_endian_size_u;

/**
*   PES system header packet header
*/
typedef struct pes_system_header_packet_header
{
    unsigned char system_header_start_code[4];
    littel_endian_size_u header_length;
    unsigned char buf[6];                   //����ֶΣ����ISOIEC 13818-1.pdf Table 2-18
} pes_system_header_packet_header_t;

/**
*   PES program stream map packet header
*/
typedef struct pes_program_stream_map_packet_header
{
    unsigned char packet_start_code_prefix[3];
    unsigned char map_stream_id;
    littel_endian_size_u program_stream_map_length;
    unsigned char buf[6];                   //����ֶΣ����ISOIEC 13818-1.pdf Table 2-18
} pes_program_stream_map_packet_header_t;

/**
*   PES video h264 packet header
*/
typedef struct pes_video_h264_packet_header
{
    unsigned char start_code[3];
    unsigned char stream_id[1];
    littel_endian_size_u packet_size;
    unsigned char buf[2];                   //����ֶΣ����ISOIEC 13818-1.pdf Table 2-18
    unsigned char pes_packet_header_stuff_size;
    unsigned char struct_stuff[3];             //��ֹ�Զ�����, ���¼���ṹ���С����
} pes_video_h264_packet_header_t;

/**
*   PES audio packet header
*/
typedef struct pes_audio_packet_header
{
    unsigned char start_code[3];
    unsigned char stream_id[1];
    littel_endian_size_u packet_size;
    unsigned char buf[2];                   //����ֶΣ����ISOIEC 13818-1.pdf Table 2-18
    unsigned char pes_packet_header_stuff_size;
    unsigned char struct_stuff[3];             //��ֹ�Զ�����, ���¼���ṹ���С����
} pes_audio_packet_header_t;

/**
*   PS packet header
*/
typedef struct ps_packet_header
{
    unsigned char start_code[4];
    unsigned char Buf1[9];              // ps��ͷ�����ݣ���������ϸ����
    unsigned char Buf2;                 // ps���е�14���ֽڵĺ�3λ����˵��������ݵĳ���
}ps_packet_header_t;


/**
*   ���ܣ�
*       ��Դ16�����ַ���source�У�����ָ���ĵ�16�����ַ����С�
*
*   �����б���
*       source��         Դ�ַ�����
*       source_length��  Դ�ַ����г���
*       seed��           �����ҵ��ַ�����
*       seed_length��    �����ҵ��ַ����г���
*       offset��         ����ɹ�����ֵ��ʾ�����ҵ��ַ�������Դ�ַ������е�λ�ơ�
*   ����ֵ��
*       0���ɹ���offsetֵ����
*       -1��ʧ�ܣ�offsetֵΪ����ֵ��������
*/
int find_next_hx_str(unsigned char* source, int source_length, unsigned char* seed, int seed_length, int* offset);
/**
*   return: �����뻺�����Ѿ���ȷ�����ĳ���
*/
int deal_ps_packet(unsigned char * packet, int length);

void writeLog(char* file_name, void* pLog, int nLen);



#endif // !__PSSTREAMDECODER_H__
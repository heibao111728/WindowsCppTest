#ifndef __PSSTREAMDECODER_H__
#define __PSSTREAMDECODER_H__

#include <stdio.h>
#include <string.h>

// PES 包stream_id 之后的两个字节中存放该PES包的长度
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
    unsigned char buf[6];                   //填充字段，详见ISOIEC 13818-1.pdf Table 2-18
} pes_system_header_packet_header_t;

/**
*   PES program stream map packet header
*/
typedef struct pes_program_stream_map_packet_header
{
    unsigned char packet_start_code_prefix[3];
    unsigned char map_stream_id;
    littel_endian_size_u program_stream_map_length;
    unsigned char buf[6];                   //填充字段，详见ISOIEC 13818-1.pdf Table 2-18
} pes_program_stream_map_packet_header_t;

/**
*   PES video h264 packet header
*/
typedef struct pes_video_h264_packet_header
{
    unsigned char start_code[3];
    unsigned char stream_id[1];
    littel_endian_size_u packet_size;
    unsigned char buf[2];                   //填充字段，详见ISOIEC 13818-1.pdf Table 2-18
    unsigned char pes_packet_header_stuff_size;
    unsigned char struct_stuff[3];             //防止自动补齐, 导致计算结构体大小出错
} pes_video_h264_packet_header_t;

/**
*   PES audio packet header
*/
typedef struct pes_audio_packet_header
{
    unsigned char start_code[3];
    unsigned char stream_id[1];
    littel_endian_size_u packet_size;
    unsigned char buf[2];                   //填充字段，详见ISOIEC 13818-1.pdf Table 2-18
    unsigned char pes_packet_header_stuff_size;
    unsigned char struct_stuff[3];             //防止自动补齐, 导致计算结构体大小出错
} pes_audio_packet_header_t;

/**
*   PS packet header
*/
typedef struct ps_packet_header
{
    unsigned char start_code[4];
    unsigned char Buf1[9];              // ps包头部数据，后续再详细划分
    unsigned char Buf2;                 // ps包中第14个字节的后3位用来说明填充数据的长度
}ps_packet_header_t;


/**
*   功能：
*       在源16进制字符串source中，查找指定的的16进制字符序列。
*
*   参数列表：
*       source：         源字符序列
*       source_length：  源字符序列长度
*       seed：           被查找的字符序列
*       seed_length：    被查找的字符序列长度
*       offset：         如果成功，该值表示被查找的字符序列在源字符序列中的位移。
*   返回值：
*       0：成功，offset值可用
*       -1：失败，offset值为垃圾值，不可用
*/
int find_next_hx_str(unsigned char* source, int source_length, unsigned char* seed, int seed_length, int* offset);
/**
*   return: 从输入缓存中已经正确处理的长度
*/
int deal_ps_packet(unsigned char * packet, int length);

void writeLog(char* file_name, void* pLog, int nLen);



#endif // !__PSSTREAMDECODER_H__

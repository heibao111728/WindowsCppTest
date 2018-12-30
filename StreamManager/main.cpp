#include "StreamManager.h"

int main()
{
    unsigned char buf_src[8] ;
    buf_src[0] = 0x70;
    buf_src[1] = 0x71;
    buf_src[2] = 0x72;
    buf_src[3] = 0x73;
    buf_src[4] = 0x74;
    buf_src[5] = 0x75;
    buf_src[6] = 0x76;
    buf_src[7] = 0x77;

    unsigned char buf_src2[8];
    buf_src2[0] = 0x80;
    buf_src2[1] = 0x81;
    buf_src2[2] = 0x82;
    buf_src2[3] = 0x83;
    buf_src2[4] = 0x84;
    buf_src2[5] = 0x85;
    buf_src2[6] = 0x86;
    buf_src2[7] = 0x87;
    
    unsigned char buf_dst[8];
    unsigned char buf_dst2[8];

    CStreamManager* pstream_manager = CStreamManager::get_instance();
    pstream_manager->write_data(buf_src, 8);
    pstream_manager->read_data(NULL, buf_dst, 6);

    pstream_manager->write_data(buf_src2, 6);
    pstream_manager->read_data(NULL, buf_dst2, 8);


    return 0;
}
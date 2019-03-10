#ifndef __BIT_MAP_H__
#define __BIT_MAP_H__

#include <windows.h>
class BitMap
{
public:
    BitMap();
    ~BitMap();
public:
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
public:
    int width_p, height_p, bitCount;
    unsigned char *dataBuf;
    LPRGBQUAD colorTable;
    bool Read(char *fileName);
    bool Write(char *_fileName);
};

#endif
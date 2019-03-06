#include "stdafx.h"
#include "bit_map.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#define NULL 0

BitMap::BitMap()
{
}

BitMap::~BitMap()
{
}


//read bitmap info from a file
bool BitMap::Read(char* fileName)
{
    FILE *_f = fopen(fileName, "rb");//open file
    if (_f == NULL) return false;

    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, _f);//read BITMAPFILEHEADER

    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, _f);//read BITMAPINFOHEADER
    width_p = infoHeader.biWidth;
    height_p = infoHeader.biHeight;
    bitCount = infoHeader.biBitCount;

    if (bitCount == 8)//if colorTable exist,read colorTable
    {
        colorTable = new RGBQUAD[256];
        fread(&colorTable, sizeof(RGBQUAD), 256, _f);
    }

    dataBuf = new unsigned char[infoHeader.biSizeImage];//read image data
    fread(dataBuf, 1, infoHeader.biSizeImage, _f);

    fclose(_f);//close file
    return true;
}

//write bitmap info to a file
bool BitMap::Write(char * _fileName)
{
    FILE* f = fopen(_fileName, "wb");//create or open file to be written
    if (f == NULL) return false;

    int colorTableSize = 0;//if bitcount is 24, there is no color table.
    if (bitCount == 8)//if bitcount is 8 ,the size of color table is 256*4,4B is the size of RGBQUAD.
        colorTableSize = sizeof(RGBQUAD) * 256;

    int headerSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTableSize;//the size of the header of bmp file.
    int lineSize = (width_p*bitCount / 8 + 3) / 4 * 4;//the size of each line in bmp file.
    int dataSize = lineSize*height_p;//the size of the image data of bmp file.

    fileHeader.bfType = 0x4D42;//set the attribute of BITMAPFILEHEADER
    fileHeader.bfSize = headerSize + dataSize;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = headerSize;

    infoHeader.biSize = 40;//set the attribute of BITMAPINFOHEADER
    infoHeader.biWidth = width_p;
    infoHeader.biHeight = height_p;
    infoHeader.biPlanes = 1;
    infoHeader.biBitCount = bitCount;
    infoHeader.biCompression = 0;
    infoHeader.biSizeImage = dataSize;
    infoHeader.biClrImportant = 0;
    infoHeader.biXPelsPerMeter = 0;
    infoHeader.biYPelsPerMeter = 0;

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, f);//write the data of BITFILEHEADER to bmp file
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, f);//write the data of BITINFOHEADER to bmp file
    if (bitCount == 8)//if color table exists,write the data of color table to bmp file
    {
        colorTable = new RGBQUAD[256];
        fwrite(&colorTable, sizeof(RGBQUAD), 256, f);
    }
    fwrite(dataBuf, 1, dataSize, f);//write the image data to bmp file

    fclose(f);//data writting is finished,close the bmp file.
    return true;
}
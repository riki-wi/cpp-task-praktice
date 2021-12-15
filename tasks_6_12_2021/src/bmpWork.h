#include <iostream>
#include <fstream>

#ifndef TASKS_6_12_2021_BMPWORK_H
#pragma pack(push, 1)

struct BITMAPFILEHEADER
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
}typedef BITMAPFILEHEADER;

struct BITMAPINFOHEADER
{
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompressions;
    uint32_t biImageSize;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biColorsUsed;
    uint32_t biColorsImportant;
}typedef BITMAPINFOHEADER;

/* only BitCount <= 8 */
struct BITMAPCOLORTABLE
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t reserved;
}typedef BITMAPCOLORTABLE;

struct PIXEL24
{
    uint8_t read;
    uint8_t green;
    uint8_t blue;
}typedef PIXEL24;

struct PICTURE
{
    BITMAPFILEHEADER bMFH;
    BITMAPINFOHEADER bMIH;
    BITMAPCOLORTABLE *bMCT;
    uint8_t *pixel;
}typedef PICTURE;

#pragma pack(pop)

char randInt();
std::string translation(unsigned long long);
std::string checkNumberForTranslation(int x);

PIXEL24 getPixel24(const unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate);
void setPixel24(unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate, PIXEL24 pixel);

PICTURE readBMP(const std::string& path);
void writeBMP(PICTURE picture, const std::string& path);
void printPixelHex(PICTURE picture);

void swapRG(const std::string& path);

void collage24(const std::string& pathOne, const std::string& pathTwo);

void mask(const std::string& pathIn, const std::string& pathOut, const double* mask, int dev, int sizeMask);

#define TASKS_6_12_2021_BMPWORK_H


#endif

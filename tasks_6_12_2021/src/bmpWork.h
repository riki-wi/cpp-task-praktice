#include <iostream>
#include <fstream>

#ifndef TASKS_6_12_2021_BMPWORK_H
#pragma pack(push, 1)

struct BITMAPFILEHEADER
{
    int16_t bfType;
    int32_t bfSize;
    int16_t bfReserved1;
    int16_t bfReserved2;
    int32_t bfOffBits;
}typedef BITMAPFILEHEADER;

struct BITMAPINFOHEADER
{
    int32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    int16_t biPlanes;
    int16_t biBitCount;
    int32_t biCompressions;
    int32_t biImageSize;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    int32_t biColorsUsed;
    int32_t biColorsImportant;
}typedef BITMAPINFOHEADER;

/* only BitCount <= 8 */
struct BITMAPCOLORTABLE
{
    int8_t red;
    int8_t green;
    int8_t blue;
    int8_t reserved;
}typedef BITMAPCOLORTABLE;

struct PIXEL24
{
    int8_t read;
    int8_t green;
    int8_t blue;
}typedef PIXEL24;

struct PICTURE
{
    BITMAPFILEHEADER bMFH;
    BITMAPINFOHEADER bMIH;
    BITMAPCOLORTABLE *bMCT;
    int8_t *pixel;
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

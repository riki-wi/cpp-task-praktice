#include "bmpWork.h"

/* рандомное число в отрезке [0:255] */
char randInt()
{
    return rand() % 256;
}

std::string checkNumberForTranslation(int x)
{
    switch (x)
    {
        case 0: return "0";
        case 10: return "A";
        case 11: return "B";
        case 12: return "C";
        case 13: return "D";
        case 14: return "E";
        case 15: return "F";
        default: return std::to_string(x);
    }
}

std::string translation(unsigned  long long x)
{
    std::string res;
    if(!x)
    {
        return "00";
    }
    while (x >= 1)
    {
        res += checkNumberForTranslation((int)x % 16);
        x = x >> 4;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

/*
создание рандомной черно-белой(монохронной) картинки с задаными размерами в пикселях
void createBlackWhiteBMP(int32_t biWidth, int32_t biHeight, const std::string& path)
{
    std::ofstream fout(path, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

    BITMAPFILEHEADER bMapFileHeader;
    bMapFileHeader.bfType = 0x4d42;
    bMapFileHeader.bfSize = 14 + 40 + 8 + (biWidth * biHeight) / 8;
    bMapFileHeader.bfReserved1 = 0;
    bMapFileHeader.bfReserved2 = 0;
    bMapFileHeader.bfOffBits = 14 + 40 + 8;

    BITMAPINFOHEADER bMapInfoHeader;
    bMapInfoHeader.biSize = 40;
    bMapInfoHeader.biWidth = biWidth;
    bMapInfoHeader.biHeight = biHeight;
    bMapInfoHeader.biPlanes = 1;
    bMapInfoHeader.biBitCount = 1;
    bMapInfoHeader.biCompressions = 0;
    bMapInfoHeader.biImageSize = biHeight * biWidth / 8;
    bMapInfoHeader.biXPelsPerMeter = 0;
    bMapInfoHeader.biYPelsPerMeter = 0;
    bMapInfoHeader.biColorsUsed = 0;
    bMapInfoHeader.biColorsImportant = 0;

    BITMAPCOLORTABLE bMapColorTableWhite;
    bMapColorTableWhite.red = 255;
    bMapColorTableWhite.blue = 255;
    bMapColorTableWhite.green = 255;
    bMapColorTableWhite.reserved = 0;

    BITMAPCOLORTABLE bMapColorTableBlack;
    bMapColorTableBlack.red = 0;
    bMapColorTableBlack.blue = 0;
    bMapColorTableBlack.green = 0;
    bMapColorTableBlack.reserved = 0;

    fout.write((char*)&bMapFileHeader, 14);
    fout.write((char*)&bMapInfoHeader, 40);
    fout.write((char*)&bMapColorTableWhite, 4);
    fout.write((char*)&bMapColorTableBlack, 4);


    for(int i = 0; i < biWidth * biWidth / 8; i++)
    {
        char x = randInt();
        fout.write((char*)& x, sizeof(char));
    }

    fout.close();
}
*/
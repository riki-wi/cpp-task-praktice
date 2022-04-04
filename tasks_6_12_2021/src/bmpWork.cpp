#include "bmpWork.h"

PICTURE readBMP(const std::string& path)
{
    std::ifstream fin(path, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << path << std::endl;
        fin.close();
        exit(-1);
    }

    PICTURE res;
    fin.read((char*)& res.bMFH.bfType, 2);
    fin.read((char*)& res.bMFH.bfSize, 4);
    fin.read((char*)& res.bMFH.bfReserved1, 2);
    fin.read((char*)& res.bMFH.bfReserved2, 2);
    fin.read((char*)& res.bMFH.bfOffBits, 4);

    fin.read((char*)& res.bMIH.biSize, 4);
    fin.read((char*)& res.bMIH.biWidth, 4);
    fin.read((char*)& res.bMIH.biHeight, 4);
    fin.read((char*)& res.bMIH.biPlanes, 2);
    fin.read((char*)& res.bMIH.biBitCount, 2);
    fin.read((char*)& res.bMIH.biCompressions, 4);
    fin.read((char*)& res.bMIH.biImageSize, 4);
    fin.read((char*)& res.bMIH.biXPelsPerMeter, 4);
    fin.read((char*)& res.bMIH.biYPelsPerMeter, 4);
    fin.read((char*)& res.bMIH.biColorsUsed, 4);
    fin.read((char*)& res.bMIH.biColorsImportant, 4);

    res.bMIH.biWidth = abs(res.bMIH.biWidth);
    res.bMIH.biHeight = abs(res.bMIH.biHeight);

    if(!res.bMIH.biImageSize)
    {
        std::cout << "Невозможно прочитать изображение" << path << std::endl;
        fin.close();
        exit(-1);
    }

    if(res.bMIH.biBitCount == 1)
    {
        res.bMCT = new BITMAPCOLORTABLE[res.bMIH.biColorsUsed];
        for(size_t i = 0; i < (res.bMFH.bfSize - res.bMIH.biImageSize - 54) / 4; i++)
        {
            fin.read((char*)&res.bMCT[i].red, 1);
            fin.read((char*)&res.bMCT[i].green, 1);
            fin.read((char*)&res.bMCT[i].blue, 1);
            fin.read((char*)&res.bMCT[i].reserved, 1);
        }

        res.pixel = new uint8_t[res.bMIH.biImageSize];
        fin.read((char*)res.pixel, res.bMIH.biImageSize);
    }
    else if(res.bMIH.biBitCount == 8)
    {
        res.bMCT = new BITMAPCOLORTABLE[res.bMIH.biColorsUsed];
        for(size_t i = 0; i < (res.bMFH.bfSize - res.bMIH.biImageSize - 54) / 4; i++)
        {
            fin.read((char*)&res.bMCT[i].red, 1);
            fin.read((char*)&res.bMCT[i].green, 1);
            fin.read((char*)&res.bMCT[i].blue, 1);
            fin.read((char*)&res.bMCT[i].reserved, 1);
        }

        res.pixel = new uint8_t[res.bMIH.biImageSize];
        fin.read((char*)res.pixel, res.bMIH.biImageSize);
    }
    else if(res.bMIH.biBitCount == 24)
    {
        res.pixel = new uint8_t[res.bMIH.biImageSize];
        fin.read((char*)res.pixel, res.bMIH.biImageSize);
    }

    else
    {
        std::cout << "Невозможно прочитать изображение " << path << std::endl;
        fin.close();
        exit(-1);
    }

    fin.close();
    return res;
}

void writeBMP(PICTURE picture, const std::string& path)
{
    std::ofstream fout(path, std::ios_base::in | std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
    if(!fout)
    {
        std::cout << "Не удается открыть файл для записи " << path << std::endl;
        fout.close();
        exit(-1);
    }

    if(!picture.bMIH.biImageSize)
    {
        std::cout << "Невозможно записать изображение " << path << std::endl;
        fout.close();
        exit(-1);
    }

    fout.write((char*)& picture.bMFH.bfType, 2);
    fout.write((char*)& picture.bMFH.bfSize, 4);
    fout.write((char*)& picture.bMFH.bfReserved1, 2);
    fout.write((char*)& picture.bMFH.bfReserved2, 2);
    fout.write((char*)& picture.bMFH.bfOffBits, 4);

    fout.write((char*)& picture.bMIH.biSize, 4);
    fout.write((char*)& picture.bMIH.biWidth, 4);
    fout.write((char*)& picture.bMIH.biHeight, 4);
    fout.write((char*)& picture.bMIH.biPlanes, 2);
    fout.write((char*)& picture.bMIH.biBitCount, 2);
    fout.write((char*)& picture.bMIH.biCompressions, 4);
    fout.write((char*)& picture.bMIH.biImageSize, 4);
    fout.write((char*)& picture.bMIH.biXPelsPerMeter, 4);
    fout.write((char*)& picture.bMIH.biYPelsPerMeter, 4);
    fout.write((char*)& picture.bMIH.biColorsUsed, 4);
    fout.write((char*)& picture.bMIH.biColorsImportant, 4);

    if(picture.bMIH.biBitCount == 1)
    {
        for(size_t i = 0; i < (picture.bMFH.bfSize - picture.bMIH.biImageSize - 54) / 4; i++)
        {
            fout.write((char*)&picture.bMCT[i].red, 1);
            fout.write((char*)&picture.bMCT[i].green, 1);
            fout.write((char*)&picture.bMCT[i].blue, 1);
            fout.write((char*)&picture.bMCT[i].reserved, 1);
        }
        fout.write((char*)picture.pixel, picture.bMIH.biImageSize);
    }
    else if(picture.bMIH.biBitCount == 8)
    {
        for(size_t i = 0; i < picture.bMIH.biColorsUsed; i++)
        {
            fout.write((char*)&picture.bMCT[i].red, 1);
            fout.write((char*)&picture.bMCT[i].green, 1);
            fout.write((char*)&picture.bMCT[i].blue, 1);
            fout.write((char*)&picture.bMCT[i].reserved, 1);
        }
        fout.write((char*)picture.pixel, picture.bMIH.biImageSize);
    }

    else if(picture.bMIH.biBitCount == 24)
    {
        fout.write((char*)picture.pixel, picture.bMIH.biImageSize);
    }

    else
    {
        std::cout << "Невозможно записать изображение" << std::endl;
        fout.close();
        exit(-1);
    }

    fout.close();
}

void printPixelHex(PICTURE picture)
{
    for(size_t i = 0; i < picture.bMIH.biImageSize; i++)
    {
        if(i % 32)
        {
            std::cout << translation(picture.pixel[i]) << " ";
        }
        else
        {
            std::cout << std::endl << translation(picture.pixel[i]) << " ";
        }
    }
}


void swapRG(const std::string& pathIn)
{
    PICTURE pct = readBMP(pathIn);

    if(pct.bMIH.biBitCount != 24)
    {
        std::cout << "Неверная битность изображений";
        exit(-1);
    }

    for(size_t i = 0; i < pct.bMIH.biImageSize; i++)
    {
        PIXEL24 pixel = getPixel24(pct.pixel, pct.bMIH.biWidth, pct.bMIH.biHeight, i, 0);
        PIXEL24 res;
        res.green = pixel.red;
        res.blue = pixel.blue;
        res.red = pixel.green;

        setPixel24(pct.pixel, pct.bMIH.biWidth, pct.bMIH.biHeight, i, 0, res);
    }
    writeBMP(pct, pathIn);
}

PIXEL24 getPixel24(const unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate)
{
    PIXEL24 res;
    res.blue = date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4)];
    res.green = date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4) + 1];
    res.red = date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4) + 2];
    return res;
}

void setPixel24(unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate, PIXEL24 pixel)
{
    date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4)] = pixel.blue;
    date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4) + 1] = pixel.green;
    date[3 * (width) * heightDate + 3 * widthDate + heightDate * (width % 4) + 2] = pixel.red;
}

uint8_t getPixel8(const unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate)
{
    return date[3 * (width) * heightDate + 3 * widthDate + heightDate * (3 * width % 4)];
}

void setPixel8(unsigned char *date, size_t width, size_t height, size_t widthDate, size_t heightDate, uint8_t pixel)
{
    date[3 * (width) * heightDate + 3 * widthDate + heightDate * (3 * width % 4)] = pixel;
}

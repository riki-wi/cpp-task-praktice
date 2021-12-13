#include <iostream>
#include <fstream>
#include <random>


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

/* only BitCount = 1 */
struct BITMAPCOLORTABLE
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t reserved;
}typedef BITMAPCOLORTABLE;

#pragma pack(pop)


/* рандомное интовое число */
char randInt()
{
    return rand() % 256;
}

/* функция получает ширину bmp файла */
int32_t getWidth(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return 0;
    }
    fin.seekg(18);
    int32_t width = 0;
    fin.read((char*)&width, 4);
    fin.close();
    return width;
}

/* функция получает высоту bmp файла */
int32_t getHeight(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return 0;
    }
    fin.seekg(22);
    int32_t height = 0;
    fin.read((char*)&height, 4);
    fin.close();
    return height;
}

/* функция получает положение пиксельных данных относительно начала bmp структуры (в байтах)
 * offBits */
int32_t getOffBits(const std::string& name)
{
    std::ifstream fin(name, std::ios_base::in | std::ios_base::binary);
    if(!fin)
    {
        std::cout << "Не удается открыть файл " << name << std::endl;
        fin.close();
        return 0;
    }
    fin.seekg(10);
    int32_t offBits = 0;
    fin.read((char*)&offBits, 4);
    fin.close();
    return offBits;
}

/* создание рандомной черно-белой(монохронной) картинки с задаными размерами в пикселях */
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

void collage(const std::string& pathOne, const std::string& pathTwo)
{
    std::string pathBig;
    std::string pathLittle;
    if((getHeight(pathTwo) < getWidth(pathOne)) && (getHeight(pathTwo) < getHeight(pathOne)))
    {
        pathBig = pathOne;
        pathLittle = pathTwo;
    }
    else if ((getHeight(pathTwo) > getWidth(pathOne)) && (getHeight(pathTwo) > getHeight(pathOne)))
    {
        pathLittle = pathOne;
        pathBig = pathTwo;
    }
    else
    {
        exit(-1);
    }

    int32_t offBitsLittle = getOffBits(pathLittle);
    int32_t offBitsBig = getOffBits(pathBig);
    std::cout << offBitsBig << " " << offBitsLittle;
    int size = getHeight(pathLittle) * getWidth(pathLittle) * 3;

    std::ifstream fin(pathLittle, std::ios_base::in | std::ios_base::binary);
    std::ofstream fout(pathBig, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    fin.seekg(offBitsLittle);
    fout.seekp(0, std::ios::end);

    /*
    for(int i = 0; i < size; i++)
    {
        char bit;
        fin.read(&bit, 1);
        fout.write(&bit, 1);
    }*/



    for(int j = 0; j < getHeight(pathLittle); j++)
    {
        fout.seekp(-(getWidth(pathLittle) + j * getWidth(pathBig) * 3), std::ios::end);
        for(int i = 0; i < getWidth(pathLittle) * 3; i++)
        {
            int* bits;
            fin.read((char*) &bits, 1);
            fout.write((char*) &bits, 1);
        }
    }
    fin.seekg(offBitsLittle);
    fout.seekp(0, std::ios::end);

    fin.close();
    fout.close();
}


int main()
{
    //createBlackWhiteBMP(640, 480, "../resources/myBlackWhiteBmp640x480.bmp");
    //createBlackWhiteBMP(100, 50, "../resources/myBlackWhiteBmp100x50.bmp");
    collage("../resources/bell.bmp", "../resources/snail.bmp");

    return 0;
}

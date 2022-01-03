#include "bmpWork.h"

void collage(const std::string& pathOne, const std::string& pathTwo)
{
    PICTURE pctOne = readBMP(pathOne);
    PICTURE pctTwo = readBMP(pathTwo);
    PICTURE *pctBig;
    PICTURE *pctLittle;
    std::string pathBig;

    if(pctOne.bMIH.biBitCount != pctTwo.bMIH.biBitCount)
    {
        std::cout << "изображения должны иметь одинаковую битность";
        exit(-1);
    }

    if(pctOne.bMIH.biHeight <= pctTwo.bMIH.biHeight && pctOne.bMIH.biWidth <= pctTwo.bMIH.biWidth)
    {
        pctLittle = &pctOne;
        pctBig = &pctTwo;
        pathBig = pathTwo;
    }
    else if(pctOne.bMIH.biHeight >= pctTwo.bMIH.biHeight && pctOne.bMIH.biWidth >= pctTwo.bMIH.biWidth)
    {
        pctBig = &pctOne;
        pctLittle = &pctTwo;
        pathBig = pathOne;
    }
    else
    {
        std::cout << "Неверные размеры изображений";
        exit(-1);
    }

    if(pctBig->bMIH.biBitCount == 24)
    {
        collage24(*pctLittle, *pctBig, pathBig);
    }
    else if(pctBig->bMIH.biBitCount == 8)
    {
        collage8(*pctLittle, *pctBig, pathBig);
    }
    else if(pctBig->bMIH.biBitCount == 1)
    {
        collage1(*pctLittle, *pctBig, pathBig);
    }
    else
    {
        std::cout << "Программа поддерживает только 1, 8, 24 битные изображения " << std::endl;
    }
}


void collage24(PICTURE pctLittle, PICTURE pctBig, const std::string& pathBig)
{
    for(size_t i = 0; i < abs(pctLittle.bMIH.biHeight); i++)
    {
        for(size_t j = 0; j < abs(pctLittle.bMIH.biWidth); j++)
        {
            PIXEL24 pixel24 = getPixel24(pctLittle.pixel, pctLittle.bMIH.biWidth, pctLittle.bMIH.biHeight, j, i);
            uint32_t height = pctBig.bMIH.biHeight - pctLittle.bMIH.biHeight + i;
            setPixel24(pctBig.pixel, pctBig.bMIH.biWidth, pctBig.bMIH.biHeight, j, height, pixel24);
        }
    }
    writeBMP(pctBig, pathBig);
}

void collage8(PICTURE pctLittle, PICTURE pctBig, const std::string& pathBig)
{

}

void collage1(PICTURE pctLittle, PICTURE pctBig, const std::string& pathBig)
{

}

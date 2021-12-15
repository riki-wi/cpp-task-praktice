#include "bmpWork.h"

void collage24(const std::string& pathOne, const std::string& pathTwo)
{
    PICTURE pctOne = readBMP(pathOne);
    PICTURE pctTwo = readBMP(pathTwo);
    PICTURE *pctBig;
    PICTURE *pctLittle;
    std::string pathBig;

    if(pctOne.bMIH.biBitCount != 24 && pctTwo.bMIH.biBitCount)
    {
        std::cout << "изображения не подходят для этой функции";
        exit(-1);
    }

    if(pctOne.bMIH.biHeight < pctTwo.bMIH.biHeight && pctOne.bMIH.biWidth < pctTwo.bMIH.biWidth)
    {
        pctLittle = &pctOne;
        pctBig = &pctTwo;
        pathBig = pathTwo;
    }
    else if(pctOne.bMIH.biHeight > pctTwo.bMIH.biHeight && pctOne.bMIH.biWidth > pctTwo.bMIH.biWidth)
    {
        pctBig = &pctOne;
        pctLittle = &pctTwo;
        pathBig = pathOne;
    }
    else
    {
        std::cout << "Неверные размеры";
        exit(-1);
    }


    for(size_t i = 0; i < pctLittle->bMIH.biHeight; i++)
    {
        for(size_t j = 0; j < pctLittle->bMIH.biWidth * 3; j += 3)
        {
            PIXEL24 pixel = getPixel24(pctLittle->pixel, pctLittle->bMIH.biWidth, pctLittle->bMIH.biHeight, j, i);
            uint32_t height = pctBig->bMIH.biHeight - pctLittle->bMIH.biHeight + i;
            setPixel24(pctBig->pixel, pctBig->bMIH.biWidth, pctBig->bMIH.biHeight, j + 3 * height, height, pixel);
        }
    }
    writeBMP(*pctBig, pathBig);
}
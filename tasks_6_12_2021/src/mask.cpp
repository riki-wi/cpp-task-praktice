#include "bmpWork.h"

// пока только для картинко с bitcount = 24;
void mask(const std::string& pathIn, const std::string& pathOut, const double* mask, int dev, int sizeMask)
{
    PICTURE pct = readBMP(pathIn);

    if(pct.bMIH.biBitCount != 24)
    {
        std::cout << "Неверная битность картинки";
        exit(-1);
    }

    auto *output = new uint8_t[3 * pct.bMIH.biHeight * pct.bMIH.biWidth];
    for (int h = 0; h < pct.bMIH.biHeight; h++)
    {
        PIXEL24 pixel;
        for (int w = 0; w < pct.bMIH.biWidth; w++)
        {
            for (int my = 0; my < sizeMask; my++)
            {
                for (int mx = 0; mx < sizeMask; mx++)
                {
                    if ((h + my - 1) >= 0 && (h + my - 1) < pct.bMIH.biHeight && (w + mx - 1) >= 0 && (w + mx - 1) < pct.bMIH.biWidth)
                    {
                        pixel.read += (uint8_t)(pct.pixel[((h + my - 1) * pct.bMIH.biWidth + w + mx - 1) * 3] * mask[my * sizeMask + mx]);
                        pixel.green += (uint8_t)(pct.pixel[((h + my - 1) * pct.bMIH.biWidth + w + mx - 1) * 3 + 1] * mask[my * sizeMask + mx]);
                        pixel.blue += (uint8_t)(pct.pixel[((h + my - 1) * pct.bMIH.biWidth + w + mx - 1) * 3 + 2] * mask[my * sizeMask + mx]);

                    }
                }
            }
            if (dev)
            {
                pixel.read /= dev;
                pixel.blue /= dev;
                pixel.green /=dev;
                setPixel24(output, pct.bMIH.biWidth,pct.bMIH.biHeight, w, h, pixel);
            }
            else
            {
                setPixel24(output, pct.bMIH.biWidth,pct.bMIH.biHeight, w, h, pixel);
            }
        }
    }
    PICTURE out;
    out.bMIH = pct.bMIH;
    out.bMCT = pct.bMCT;
    out.bMFH = pct.bMFH;
    out.pixel = output;
    writeBMP(out, pathOut);
}
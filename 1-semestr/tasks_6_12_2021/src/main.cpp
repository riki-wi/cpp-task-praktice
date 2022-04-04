#include "bmpWork.h"

int main()
{
    //copy
    PICTURE pct1 = readBMP("../resources/copy/1.bmp");
    writeBMP(pct1, "../resources/copy/1out.bmp");

    PICTURE pct2 = readBMP("../resources/copy/2.bmp");
    writeBMP(pct2, "../resources/copy/2out.bmp");

    PICTURE pct3 = readBMP("../resources/copy/3.bmp");
    writeBMP(pct3, "../resources/copy/3out.bmp");

    PICTURE pct5 = readBMP("../resources/copy/5.bmp");
    writeBMP(pct5, "../resources/copy/5out.bmp");

    PICTURE pct6 = readBMP("../resources/copy/6.bmp");
    writeBMP(pct6, "../resources/copy/6out.bmp");

    PICTURE pct7 = readBMP("../resources/copy/7.bmp");
    writeBMP(pct7, "../resources/copy/7out.bmp");


    //swap
    swapRG("../resources/swap/exampleB1.bmp");
    swapRG("../resources/swap/exampleG1.bmp");
    swapRG("../resources/swap/exampleR1.bmp");

    //collage
    collage("../resources/collage/24/24_31x32.bmp", "../resources/collage/24/24_171x147.bmp");
    collage("../resources/collage/24/24_512x512.bmp", "../resources/collage/24/24_171x147.bmp");
    return 0;
}

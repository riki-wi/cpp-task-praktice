#include "bmpWork.h"

int main()
{

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

    std::cout << pct4.bMIH.biImageSize;

    /*
    PICTURE pct8 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct8, "../resources/copy/8out.bmp");

    PICTURE pct24 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct24, "../resources/copy/8out.bmp");

    swapRG("../resources/swap/exampleB1.bmp"); */

    //collage24("../resources/collage/24/24_31x32.bmp", "../resources/collage/24/land.bmp");
    //collage24("../resources/collage/24/24_256*256.bmp", "../resources/collage/24/land.bmp");

    return 0;
}

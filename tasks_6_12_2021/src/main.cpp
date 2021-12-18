#include "bmpWork.h"

int main()
{
    /*
    PICTURE pct1 = readBMP("../resources/copy/1in.bmp");
    writeBMP(pct1, "../resources/copy/1out.bmp");

    PICTURE pct8 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct8, "../resources/copy/8out.bmp");

    PICTURE pct24 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct24, "../resources/copy/8out.bmp");

    swapRG("../resources/swap/exampleB1.bmp"); */

    collage24("../resources/collage/24/24_31x32.bmp", "../resources/collage/24/land.bmp");
    collage24("../resources/collage/24/24_256*256.bmp", "../resources/collage/24/land.bmp");

    return 0;
}

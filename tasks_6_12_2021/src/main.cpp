#include "bmpWork.h"

int main()
{

    PICTURE pct1 = readBMP("../resources/copy/1in.bmp");
    writeBMP(pct1, "../resources/copy/1out.bmp");

    PICTURE pct8 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct8, "../resources/copy/8out.bmp");

    PICTURE pct24 = readBMP("../resources/copy/8in.bmp");
    writeBMP(pct24, "../resources/copy/8out.bmp");

    swapRG("../resources/swap/exampleB1.bmp");

    return 0;
}

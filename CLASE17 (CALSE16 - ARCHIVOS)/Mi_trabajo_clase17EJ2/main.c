#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

int main()
{
    sPixel *pPixel;
    sPixel *pAuxiliarPixel;
    sPixel *auxiliarPixel;

    pPixel = pixel_new();


    if(pixel_setRGB (pPixel, 10 , 255, 255, 255) == -1)
    {
        printf("ERROR");
    }

    pAuxiliarPixel = pixel_getRGB (pPixel, 10);




    printf("Hello world!\n");
    return 0;
}




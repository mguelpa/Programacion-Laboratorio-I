#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

//static sPixel pixeles[1024]; ----> no existe se utiliza memoria dinamica



sPixel* pixel_new (int size)
{
    sPixel arrayPixel = NULL;



    return pixeles;
}

int pixel_setRGB (sPixel* nombre_array, int index, int r, int g, int b)
{
    int retorno = -1;
    if(nombre_array != NULL && index >= 0)
    {
        (nombre_array+index)->r = r;
        (nombre_array+index)->g = g;
        (nombre_array+index)->b = b;
        retorno = 0;
    }
    return retorno;
}

sPixel* pixel_getRGB (sPixel* nombre_array, int index)
{
    return nombre_array+index;
}

sPixel pixel_getPixel (sPixel* nombre_array, int index)
{
    return *(pixeles+index);
}


#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

ArrayList* al_new(void)
{
    ArrayList* pArray;
    pArray = malloc(sizeof(ArrayList));
    pArray->rSize = INIT_SIZE;
    pArray->size = 0;
    pArray->pElements = malloc(sizeof(void*) * pArray->rSize);
    return pArray;
}

int al_add(ArrayList* pArray,void *element)
{
    int retorno = -1;
    if(pArray->size < pArray->rSize)
    {
        *(pArray->pElements+pArray->size) = element;
        pArray->size++;
        retorno = 0;
    }
    return retorno;
}

void al_debugShow(ArrayList* pArray)
{
    int i;
    for(i=0; i < pArray->size; i++)
    {
        printf("\n%p numero %d de %d",*(pArray->pElements+i) ,i,pArray->size);
    }
}

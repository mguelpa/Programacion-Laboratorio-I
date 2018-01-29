#include "ArrayList.h"

#ifndef AFFILIATE_H_INCLUDED
#define AFFILIATE_H_INCLUDED

    #define MAX_CHARS_NOMBRES 20
    #define MAX_CHARS_DNI 20

    #define SLT_EMPTY 0
    #define SLT_LOAD  1
    #define SLT_DOWN -1

    typedef struct
    {
        unsigned int id;
        int status;

        char nombre[MAX_CHARS_NOMBRES];
        char apellido[MAX_CHARS_NOMBRES];
        char dni[MAX_CHARS_DNI];
        int  edad;

    } sAsociado;

#endif // AFFILIATE_H_INCLUDED

sAsociado* affi_newElement (void);
sAsociado* affi_getElementById (ArrayList* list, unsigned int id);
int affi_searchIndexById (sAsociado* list, int length, int id);
int affi_resetData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4);
int affi_setData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4);

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

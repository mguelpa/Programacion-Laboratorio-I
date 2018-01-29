#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED

#define STATUS_EMPTY  0
#define STATUS_LOADED 1
#define STATUS_DOWN  -1

typedef struct
{
    unsigned int id;
    int flagEstado;

    unsigned int idEntidad1;
    char valueA[50];
    int  valueB;
}sEntidad2;

#endif // ENTIDAD2_H_INCLUDED


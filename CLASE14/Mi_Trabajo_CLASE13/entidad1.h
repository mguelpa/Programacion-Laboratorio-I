#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED

#define STATUS_EMPTY  0
#define STATUS_LOADED 1
#define STATUS_DOWN  -1

typedef struct
{
    unsigned int id;
    int flagEstado;

    char valueA[50];
    int  valueB;
}sEntidad1;


int ent1_init (sEntidad1* nombre_array, int len);
int ent1_alta (sEntidad1* nombre_array, int len)
int ent1_modificar()
int ent1_alta (sEntidad1* nombre_array, int len);
#endif // ENTIDAD1_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 50

typedef struct
{
    char nombre[MAX_CHAR];
    char apellido[MAX_CHAR];
    char dni[MAX_CHAR];
    int edad;
}sAlumno;


int main()
{
    sAlumno maxi;
    sAlumno copia;

    strncpy(maxi.nombre, "Maximiliano", MAX_CHAR);
    maxi.nombre[MAX_CHAR] = 0;

    strncpy(maxi.apellido, "Guelpa", MAX_CHAR);
    strncpy(maxi.dni, "35.340.965", MAX_CHAR);
    maxi.edad = 27;

    printf("%s\n", maxi.nombre);
    printf("%s\n", maxi.apellido);
    printf("%s\n", maxi.dni);
    printf("%d\n", maxi.edad);

    copia = maxi;

    printf("%s\n", copia.nombre);
    printf("%s\n", copia.apellido);
    printf("%s\n", copia.dni);
    printf("%d\n", copia.edad);

    return 0;
}
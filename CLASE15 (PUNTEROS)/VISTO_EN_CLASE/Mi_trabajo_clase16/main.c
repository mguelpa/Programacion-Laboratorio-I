#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nombre[20];
    char apellido[20];
    int edad;
}sPersona;

int cargarPersona (sPersona* nombre_persona);
int printPersona (sPersona* nombre_persona);


int main()
{
    sPersona maxi;

    cargarPersona(&maxi);
    printPersona(&maxi);

    printf("\nHello world!\n");
    return 0;
}

int cargarPersona (sPersona* nombre_persona)
{
    char auxNombre[20];
    char auxApellido[20];
    int auxEdad;

    printf("ingrese el nombre: ");
    fgets(auxNombre, 20, stdin);

    printf("ingrese el apellido: ");
    fgets(auxApellido, 20, stdin);

    printf("ingrese la edad: ");
    scanf("%d", &auxEdad);

    strncpy(nombre_persona->nombre, auxNombre, 20);
    strncpy(nombre_persona->apellido, auxApellido, 20);
    nombre_persona->edad = auxEdad;

    return 0;
}

int printPersona (sPersona* nombre_persona)
{
    printf("%s", nombre_persona->nombre);
    printf("%s", nombre_persona->apellido);
    printf("%d", nombre_persona->edad);

    return 0;
}

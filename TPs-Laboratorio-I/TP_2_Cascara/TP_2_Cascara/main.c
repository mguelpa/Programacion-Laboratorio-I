#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validar.h"


int main()
{
	sPersona alumnos[MAX_ALUMNOS];

    char seguir = 's';
    char opcion[5] = {"5"};

    pers_initArray(alumnos, MAX_ALUMNOS);

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        val_getUnsignedInt(opcion, 5,"", "Ha ingresado una opcion no valida.\n Ingrese una opcion del 1 al 4, o 5 para salir: ", 3);

        switch(atoi(opcion))
        {
            case 1:
                system("cls");
                pers_logPerson(alumnos, MAX_ALUMNOS, "--> Supero el limite de carga de datos! <--\n\n\a");
                break;
            case 2:
                system("cls");
                pers_deletePerson(alumnos, "El docuemnto ingresado no existe en el listado");
                break;
            case 3:
                system("cls");
                pers_printList(alumnos, MAX_ALUMNOS);
                break;
            case 4:
                system("cls");
                pers_chartArray(alumnos, MAX_ALUMNOS);
                printf("\n\n");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

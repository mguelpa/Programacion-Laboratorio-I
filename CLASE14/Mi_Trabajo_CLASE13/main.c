#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"

#define LEN_ENTIDADES1 50
#define LEN_ENTIDADES2 50

int main()
{
    sEntidad1 listaEntidades1[LEN_ENTIDADES1];
    sEntidad1 listaEntidades2[LEN_ENTIDADES2];

    ent1_init(listaEntidades1, LEN_ENTIDADES1);
    ent2_init(listaEntidades2, LEN_ENTIDADES2);

    while(1)
    {
        system("cls");

        printf("1- ALTA ASOCIADO\n");
        printf("2- MODIFICAR DATOS ASOCIADO\n");
        printf("3- BAJA DE ASCIADO\n");
        printf("4- REGISTRAR LLAMADA\n");
        printf("5- FINALIZAR LLAMADA\n");
        printf("6- INFORME\n");
        printf("7- LISTAR LLAMADAS\n");
        printf("8- LISTAR ASOCIADOS\n");

        printf("9- Salir\n");

        char opcion[50];
        if(val_getUnsignedInt(opcion, "Elija:", "", 3, 50) == 0)
        {
            int op = atoi(opcion);
            switch(op)
            {
                case 1:
                    break;

            }
        }
    }
    printf("Hello world!\n");
    return 0;
}

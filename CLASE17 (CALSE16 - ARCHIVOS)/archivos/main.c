#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    char apellido[50];
}sSocio;

int main()
{
    FILE *pArchivo;

    sSocio persona;
    int cantidad;

    printf("ingrese el nombre: ");
    fflush(stdin);
    fgets(persona.nombre, 50, stdin);

    printf("ingrese el apellido: ");
    fflush(stdin);
    fgets(persona.apellido, 50, stdin);

//    if( ( pArchivo = fopen("data.bin","rb") ) == NULL)
//    {
//        if( ( pArchivo = fopen("data.bin","wb") ) == NULL)
//        {
//            printf("\nEl archivo no puede ser abierto");
//            exit (1);
//        }
//    }



    //Se abre en modo escritura
    if( ( pArchivo = fopen("data.txt","w") ) == NULL)
    {
        printf("\nEl archivo no puede ser abierto");
        exit (1);
    }


    //Se escribe al archivo
    cantidad = fwrite ( &persona, sizeof ( persona ), 1, pArchivo );

    printf("\nSe escribieron %d caracteres", cantidad);
    fclose(pArchivo);

    return 0;
}

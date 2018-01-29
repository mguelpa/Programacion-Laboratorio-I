#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[20];
    char descripcion[64];
    float precio;
    int estaCargado;
}Producto;

int validarPrecio(char bPrecio[])
{
    int retorno = 0,i;
    while(bPrecio[i] != 10)
    {
        ...

        i++;
    }


    return retorno;
}

int inicializarArray(Producto a[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        a[i].estaCargado = 0;
    }
    return 0;
}
int cargarDato(Producto a[],int indice)
{
    //NOOOOOOO ---> fgets(a[indice].nombre,20,stdin);
    char bNombre[20],bDesc[50],bPrecio[20];
    print("Precio: ");validarPrecio(bPrecio)
    fgets(bPrecio,20,stdin);
    bPrecio[19] = 0;
    bPrecio[18] = 10; // LF

    if(validarPrecio(bPrecio) == 0)
    {
        a[indice].precio = atof(bPrecio);
    }



    return 0;
}
int main()
{
    Producto productos[200];

    inicializarArray(productos,200);

    cargarDato(productos,55);


    printf("Hello world!\n");
    return 0;
}

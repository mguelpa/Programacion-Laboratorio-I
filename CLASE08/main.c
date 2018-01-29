#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LAPTOPS 3

typedef struct
{
    int id;
    int isEmpty;
    char nombre[20];
    char descripcion[50];
    float precio;

}sProducto;

int menuOpciones(sProducto* producto);
int indiceVacio(sProducto* producto, int len);
int imprimirDatos(sProducto* producto, int indice);
int cargarDatos(sProducto* producto, int indice);
int resetArray(sProducto a[],int len);
int esFloat(char* str);

int main()
{
    int indice;
    sProducto laptops[MAX_LAPTOPS];

    resetArray(laptops, MAX_LAPTOPS);
    menuOpciones(laptops);


    return 0;
}



//////////////////////////////////////////
int resetArray(sProducto* a,int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        a[i].isEmpty = 0;
        strcpy(a[i].nombre, "0");
        strcpy(a[i].descripcion, "0");
        a[i].precio = 0;
    }
    return 0;
}
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
int cargarDatos(sProducto* producto, int indice)
{
    char auxValidar[20];



    printf("Ingrese el nombre del producto: ");
    fflush(stdin);
    fgets(producto[indice].nombre, 20, stdin);

    printf("Ingrese la descripcion del producto: ");
    fflush(stdin);
    fgets(producto[indice].descripcion, 20, stdin);

    printf("Ingrese el precio del producto: ");
    fflush(stdin);
    gets(auxValidar);
    if(esFloat(auxValidar) == 0)
    {
        producto[indice].precio = atof(auxValidar);
    }
    else
    {
        printf("no se cargo dato");
    }
    producto[indice].isEmpty = 1;
    return 0;
}
////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////
int imprimirDatos(sProducto* producto, int indice)
{
        printf("%s\n", producto[indice].nombre);
        printf("%s\n", producto[indice].descripcion);
        printf("%f\n", producto[indice].precio);

        return 0;
}
/////////////////////////////////////////////////////




////////////////////////////////////////////////////
int indiceVacio(sProducto* producto, int len)
{
    int i;
    int indiceVacio;

    for(i=0; i<len; i++)
    {
        if(producto[i].isEmpty == 0)
        {
            indiceVacio = i;
        }
    }
    return indiceVacio;
}
////////////////////////////////////////////////////

int menuOpciones(sProducto* producto)
{
    int i;
    int indice;
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        printf("1- Cargar un producto\n");
        printf("2- Imprimir lista productos\n");

        printf("3- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indice = indiceVacio(producto, MAX_LAPTOPS);
                cargarDatos(producto, indice);
                break;
            case 2:
                for(i=0; i<MAX_LAPTOPS; i++)
                {
                    imprimirDatos(producto, i);
                }
                break;
            case 3:
                seguir = 'n';
                break;
            default:
                seguir = 's';
                break;
        }
    }
    return 0;
}
////////////////////////////////////////////

//////////////////////////////////////////
int generarID(sProducto* a, int indice)
{
    for(i=0; i<len; i++)
    {
        for()
    }
    if(a[indice].id == i)

}
















/////////////////////////////////////////////////////////////////////////////
int esFloat(char* str)
{
    int i = 0;
    int contadorGuiones = 0, contadorPuntos = 0;
    int retorno;

    while(str[i] != '\0')
    {
        if((str[i] != '-') && (str[i] != '.') && (str[i] < '0' || str[i] > '9'))
            return -1;
        if(str[i] == '-')
            contadorGuiones++;
        else if(str[i] == '.')
            contadorPuntos++;
        i++;
    }
    if(contadorGuiones >= 2 || contadorPuntos >= 2)
        retorno = -2;
    else
    {
        if(atof(str) == 0)
        {
            retorno = -3;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////

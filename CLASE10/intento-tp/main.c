#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_BUFFER 4096 //----> revisar en codigo clase09.4

#define MAX_CHARS_ID 3
#define MAX_CHARS_NOMBRE 21
#define MAX_CHARS_PRECIO 11
#define MAX_CHARS_DESCRIPCION 51

#define MAX_PRODUCTOS 10

#define LOADED 1
#define EMPTY 0
#define DOWN -1


typedef struct
{
    unsigned int id;
    int estado;

    char nombre[MAX_CHARS_NOMBRE];
    char descripcion[MAX_CHARS_DESCRIPCION];
    float precio;
} sProducto;


int prod_initArray(sProducto* arrayProductos, int length);
int prod_loadProduct (sProducto* arrayProductos, int length);
int prod_editProduct (sProducto* arrayProductos);
int prod_deleteProduct (sProducto* arrayProductos);
int prod_printList (sProducto* arrayProductos, int length);

int prod_loadData (sProducto* arrayProductos, int index);
int prod_modifyData (sProducto* arrayProductos, int index);
void prod_deleteData (sProducto* arrayroductos, int index);
void pord_printData(sProducto* arrayProductos, int index);

int prod_generateId(sProducto* arrayProductos, int length);
int prod_getIndexById (sProducto* arrayProductos, int id, int length);
int prod_searchEmptySlot(sProducto* arrayProductos);


void myFgets(char* buffer, int length, FILE* archivo);

int val_getName(char* destino, char* solicitud, char* mensajeError, int intentos, int limite);
int val_getPrice(char* destino, char* solicitud, char* mensajeError, int intentos, int limite);
int val_getUnsignedInt (char* destino, char* solicitud, char* mensajeError, int intentos, int length);

int val_validateName(char* strNombre);
int val_validatePrice(char* strPrice);
int val_validateUnsignedInt (char* strUnsignedInt);

int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);



int main()
{
    sProducto laptops[MAX_PRODUCTOS];
    char respuesta = 's';
    int valor;
    int i;

    prod_initArray(laptops, MAX_PRODUCTOS);

    do
    {
        printf("MENU PRINCIPAL:\n");
        printf("1. Cargar datos \n");
        printf("2. Imprimir datos \n");
        printf("3. Modificar datos \n");
        printf("4. Borrar producto \n");
        printf("9. Salir \n");

        scanf("%d", &valor);
        system("cls");

        switch(valor)
        {
        case 1:
            prod_loadProduct(laptops, MAX_PRODUCTOS);
            system("cls");
            break;
        case 2:
            prod_printList(laptops, MAX_PRODUCTOS);
            break;
        case 3:
            prod_editProduct(laptops);
            break;
        case 4:
            prod_deleteProduct(laptops);
            break;
        case 5:
            for(i=0; i<MAX_PRODUCTOS; i++)
            {
                printf("id: %d\n", laptops[i].id);
                printf("estado: %d\n", laptops[i].estado);
            }
            break;
        case 9:
            respuesta = 'n';
            break;
        default:
            respuesta = 'n';
            break;
        }

    }
    while(respuesta != 'n');

    printf("hello world!\n");

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////
int prod_initArray(sProducto* arrayProductos, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        arrayProductos[i].estado = EMPTY;
        arrayProductos[i].id = EMPTY;
        arrayProductos[i].precio = EMPTY;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_loadProduct (sProducto* arrayProductos, int length)
{
    int retorno = -1;
    char respuesta = 'n';
    int index;
    int i = 0;

    do
    {
        index = prod_searchEmptySlot(arrayProductos);

        if(prod_loadData(arrayProductos, index) == 0)
        {
            printf("carga exitosa.\n");
        }
        else
        {
            printf("error al cargar los datos.\n");
            retorno = -1;
            break;
        }
        continuar("desea continuar? S/N: ", "Ha ingresado una opcion no valida. intente nuevamente: ", 3, &respuesta);
        i++;
    }
    while(respuesta != 'n' && i < length);

    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_editProduct (sProducto* arrayProductos)
{
    int retorno = -1;

    char bID[MAX_CHARS_ID];
    int id;
    int index;

    if(val_getUnsignedInt(bID, "ingrese el ID del product a modificar: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_ID) == 0)
    {
        id = atoi(bID);
        index = prod_getIndexById(arrayProductos, id, MAX_PRODUCTOS);

        if(prod_modifyData(arrayProductos, index) == 0)
        {
            retorno = 0;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_deleteProduct (sProducto* arrayProductos)
{
    int retorno = -1;

    char bID[MAX_CHARS_ID];
    int id;
    int index;

    if(val_getUnsignedInt(bID, "ingrese el ID del product a borrar: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_ID) == 0)
    {
        id = atoi(bID);
        index = prod_getIndexById(arrayProductos, id, MAX_PRODUCTOS);

        prod_deleteData(arrayProductos, index);
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_printList (sProducto* arrayProductos, int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        if(arrayProductos[i].estado == LOADED)
        {
            pord_printData(arrayProductos, i);
        }
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
int prod_loadData (sProducto* arrayProductos, int index)
{
    int retorno = -1;
    char bNombre[MAX_CHARS_NOMBRE];
    char bPrecio[MAX_CHARS_PRECIO];
    int idGenerado;

    //char bDescripcion[MAX_CHARS_DESCRIPCION];

    idGenerado = prod_generateId(arrayProductos, MAX_PRODUCTOS);

    if(val_getName(bNombre, "ingrese el nombre del producto: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_NOMBRE) == 0)
    {
        if(val_getPrice(bPrecio, "ingrese el precio del producto: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_PRECIO) == 0)
        {
            strncpy(arrayProductos[index].nombre, bNombre, MAX_CHARS_DESCRIPCION);
            arrayProductos[index].precio = atof(bPrecio);
            arrayProductos[index].estado = LOADED;
            arrayProductos[index].id = idGenerado;

            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_modifyData (sProducto* arrayProductos, int index)
{
    int retorno = -1;

    char bNombre[MAX_CHARS_NOMBRE];
    char bPrecio[MAX_CHARS_PRECIO];

    if(val_getName(bNombre, "ingrese el nombre del producto: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_NOMBRE) == 0)
    {
        if(val_getPrice(bPrecio, "ingrese el precio del producto: ", "Ha ingresado caracteres no admitidos\n", 3, MAX_CHARS_PRECIO) == 0)
        {
            strncpy(arrayProductos[index].nombre, bNombre, MAX_CHARS_DESCRIPCION);
            arrayProductos[index].precio = atof(bPrecio);
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void prod_deleteData (sProducto* arrayProductos, int index)
{
    arrayProductos[index].estado = DOWN;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void pord_printData(sProducto* arrayProductos, int index)
{

    printf("---------------------------------------------\n");

    printf("Nombre producto: %s\n", arrayProductos[index].nombre);
    printf("Precio producto: %.2f\n", arrayProductos[index].precio);
    printf("ID     producto: %d\n", arrayProductos[index].id);
    printf("Estado producto: %d\n\n", arrayProductos[index].estado);

    printf("---------------------------------------------\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
int prod_generateId(sProducto* arrayProductos, int length)
{
    int i;
    int id = 0;

    for(i=0; i<length; i++)
    {
        if(arrayProductos[i].estado == LOADED && arrayProductos[i].id > id)
        {
            id = arrayProductos[i].id;
        }
    }
    return id +1;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_getIndexById (sProducto* arrayProductos, int id, int length)
{
    int i;
    int index;

    for(i=0; i<length; i++)
    {
        if(arrayProductos[i].id == id)
        {
            index = i;
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int prod_searchEmptySlot(sProducto* arrayProductos)
{
    int retorno = -1;
    int i;

    for(i=0; i<MAX_PRODUCTOS; i++)
    {
        if(arrayProductos[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////


// ////////////////////////////////////////////////////////////////////////////////////////////////
// int searchLoadedSlots(sProducto* a)
// {
//     int retorno = -1;
//     int i;

//     for(i=0; i<MAX_PRODUCTOS; i++)
//     {
//         if(a[i].estado == LOADED)
//         {
//             retorno = i;
//             break;
//         }
//     }
//     return retorno;
// }
// ////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
void myFgets(char* buffer, int length, FILE* archivo)
{
    int i=0;

    fgets(buffer, length, archivo);

    buffer[length-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
int val_getName(char* destino, char* solicitud, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_CHARS_NOMBRE];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(solicitud);

        while(intentos > 0)
        {
            fflush(stdin);
            myFgets(buffer, limite, stdin);

            if(val_validateName(buffer) == -1)
            {
                printf(mensajeError);
            }
            else
            {
                strncpy(destino, buffer, limite);
                retorno = 0;
                break;
            }
            intentos --;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_getPrice(char* destino, char* solicitud, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_CHARS_PRECIO];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(solicitud);

        while(intentos > 0)
        {
            myFgets(buffer, limite, stdin);

            if(val_validatePrice(buffer) == -1)
            {
                printf(mensajeError);
            }
            else
            {
                strncpy(destino, buffer, limite);
                retorno = 0;
                break;
            }
            intentos --;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_getUnsignedInt (char* destino, char* solicitud, char* mensajeError, int intentos, int length)
{
    int retorno = -1;
    char buffer[length];

    printf(solicitud);

    while(intentos > 0)
    {
        fflush(stdin);
        myFgets(buffer, length, stdin);

        if(val_validateUnsignedInt(buffer) == -1)
        {
            printf(mensajeError);
            //continue; ----> ver que pasa con esto!!
        }
        else
        {
            strncpy(destino, buffer, length);
            retorno = 0;
            break;
        }
        intentos --;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
int val_validateName(char* strNombre)
{
    int retorno = 0;
    int i = 0;

    while(strNombre[i] != '\0')
    {
        if(strNombre[i] < 'a' || strNombre[i] > 'z')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_validatePrice(char* strPrice)
{
    int retorno = 0;
    int i = 0;
    int dot = 0;

    while(strPrice[i] != '\0')
    {
        if((strPrice[i] < '0' || strPrice[i] > '9') && strPrice[i] != '.' && strPrice[i] != '-')
        {
            retorno = -1;
            break;
        }
        else
        {
            if(strPrice[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(strPrice[i] == '.')
            {
                dot++;
                if(dot > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_validateUnsignedInt (char* strUnsignedInt)
{
    int retorno = 0;
    int i = 0;

    while(strUnsignedInt[i] != '\0')
    {
        if(strUnsignedInt[i] < '0' || strUnsignedInt[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer)
{
    char aux;
    printf(solicitud);
    fflush(stdin);
    aux = tolower(getchar());
    while(!(aux == 's' || aux == 'n'))
    {
        printf(msjIntentos);
        fflush(stdin);
        aux = tolower(getchar());
        intentos--;
        if(intentos < 1)
        {
            *buffer = 'n';
            return -1;
        }
    }
    *buffer = aux;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////



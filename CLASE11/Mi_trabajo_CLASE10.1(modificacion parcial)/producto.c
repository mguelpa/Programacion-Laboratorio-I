#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "producto.h"
#include "validar.h"

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

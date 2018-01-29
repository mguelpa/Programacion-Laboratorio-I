#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "producto.h"
#include "validar.h"

static int prod_obtenerID (sProducto* arrayProducto, int longitud);

static int prod_buscarIndiceId (sProducto* arrayProducto, int longitud, int id);











int prod_cargarProducto (sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51) == 0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51) == 0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre,bNombre,51);
                arrayProducto[index].precio = atof(bPrecio);
                arrayProducto[index].estado = PRODUCTO_OCUPADO;
                arrayProducto[index].id = prod_obtenerID(arrayProducto, 200);
                retorno = 0;
            }
        }
    }
    return retorno;
}











int prod_initProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProducto[i].estado = PRODUCTO_LIBRE;
        }
    }
    return retorno;
}










int prod_printProducto (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                printf(" - ID: %d\n - Nombre: %s\n - Precio: %.2f\n",i,arrayProducto[i].nombre,arrayProducto[i].precio);
            }
        }

    }
    return retorno;
}










int prod_buscarProductoLibre (sProducto* arrayProducto, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 4)  Agregar al tipo de dato el campo ID que represente
 *     un identificador unico. Modificar el codigo anterior
 *     para que el ID se genere automaticamente. Se debera
 *     cargar el ID automaticamente al cargar un producto,
 *     y se debera imprimir al imprimir la lista.
 */

static int prod_obtenerID (sProducto* arrayProducto, int longitud)
{
    int i;
    int index = -1;

    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(index < arrayProducto[i].id)
                    index = arrayProducto[i].id;
            }
        }

    }
    return index +1;
}







static int prod_buscarIndiceId (sProducto* arrayProducto, int longitud, int id)
{
    int retorno = -1;
    int i;
    if(arrayProducto != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProducto[i].estado == PRODUCTO_OCUPADO)
            {
                if(id == arrayProducto[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }

    }
    return retorno;
}



/**
 * 6) Realizar una funcion que reciba el array, un indice, y le permita al
 *    usuario modificar los campos nombre y precio del item del array en la
 *    posicion especificada por el indice.
 *
 */
int prod_modificarCampos (sProducto* arrayProducto, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProducto != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51) == 0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51) == 0)
            {
                //printf("Float ok");
                strncpy(arrayProducto[index].nombre, bNombre, 51);
                arrayProducto[index].precio = atof(bPrecio);
                retorno = 0;
            }
        }
    }
    return retorno;
}

/**
 * 7) Agregar una opcion en el menu. "Editar producto"
 *    que pida al usuario el ID del mismo y le permita
 *    cambiar el nombre y el precio.
 *
 */

int prod_editarProducto (sProducto* arrayProducto)
{
    int id;
    int indice;
    int retorno = -1;
    char bufferId[51];

    if(val_getUnsignedInt(bufferId, "ingrese el ID del producto: \n", "Error. Reintente", 3, 100) == 0)
    {
        id = atoi(bufferId);
        printf("id: %d\n", id);
        indice = prod_buscarIndiceId(arrayProducto, 200, id);
        printf("indice: %d\n", indice);
        if(prod_modificarCampos(arrayProducto, indice) == 0)
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


int prod_brrarProducto (sProducto* arrayProducto)
{
    int id;
    int indice;
    int retorno = -1;
    char buffer[51];

    if(val_getUnsignedInt(buffer, "ingrese el ID del producto: \n", "Error. Reintente", 3, 100) == 00000)
    {
        id = atoi(buffer);
        printf("id: %d\n", id);
        indice = prod_buscarIndiceId(arrayProducto, 200, id);
        printf("indice: %d\n", indice);
        arrayProducto[indice].estado = PRODUCTO_LIBRE; //-->borrar PRODUCTO_LIBRE = 0
    }
    return retorno;
}

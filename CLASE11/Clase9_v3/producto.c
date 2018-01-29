#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "validar.h"

// Funciones privadas
static int buscarProximoId (Producto* arrayProductos, int longitud);
static int buscarIndiceId (Producto* arrayProductos, int longitud, int id);
static int modificarProductoPorIndice(Producto* arrayProductos, int index);
//___________________


int prod_editarProducto(Producto* arrayProductos,int len)
{
    char idStr[32];
    int id;
    int index;
    if(val_getUnsignedInt(idStr, "Ingrese ID a modificar:","INCORRECTO",2,32))
    {
        id = atoi(idStr);
        index = buscarIndiceId(arrayProductos,len,id);
        if(index>=0)
        {
           return modificarProductoPorIndice(arrayProductos,index);
        }
    }
    return -1;
}


static int modificarProductoPorIndice (Producto* arrayProductos, int index)
{
    int retorno = -1;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProductos != NULL && index >= 0)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {

            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                strncpy(arrayProductos[index].nombre,bNombre,51);
                arrayProductos[index].precio = atof(bPrecio);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int prod_cargarProducto (Producto* arrayProductos, int index, int len)
{
    int retorno = -1;
    int id;
    char bNombre[51];
    char bPrecio[51];

    if(arrayProductos != NULL && index >= 0 && index < len)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?","\nError:\n",3,51)==0)
        {
            //printf("NOMBRE ok");
            if(val_getFloat(bPrecio,"\nPrecio?","\nError:\n",3,51)==0)
            {
                //printf("Float ok");
                id = buscarProximoId(arrayProductos,len);
                if(id != -1)
                {
                    strncpy(arrayProductos[index].nombre,bNombre,51);
                    arrayProductos[index].precio = atof(bPrecio);
                    arrayProductos[index].estado = PRODUCTO_OCUPADO;
                    arrayProductos[index].id = id;
                    retorno = 0;
                }
            }
        }

    }
    return retorno;
}

int prod_initProducto (Producto* arrayProductos, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            arrayProductos[i].estado = PRODUCTO_LIBRE;
        }

    }
    return retorno;
}

int prod_printProducto (Producto* arrayProductos, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProductos[i].estado == PRODUCTO_OCUPADO)
            {
                printf("ID: %d - Nombre:%s - Precio: %.2f\n",arrayProductos[i].id,arrayProductos[i].nombre,arrayProductos[i].precio);
            }
        }

    }
    return retorno;
}


int prod_buscarIndiceProductoLibre (Producto* arrayProductos, int longitud)
{
    int retorno = -1;
    int i;
    if(arrayProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProductos[i].estado == PRODUCTO_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;
}


static int buscarProximoId (Producto* arrayProductos, int longitud)
{
    int i;
    int idMax = -1;
    if(arrayProductos != NULL && longitud > 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProductos[i].estado == PRODUCTO_OCUPADO)
            {
                if(idMax < arrayProductos[i].id)
                    idMax = arrayProductos[i].id;
            }
        }

    }
    return idMax + 1;
}


static int buscarIndiceId (Producto* arrayProductos, int longitud, int id)
{
    int i;
    int retorno = -1;
    if(arrayProductos != NULL && longitud > 0 && id >= 0)
    {
        for(i=0; i<longitud ; i++)
        {
            if(arrayProductos[i].estado == PRODUCTO_OCUPADO)
            {
                if(id == arrayProductos[i].id)
                {
                    retorno = i;
                    break;
                }

            }
        }

    }
    return retorno;
}


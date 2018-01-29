#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#include "validar.h"


int main()
{
    sProducto arrayProductos[200];

    char bufferInt[40];

    prod_initProducto(arrayProductos,200);
    do
    {
        val_getUnsignedInt(bufferInt,"MENU OPCIONES:\n\n1. Alta Producto.\n2. Listar Productos.\n3. Modificar producto.\n8. Salir.\n", "\nSolo 1 y 2\n", 2, 40);
        switch(atoi(bufferInt))
        {
            case 1:
                prod_cargarProducto (arrayProductos, prod_buscarProductoLibre(arrayProductos,200));
                break;

            case 2:
                prod_printProducto(arrayProductos,200);
                break;

            case 3:
                prod_editarProducto(arrayProductos);
                break;
        }
    }while(atoi(bufferInt) != 8);

    return 0;
}

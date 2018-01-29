#include <stdio.h>
#include <stdlib.h>
#include "producto.h"

int main()
{
    sProducto arrayProductos[200];
    prod_initProducto(arrayProductos,200);
    prod_menuOpciones(arrayProductos);
    prod_cargarProducto (arrayProductos, 44);
    prod_cargarProducto (arrayProductos, 18);
    prod_printProducto(arrayProductos,200);
    prod_itemVacio(arrayProductos, 200);



    return 0;
}

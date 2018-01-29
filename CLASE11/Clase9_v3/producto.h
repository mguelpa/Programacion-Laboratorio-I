#ifndef _PRODUCTO
#define _PRODUCTO
typedef struct{
    char nombre[51];
    char desc[51];
    float precio;
    int id;
    unsigned char estado;
}Producto;
#endif // _PRODUCTO

#define PRODUCTO_LIBRE 0
#define PRODUCTO_OCUPADO 1

int prod_modificarProducto (Producto* arrayProductos, int len);
int prod_cargarProducto (Producto* arrayProductos, int index, int len);
int prod_printProducto (Producto* arrayProductos, int longitud);
int prod_initProducto (Producto* arrayProductos, int longitud);
int prod_buscarIndiceProductoLibre (Producto* arrayProductos, int longitud);
int prod_editarProducto(Producto* arrayProductos,int len);

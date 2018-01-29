#ifndef _PRODUCTO
#define _PRODUCTO

#define MAX_PRODUCTOS 10

#define MAX_CHARS_ID 3
#define MAX_CHARS_NOMBRE 21
#define MAX_CHARS_PRECIO 11
#define MAX_CHARS_DESCRIPCION 51

typedef struct
{
    unsigned int id;
    int estado;

    char nombre[MAX_CHARS_NOMBRE];
    char descripcion[MAX_CHARS_DESCRIPCION];
    float precio;
} sProducto;

#endif // _PRODUCTO

//#define MAX_PRODUCTOS 10

//#define MAX_CHARS_ID 3
//#define MAX_CHARS_NOMBRE 21
//#define MAX_CHARS_PRECIO 11
//#define MAX_CHARS_DESCRIPCION 51

#define LOADED 1
#define EMPTY 0
#define DOWN -1

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


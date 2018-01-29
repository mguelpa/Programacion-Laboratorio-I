#include <stdio.h>
#include <stdlib.h>

#include "Producto.h"
#include "validar.h"

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

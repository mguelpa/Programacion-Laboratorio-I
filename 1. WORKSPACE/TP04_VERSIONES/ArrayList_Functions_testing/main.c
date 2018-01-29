#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "affiliate.h"
#include "controller.h"
#include "inputs.h"

int main()
{
    int  opcion, i;
    char menu[15][100] = {
    "*********************************************************************************************",
    "*| ArrayList: Function Testing                                                             |*",
    "*|-----------------------------------------------------------------------------------------|*",
    "*|  ABM                        |  TEST 1.                    |  TEST 2.                    |*",
    "*|-----------------------------|-----------------------------|-----------------------------|*",
    "*|  1. Nuevo Socio.            |  5.  al_debugShow.          |  13. al_clear.              |*",
    "*|                             |  6.  al_clone.              |  14. al_indexOf.            |*",
    "*|  2. Modificacion            |  7.  al_subList.            |  15. al_get.                |*",
    "*|     Datos Socio.            |  8.  al_deleteArrayList.    |  16. al_pop.                |*",
    "*|                             |  9.  al_add.                |  17. al_isEmpty.            |*",
    "*|  3. Baja de Socio.          |  10. al_push.               |  18. al_contains.           |*",
    "*|                             |  11. al_set.                |  19. al_containsAll.        |*",
    "*|  4. HardCode Socio.         |  12. al_remove.             |  20. al_len.                |*",
    "*|_____________________________|_____________________________|_____________________________|*",
    "*********************************************************************************************",
    };


 //DECLARACION E INICIALIZACION DEL ARRAYLIST.
    ArrayList* listaAsociados;
        listaAsociados = al_newArrayList();

    ArrayList* lista1;
    ArrayList* lista2;

    sAsociado socio;
    socio.id = 90;
    socio.status = 1;
    strcpy(socio.nombre, "Maximiliano");
    strcpy(socio.apellido, "Guelpa");
    strcpy(socio.dni, "35340965");
    socio.edad = 27;

    do
    {
        opcion = 0;
        //system("cls");
        for(i=0; i<15; i++)
        printf("   %s\n", menu[i]);

        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 20. **\n", 3, 1, 21, &opcion);
        switch(opcion)
        {
            //ALTA
            case 1:
                ctrl_newAffiliate (listaAsociados);
                break;
            //BAJA
            case 2:
                ctrl_modifyAffiliate (listaAsociados);
                break;
            //MODIFICACION
            case 3:
                ctrl_downAffiliate (listaAsociados);
                break;
            //HARDCODE
            case 4:
                ctrl_hardCode (listaAsociados);
                break;

            ////////////////////////////////////////////////

            //al_debugShow
            case 5:
                al_debugShow(listaAsociados);
                for(i=0; i<listaAsociados->size; i++)
                ctrl_debugShow ( *(listaAsociados->pElements+i) );
                break;

            //al_clone
            case 6:
                lista1 = al_clone (listaAsociados);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_subList
            case 7:
                lista2 = al_subList (listaAsociados, 2, 5);
                al_debugShow (lista2);
                for(i=0; i<lista2->size; i++)
                ctrl_debugShow ( *(lista2->pElements+i) );
                system ("pause");
                break;

            //al_deleteArrayList
            case 8:
                al_deleteArrayList (lista2);
                al_debugShow (lista2);
                system("pause");
                break;

            //al_add
            case 9:
                al_add (lista1, &socio);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_push
            case 10:
                al_push (lista1, 2, &socio);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_set
            case 11:
                al_set (lista1, 3, &socio);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_remove
            case 12:
                al_remove (lista1, 3);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_clear
            case 13:
                al_clear (lista1);
                al_debugShow (lista1);
                for(i=0; i<lista1->size; i++)
                ctrl_debugShow ( *(lista1->pElements+i) );
                system ("pause");
                break;

            //al_indexOf
            case 14:
                printf("el socio pasado corresponde al indice: %d\n", al_indexOf (lista1, &socio));
                system ("pause");
                break;

            //al_get
            case 15:
                break;
            //al_pop
            case 16:
                break;
            //al_isEmpty
            case 17:
                break;
            //al_contains
            case 18:
                break;

            //al_containsAll
            case 19:
                printf("contains all? %d", al_containsAll (listaAsociados, lista2));
                break;

            //al_len
            case 20:
                printf("al_len (listaAsociados) = %d", al_len (listaAsociados));
                break;
            ////////////////////////////////////////////////
            default:
                opcion = 21;
                break;
        }

    }while(opcion != 21);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"
#include "parser.h"

/****************************************************
    HACER:
        1.  Agregar al arraylist una funcion que permita filtrar elementos en forma generica
            prototipo de la funcion:

                ArrayList* al_filter(ArrayList* listIn,int (*functionFilter)(void*));

            Esta funcion recibe como argumentos un arraylist y un puntero a funcion, y devuelve un nuevo ArrayList
            con ciertos elementos de la lista de entrada. La funcion pasada como argumento decidira si cada uno de los
            elementos de la lista origen se copian en la lista de salida.

            el prototipo de la funcion pasada como argumento es:
                int funcionQuFiltra(void* item);

            esta funcion debera devolver un 1 para mantener el elemento en la lista de salida y un 0 para filtrarlo.

        2. Leer el archivo data.csv de empleados y cargarlos en un arraylist
        3. Utilizandola funcion agregada en el arraylist, obtener otra lista filtrada, en donde todos los empleados
           sean mayores de 30 y sean programadores.
        4. Escribir esta lista obtenida en otro archivo out.csv
*****************************************************/



int main()
{

    ArrayList* lista = al_newArrayList();

    parserEmployee (lista);

    printf("*********** LISTA COMPLETA ****************\n");
    int i;

    for(i=0; i<al_len(lista); i++)
    {
        Employee* e = al_get(lista, i);
        employee_print(e);
    }

    // Obtengo lista filtrada
    ArrayList* filteredList = al_filter(lista, employee_filterEmployee);

    printf("*********** LISTA FILTRADA ****************\n");
    for(i=0; i<al_len(filteredList); i++)
    {
        Employee* e = al_get(filteredList, i);
        employee_print(e);
    }

    // genero archivo con lista filtrada
    dm_dumpEmployeeList(filteredList);

    return 0;
}

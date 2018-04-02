#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "funciones.h"

#define STOCK_PELICULAS 10

int main()
{
    int  opcion, i;
    char menu[12][100] = {
    "****************************************************",
    "*            PUBLICACIONES PANTALLAS               *",
    "****************************************************",
    "* 1. Nueva Pelicula.      4. Listar Peliculas      *",
    "*                            cargadas.             *",
    "*                                                  *",
    "* 2. Eliminar Pelicula.   5. Generar Pagina WEB.   *",
    "*                                                  *",
    "*                                                  *",
    "* 3. Modificar Pelicula.  6. Salir.                *",
    "*                                                  *",
    "****************************************************",
    };


    EMovie peliculas [STOCK_PELICULAS];
        emov_arrayInit(peliculas, STOCK_PELICULAS);

        emov_cheater (peliculas);


    do
    {
        opcion = 0;
        system("cls");
        for(i=0; i<12; i++)
        printf("   %s\n", menu[i]);
        input_getInt("   Ingrese una opcion: ", "\t** seleccione una opcion del 1 al 6. **\n", MAX_REINGRESOS, 1, 6, &opcion);

        switch( opcion )
        {
            //AGREGAR PELICULA
            case 1:
                func_agregarPelicula(peliculas, STOCK_PELICULAS);
                printf("pelicula cargada con exito\n");
                system("pause");
                break;

            //BORRAR PELICULA
            case 2:
                func_borrarPelicula(peliculas, STOCK_PELICULAS);
                printf("se ha borrado la pelicula seleccinada de la cartelera\n");
                system("pause");
                break;

            //MODIFICAR PELICULA
            case 3:
                func_modificarPelicula(peliculas, STOCK_PELICULAS);
                printf("se ha modificado la pelicula seleccinada de la cartelera\n");
                system("pause");
                break;

            //MOSTRAR PELICULAS CARGADAS
            case 4:
                emov_arrayRecords(peliculas, STOCK_PELICULAS);
                system("pause");
                break;

            //GENERAR PAGINA WEB
            case 5:
                func_generarPagina(peliculas, STOCK_PELICULAS);
                printf("se ha generado el archivo exitosamente\n");
                system("pause");
                break;

            case 6:
                opcion = 7;
                break;
        }
    }while(opcion != 7);

    return 0;
}

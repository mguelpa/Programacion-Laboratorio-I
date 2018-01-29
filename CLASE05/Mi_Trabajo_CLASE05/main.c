#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

#define MAX_EMPLEADOS 3

int main()
{
    //char respuesta = 'n';


    int edad[MAX_EMPLEADOS];
    float sueldo[MAX_EMPLEADOS];

    float mayorSueldo;
    float promedioEdades;

    obtenerDatos(edad, sueldo, MAX_EMPLEADOS);

    modificarRegistro(edad, sueldo, MAX_EMPLEADOS, "Ingrese el Numero de empleado: ", "Reingrese la edad: ", "Reingrese el sueldo: ");








//    switch(valor)
//    {
//    case 1:
//        do
//        {
//            if(modificarRegistro(edad, sueldo, MAX_EMPLEADOS, "Ingrese el Numero de empleado: ", "Reingrese la edad: ", "Reingrese el sueldo: ") = -1)
//            {
//                printf("Los datos ingresados no son correctos. \n NO SE MODIFICO EL REGISTRO.");
//            }
//            else
//            printf("El registro fue modificado de manera exitosa!");
//
//            printf("desea modificar un nuevo registro? S/N:");
//            fflush(stdin);
//            scanf("%c", &respuesta);
//        }while(respuesta != 'n');
//
//    case 2:
//        do
//        {
//            if(modificarRegistro(edad, sueldo, MAX_EMPLEADOS, "Ingrese el Numero de empleado: ", "Reingrese la edad: ", "Reingrese el sueldo: ") = 0)
//            {
//                printf("Los datos ingresados no son correctos. \n NO SE MODIFICO EL REGISTRO.");
//            }
//            else
//            printf("El registro fue modificado de manera exitosa!");
//
//            printf("desea modificar un nuevo registro? S/N:");
//            fflush(stdin);
//            scanf("%c", &respuesta);
//        }while(respuesta != 'n');
//    }








    imprimirDatos(edad, sueldo, MAX_EMPLEADOS);




    if( promediarEdades(edad, MAX_EMPLEADOS, &promedioEdades) == -1)
    {
         printf("Error: no se encuentran registros validos.");
    }
    else
    {
          printf("La edad promedio es: %.2f\n", promedioEdades);
    }




    if(buscarMayorFloat(sueldo, MAX_EMPLEADOS, &mayorSueldo) == -1)
    {
        printf("Error: no se encuentran registros validos.\n");
    }
    else
    {
        printf("El mayor sueldo es: %.2f\n", mayorSueldo);
    }




    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    double operando1;
    double operando2;
    double resultado;

    char respuesta = 'n';
    char seguir = 's';

    int opcion = 0;

    while(seguir == 's')
    {
        printf("\n1- Ingresar 1er operando (A= %.2f )\n", operando1);
        printf("2- Ingresar 2do operando (B= %.2f )\n", operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(obtenerNumero("ingrese el 1er operando: ", &operando1)== -1)
            {
                printf("\nHa ingresado caracteres no validos");
            }
            else
            {
                printf("\nEl numero ha sido cargado de manera exitosa");
            }
            break;
        case 2:
            if(obtenerNumero("ingrese el 2do operando: ", &operando2)== -1)
            {
                printf("\nha ingresado caracteres no validos");
            }
            else
            {
                printf("\nEl numero ha sido cargado de manera exitosa");
            }
            break;

        case 3:
            sumar(operando1, operando2, &resultado);
            printf("El resultado de la suma entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
            break;

        case 4:
            restar(operando1, operando2, &resultado);
            printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
            break;

        case 5:
            if(dividir(operando1, operando2, &resultado) == -1)
            {
                    printf("\n\nNo es posible dividir por 0 !!!\n");
                    printf("desea modificar el 2do operando?S/N: ");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    if(respuesta != 'n')
                    {
                        obtenerNumero("Ingrese el nuevo operando", &operando2);
                        printf("El resultado de la division entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);

                    }
                    else
                    {
                        printf("no se realiza operacion.\n");
                    }
            }
            break;

        case 6:
            multiplicar(operando1, operando2, &resultado);
            printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
            break;

        case 7:
            calcularFactorial(operando1, &resultado);
            printf("El factorial del 1er operando: %.2f es: %.2f\n\n", operando1, resultado);

            calcularFactorial(operando2, &resultado);
            printf("El factorial del 2do operando: %.2f es: %.2f\n\n", operando2, resultado);
            break;

        case 8:
            sumar(operando1, operando2, &resultado);
            printf("El resultado de la suma entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);

            restar(operando1, operando2, &resultado);
            printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);

            if(dividir(operando1, operando2, &resultado) == -1)
            {
                    printf("\n\nNo es posible dividir por 0 !!!\n");
                    printf("desea modificar el 2do operando?S/N: ");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    if(respuesta != 'n')
                    {
                        obtenerNumero("Ingrese el nuevo operando", &operando2);
                        printf("El resultado de la division entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
                    }
                    else
                    {
                        printf("no se realiza operacion.");
                    }
            }

            multiplicar(operando1, operando2, &resultado);
            printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);

            calcularFactorial(operando1, &resultado);
            printf("El factorial del 1er operando: %.2f es: %.2f\n\n", operando1, resultado);
            //MENSAJE NO ES POSIBLE CALCULAR EL FACTORIAL DE 0
            //PREGUNTA DESEA CAMBIAR EL NUMERO?

            calcularFactorial(operando2, &resultado);
            printf("El factorial del 2do operando: %.2f es: %.2f\n\n", operando2, resultado);
            //MENSAJE NO ES POSIBLE CALCULAR EL FACTORIAL DE 0
            //PREGUNTA DESEA CAMBIAR EL NUMERO?

        case 9:
            seguir = 'n';
            break;

        default:
            seguir = 'n';
            break;
        }
    }
    return 0;
}

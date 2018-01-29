/********************************************************************************************
 * Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 *     1. Ingresar 1er operando (A=x)
 *     2. Ingresar 2do operando (B=y)
 *     3. Calcular la suma (A+B)
 *     4. Calcular la resta (A-B)
 *     5. Calcular la division (A/B)
 *     6. Calcular la multiplicacion (A*B)
 *     7. Calcular el factorial (A!)
 *     8. Calcular todas las operaciones
 *     9. Salir
 *
 * • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 *   que contenga las funciones para realizar las 4 operaciones.
 *
 * • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 *   (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado).
 *
 * • Deberán contemplarse los casos de error (división por cero, etc).
 *
 * • Documentar todas las funciones.
 ********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float operando1 = 0;
    float operando2 = 0;
    float resultado;
    int flag1 = 2;
    int flag2 = 2;
    //int sarasa;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A= %.2f)\n", operando1);
        printf("2- Ingresar 2do operando (B= %.2f)\n", operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        //system("cls");

        switch(opcion)
        {
            case 1:
                flag1 = 0;
                operando1 = ingresaOprando("Ingrese el 1er operando: ");
                if(operando1 == 0)
                {
                    flag1 = 1;
                }
                break;
            case 2:
                flag2 = 0;
                operando2 = ingresaOprando("Ingrese el 2do operando: ");
                if(operando2 == 0)
                {
                    flag2 = 1;
                }
                break;





            case 3:
                resultado = sumar(operando1, operando2);
                printf("El resultado de la suma entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
                break;





            case 4:
                resultado = restar(operando1, operando2);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
                break;





            case 5:
                if(flag2 == 1 || flag2 == 2)
                {

                    do
                    {
                        printf("\n\nNo es posible dividir por 0 !!!\n");
                        printf("Re ingrese el 2do operando con un valor distinto de 0: ");
                        scanf("%f", &operando2);
                    }
                    while(operando2 == 0);
                    flag2 = 0;
                }
                resultado = dividir(operando1, operando2);
                printf("El resultado de la division entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
                break;





            case 6:
                resultado = multiplicar(operando1, operando2);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n\n", operando1, operando2, resultado);
                break;





            case 7:
                if(flag1 == 1 || flag1 == 2)
                {

                    do
                    {
                        printf("\n\nNo es posible realizar el factorial de 0 !!!\n");
                        printf("Re ingrese el 1er operando con un valor distinto de 0: ");
                        scanf("%f", &operando1);
                    }
                    while(operando1 == 0);
                    flag1 = 0;
                }
                resultado = calcularFactorial(operando1);
                printf("El factorial del 1er operando: %.2f es: %.2f\n\n", operando1, resultado);


                if(flag2 == 1 || flag2 == 2)
                {

                    do
                    {
                        printf("\nNo es posible realizar el factorial de 0 !!!\n");
                        printf("Re ingrese el 2do operando con un valor distinto de 0: ");
                        scanf("%f", &operando2);
                    }
                    while(operando2 == 0);
                    flag2 = 0;
                }
                resultado = calcularFactorial(operando2);
                printf("El factorial del 2do operando: %.2f es: %.2f\n\n", operando2, resultado);
                break;





            case 8:
                resultado = sumar(operando1, operando2);
                printf("El resultado de la suma entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);

                resultado = restar(operando1, operando2);
                printf("El resultado de la resta entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);


                if(flag2 == 1 || flag2 == 2)
                {

                    do
                    {
                        printf("\nNo es posible dividir por 0 !!!\n");
                        printf("Re ingrese el 2do operando con un valor distinto de 0: ");
                        scanf("%f", &operando2);
                    }
                    while(operando2 == 0);
                    flag2 = 0;
                }
                resultado = dividir(operando1, operando2);
                printf("El resultado de la division entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);

                resultado = multiplicar(operando1, operando2);
                printf("El resultado de la multiplicacion entre %.2f y %.2f es: %.2f\n", operando1, operando2, resultado);



                if(flag1 == 1 || flag1 == 2)
                {

                    do
                    {
                        printf("\nNo es posible realizar el factorial de 0 !!!\n");
                        printf("Re ingrese el 1er operando con un valor distinto de 0: ");
                        scanf("%f", &operando1);
                    }
                    while(operando1 == 0);
                    flag1 = 0;
                }
                resultado = calcularFactorial(operando1);
                printf("\nEl factorial del 1er operando: %.2f es: %.2f\n\n", operando1, resultado);


                if(flag2 == 1 || flag2 == 2)
                {

                    do
                    {
                        printf("No es posible realizar el factorial de 0 !!!\n\n");
                        printf("Re ingrese el 2do operando con un valor distinto de 0: ");
                        scanf("%f", &operando2);
                    }
                    while(operando2 == 0);
                    flag2 = 0;
                }
                resultado = calcularFactorial(operando2);
                printf("El factorial del 2do operando: %.2f es: %.2f\n\n", operando2, resultado);
                break;





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

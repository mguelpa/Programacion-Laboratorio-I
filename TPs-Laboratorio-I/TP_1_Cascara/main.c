#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define MAX_INTENTOS 3

int main()
{
    double operando1 = 0;
    double operando2 = 0;
    double resultado;

    char respuesta = 'n';
    char seguir = 's';

    int intentos = 0;
    int opcion = 0;

    while(seguir == 's')
    {
        printf("1- Ingresar 1er operando (A= %.2f )\n", operando1);
        printf("2- Ingresar 2do operando (B= %.2f )\n", operando2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
        case 1:
            if(obtenerNumero("ingrese el 1er operando: ", &operando1)== -1)
            {
                printf("Ha ingresado caracteres no validos. Intente nuevamente...\n");
            }
            else
            {
                printf("El numero se cargo correctamente\n\n");
            }
            break;
        case 2:
            if(obtenerNumero("ingrese el 2do operando: ", &operando2)== -1)
            {
                printf("Ha ingresado caracteres no validos. Intente nuevamente...\n");
            }
            else
            {
                printf("El numero se cargo correctamente\n\n");
            }
            break;
        case 3:
            sumar(operando1, operando2, &resultado);
            printf("El resultado de la suma (%.2f) + (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
            break;
        case 4:
            restar(operando1, operando2, &resultado);
            printf("El resultado de la resta entre (%.2f) - (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
            break;
        case 5:
            if(dividir(operando1, operando2, &resultado) == -1)
            {
                intentos = 0;
                printf("No es posible dividir por 0 !!!\n");
                printf("desea modificar el 2do operando?S/N: ");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    while(operando2 == 0 && intentos < MAX_INTENTOS)
                    {
                        intentos++;
                        obtenerNumero("Ingrese el nuevo operando: ", &operando2);
                        if(operando2!=0)
                            intentos--;
                    }
                    if(intentos == MAX_INTENTOS)
                    {
                        printf("---> no se realizo operacion. <--- \n\n");
                    }
                    else
                    {
                        dividir(operando1, operando2, &resultado);
                        printf("El resultado de la division (%.2f) / (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
                    }
                }
                else if(respuesta == 'n' || intentos > MAX_INTENTOS)
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                dividir(operando1, operando2, &resultado);
                printf("El resultado de la division (%.2f) / (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
            }
            break;
        case 6:
            multiplicar(operando1, operando2, &resultado);
            printf("El resultado de la multiplicacion (%.2f) * (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
            break;
        case 7:
            if(calcularFactorial(operando1, &resultado) == -1)
            {
                printf("\n\nResultado no definido!!!\n");
                printf("desea modificar el %.2f operando?S/N: ", operando1);
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    obtenerNumero("Ingrese el nuevo operando: ", &operando1);
                    calcularFactorial(operando1, &resultado);
                    printf("El resultado del factorial de %.2f es: %.2f\n\n", operando1, resultado);
                }
                else
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                printf("El resultado del factorial de %.2f es: %.2f\n\n", operando1, resultado);
            }

            if(calcularFactorial(operando2, &resultado) == -1)
            {
                printf("\n\nResultado no definido!!!\n");
                printf("desea modificar el %.2f operando?S/N: ", operando2);
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    obtenerNumero("Ingrese el nuevo operando", &operando2);
                    calcularFactorial(operando2, &resultado);
                    printf("El resultado del factorial de %.2f es: %.2f\n\n", operando2, resultado);
                }
                else
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                printf("El resultado del factorial de %.2f es: %.2f\n\n", operando2, resultado);
            }
            break;
        case 8:
            printf("----------------------------------------------------------------\n");
            sumar(operando1, operando2, &resultado);
            printf("El resultado de la suma\t\t  (%.2f) + (%.2f) es: %.2f\n", operando1, operando2, resultado);

            restar(operando1, operando2, &resultado);
            printf("El resultado de la resta\t  (%.2f) - (%.2f) es: %.2f\n", operando1, operando2, resultado);


            if(dividir(operando1, operando2, &resultado) == -1)
            {
                intentos = 0;
                printf("No es posible dividir por 0 !!!\n");
                printf("desea modificar el 2do operando?S/N: ");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    while(operando2 == 0 && intentos < MAX_INTENTOS)
                    {
                        intentos++;
                        obtenerNumero("Ingrese el nuevo operando: ", &operando2);
                        if(operando2!=0)
                            intentos--;
                    }
                    if(intentos == MAX_INTENTOS)
                    {
                        printf("---> no se realizo operacion. <--- \n\n");
                    }
                    else
                    {
                        dividir(operando1, operando2, &resultado);
                        printf("El resultado de la division\t  (%.2f) / (%.2f) es: %.2f\n\n", operando1, operando2, resultado);
                    }
                }
                else if(respuesta == 'n' || intentos > MAX_INTENTOS)
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                dividir(operando1, operando2, &resultado);
                printf("El resultado de la division\t  (%.2f) / (%.2f) es: %.2f\n", operando1, operando2, resultado);
            }
            multiplicar(operando1, operando2, &resultado);
            printf("El resultado de la multiplicacion (%.2f) * (%.2f) es: %.2f\n", operando1, operando2, resultado);
            printf("----------------------------------------------------------------\n");

            if(calcularFactorial(operando1, &resultado) == -1)
            {
                printf("Error. Resultado no definido!!!\n");
                printf("desea modificar el operando cargado con %.2f ?S/N: ", operando1);
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    obtenerNumero("Ingrese el nuevo operando: ", &operando1);
                    calcularFactorial(operando1, &resultado);
                    printf("El resultado del factorial de %.2f es: %.2f\n\n", operando1, resultado);
                }
                else
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                printf("El resultado del factorial de %.2f es: %.2f\n\n", operando1, resultado);
            }

            if(calcularFactorial(operando2, &resultado) == -1)
            {
                printf("Error. Resultado no definido!!!\n");
                printf("desea modificar el operando cargado con %.2f ?S/N: ", operando2);
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta != 'n')
                {
                    obtenerNumero("Ingrese el nuevo operando: ", &operando2);
                    calcularFactorial(operando2, &resultado);
                    printf("El resultado del factorial de %.2f es: %.2f\n", operando2, resultado);
                }
                else
                {
                    printf("---> no se realizo operacion. <--- \n\n");
                }
            }
            else
            {
                printf("El resultado del factorial de %.2f es: %.2f\n", operando2, resultado);
            }
            printf("----------------------------------------------------------------\n\n");
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

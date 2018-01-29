/**************************************************
 * Realizar un programa que solicite números hasta
 * que el usuario lo indique:
 *    A. promedio
 *    B. máximo
 *    C. mínimo
 **************************************************/
#include <stdio.h>
#include <stdlib.h>

#define CANT_INGRESOS 5

int main()
{
    float sumIngresados = 0;
    float numIngresado;
    float max = 0;
    float min = 0;
    float prom;
    int flag = 0;
    int contIngresos = 0;
    char respuesta = 'S';

    do
    {
        printf("Ingrse un numero: ");
        scanf("%f", &numIngresado);

        if(flag == 0)
        {
            min = numIngresado;
            max = numIngresado;
            flag++;
        }

        if(numIngresado>max)
        {
            max = numIngresado;
        }
        if(numIngresado<min)
        {
            min = numIngresado;
        }
        printf("desea seguir ingresando numeros? S/N");
        fflush(stdin);
        scanf("%c", &respuesta);

        sumIngresados = numIngresado + sumIngresados;
        contIngresos++;

    }
    while(respuesta == 'S');

    prom = sumIngresados / contIngresos;

    printf("El mayor numero ingresado es: %.2f\n", max);
    printf("El menor numero ingresado es: %.2f\n", min);
    printf("El promedio es: %.2f\n", prom);
    return 0;
}


/**************************************************
 * Realizar un programa que solicite cinco números
 * e imprima por pantalla:
 *    A. promedio
 *    B. máximo
 *    C. mínimo
 **************************************************/
#include <stdio.h>
#include <stdlib.h>

#define CANT_INGRESOS 5

int main()
{
    int i;
    float sumIngresados = 0;
    float numIngresado;
    float max = 0;
    float min = 0;
    float prom;

    for(i=0; i< CANT_INGRESOS; i++)
    {
        printf("Ingrse un numero: ");
        scanf("%f", &numIngresado);

        if(i == 0)
        {
            min = numIngresado;
            max = numIngresado;
        }


        if(numIngresado>max)
        {
            max = numIngresado;
        }
        if(numIngresado<min)
        {
            min = numIngresado;
        }

        sumIngresados = numIngresado + sumIngresados;
    }

    prom = sumIngresados / CANT_INGRESOS;


    printf("El mayor numero ingresado es: %.2f\n", max);
    printf("El menor numero ingresado es: %.2f\n", min);
    printf("El promedio es: %.2f\n", prom);
    return 0;
}


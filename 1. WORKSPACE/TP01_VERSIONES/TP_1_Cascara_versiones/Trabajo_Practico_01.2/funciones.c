#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


int obtenerNumero(char mensaje[], double* numero)
{
    char str[20];
    int flag = 0;
    int retorno;
    int i=0;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", str);

    while(str[i] != '\0')
    {
        if(str[i] < '-' || str[i] > '9' || str[i] == '/')
            flag++;
        i++;
    }
    if(flag == 0)
    {
        *numero = atof(str);
        retorno = 0;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}
/***************************************************************
 *                     CALCULA SUMA                            *
 *\brief
 *\param
 *\return
 **************************************************************/
int sumar(double numero1, double numero2, double* suma)
{
    *suma = numero1 + numero2;
    return 0;
}

/***************************************************************
 *                     CALCULA RESTA                           *
 *\brief
 *\param
 *\return
 **************************************************************/
int restar(double numero1, double numero2, double* resta)
{
    *resta = numero1 - numero2;
    return 0;
}
/***************************************************************
 *                    CALCULA COCIENTE                         *
 *\brief
 *\param
 *\return
 **************************************************************/
int dividir(double numero1, double numero2, double* cociente)
{
    int retorno;

    if(numero2 == 0)
    {
        printf("No es posible dividir por 0!!!");
        retorno = -1;
    }
    else
    {
        *cociente = numero1 / numero2;
        retorno = 0;
    }
    return retorno;
}
/***************************************************************
 *                    CALCULA PRODUCTO                         *
 *\brief
 *\param
 *\return
 **************************************************************/
int multiplicar(double numero1, double numero2, double* producto)
{
    *producto = numero1 * numero2;
    return 0;
}

/***************************************************************
 *                  CALCULA EL FACTORIAL                       *
 *\brief
 *\param
 *\return
 **************************************************************/
int calcularFactorial(double numero, double* resultado)
{
    int i;
    int retorno;
    int factorial = 1;

    int convertido;

    convertido = numero;
    printf("%d", convertido);

    if(convertido == 1)
    {
        *resultado = 1;
        retorno = 1;
    }
    else
    {
        for(i=0; i<=(int)numero; i++)
        {
            factorial = i * factorial;
        }
        *resultado = factorial;
        retorno = 0;
    }
    return retorno;
}

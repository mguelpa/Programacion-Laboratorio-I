#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
/**************************************************
 * \brief
 *
 * \param
 * \param
 *
 * \return
 */
    int obtenerNumero(char mensaje[], double* numero)
    {
        int menos = 0;
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
            else if(str[i] == '-')
            {
                menos++;
            }
            i++;
        }
        if(flag == 0 && menos < 2)
        {
            *numero = atof(str);
            retorno = 0;
        }
        else if (menos > 1 || flag != 0)
        {
            retorno = -1;
        }

        return retorno;
    }
/**************************************************
 * \brief
 *
 * \param
 * \param
 *
 * \return
 */
int sumar(double numero1, double numero2, double* suma)
{
    if(numero1 == 0 && numero2 == 0)
        *suma = 0;
    else
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

    if(numero1 == 0 || numero2 == 0)
    {
        if(numero2 == 0)
        {
            retorno = -1;
        }
        else
        {
            *cociente = 0;
            retorno = 0;
        }
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
    if(numero1 == 0 || numero2 == 0)
        *producto = 0;
    else
    {
        *producto = numero1 * numero2;
    }
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
    int retorno = 0;
    int i;
    int numeroAInt;
    float resultadoParcial = 1;

    numeroAInt = numero;
    if(numero == numeroAInt)
    {
        if(numeroAInt<0)
        {
            numeroAInt = numeroAInt * -1;
            for(i=1; i<=numeroAInt; i++)
            {
                resultadoParcial = resultadoParcial * i;
            }
            resultadoParcial = resultadoParcial * -1;
            *resultado = resultadoParcial;
            retorno = 0;
        }
        else
        {
            if(numeroAInt == 0)
            {
                resultadoParcial = 1;
                *resultado = resultadoParcial;
                retorno = 0;
            }
            for(i=1; i<=numeroAInt; i++)
            {
                resultadoParcial = resultadoParcial * i;
                *resultado = resultadoParcial;
                retorno = 0;
            }
        }
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}
/********************************************************************************
 * \brief 	Funcion usada para preguntar al usuario si desea continuar
 *              - Chequea que solo sean admitidas las letras "s" o "n".
 *              - utiliza funcion tolower contenida en <ctype.h>
 *
 * \param       1 preguntar
 * \param       2 mensaje Error max intentos
 * \param       cantidad de intentos
 * \param       variable donde cargar la letra ingresada correctamente
 *
 * \return      (0) letra cargada correctamente (-1) supero intentos
 */
    int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer)
    {
        int contador = 0;
        char aux;

        contador = intentos;
        printf(solicitud);
        fflush(stdin);
        aux = tolower(getchar());
        while(!(aux == 's' || aux == 'n'))
        {
            printf(msjIntentos);
            fflush(stdin);
            aux = tolower(getchar());
            contador--;
            if(contador < 1)
            {
                *buffer = 'n';
                return -1;
            }
        }
        *buffer = aux;
        return 0;
    }

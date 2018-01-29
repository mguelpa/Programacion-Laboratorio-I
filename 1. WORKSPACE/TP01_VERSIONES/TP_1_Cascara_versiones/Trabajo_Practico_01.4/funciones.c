#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
/******************************************************************
 *          FUNCION: OBTENER NUMERO
 *
 * \brief   Funcion utilizada para solicitar un
 *          numero al usuario tomarlo como caracter
 *          y pasarlo a numerico incluyendo signo
 *          egativo.
 *
 * \param   1. solicitud a ser mostrada
 * \param   2. puntero a la variable a ser modificada
 *
 * \return  (0) =  conversion exitosa (-1) = caracteres no validos
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

/******************************************************************
 *          FUNCION: SUMAR
 *
 * \brief   Funcion utilizada para realizar una suma entre dos
 *          operandos, filtra si se ingresa un cero negativo.
 *
 * \param   1. pasaje por valor (double) del primer operando.
 * \param   2. pasaje por valor (double) del segundo operando.
 * \param   3. puntero a la variable a ser modificada con el resul
 *             tado.
 *
 * \return  (0) =  operacion exitosa (-1) = ingreso de cero negativo
 */
    int sumar(double numero1, double numero2, double* suma)
    {
        int retorno;
        if(numero1 == 0 && numero2 == 0)
        {
            *suma = 0;
            retorno = -1;
        }
        else
        {
            *suma = numero1 + numero2;
            retorno = 0;
        }
        return retorno;
    }

/******************************************************************
 *          FUNCION: RESTAR
 *
 * \brief   Funcion utilizada para realizar una resta entre dos
 *          operandos.
 *
 * \param   1. pasaje por valor (double) del primer operando.
 * \param   2. pasaje por valor (double) del segundo operando.
 * \param   3. puntero a la variable a ser modificada con el resul
 *             tado.
 *
 * \return  (0) =  operacion exitosa, fin de la funcion
 */
    int restar(double numero1, double numero2, double* resta)
    {
        *resta = numero1 - numero2;
        return 0;
    }

/******************************************************************
 *          FUNCION: DIVIDIR
 *
 * \brief   Funcion utilizada para realizar division entre dos
 *          operandos.
 *
 * \param   1. pasaje por valor (double) del primer operando.
 * \param   2. pasaje por valor (double) del segundo operando.
 * \param   3. puntero a la variable a ser modificada con el resul
 *             tado.
 *
 * \return  (0) =  operacion exitosa (-1) = Error. Division por 0
 */
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

/******************************************************************
 *          FUNCION: MULTIPLICAR
 *
 * \brief   Funcion utilizada para realizar el producto entre dos
 *          operandos.
 *
 * \param   1. pasaje por valor (double) del primer operando.
 * \param   2. pasaje por valor (double) del segundo operando.
 * \param   3. puntero a la variable a ser modificada con el resul
 *             tado.
 *
 * \return  (0) =  operacion exitosa, fin de funcion.
 */
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

/******************************************************************
 *          FUNCION: FACTORIAL
 *
 * \brief   Funcion utilizada para realizar el factorial de un solo
 *          operando. si el numero es decimal no realiza la operaci
 *          porque es un resultado indefinido. reconoce flotantes
 *          sin decimales.
 *
 * \param   1. pasaje por valor (double) del operando.
 * \param   3. puntero a la variable a ser modificada con el resul
 *             tado.
 *
 * \return  (0) =  operacion exitosa (-1) = Error. Resutado indefinido
 */
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

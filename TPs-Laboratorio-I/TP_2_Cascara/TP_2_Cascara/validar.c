#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 4096

/******************************************************************
 * \brief   Funcion utilizada para solicitar el nombre a cargar.
 *
 * \param   1. buffer donde cargar los datos una vez validados.
 * \param   2. Limite del array.
 * \param   3. solicitud a mostrar por pantalla.
 * \param   4. mensaje de error.
 * \param   5. cantidad de re ingresos admitidos.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *             
 */
    int val_getName (char* target, int length, char* request, char* errorMsg, int attempts)
    {
    	int retorno = -1;
    	char bufferName[length];

    	if(target != NULL && length > 0 && length < MAX_INPUT_BUFFER)
        {
        	printf(request);

        	while(attempts > 0)
        	{
        		fflush(stdin);
        		fgetsSwitchLF(bufferName, length, stdin);

    	   		if(val_validateName(bufferName) == -1)
    	   		{
    	   			printf(errorMsg);
    	   		}
    	   		else
    	   		{
                    strncpy(target, bufferName, length);
                    retorno = 0;
                    break;
    	   		}
       			attempts--;
       	    }
        }
    	return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para solicitar un numero sin signo
 *
 * \param   1. buffer donde cargar los datos una vez validados.
 * \param   2. Limite del array.
 * \param   3. solicitud a mostrar por pantalla.
 * \param   4. mensaje de error.
 * \param   5. cantidad de re ingresos admitidos.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *             
 */
    int val_getUnsignedInt(char* target, int length, char* request, char* errorMsg, int attempts)
    {
    	int retorno = -1;
    	char bufferAge[length];

    	if(target != NULL && length > 0 && length < MAX_INPUT_BUFFER)
        {
        	printf(request);

        	while(attempts > 0)
        	{
        		fflush(stdin);
        		fgetsSwitchLF(bufferAge, length, stdin);

    	   		if(val_validateUnsignedInt(bufferAge) == -1)
    	   		{
                    if(attempts == 1)
                        break;
    	   			printf(errorMsg);
    	   		}
    	   		else
    	   		{
                    strncpy(target, bufferAge, length);
                    retorno = 0;
                    break;
    	   		}
       			attempts--;
       	    }
        }
    	return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para solicitar la edad.
 *
 * \param   1. buffer donde cargar los datos una vez validados.
 * \param   2. Limite del array.
 * \param   3. solicitud a mostrar por pantalla.
 * \param   4. mensaje de error (caracteres no admitidos).
 * \param   5. mensaje de error (edad fuera de rango).
 * \param   6. cantidad de re ingresos admitidos.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 * \return  (-2) =  supero tamaño del array.
 *             
 */
    int val_getAge(char* target, int length, char* request, char* errorMsg, char* errorMsg2, int attempts)
    {
        int retorno = -1;
        char bufferAge[length];

        if(target != NULL && length > 0 && length < MAX_INPUT_BUFFER)
        {
            printf(request);

            while(attempts > 0)
            {
                fflush(stdin);
                fgetsSwitchLF(bufferAge, length, stdin);

                if(val_validateAge(bufferAge) == -1)
                {
                    if(attempts == 1)
                        break;
                    printf(errorMsg);

                }
                else if(val_validateAge(bufferAge) == -2)
                {
                    if(attempts == 1)
                        break;
                    printf(errorMsg2);

                }
                else
                {
                    strncpy(target, bufferAge, length);
                    retorno = 0;
                    break;
                }
                attempts--;
            }
        }
        return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para validar caracteres ingresados
 *          en un nombre.
 *
 * \param   1. array a analizar.
 *
 * \return  ( 0) =  caracteres admitidos.
 * \return  (-1) =  caracteres no admitidos.
 *             
 */
    int val_validateName(char* strNombre)
    {
        int retorno = 0;
        int i = 0;

        while(strNombre[i] != '\0')
        {
            if((strNombre[i] < 'a' || strNombre[i] > 'z') && (strNombre[i] < 'A' || strNombre[i] > 'Z'))
            {
                retorno = -1;
                break;
            }
            i++;
        }
        return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para validar caracteres ingresados
 *          en un numero.
 *
 * \param   1. array a analizar.
 *
 * \return  ( 0) =  caracteres admitidos.
 * \return  (-1) =  caracteres no admitidos.
 *             
 */
    int val_validateUnsignedInt (char* strUnsignedInt)
    {
        int retorno = 0;
        int i = 0;

        while(strUnsignedInt[i] != '\0')
        {
            if(strUnsignedInt[i] < '0' || strUnsignedInt[i] > '9')
            {
                retorno = -1;
                break;
            }
            i++;
        }
        return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para validar caracteres ingresados
 *          en una edad.
 *
 * \param   1. array a analizar.
 *
 * \return  ( 0) =  caracteres admitidos.
 * \return  (-1) =  caracteres no admitidos.
 *             
 */
    int val_validateAge (char* strAge)
    {
        int retorno = 0;
        int i = 0;

        while(strAge[i] != '\0')
        {
            if(strAge[i] < '0' || strAge[i] > '9' || i > 3)
            {
                retorno = -1;
                break;
            }
            i++;
        }
        if(atoi(strAge) > MAX_EDAD_ADMITIDA || atoi(strAge) < 1){
            retorno = -2;
        }

        return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para cambiar terminador LF de windows
 *
 * \param   1. array a analizar.
 * \param   2. limite del array.
 * \param   3. nombre del "archivo" a pasar a la funcion fgets().
 *        
 */
    void fgetsSwitchLF (char* str, int length, FILE* fileName)
    {
        int i=0;
        fflush(stdin);
        fgets(str, length, fileName);
        str[length-1] = '\0';

        while(str[i] != '\0')
        {
            if(str[i] == 10)
            {
                str[i] = '\0';
                break;
            }
            i++;
        }
    }
/*****************************************************************************
 * \brief   Funcion utilizada para preguntar al usuario si desea "continuar"
 *              - Chequea que solo sean admitidas las letras "s" o "n".
 *              - utiliza funcion tolower contenida en <ctype.h>
 *
 * \param       1. pregunta al usuario
 * \param       2. mensaje Error max intentos
 * \param       3. cantidad de intentos
 * \param       4. variable donde cargar la letra ingresada correctamente
 *
 * \return      (0) letra cargada correctamente (-1) supero cantidad intentos
 */
    int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer)
    {
        char aux;
        printf(solicitud);
        fflush(stdin);
        aux = tolower(getchar());
        while(!(aux == 's' || aux == 'n'))
        {
            printf(msjIntentos);
            fflush(stdin);
            aux = tolower(getchar());
            intentos--;
            if(intentos < 1)
            {
                *buffer = 'n';
                return -1;
            }
        }
        *buffer = aux;
        return 0;
    }

/********************************************************************
 * \brief   Funcion utilizada para obtener un indice en funcion de 
 *          un id ingresado (en este caso un DNI).
 *
 * \param   1. array a analizar.
 * \param   2. limite del array.
 * \param   3. id a buscar (DNI).
 *
 * \return  ( i) =  indice del array correspondiente al id ingresado.
 *             
 */
    int pers_getIndexById (sPersona* arrayAlumnos, int length, int id)
    {
        int i;
        int index;

        for(i=0; i<length; i++)
        {
            if(atoi(arrayAlumnos[i].dni) == id)
            {
                index = i;
            }
        }
        return index;
    }


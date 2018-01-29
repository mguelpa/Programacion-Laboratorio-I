#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validar.h"

#define MAX_INPUT_BUFFER 4096 //----> revisar en codigo clase09.4


////////////////////////////////////////////////////////////////////////////////////////////////
void myFgets(char* buffer, int length, FILE* archivo)
{
    int i=0;

    fgets(buffer, length, archivo);

    buffer[length-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
int val_getName(char* destino, char* solicitud, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_CHARS_NOMBRE];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(solicitud);

        while(intentos > 0)
        {
            fflush(stdin);
            myFgets(buffer, limite, stdin);

            if(val_validateName(buffer) == -1)
            {
                printf(mensajeError);
            }
            else
            {
                strncpy(destino, buffer, limite);
                retorno = 0;
                break;
            }
            intentos --;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_getPrice(char* destino, char* solicitud, char* mensajeError, int intentos, int limite)
{
    int retorno = -1;
    char buffer[MAX_CHARS_PRECIO];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(solicitud);

        while(intentos > 0)
        {
            myFgets(buffer, limite, stdin);

            if(val_validatePrice(buffer) == -1)
            {
                printf(mensajeError);
            }
            else
            {
                strncpy(destino, buffer, limite);
                retorno = 0;
                break;
            }
            intentos --;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_getUnsignedInt (char* destino, char* solicitud, char* mensajeError, int intentos, int length)
{
    int retorno = -1;
    char buffer[length];

    printf(solicitud);

    while(intentos > 0)
    {
        fflush(stdin);
        myFgets(buffer, length, stdin);

        if(val_validateUnsignedInt(buffer) == -1)
        {
            printf(mensajeError);
            //continue; ----> ver que pasa con esto!!
        }
        else
        {
            strncpy(destino, buffer, length);
            retorno = 0;
            break;
        }
        intentos --;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
int val_validateName(char* strNombre)
{
    int retorno = 0;
    int i = 0;

    while(strNombre[i] != '\0')
    {
        if(strNombre[i] < 'a' || strNombre[i] > 'z')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
int val_validatePrice(char* strPrice)
{
    int retorno = 0;
    int i = 0;
    int dot = 0;

    while(strPrice[i] != '\0')
    {
        if((strPrice[i] < '0' || strPrice[i] > '9') && strPrice[i] != '.' && strPrice[i] != '-')
        {
            retorno = -1;
            break;
        }
        else
        {
            if(strPrice[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(strPrice[i] == '.')
            {
                dot++;
                if(dot > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////

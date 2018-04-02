#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interface.h"

//void interface_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName);
//int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);
//
//int interface_getInt (char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, int* target);
//int interface_getNumericStr (char* request, char* input);
//int validate_verifyStrNumbr (char* buffer);
//
//int interface_getNames(char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, char* target);
//int interface_getAlfabeticStr (char* request, char* input);
//int validate_verifyStrName (char* buffer);

////////////////////////////////////////////////////////////////////////////////////////////////////
void interface_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName)
{
    int i = 0;

    printf(request);
    fflush(stdin);

    fgets(targetStr, length, fileName);
    targetStr[length-1] = '\0'; //---> ultimo indice de array (tamaño 10; indice 0 - 9)

    while(targetStr[i] != '\0')
    {
        if(targetStr[i] == 10){
            targetStr[i] = '\0'; //---> LF switch
            break;
        }
        i++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
int interface_continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer)
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
        if(intentos < 1){
            *buffer = 'n';
            return -1;
        }
    }
    *buffer = aux;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getNames(char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, char* target)
{
    int retorno = -1;

    char auxStrNames[1024];
    int  i;

    for(i = 0; i<attemps; i++)
    {
        if(!interface_getAlfabeticStr(request, auxStrNames))
        {
            if(i == 2)
            return -1;
            printf(errorMsg);
            continue;
        }

        if(strlen(auxStrNames) > max || strlen(auxStrNames) < min)
        {
            if(i == 2)
            return -1;

            printf (errorMsg2);
            continue;
        }
        else{
            strcpy(target, auxStrNames);
            retorno = 0;
            break;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getAlfabeticStr (char* request, char* input)
{
    char aux[5] = {"aaaaa"};

    interface_fgetsSwitchLF(request, aux, 5, stdin);

    if(validate_verifyStrName(aux) == 1)
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int validate_verifyStrName (char* buffer)
{
   int i = 0;
   while(buffer[i] != '\0')
   {
       if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getInt(char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, int* target)
{
    int retorno = -1;

    char auxStrNum[10];
    //int  auxInt = 0;

        if(interface_getNumericStr(request, errorMsg, attemps, auxStrNum) == 1)
        {
            //auxInt = atoi (auxStrNum);

            if(atoi (auxStrNum) > max || atoi (auxStrNum) < min)
            {
                printf (errorMsg2);
            }
            else{
                *target = atoi (auxStrNum);
                retorno = 0;
            }
        }
        else{
            printf(errorMsg);
        }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getNumericStr (char* request, char* errorMsg, int attemps, char* target)
{
    int retorno = -1;
    char aux[10];
    int i;

    for(i = 0; i<attemps; i++)
    {
        interface_fgetsSwitchLF(request, aux, 10, stdin);
        if(validate_verifyStrNumbr(aux) == 1){
            strcpy(target, aux);
            retorno = 1;
            break;
        }
        else{
            printf(errorMsg);
            retorno = -1;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int validate_verifyStrNumbr (char* buffer)
{
    int retorno = 1;
    int i = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-')
        {
            retorno = -1;
            break;
            if(i != 0 && buffer[i] == '-')
            {
                retorno = -2;
                break;
            }
        }
        i++;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

















////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getAlfaNumericNames(char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, char* target)
{
    int retorno = -1;

    char auxStr[50];
    //int  auxInt = 0;

        if(interface_getAlfaNumericStr(request, errorMsg, attemps, auxStr) == 1)
        {

            if(strlen (auxStr) > max || strlen (auxStr) < min)
            {
                printf (errorMsg2);
            }
            else{
                strcpy (target, auxStr);
                retorno = 0;
            }
        }
        else{
            printf(errorMsg);
        }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getAlfaNumericStr (char* request, char* errorMsg, int attemps, char* target)
{
    int retorno = -1;
    char aux[10];
    int i;

    for(i = 0; i<attemps; i++)
    {
        interface_fgetsSwitchLF(request, aux, 10, stdin);
        if(validate_verifyStrAlfaNumeric (aux) == 0){
            strcpy(target, aux);
            retorno = 1;
            break;
        }
        else{
            printf(errorMsg);
            retorno = -1;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int validate_verifyStrAlfaNumeric (char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return -1;
       i++;
   }
   return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getFloat(char* request, char* errorMsg, char* errorMsg2, int attemps, float min, float max, float* target)
{
    int retorno = -1;

    char str[256];
    float aux;

    if(interface_getFloatStr(request, errorMsg, errorMsg2, attemps, min, max, str) == 0)
    {
        aux = atof (str);
        *target = aux;
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int interface_getFloatStr (char* request, char* errorMsg, char* errorMsg2, int attemps, float min, float max, char* target)
{
    int retorno = -1;
    char aux[256];
    int i = 0;

    do
    {
        interface_fgetsSwitchLF(request, aux, 256, stdin);
        switch(validate_verifyStrFloat(aux))
        {
            case -1:

                if(attemps > 1){
                    retorno = -1;
                    printf (errorMsg);
                    printf(" (intentos restantes %d)\n\n", attemps -1);
                }
                break;

            case -2:

                if(attemps > 1){
                    retorno = -1;
                    printf (errorMsg);
                    printf(" (intentos restantes %d)\n\n", attemps -1);
                }
                break;

            case -3:

                strcpy(target, "0");
                retorno = 0;
                break;

            case  0:

                if(atof (aux) <= max && atof (aux) >= min)
                {
                    strcpy(target, aux);
                    retorno = 0;
                }
                else if(attemps > 1)
                {
                    retorno = -3;
                    printf (errorMsg2);
                    printf(" (intentos restantes %d)\n\n", attemps -1);
                }
                break;
        }
        attemps--;

    }while(attemps > i && retorno != 0);

    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int validate_verifyStrFloat (char* buffer)
{
    int i = 0;
    int contadorGuiones = 0, contadorPuntos = 0;
    int retorno;

    while(buffer[i] != '\0')
    {
        if((buffer[i] != '-') && (buffer[i] != '.') && (buffer[i] < '0' || buffer[i] > '9'))
            return -1;
        if(buffer[i] == '-')
            contadorGuiones++;
        else if(buffer[i] == '.')
            contadorPuntos++;
        i++;
    }
    if(contadorGuiones >= 2 || contadorPuntos >= 2){
        retorno = -2;
    }
    else
    {
        if(atof(buffer) == 0){
            retorno = -3;
        }
        else{
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

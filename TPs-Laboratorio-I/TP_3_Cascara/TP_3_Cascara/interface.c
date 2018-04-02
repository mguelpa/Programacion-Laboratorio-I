#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interface.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
void input_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName)
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
///////////////////////////////////////////////////////////////////////////////
int input_continuar (char* solicitud, char* msjIntentos, int intentos, char* buffer)
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
///////////////////////////////////////////////////////////////////////////////
int input_getInt (char* request, char* errorMsg, int attemps, int min, int max, int* target)
{
    int retorno = -1;
    char auxStrNum[256];

    retorno = input_getNumericStr(request, errorMsg, attemps, min, max, auxStrNum);
    if(retorno == 0)
    {
        *target = atoi(auxStrNum);
         retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int input_getNumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target)
{
    int  retorno;
    char auxStrNum[256];

    int i = 0;

    do
    {
        input_fgetsSwitchLF(request, auxStrNum, 256, stdin);
        retorno = valid_verifyStrNumbr(auxStrNum);
        switch (retorno)
        {
            case -2:
                if(i < attemps)
                printf("\t** formato invalido **\n\n");
                break;

            case -1:
                if(i < attemps)
                printf("\t** ha ingresado caracteres invalidos **\n\n");
                break;

            case  0:
                if (atoi(auxStrNum) < min || atoi(auxStrNum) > max){
                    retorno = -1;
                    if (i<attemps){
                    printf(errorMsg);
                    break;
                    }
                }else{strcpy(target, auxStrNum);return 0;}
        }
        i++;
    } while(i < attemps);
    if (retorno != 0)
    {
        printf("\t ---> operacion cancelada <--- \n\a\t");
        printf("\n\n");
        system("pause");
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int valid_verifyStrNumbr (char* buffer)
{
    int retorno = 0;

    int i = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '-')
        {
            retorno = -1;
            break;
        }
        if(i != 0 && buffer[i] == '-')
        {
            retorno = -2;
            break;
        }
        i++;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int input_getFloat (char* request, char* errorMsg, int attemps, int min, int max, float* target)
{
    int retorno = -1;
    char auxStrNum[256];

    retorno = input_getFloatStr (request, errorMsg, attemps, min, max, auxStrNum);
    if(retorno == 0)
    {
        *target = atof (auxStrNum);
         retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int input_getFloatStr (char* request, char* errorMsg, int attemps, int min, int max, char* target)
{
    int  retorno = -1;
    char auxStrNum[256];

    int i = 0;

    do
    {
        input_fgetsSwitchLF(request, auxStrNum, 256, stdin);
        retorno = valid_verifyStrFloat(auxStrNum);
        switch (retorno)
        {
            case -2:
                if(i < attemps)
                printf("\t** formato invalido **\n\n");
                break;

            case -1:
                if(i < attemps)
                printf("\t** ha ingresado caracteres invalidos **\n\n");
                break;

            case  0:
                if(atof(auxStrNum) < min || atof(auxStrNum) > max){
                    retorno = -1;
                    if (i<attemps){
                    printf(errorMsg);
                    break;
                    }
                }else{strcpy(target, auxStrNum);return 0;}
            case  1:
                strcpy(target, "0");
                retorno = 0;
                break;
        }
        i++;
    } while(i < attemps);
    if (retorno != 0)
    {
        printf("\t ---> operacion cancelada <--- \n\a\t");
        printf("\n\n");
        system("pause");
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int valid_verifyStrFloat (char* str)
{
    int i = 0;
    int points =0;
    int retorno = 0;

    while(str[i] != '\0')
    {
        if((str[i] != '-') && (str[i] != '.') && (str[i] < '0' || str[i] > '9')){
            return -1;
        }
        else if((str[i] == '.' && i == 0) || (str[i] == '-' && i != 0) || (points > 1)){
            return -2;
        }
        else
        {
            if(str[i] == '.')
            points++;
        }
        i++;
    }
    if(atof(str) == 0)
    retorno = 1;
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int input_getAnumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target)
{
    int retorno = -1;
    char auxStr[max +2];

    int i = 0;

    do
    {
        input_fgetsSwitchLF(request, auxStr, max+2, stdin);
        retorno = valid_verifyAnumeric (auxStr);
        switch (retorno)
        {
            case -1:
                if(i < attemps)
                printf("\t** ha ingresado caracteres invalidos **\n\n");
                break;

            case  0:
                if(strlen (auxStr) > max || strlen (auxStr) < min){
                    retorno = -1;
                    if(i < attemps)
                    printf (errorMsg);
                    break;
                }else{strcpy(target, auxStr);return 0;}
        }
        i++;
    } while(i < attemps);
    if (retorno != 0)
    {
        printf("\t ---> operacion cancelada <--- \n\a\t");
        printf("\n\n");
        system("pause");
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int valid_verifyAnumeric (char* str)
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
int input_getLiks (char* request, char* errorMsg, int attemps, int min, int max, char* target)
{
    int retorno = -1;
    char auxStr[max +2];

    int i = 0;

    do
    {
        input_fgetsSwitchLF(request, auxStr, 301, stdin);
        retorno = valid_verifyLinks (auxStr);
        switch (retorno)
        {
            case -1:
                if(i < attemps)
                printf("\t** ha ingresado caracteres invalidos **\n\n");
                break;

            case  0:
                if(strlen (auxStr) > max || strlen (auxStr) < min){
                    retorno = -1;
                    if(i < attemps)
                    printf (errorMsg);
                    break;
                }else{strcpy(target, auxStr);return 0;}
            default:
                printf("sarasa");
                break;
        }
        i++;
    } while(i < attemps);
    if (retorno != 0)
    {
        printf("\t ---> operacion cancelada <--- \n\a\t");
        printf("\n\n");
        system("pause");
    }
    return retorno;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
int valid_verifyLinks (char* str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        if( (str[i] < '_' || str[i] > 'z') &&
            (str[i] < '@' || str[i] > '[') &&
            (str[i] < '0' || str[i] > ';') &&
            (str[i] < '&' || str[i] > '/') &&
            (str[i] != '!') &&
            (str[i] != '~') &&
            (str[i] != '?') &&
            (str[i] != ']') &&
            (str[i] != '=') &&
            (str[i] != '#') &&
            (str[i] != '$')                   )
        {return -1;}
        i++;
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////
int input_getTitles (char* request, char* errorMsg, int attemps, int min, int max, char* target)
{
    int retorno = -1;
    char auxStr[max +2];

    int i = 0;

    do
    {
        input_fgetsSwitchLF(request, auxStr, max +2, stdin);
        retorno = valid_verifyTitles (auxStr);
        switch (retorno)
        {
            case -1:
                if(i < attemps)
                printf("\t** ha ingresado caracteres invalidos **\n\n");
                break;

            case  0:
                if(strlen (auxStr) > max || strlen (auxStr) < min){
                    retorno = -1;
                    if(i < attemps)
                    printf (errorMsg);
                    break;
                }else{strcpy(target, auxStr);return 0;}
        }
        i++;
    } while(i < attemps);
    if (retorno != 0)
    {
        printf("\t ---> operacion cancelada <--- \n\a\t");
        printf("\n\n");
        system("pause");
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int valid_verifyTitles (char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if( (str[i] < ' ' || str[i] > 'z') || (str[i] == 92) )
        {
            return -1;
        }
        i++;
    }
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void output_justifyParagraph (char* text)
{
    int i = 0;

    while(text[i] != '\0')
    {
        if (i%50 == 0 /*&& text[i] == ' '*/)
            printf("\n\t\t");
//        else if (i%50 == 0 && text[i] != ' ')
//        {
//            while(text[i] != ' ')
//                i--;
//            printf("\n");
//        }
        printf("%c", text[i]);
        i++;
    }
}


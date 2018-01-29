/**********************************************************************
 * pedir nombre y edad en una funcion y guardar en dos arrays paralelos
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTOS 5
#define MAX_CARACTERES 50
#define LF 10

int obtenerEdad(int* pEdad, char* solicitud);
int validarNumero(char* buffer);


int main()
{
    //char arrayNombres[MAX_ELEMENTOS][MAX_CARACTERES];
    int edad [MAX_ELEMENTOS];
    int i;

    for (i=0; i<MAX_ELEMENTOS; i++)
    {
        if(obtenerEdad(&edad[i], "edad? ") == -1)
        {
            printf("mal");
        }
    }
    return 0;
}

int obtenerEdad(int* pEdad, char* solicitud)
{
    char buffer[4096];
    int retorno = -1;
    printf(solicitud);
    fgets(buffer, 4096, stdin);
    buffer[4095] = '\0';

    if(validarNumero(buffer) == 0)
    {
        *pEdad = atoi(buffer);
        retorno = 0;
    }
    return retorno;
}

int validarNumero(char* buffer)
{
    int retorno = 0, i=0;
    while(buffer[i]!= LF)
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}


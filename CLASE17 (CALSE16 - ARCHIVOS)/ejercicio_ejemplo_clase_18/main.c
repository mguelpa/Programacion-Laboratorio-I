/******************************************************************
* Programa: Ejemplo Clase 18
*
* Objetivo:

    Crear una struct con dos campos de cadena de caracteres, uno llamado �key� y otro llamado �value�.
    struct S_Data
    {
        char* key;
        char* value;
    };

    Hacer una funci�n que  reciba el nombre de un archivo y un array de estas estructuras.La funci�n leer� un archivo de texto con el siguiente formato:

    clave=valor
    clave=valor

    La funci�n deber� leer cada l�nea del archivo y separar por el caracter �=� la clave y el valor, y deber� cargarlo en una struct del array,
    generando de forma din�mica las variables para almacenar ambas palabras, y luego guardando los punteros en la struct.
    Prototipo de la funci�n:

    int loadDataFile(char* fileName,struct S_Data* array,int arrayLen)

    La funci�n devolver� la cantidad de items que se cargaron en el array, y nunca se superar� el tama�o del array
*
* Aspectos a destacar:
*
*   Uso de archivos. Uso de memoria din�mica.
*
* Version: 0.1 del 09 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


struct S_Data
{
    char* key;
    char* value;
};


int loadDataFile(char* fileName,struct S_Data* array,int arrayLen)
{
    FILE *fp;
    char lineStr[128]; // variable donde almacenamos la l�nea le�da

    // Abrimos el archivo para lectura
    fp = fopen(fileName , "r");
    if(fp == NULL)
    {
       perror("Error opening file");
       return -1;
    }

    // Leemos las l�neas
    int index=0;
    while( fgets (lineStr, 128, fp)!=NULL ) // Leemos una l�nea, 128 caracteres como m�ximo
    {
        //printf(lineStr);

        // Separamos las palabras por el "="
        int indexDivider = strcspn(lineStr,"="); // devuelve la posici�n del signo "="

        int keyLen = indexDivider+1; // calculo el tama�o del texto de la clave (palabra antes del "=")
        int valueLen = strlen(lineStr) - indexDivider -1; // calculo el tama�o del texto del valor (palabra despues del "=")

        char* key = (char* )malloc(keyLen); // pedimos memoria para guardar la clave
        char* value = (char* )malloc(valueLen); // pedimos memoria para guardar el valor

        strncpy(key,lineStr,keyLen-1);  // copiamos el string con la clave
        key[keyLen-1]=0x00;

        strncpy(value,&lineStr[keyLen],valueLen-1); //copiamos el atring con el valor
        value[valueLen-1]=0x00;

        // guardamos los punteros creados con malloc en la struct
        array[index].key = key;
        array[index].value = value;

        // contamos la cantidad de items en el array, si se llega al maximo pemitido, se sale
        index++;
        if(index>=arrayLen)
            break;
    }

    fclose(fp);
    return index;
};

int main()
{
    struct S_Data array[16];
    int len = loadDataFile("dict.txt",array,16);

    int i;
    for(i=0; i<len;i++)
        printf("%s = %s\r\n",array[i].key,array[i].value);

    return 0;
}

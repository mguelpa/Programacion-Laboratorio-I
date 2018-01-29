#include <stdio.h>
#include <stdlib.h>

#include "Socios.h"

ArrayList* listaSocios;
void aumentarSalario (void* item);
void printSocio (void* item);


int main()
{
    int i;
    listaSocios = al_newArrayList();
    FILE *pFile;
    Socio* newSocio;
    char var1[50],var2[50],var3[50];

    pFile = fopen("data.csv","r");

    if(pFile != NULL)
        printf("SIIIIIIIIIIIIIIIII\n\n");

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
        newSocio = soc_new(var2, "", "", atoi(var1), 0, atof(var3));
        al_add(listaSocios, newSocio);
    }
    fclose(pFile);

    for(i=0; i<al_len(listaSocios); i++)
    {
        newSocio = al_get(listaSocios, i);
        printf("ID: %d\n",soc_getId(newSocio));
        printf("ESTADO: %d\n",soc_getEstado(newSocio));
        printf("NOMBRE: %s\n",soc_getNombre(newSocio));
        printf("SALARIO: %f\n",soc_getSalario(newSocio));
    }

    al_map(listaSocios, aumentarSalario);

    al_map(listaSocios, printSocio);


    return 0;
}

void aumentarSalario (void* item)
{
    Socio* s = (Socio*)item;
    //s->salario = e->salario * 1.2;
    soc_setSalario(s, soc_getSalario(s)* 1.2);
}

void printSocio (void* item)
{
    Socio* s = (Socio*)item;
        printf("ID: %d\n",soc_getId(s));
        printf("ESTADO: %d\n",soc_getEstado(s));
        printf("NOMBRE: %s\n",soc_getNombre(s));
        printf("SALARIO: %f\n",soc_getSalario(s));
}


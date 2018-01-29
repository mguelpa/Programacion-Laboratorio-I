#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "controller.h"
//#include "affiliate.h"
#include "ArrayList.h"
#include "inputs.h"



////////////////////////////////////////////////////////////////////////////////
int ctrl_hardCode ( ArrayList* list )
{
    int i;

    int id[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int status[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char nombre[10][MAX_CHARS_NOMBRES] = {"maxi", "ana", "ale", "oski", "viky", "euge", "tomy", "martin", "pablo", "lean"};
    float salario[10] = {5000, 6000, 7000, 8000, 9000, 1000, 2000, 3000, 4000, 5000};


    Socio* socio;

    for (i=0; i<10; i++)
    {
        socio = soc_newSocio();
        soc_setId(socio, id[i]);
        soc_setEstado(socio, status[i]);
        soc_setNombre(socio, nombre[i]);
        soc_setNombre(socio, nombre[i]);
        al_add(socio, socio);
    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////

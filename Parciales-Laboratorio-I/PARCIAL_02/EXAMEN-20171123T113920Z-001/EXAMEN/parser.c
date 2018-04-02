#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee (ArrayList* pArrayListEmployee)
{
    FILE *pFile;

    Employee* auxiliar;
    char id[1024];
    char firstName[1024];
    char lastName[1024];
    char age[1024];
    char type[1024];

    pFile = fopen("data.csv","r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, firstName, lastName, age, type);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, firstName, lastName, age, type);

            auxiliar = employee_new(atoi(id), EMPLOYEE_ACTIVE, firstName, lastName, atoi(age), atoi(type));
            al_add(pArrayListEmployee, auxiliar);

        }
        fclose(pFile);
    }
    return 0;
}

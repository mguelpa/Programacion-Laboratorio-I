#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"


int dm_dumpEmployeeList(ArrayList* list)
{
    int i, retorno = -1;
    void* pSubject = NULL;

    FILE* subjectsBin = fopen ("out.csv", "w");


    if( subjectsBin != NULL )
    {
        for(i=0; i<al_len (list); i++)
        {
            pSubject = al_get (list, i);

            fprintf (subjectsBin,"%d,%s,%s,%d,%d\n", employee_getID(pSubject), employee_getName(pSubject), employee_getSurname(pSubject), employee_getAge(pSubject), employee_getType(pSubject));
            //fwrite (pSubject, sizeof (Employee), 1, subjectsBin);

            retorno = 0;
        }
    }
    fclose (subjectsBin);
    return retorno;

    return 0;
}


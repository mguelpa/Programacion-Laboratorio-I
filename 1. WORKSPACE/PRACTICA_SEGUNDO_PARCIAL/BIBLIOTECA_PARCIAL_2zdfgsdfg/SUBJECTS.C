#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Subjects.h"

//////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO          //
//////////////////////////////////////////////////
Subject* sub_new (int id, int status, char* name, char* surname/*,int age,char* dni,float salary*/)
{
    Subject* newSubject = malloc (sizeof(Subject));

    sub_setID (newSubject, id);
    sub_setStatus (newSubject, status);


    sub_setName (newSubject, name);
    sub_setSurname (newSubject, surname);

    //sub_setAge (newSubject, age);
    //sub_setDni (newSubject, dni);
    //sub_setSalario(newSubject, salario);
    return newSubject;
}
Subject* sub_findById (ArrayList* subject, int id)
{
    void* retorno = NULL;
    Subject* auxiliar;

    int i;
    for(i = 0; i<al_len( subject ); i++)
    {
        auxiliar = al_get( subject, i );
        if(auxiliar->subjectID == id)
        {
            retorno = auxiliar;
        }
    }
    return retorno;
}
int sub_delete (Subject* this)
{
    free(this);
    return 0;
}
//////////////////////////////////////////////////
// SETERS                                       //
//////////////////////////////////////////////////
int sub_setID (Subject* this, int subjectID)
{
    this->subjectID = subjectID;
    return 0;
}
int sub_setStatus (Subject* this, int subStatus)
{
    this->subStatus = subStatus;
    return 0;
}


int sub_setName (Subject* this, char* name)
{
	strcpy (this->name, name);
    return 0;
}
int sub_setSurname (Subject* this, char* surname)
{
	strcpy (this->surname, surname);
    return 0;
}
/*int sub_setAge (Subject* this, int age)
{
	this->age = age;
    return 0;
}
*/
/*int sub_setDni (Subject* this, char* dni)
{
	strcpy (this->dni, dni);
    return 0;
}
*/
/*int sub_setSalary (Subject* this, float salary)
{
    this->salary = salary;
    return 0;
}
*/
//////////////////////////////////////////////////
// GETERS                                       //
//////////////////////////////////////////////////
int sub_getID (Subject* this)
{
    return this->subjectID;
}
int sub_getStatus (Subject* this)
{
    return this->subStatus;
}


char* sub_getName (Subject* this)
{
    return this->name;
}
char* sub_getSurname (Subject* this)
{
    return this->surname;
}
/*int sub_getAge (Subject* this)
{
    return this->age;
}
*/
/*char* sub_getDni (Subject* this)
{
    return this->dni;
}
*/
/*float sub_getSalary (Subject* this)
{
    return this->salary;
}
*/


int sub_hardCode (ArrayList* list)
{
    int subjectID [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int subStatus [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char name [10][MAX_CHARS_NOMBRES] = {"maxi", "ana", "ale", "oski", "viky", "euge", "tomy", "martin", "pablo", "lean"};
    char surname [10][MAX_CHARS_NOMBRES] = {"maxi", "ana", "ale", "oski", "viky", "euge", "tomy", "martin", "pablo", "lean"};

    //int  age [10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    //char dni [10][MAX_CHARS_DNI] = {"111", "222", "333", "444", "555", "666", "777", "888", "999", "100"};
    //float salary [10] = {5000, 6000, 7000, 8000, 9000, 1000, 2000, 3000, 4000, 5000};

    Subject* newSubject;
    int i;

    for(i=0; i<10; i++)
    {
        newSubject = (Subject*)malloc ( sizeof(Subject) );

        sub_setID(newSubject, subjectID[i]);
        sub_setStatus(newSubject, subStatus[i]);

        sub_setName(newSubject, name[i]);
        sub_setSurname(newSubject, surname[i]);

        //sub_setAge(newSubject, age[i]);
        //sub_setDni(newSubject, dni[i]);
        //sub_setSalary(newSubject, salary[i]);

        al_add(list, newSubject);
    }

    return 0;
}
void sub_debugShow (ArrayList* list)
{
    Subject* auxiliar;
    int i;

    for(i=0; i<al_len(list); i++)
    {
        auxiliar = al_get (list, i);
        printf("subjectID: %d", sub_getID(auxiliar));
        printf("subStatus: %d", sub_getStatus(auxiliar));

        printf("name: %s", sub_getName(auxiliar));
        printf("surname: %s", sub_getSurname(auxiliar));

        //printf("age: %d", sub_getAge(auxiliar));
        //printf("dni: %s", sub_getDni(auxiliar));
        //printf("salary: %.2f", sub_getSalary(auxiliar));
    }
}

int sub_parseSubject(ArrayList* list)
{
    int i;
    list = al_newArrayList();
    FILE *pFile;

    Subject* auxiliar;
    char var1[50],var2[50],var3[50];

    pFile = fopen("data.csv","r");

    if(pFile != NULL)
        printf("SIIIIIIIIIIIIIIIII\n\n");

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);

        auxiliar = sub_new(atoi(var1), 0, var2, var3);
        al_add(list, auxiliar);
    }
    fclose(pFile);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "Employee.h"

//////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO          //
//////////////////////////////////////////////////
Employee* employee_new (int id, int status, char* name, char* surname, int age, int type /*,char* dni,float salary*/)
{
    Employee* newEmployee = malloc (sizeof(Employee));

    employee_setID (newEmployee, id);
    employee_setStatus (newEmployee, status);


    employee_setName (newEmployee, name);
    employee_setSurname (newEmployee, surname);

    employee_setAge (newEmployee, age);
    employee_setType (newEmployee, type);

    return newEmployee;
}
Employee* employee_findById (ArrayList* list, int id)
{
    void* retorno = NULL;
    Employee* auxiliar;

    int i;
    for(i = 0; i<al_len( list ); i++)
    {
        auxiliar = al_get( list, i );
        if(auxiliar->employeeID == id)
        {
            retorno = auxiliar;
        }
    }
    return retorno;
}
int employee_delete (Employee* this)
{
    free(this);
    return 0;
}
//////////////////////////////////////////////////
// SETERS                                       //
//////////////////////////////////////////////////
int employee_setID (Employee* this, int employeeID)
{
    this->employeeID = employeeID;
    return 0;
}
int employee_setStatus (Employee* this, int empStatus)
{
    this->empStatus = empStatus;
    return 0;
}


int employee_setName (Employee* this, char* name)
{
	strcpy (this->name, name);
    return 0;
}
int employee_setSurname (Employee* this, char* surname)
{
	strcpy (this->surname, surname);
    return 0;
}
int employee_setAge (Employee* this, int age)
{
	this->age = age;
    return 0;
}
int employee_setType (Employee* this, int type)
{
	this->type = type;
    return 0;
}

//////////////////////////////////////////////////
// GETERS                                       //
//////////////////////////////////////////////////
int employee_getID (Employee* this)
{
    return this->employeeID;
}
int employee_getStatus (Employee* this)
{
    return this->empStatus;
}


char* employee_getName (Employee* this)
{
    return this->name;
}
char* employee_getSurname (Employee* this)
{
    return this->surname;
}
int employee_getAge (Employee* this)
{
    return this->age;
}
int employee_getType (Employee* this)
{
    return this->type;
}




int employee_hardCode (ArrayList* list)
{
    int employeeID [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int subStatus [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    char name [10][MAX_CHARS_NOMBRES] = {"john", "peter", "jenn", "mary", "david", "susan", "tomy", "amy", "pablo", "carol"};
    char surname [10][MAX_CHARS_NOMBRES] = {"john", "peter", "jenn", "mary", "david", "susan", "tomy", "amy", "pablo", "carol"};

    int  age [10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
    //char dni [10][MAX_CHARS_DNI] = {"111", "222", "333", "444", "555", "666", "777", "888", "999", "100"};
    //float salary [10] = {5000, 6000, 7000, 8000, 9000, 1000, 2000, 3000, 4000, 5000};

    Employee* newEmployee;
    int i;

    for(i=0; i<10; i++)
    {
        newEmployee = (Employee*)malloc ( sizeof(Employee) );

        employee_setID(newEmployee, employeeID[i]);
        employee_setStatus(newEmployee, subStatus[i]);

        employee_setName(newEmployee, name[i]);
        employee_setSurname(newEmployee, surname[i]);

        employee_setAge(newEmployee, age[i]);
        //employee_setDni(newEmployee, dni[i]);
        //employee_setSalary(newEmployee, salary[i]);

        al_add(list, newEmployee);
    }

    return 0;
}
void employee_debugShow (ArrayList* list)
{
    Employee* auxiliar;
    int i;

    for(i=0; i<al_len(list); i++)
    {
        auxiliar = al_get (list, i);
        printf("employeeID: %d", employee_getID(auxiliar));
        printf("subStatus: %d", employee_getStatus(auxiliar));

        printf("name: %s", employee_getName(auxiliar));
        printf("surname: %s", employee_getSurname(auxiliar));
        printf("age: %d", employee_getAge(auxiliar));
        printf("type: %d", employee_getType(auxiliar));
    }
}



void employee_print(Employee* this)
{
    printf("employeeID: %d\n", employee_getID(this));
    printf("empStatus: %d\n", employee_getStatus(this));

    printf("name: %s\n", employee_getName(this));
    printf("surname: %s\n", employee_getSurname(this));
    printf("age: %d\n", employee_getAge(this));
    printf("type: %d\n\n", employee_getType(this));
}

int employee_filterEmployee(void* item)
{
    int retorno = 0;

    if(employee_getType(item) == 4)
    {
        if(employee_getAge(item) > 30)
        {
            retorno = 1;
        }
    }
    return retorno;
}





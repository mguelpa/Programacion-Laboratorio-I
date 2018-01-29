#include "ArrayList.h"

#ifndef SUBJECTS_H_INCLUDED
#define SUBJECTS_H_INCLUDED

    #define	MAX_CHARS_NOMBRES 50
    #define	MAX_CHARS_DNI 50


    typedef struct
    {
        int id;
        int estado;
        char nombre;
        char apellido;
        char dni[];
    }Cliente; //---> utilizar este




    typedef struct{
        int subjectID;
        int subStatus;

        char name [MAX_CHARS_NOMBRES +1];
        char surname [MAX_CHARS_NOMBRES +1];
        //int  age;
        char dni [MAX_CHARS_DNI +1];
        //float salary;
    }Subject;

#endif // SUBJECTS_H_INCLUDED

#define SUB_ACTIVE 0
#define SUB_INACTIVE 1

Subject* sub_new (int id, int status, char* name, char* surname/*,int age,char* dni,float salary*/);
Subject* sub_findById (ArrayList* this, int id);
int sub_hardCode (ArrayList* list);
void sub_debugShow (ArrayList* list);
int sub_parseSubject(ArrayList* list);
int sub_delete (Subject* this);

//________________________________________________
int sub_setID (Subject* this, int id);
int sub_setStatus (Subject* this, int estado);

int sub_setName (Subject* this, char* name);
int sub_setSurname (Subject* this, char* surname);

//int sub_setAge (Subject* this, int age);
//int sub_setDni (Subject* this, int dni);
//int sub_setSalary (Subject* this, float salary);


//________________________________________________
int sub_getID (Subject* this);
int sub_getStatus (Subject* this);

char* sub_getName (Subject* this);
char* sub_getSurname (Subject* this);

//int sub_getAge (Subject* this);
//int sub_getDni (Subject* this);
//float sub_getSalary (Subject* this);


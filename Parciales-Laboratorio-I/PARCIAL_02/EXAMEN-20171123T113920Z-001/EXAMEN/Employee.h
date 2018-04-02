#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

	#define EMPLOYEE_TYPE_ARCHITECT    0
	#define EMPLOYEE_TYPE_MANAGER      1
	#define EMPLOYEE_TYPE_DESIGNER     2
	#define EMPLOYEE_TYPE_JUNIOR       3
	#define EMPLOYEE_TYPE_PROGRAMMER   4

    #define	MAX_CHARS_NOMBRES 50
    #define	MAX_CHARS_DNI 50

    typedef struct{
        int employeeID;
        int empStatus;

        char name [MAX_CHARS_NOMBRES +1];
        char surname [MAX_CHARS_NOMBRES +1];
        int  age;
        //char dni [MAX_CHARS_DNI +1];
        //float salary;
        int type;
    }Employee;



#endif // _EMPLOYEE_H

#define EMPLOYEE_ACTIVE 0
#define EMPLOYEE_INACTIVE 1

int employee_filterEmployee(void* item);
void employee_print(Employee* this);
//Employee* employee_new(void);
//void employee_delete(Employee* this);


Employee* employee_new (int id, int status, char* name, char* surname, int age, int type);
Employee* employee_findById (ArrayList* this, int id);
int employee_hardCode (ArrayList* list);
void employee_debugShow (ArrayList* list);
int employee_parseSubject(ArrayList* list);
int employee_delete (Employee* this);

//________________________________________________
int employee_setID (Employee* this, int id);
int employee_setStatus (Employee* this, int estado);

int employee_setName (Employee* this, char* name);
int employee_setSurname (Employee* this, char* surname);
int employee_setAge (Employee* this, int age);
int employee_setType (Employee* this, int type);


//int employee_setDni (Employee* this, int dni);
//int employee_setSalary (Employee* this, float salary);


//________________________________________________
int employee_getID (Employee* this);
int employee_getStatus (Employee* this);

char* employee_getName (Employee* this);
char* employee_getSurname (Employee* this);
int employee_getAge (Employee* this);
int employee_getType (Employee* this);


//int employee_getDni (Employee* this);
//float employee_getSalary (Employee* this);

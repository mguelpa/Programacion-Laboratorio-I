#ifndef _FUNCIONES
#define _FUNCIONES

#define MAX_ALUMNOS 20
#define MAX_EDAD_ADMITIDA 150

#define MAX_INPUT_BUFFER 4096

#define MAX_CHARS_NOMBRE 50
#define MAX_CHARS_EDAD 4
#define MAX_CHARS_DNI 15
#define MAX_INTENTOS_REINGRESOS 3

typedef struct{
	int status;

	char nombre[MAX_CHARS_NOMBRE];
	char dni[MAX_CHARS_DNI];
	unsigned int edad;

} sPersona;

#endif // _FUNCIONES

#define STATUS_EMPTY 0
#define STATUS_LOADED 1
#define STATUS_DOWN -1


void pers_initArray (sPersona* arrayAlumnos, int length);
int pers_searchEmptySlot (sPersona* arrayAlumnos, int length);
int pers_getIndexById (sPersona* arrayAlumnos, int length, int id);

int pers_logPerson (sPersona* arrayAlumnos, int length, char* errorMsg);
int pers_deletePerson (sPersona* arrayAlumnos, char* errorMsg);
int pers_chartArray (sPersona* arrayAlumnos, int length);

int pers_loadData (sPersona* arrayAlumnos, int index);
void pers_deleteData (sPersona* arrayAlumnos, int index);

int pers_sortByName (sPersona* arrayAlumnos, int length);
int pers_sortByAge (sPersona* arrayAlumnos, int length, int* valueA, int* valueB, int* valueC);

void pers_plotData (int valueA, int valueB, int valueC);


int pers_printList (sPersona* arrayAlumnos, int length);
void pers_printData(sPersona* arrayAlumnos, int index);



#define DEBUG 1 //ESTOY EN MODO DEGUB


#ifndef __EMPLEADO
#define __EMPLEADO
#define NAME_SIZE 51
#define LAST_NAME_SIZE 51
typedef struct
{
    char nombre[NAME_SIZE];
    char apellido[LAST_NAME_SIZE];
    int idSector;
}Empleado;
#endif // __EMPLEADO



Empleado* empleado_new(void);
Empleado* empleado_newConstructor(char *nombre,char *apellido,int idSector);
void empleado_delete(Empleado* pEmpleado);
int empleado_setNombre(Empleado* pEmpleado, char *nombre);
char* empleado_getNombre(Empleado* pEmpleado);
int empleado_setApellido(Empleado* pEmpleado, char *apellido);
char* empleado_getApellido(Empleado* pEmpleado);
int empleado_setIdSector(Empleado* pEmpleado, int idSector);
int empleado_getIdSector(Empleado* pEmpleado);
void empleado_debugShow(Empleado* pEmpleado);

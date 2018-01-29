#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pEmpleado[50];
    void *generico[50]
    int i;

    for(i=0; i<50; i++)
    {
        pEmpleado[i] = empleado_newConstructor("JUAN","PEREZ", i);

    }
    //pEmpleado = empleado_newConstructor("JUAN","PEREZ",44);
    //empleado_debugShow(pEmpleado);
    //empleado_setNombre(pEmpleado, "XX");
    //empleado_debugShow(pEmpleado);
    //empleado_setApellido(pEmpleado, "AA");
    //empleado_debugShow(pEmpleado);

    empleado_debugShow(pEmpleado[33]);
    empleado_debugShow(pEmpleado[42]);


    //printf("\nEL NOMBRE ES : %s", empleado_getNombre(pEmpleado));

    return 0;
}

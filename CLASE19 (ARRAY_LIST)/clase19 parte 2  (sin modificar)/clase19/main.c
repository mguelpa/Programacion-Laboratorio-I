#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "arrayList.h"

int main()
{
    //Empleado *pEmpleado[50];
    void *pGenerico[50];
    int i;

    for(i=0;i<50;i++)
    {
      // pEmpleado[i] = empleado_newConstructor("JUAN","PEREZ",i);
        pGenerico[i] = empleado_newConstructor("JUAN","PEREZ",i);
    }
    //empleado_debugShow(pEmpleado[33]);
    empleado_debugShow((Empleado*)pGenerico[42]);

    ArrayList* listaEmpleados;
    listaEmpleados = al_new();
    al_add(listaEmpleados,empleado_newConstructor("1","PEREZ",1));
    al_add(listaEmpleados,empleado_newConstructor("2","PEREZ",2));
    al_add(listaEmpleados,empleado_newConstructor("3","PEREZ",3));
    al_add(listaEmpleados,empleado_newConstructor("3","PEREZ",3));
    al_debugShow(listaEmpleados);






    return 0;
}

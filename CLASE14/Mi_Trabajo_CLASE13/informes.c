#include <stdio.h>
#include <stdlib.h>
#include "entidad1.h"
#include "entidad2.h"
#include "informes.h"
// con esta funcion puedo acceder a cualquier campo es labase par cualquier otro tipo de consulta
void imprimirTodo(sEntidad1* nombre_arrayE1, int lenEntidad1, sEntidad2* nombre_arrayE2, int lenEntidad2)
{
    int indexE2;
    for(indexE2=0; indexE2<lenEntidad2; indexE2++)
    {
        if(arrayEntidad2[indexE2].flagEstado == STATUS_LOADED)
        {
            int idE1 = arrayEntidad2[indexE2].idEntidad1;
            int indexE1 = ent1_buscarIndicePorId(nombre_arrayE1, lenEntidad1, idE1)

            //se puede filtrar a partir de aca para conseguir cualuqier dato por ejemplo
            printf("%dt%s | %d\t%s", nombre_arrayE1[indexE1].id, nombre_arrayE1[indexE1].valueA, nombre_arrayE1[indexE1].id, nombre_arrayE1[indexE1].valueA)
        }
    }
}


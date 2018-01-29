#include <stdio.h>
#include <stdlib.h>
void printMatrix (char* , int rows, int columns);

int main()
{
    int i;
    char menu[26][100] = {
    "*************************************************************",
    "**  CLIENT MANAGER:  Lomas Social Club                     **",
    "*************************************************************",
    "*|     AGENDA CLIENTES     |    |     GESTOR COMERCIAL     |*",
    "*|                         |    |                          |*",
    "*|  1. Nuevo Asociado.     |    |   4. Nuevo servicio.     |*",
    "*|                         |    |                          |*",
    "*|  2. Modificacion        |    |   5. Editar servicio.    |*",
    "*|     Datos Asociados.    |    |                          |*",
    "*|                         |    |                          |*",
    "*|  3. Baja de Asociados.  |    |   6. Baja de Servicios.  |*",
    "*|-------------------------|    |--------------------------|*",
    "*|                         |    |                          |*",
    "*|  7. Inscripciones.      |    |  10. Parse Subjects      |*",
    "*|                         |    |                          |*",
    "*|                         |    |                          |*",
    "*|  8. Editar              |    |  11. cant de servicios   |*",
    "*|     inscripciones.      |    |      por cada socio.     |*",
    "*|                         |    |                          |*",
    "*|  9. Baja inscripciones. |    |  12. servicio con mas    |*",
    "*|                         |    |      socios.             |*",
    "*|                         |    |                          |*",
    "*|                         |    |  12. Listar todo.        |*",
    "*|                         |    |                          |*",
    "*|                         |    |  14. Salir.              |*",
    "*************************************************************",
    };

    for(i=0; i<26; i++)
    printf("   %s\n", menu[i]);

    printMatrix(menu, 26, 100);

    printf("Hello world!\n");
    return 0;
}

void printMatrix (char* menu, int rows, int columns)
{
    int i,j;
    char c;

    for(i=0; i<rows; i++)
    {
        //char c = *(menu+i*columns+j);
        for(j=0; c!= '\0'; j++)
        {
            c = *(menu+i*columns+j);
            printf("%c", c );
        }
        printf("\n");
    }
}

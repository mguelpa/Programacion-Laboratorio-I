#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

///////////////////////////////////////////////////////////////////////////
/*************************************************
 * \brief FUNCION CARGA DATOS EN ARRAYS PARALELOS
 *
 * \param dato1 = array1
 * \param dato2 = array2
 *
 * \return (0) = OKint buscarMaximo(int dato1, float dato2, int maxInt, float maxfloat int iteraciones)
 */
    int obtenerDatos(int array1[], float array2[], int rangoBusqueda)
    {
        int i;

        for(i=0; i<rangoBusqueda; i++)
        {
            printf("Ingrese la edad del empleado %d: ", i+1);
            scanf("%d", &array1[i]);

            printf("Ingrese el sueldo del empleado %d: ", i+1);
            scanf("%f", &array2[i]);
        }
        return 0;
    }
///////////////////////////////////////////////////////////////////////////
/******************************************************
 * \brief FUNCION IMPRIME DATOS DE LOS ARRAYS PARALELOS
 *
 * \param dato1 = array1
 * \param dato2 = array2
 *
 * \return (0) = OK
 */
    int imprimirDatos(int array1[], float array2[], int rangoBusqueda)
    {
        int i;

        printf("\n\nNRO\t\tEDAD\t\tSUELDO\n");
        for(i=0; i<rangoBusqueda; i++)
        {
            printf("%d\t\t%d\t\t%.2f\n", i+1, array1[i], array2[i]);
        }
        return 0;
    }
///////////////////////////////////////////////////////////////////////////
/**************************************************
 * \brief FUNCION CALCULA EL PROMEDIO DE LAS EDADES
 *
 * \param dato1 = array1
 * \param dato2 = array2
 *
 * \return ( 0) = OK
 *         (-1) = ERROR, NO SE PROCESO INFORMACION
 */
    int promediarEdades(int* array1, int tamanioArray, float* resultado)
    {
        int i;
        int retorno = -1;

        int sumaEdades = 0;

        for(i=0; i<tamanioArray; i++)
        {
            if(tamanioArray > 0 && array1 != NULL && resultado != NULL)
            {
                retorno = 0;
                sumaEdades = sumaEdades + array1[i];
            }

            *resultado = (float)sumaEdades / tamanioArray;
        }
        return retorno;
    }
///////////////////////////////////////////////////////////////////////////
/***********************************************************
 * \brief FUNCION ENCUENTRA EL PRIMER MAYOR SUELDO EXISTENTE
 *
 * \param
 * \param array2
 *
 * \return ( 0) = OK
 *         (-1) = ERROR, NO SE PROCESO INFORMACION
 */
    int buscarMayorFloat(float* array2, int tamanioArray, float* resultado)
    {
        int i;
        int retorno = -1;
        float mayorFloat;


        if(tamanioArray > 0 && array2 != NULL && resultado != NULL)
        {
            retorno = 0;

            for(i=0; i<tamanioArray; i++)
            {
                mayorFloat = array2[i];

                if(array2[i] > mayorFloat)
                {
                    mayorFloat = array2[i];
                }
            }
            *resultado = mayorFloat;
        }
        return retorno;
    }
///////////////////////////////////////////////////////////////////////////
/***********************************************************
 * \brief FUNCION QUE MODIFICA UN REGISTRO
 *
 * \param
 * \param array2
 *
 * \return ( 0) = SE MODIFICO REGISTRO CORRECTAMENTE
 *         (-1) = UNO DE LOS DATOS SE INGRESO DE MANERA INCORRECTA
 *         (-2) = LOS DOS DATOS FUERON INGRESADOS DE MANERA INCORRECTA
 */
    int modificarRegistro(int* array1, float* array2, int tamanioArray, char solicitud0[], char solicitud1[], char solicitud2[])
    {
        char retorno = 0;
        int aux;
        int nuevaEdad;
        float nuevoSueldo;

        printf("%s", solicitud0);
        scanf("%d", &aux);

        printf("%s", solicitud1);
        scanf("%d", &nuevaEdad);
        if(nuevaEdad > 0 && nuevaEdad < 120 && nuevaEdad && NULL && array1 != NULL)
        {
            *array1[aux] = nuevaEdad; //PREGUNTAR COMO APUNTAR AL ELEMENTO DEL ARRAY Y MODIFICARLO
        }
        else
            retorno--;

        printf("%s", solicitud2);
        if(nuevoSueldo > 0 && nuevoSueldo < 120 && nuevoSueldo && NULL && array2 != NULL)
        {
            *array2[aux] = nuevoSueldo; //PREGUNTAR COMO APUNTAR AL ELEMENTO DEL ARRAY Y MODIFICARLO
        }
        else
            retorno--;

        return retorno;
    }
///////////////////////////////////////////////////////////////////////////
/***********************************************************
 * \brief FUNCION QUE ELIMINA UN REGISTRO
 *
 * \param
 * \param array2
 *
 * \return ( 0) = SE ELIMINO REGISTRO CON EXITO
 *         (-1) = UNO DE LOS DATOS SE INGRESO DE MANERA INCORRECTA
 *         (-2) = LOS DOS DATOS FUERON INGRESADOS DE MANERA INCORRECTA
 */
int eliminarRegistro(int* array1, float* array2, int tamanioArray, char solicitud0[], char solicitud1[], char solicitud2[])
{
    char retorno = 0;
    int aux;

    printf("%s", solicitud0);
    scanf("%d", &aux);

    if(aux < 0 && aux > tamanioArray && aux && NULL && array1 != NULL && array2 != NULL)
    {
        *array1[aux] = -1; //PREGUNTAR COMO APUNTAR AL ELEMENTO DEL ARRAY Y MODIFICARLO Y COMO CARGAR UN VALOR PARA QUE NO SEA CALCULADO EN EL PROMEDIO O MAYOR Y MENOR
        *array2[aux] = -1; //PREGUNTAR COMO APUNTAR AL ELEMENTO DEL ARRAY Y MODIFICARLO Y COMO CARGAR UN VALOR PARA QUE NO SEA CALCULADO EN EL PROMEDIO O MAYOR Y MENOR
    }
    else
        retorno--;

    return retorno;
}

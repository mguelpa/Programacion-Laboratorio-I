#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "validar.h"

/******************************************************************
 * \brief   Funcion utilizada para inicialzara el array estructura
 *
 * \param   1. Puntero al array a inicializar.
 * \param   2. Limite del array.
 */
    void pers_initArray (sPersona* arrayAlumnos, int length)
    {
        int i;
        for(i=0; i<length; i++)
        {
            arrayAlumnos[i].status = STATUS_EMPTY;
            strcpy(arrayAlumnos[i].nombre, "0000");
            strcpy(arrayAlumnos[i].dni, "0000");
            arrayAlumnos[i].edad = 0;
        }
    }

/******************************************************************
 * \brief   Funcion utilizada para buscar un espacio vacio donde
 *          cargar datos (STATUS_EMPTY)
 *
 * \param   1. Puntero al array donde buscar.
 * \param   2. Limite del array.
 *
 * \return  (-1) =  no se encontraron espacios libres.
 * \return  ( i) =  indice del espacio libre (STATUS_EMPTY).
 */
    int pers_searchEmptySlot (sPersona* arrayAlumnos, int length)
    {
        int retorno = -1;
        int i;

        for(i=0; i<length; i++)
        {
            if(arrayAlumnos[i].status == STATUS_EMPTY)
            {
                retorno = i;
                break;
            }
        }
        return retorno;
    }

/******************************************************************
 * \brief   Funcion utilizada para loguear una persona en el array
 *          busca un lugar vacio, carga los datos, da opcion a
 *          continuar cargando simpre que no se supere el tamaño.
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 * \return  (-2) =  supero tamaño del array.
 *
 */
    int pers_logPerson (sPersona* arrayAlumnos, int length, char* errorMsg)
    {
        int retorno = 0;
        char respuesta = 'n';
        int i = 0;
        int index;

        do
        {
            index = pers_searchEmptySlot(arrayAlumnos, MAX_ALUMNOS);
            if(index == -1){
                printf(errorMsg);
                respuesta = 'n';
                retorno = -2;
            }
            else{
                if(pers_loadData(arrayAlumnos, index) == 0)
                {
                    printf("carga exitosa.\n");
                    retorno = 0;
                }
                else
                {
                    printf("Error en la carga.\n --> No se han guardado datos <-- \a\n");
                    retorno = -1;
                    break;
                }
                continuar("desea continuar cargando datos? S/N: ", "Ha ingresado una opcion no valida. intente nuevamente: ", 3, &respuesta);
                i++;
            }

        }
        while(respuesta != 'n' && i < length);
        if(i >= length){
                printf(errorMsg);
                retorno = -2;
            }

        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para copiar los datos luego de validar
 *          si las validaciones son correctas copia los datos del
 *          buffer en el array de lo contario no se modifica el array.
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la validacion no se modifica
 *                  espacio.
 */
    int pers_loadData (sPersona* arrayAlumnos, int index)
    {
        int retorno = -1;
        char auxNombre[MAX_CHARS_NOMBRE];
        char auxEdad[MAX_CHARS_EDAD];
        char auxDNI[MAX_CHARS_DNI];


        if(val_getName(auxNombre, MAX_CHARS_NOMBRE, "Ingrese el nombre: ", "Ha ingresado caracteres no validos.\n", MAX_INTENTOS_REINGRESOS) == 0)
        {
            if(val_getAge(auxEdad, MAX_CHARS_EDAD, "Ingrese la edad: ", "Ha ingresado caracteres no validos.\n", "La edad debe estar comprendida entre 1 y 150.\n", MAX_INTENTOS_REINGRESOS) == 0)
            {
                if(val_getUnsignedInt(auxDNI, MAX_CHARS_DNI, "Ingrese el Nro de DNI: ", "Ha ingresado caracteres no validos.\n", MAX_INTENTOS_REINGRESOS) == 0)
                {
                    strncpy(arrayAlumnos[index].dni, auxDNI, MAX_CHARS_DNI);
                    strncpy(arrayAlumnos[index].nombre, auxNombre, MAX_CHARS_NOMBRE);
                    arrayAlumnos[index].edad = atoi(auxEdad);
                    arrayAlumnos[index].status = STATUS_LOADED;
                    retorno = 0;
                }
            }
        }
        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para buscar un DNI en el array, si lo
 *          encuentra lo borra, si no existe devuelve error.
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  Carga de datos exitosa.
 * \return  (-1) =  El documento ingresado no existe en el array.
 *
 */
    int pers_deletePerson (sPersona* arrayAlumnos, char* errorMsg)
    {
        int retorno = -1;

        char auxDNI[MAX_CHARS_DNI];
        int dni;
        int index;

        if(val_getUnsignedInt(auxDNI, MAX_CHARS_DNI, "ingrese el DNI de la persona que desea borrar: ", "Ha ingresado caracteres no admitidos\n", MAX_INTENTOS_REINGRESOS) == 0)
        {
            dni = atoi(auxDNI);
            index = pers_getIndexById(arrayAlumnos, MAX_ALUMNOS, dni);
            if(index == -1){
                printf(errorMsg);
                retorno = -1;
            }
            else{
                pers_deleteData(arrayAlumnos, index);
                retorno = 0;
            }
        }
        return retorno;
    }

/*********************************************************************
 * \brief   Funcion utilizada para realizar una baja logica de manera
 *          que los datos permanezcan guardados, busca un indice y
 *          cambia el estado por baja (STATUS_DOWN)
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. indice del dato a dar de baja.
 */
    void pers_deleteData (sPersona* arrayAlumnos, int index)
    {
        arrayAlumnos[index].status = STATUS_DOWN;
    }

/********************************************************************
 * \brief   Funcion utilizada para imprimir el listado ordenado por
 *          nombre siempre que haya datos cargados en el array
 *          (STATUS_LOADED), de lo contrario imprime un mensaje error
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  impresion exitosa.
 * \return  (-1) =  aun no se han cargado datos.
 *
 */
    int pers_printList (sPersona* arrayAlumnos, int length)
    {
        int i;
        int retorno;

        if(pers_sortByName(arrayAlumnos, length) == -1){
            printf("Aun no se han cargado datos.\n\n");
            retorno = -1;
        }
        else
        {
            for(i=0; i<length; i++)
            {
                if(arrayAlumnos[i].status == STATUS_LOADED)
                {
                    pers_printData(arrayAlumnos, i);
                }
            }
            retorno = 0;
        }
        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para imprimir cada uno de los campos
 *          cargados.
 *
 * \param   1. Puntero al array a buscar los datos.
 * \param   2. Indice de los datos a imprimir.
 *
 */
    void pers_printData(sPersona* arrayAlumnos, int index)
    {

        printf("---------------------------------------------\n");

        printf("Nombre: %s\n", arrayAlumnos[index].nombre);
        printf("Edad: %d\n", arrayAlumnos[index].edad);
        printf("DNI: %s\n", arrayAlumnos[index].dni);
        //printf("Estado: %d\n\n", arrayAlumnos[index].status);

        printf("---------------------------------------------\n\n");
    }

/********************************************************************
 * \brief   Funcion utilizada para ordenar por nombre alfaeticamente
 *          el array.
 *
 * \param   1. Puntero al array a ordenar.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  ordenamiento de por lo menos un dato.
 * \return  (-1) =  aun no se han cargado datos.
 *
 */
    int pers_sortByName (sPersona* arrayAlumnos, int length)
    {
        int i;
        int j;
        int retorno;
        sPersona auxiliar;

        for(i=0; i<length-1; i++)
        {
            if(arrayAlumnos[i].status == STATUS_LOADED){
               retorno = 0;
                for(j= i+1; j<length; j++)
                {
                    if(strcmp(arrayAlumnos[i].nombre, arrayAlumnos[j].nombre) > 0)
                    {
                        auxiliar = arrayAlumnos[i];
                        arrayAlumnos[i] = arrayAlumnos[j];
                        arrayAlumnos[j] = auxiliar;
                        retorno = 0;
                    }
                }
            }
            else{
                retorno = -1;
            }
        }
        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para graficar menores de 18, de 19 - 35
 *          y mayores de 35.
 *
 * \param   1. Puntero al array a buscar datos.
 * \param   2. Limite del array.
 *
 * \return  ( 0) =  ordenamiento de por lo menos un dato.
 * \return  (-1) =  aun no se han cargado datos.
 *
 */
    int pers_chartArray (sPersona* arrayAlumnos, int length)
    {
        int retorno = -1;

        int minus18;
        int f19to35;
        int plus35;

        if(pers_sortByAge (arrayAlumnos, length, &minus18, &f19to35, &plus35) == -1){
            printf("Aun no se han cargado datos.");
        }
        else{
            pers_plotData (minus18, f19to35, plus35);
            retorno = 0;
        }
        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para contar menores de 18, de 19 - 35
 *          y mayores de 35.
 *
 * \param   1. Puntero al array a buscar datos.
 * \param   2. Limite del array.
 * \param   3. valorA a graficar (en este caso representa <18).
 * \param   4. valorB a graficar (en este caso representa 19 - 35).
 * \param   5. valorC a graficar (en este caso representa >35).
 *
 * \return  ( 0) =  obtencion de por lo menos un dato cargado.
 * \return  (-1) =  aun no se han cargado datos.
 *
 */
    int pers_sortByAge (sPersona* arrayAlumnos, int length, int* valueA, int* valueB, int* valueC)
    {
        int retorno = -1;

        int minus18 = 0;
        int f19to35 = 0;
        int plus35  = 0;

        int i;


        for(i=0; i< length; i++)
        {
            if(arrayAlumnos[i].edad < 18 && arrayAlumnos[i].status == STATUS_LOADED)
            {
                minus18++;
                retorno = 0;
            }
            else if(arrayAlumnos[i].edad > 35 && arrayAlumnos[i].status == STATUS_LOADED)
            {
                plus35++;
                retorno = 0;
            }
            else if(arrayAlumnos[i].status == STATUS_LOADED)
            {
                f19to35++;
                retorno = 0;
            }

        }


        *valueA = minus18;
        *valueB = f19to35;
        *valueC = plus35;

        return retorno;
    }

/********************************************************************
 * \brief   Funcion utilizada para imprimir por pantalla un grafico.
 *
 * \param   1. valorA a graficar (en este caso representa <18).
 * \param   2. valorB a graficar (en este caso representa 19 - 35).
 * \param   3. valorC a graficar (en este caso representa >35).
 *
 */
    void pers_plotData (int valueA, int valueB, int valueC)
    {
    // valueA = +18
    // valueB =  19 - 35
    // valueC = +35

        int max;

        int i;
        int flag = 0;



        if(valueA > valueB && valueA > valueC)
        {
            max = valueA;
        }
        else if(valueB > valueA && valueB > valueC)
        {
            max = valueB;
        }
        else
        {
            max = valueC;
        }






    for(i = max; i > 0; i--)
    {

        printf("%02d|", i);


        if(i <= valueA)
        {
            printf(" *");
        }

        if(i <= valueB)
        {
            flag = 1;
            printf("\t   *");
        }

        if(i <= valueC)
        {

            if(flag == 0)
                printf("\t\t   * ");

            if(flag == 1)
                printf("\t   * ");
        }

        printf("\n");
    }
    printf("--+-------------------\n");
    printf("  |<18| |19-35|  |>35|");
}
//____________________________________________________________________________________________

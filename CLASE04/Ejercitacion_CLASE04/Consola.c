#include <stdio.h>
#include <stdlib.h>
/*****************************************************************
 * \brief FUNCION QUE SOLICITA UN NUMERO AL USUARIO
 *
 * \param   1er solicitud
 * \param   2do mensaje de error
 * \param   3er pregunta para verificar usuario
 * \param   4to cantidad de reintentos
 * \param   5to puntero de variable a cargar valor
 * \param   6to rango: minimo valor permitido
 * \param   7mo rango: maximo valor permitido
 *
 * \return (0) SIN ERRORES (-1) USUARIO DECIDE SALIR DEL PROGRAMA
 */
    int obtenerNumero(char solicitud[], char mensajeError[], char pregunta[], int reintentos, float* valor, float minimo, float maximo)
    {
        int i;
        int contador = 0;
        int retorno;
        float aux;
        char respuesta = 's';

        printf("%s", solicitud);
        scanf("%f", &aux);

        do
        {
            for(i=0; i<reintentos; i++)
            {
                if(aux < minimo || aux > maximo)
                {
                    printf("%s", mensajeError);
                    scanf("%f", &aux);

                    contador++;
                    retorno = -1;
                }
            }
            if(aux < minimo || aux > maximo)
            {
                printf("%s", pregunta);
                scanf("%s", &respuesta);
                if (respuesta == 'n')
                {
                    return -1;
                }
            }
            else
            {
                respuesta = 'n';
            }
        }
        while(respuesta != 'n');

        *valor = aux;
        retorno = 0;


        return retorno;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNCION CONSOLA SIMPLE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int obtenerNumero(char solicitud[], char mensajeError[], int reintentos, float* valor, float minimo, float maximo)
//{
//    int contador = 0;
//    int retorno;
//    float aux;
//
//    printf("%s", solicitud);
//    scanf("%f", &aux);
//
//    do
//    {
//        if(aux < minimo || aux > maximo)
//        {
//            retorno = -1;
//            printf("%s", mensajeError)
//        }
//        else
//        {
//            *valor = aux;
//            retorno = 0;
//        }
//        contador++;
//
//    }while(contador < reintentos)
//
//    return retorno;
//}

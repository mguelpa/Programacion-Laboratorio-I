#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

    #define MAX_REINGRESOS 3
    #define MAX_CHARS_HTML 2048
    #define MAX_CHARS_TITULOS 50
    #define MAX_CHARS_GENEROS 50
    #define MAX_CHARS_DESCRIPCIONES 500
    #define MAX_CHARS_LINKS 500

    #define MOVIE_EMPTY 0
    #define MOVIE_TAKEN 1
    #define MOVIE_DOWN -1

    typedef struct{
        int emov_slot;
        int emov_code;

        char titulo[MAX_CHARS_TITULOS +1];
        char genero[MAX_CHARS_GENEROS +1];
        int  duracion;
        char descripcion[MAX_CHARS_DESCRIPCIONES +1];
        int  puntaje;
        char linkImagen[MAX_CHARS_LINKS +1]; //2KBytes length
    }EMovie;

#endif // MOVIES_H_INCLUDED

/********************************************************
 * \brief  funcion utilizada para inicializar el array.
 *
 * \param    1. se pasa nombre del array a inicializar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = inicializacion correcta.
 * \return (-1) = error en la inicializacion.
 */
    int emov_arrayInit (EMovie* nombre_array, int length);


/**********************************************************
 * \brief  funcion utilizada para imprimir datos cargados.
 *
 * \param    1. se pasa nombre del array a inicializar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = impresion correcta.
 * \return (-1) = error en la impresion.
 */
    int emov_arrayRecords (EMovie* nombre_array, int length);


/**************************************************************
 * \brief  funcion utilizada para buscar un indice en el array.
 *
 * \param    1. se pasa nombre del array a buscar.
 * \param    2. se pasa el limite del array.
 * \param    3. se pasa el buffer donde guardar el codigo generado.
 *
 * \return ( 0) = codigo generado correctamente.
 * \return (-1) = error en la generacion del codigo.
 */
    int emov_searchIndexByID (EMovie* nombre_array, int length, int* code);


/************************************************************
 * \brief  funcion utilizada para cargar los datos validados.
 *
 * \param    1. se pasa nombre del array a cargar.
 * \param    2. se pasa indice donde cargar.
 * \param    3. se pasa el buffer de datos validos.
 * \param    4. se pasa el buffer de datos validos.
 * \param    5. se pasa el buffer de datos validos.
 * \param    6. se pasa el buffer de datos validos.
 * \param    7. se pasa el buffer de datos validos.
 * \param    8. se pasa el buffer de datos validos.
 *
 * \return ( 0) = carga correcta.
 * \return (-1) = error en la carga.
 */
    int emov_loadData (EMovie* nombre_array, int index, char* data1, char* data2, int* data3, char* data4, int* data5, char* data6);


/**************************************************************
 * \brief  funcion utilizada para modificar los datos validados.
 *
 * \param    1. se pasa nombre del array a modificar.
 * \param    2. se pasa indice donde cargar.
 * \param    3. se pasa el buffer de datos validos.
 * \param    4. se pasa el buffer de datos validos.
 * \param    5. se pasa el buffer de datos validos.
 * \param    6. se pasa el buffer de datos validos.
 * \param    7. se pasa el buffer de datos validos.
 * \param    8. se pasa el buffer de datos validos.
 *
 * \return ( 0) = carga correcta.
 * \return (-1) = error en la carga.
 */
    int emov_modifyData (EMovie* nombre_array, int index, char* data1, char* data2, int* data3, char* data4, int* data5, char* data6);


/*********************************************************************
 * \brief   Funcion utilizada para realizar una baja logica de manera
 *          que los datos permanezcan guardados, busca un indice y
 *          cambia el estado por baja (STATUS_DOWN)
 *
 * \param   1. Puntero al array a modificar.
 * \param   2. indice del dato a dar de baja.
 */
    int emov_downData (EMovie* nombre_array, int index);


/********************************************************
 * \brief  funcion utilizada para harcodear datos en el
 *          array de manera que sea mas facil testear.
 *
 * \param    1. se pasa nombre del array a inicializar.
 */
    void emov_cheater (EMovie* nombre_array1);






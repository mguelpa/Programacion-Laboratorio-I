#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED

    #define MAX_REINGRESOS 3

    #define MAX_CHARS_NOMBRES 20
    #define MAX_CHARS_DESCRIPCIONES 50
    #define MAX_CHARS_DIRECCIONES 50

    #define SLT_EMPTY 0
    #define SLT_LOADED 1
    #define SLT_DOWN -1

    #define SCR_FREE  0
    #define SCR_TAKEN 1

    #define TYPE_LCD 1
    #define TYPE_LED 2

    typedef struct{
        int scr_slot;
        int scr_id;
        int scr_type;
        int scr_availability;

        char name[MAX_CHARS_NOMBRES+1];
        char review[MAX_CHARS_DESCRIPCIONES+1];
        char address[MAX_CHARS_DIRECCIONES+1];
        float price;
    }sScreen;

#endif // PANTALLAS_H_INCLUDED

/**
 * \brief   Funcion utilizada para inicializar el array.
 *
 * \param   1. puntero al array a inicializar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  inicializacion exitosa.
 * \return  (-1) =  error en la inicializacion.   
 */
int scr_arrayInit (sScreen* nombre_array, int length);




/**
 * \brief   Funcion utilizada para ver los datos cargados en array.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  inicializacion exitosa.
 * \return  (-1) =  error en la inicializacion.   
 */
int scr_arrayRecords (sScreen* nombre_array, int length);




/**
 * \brief   Funcion utilizada para dar de baja un espacio del array estructura.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_downData (sScreen* nombre_array, int index);




/**
 * \brief   Funcion utilizada para dar de baja un espacio del array estructura.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_loadData (sScreen* nombre_array, int length, int* data1, char* data2, char* data3, char* data4, float* data5);




/**
 * \brief   Funcion utilizada para modificar los datos luego de haber sido cargados.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 * \param   3. datos validos a cargar en estructura.
 * \param   4. datos validos a cargar en estructura.
 * \param   5. datos validos a cargar en estructura.
 * \param   6. datos validos a cargar en estructura.
 * \param   7. datos validos a cargar en estructura.
 *    
 * \return  ( 0) =  carga correcta.
 * \return  (-1) =  error en la carga de datos.   
 */
int scr_modifyData (sScreen* nombre_array, int length, int data1, char* data2, char* data3, char* data4, float data5);




/**
 * \brief   Funcion utilizada para imprimir los datos.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_printData (sScreen* nombre_array, int index);





/**
 * \brief   Funcion utilizada para dar de baja un espacio del array estructura.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_listScreens (sScreen* nombre_array, int length);




/**
 * \brief   Funcion utilizada para dar de baja un espacio del array estructura.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_searchIndexById (sScreen* nombre_array, int length, int id);




/**
 * \brief   Funcion utilizada para dar de baja un espacio del array estructura.
 *
 * \param   1. puntero al array a buscar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  baja correcta.
 * \return  (-1) =  error en la baja de datos.   
 */
int scr_getData (sScreen* nombre_array, int index, sScreen* dataTarget);

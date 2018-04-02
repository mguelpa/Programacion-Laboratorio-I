#ifndef PUBLICACIONES_H_INCLUDED
#define PUBLICACIONES_H_INCLUDED

    #define MAX_CHARS_CUIT 13 //20
    #define MAX_CHARS_ARCHIVOS 20

    #define ADV_FREE  0
    #define ADV_TAKEN 2
    #define ADV_DOWN -1

    typedef struct{
        int adv_slot;
        int adv_code;

        char clientID[MAX_CHARS_CUIT +1];
        int  scr_code;
        int  adv_lapse;
        char adv_archive[MAX_CHARS_ARCHIVOS +1];
    }sAdvertisement;

#endif // PUBLICACIONES_H_INCLUDED

/**
 * \brief   Funcion utilizada para inicializar el array.
 *
 * \param   1. puntero al array a inicializar.
 * \param   2. limite del array.
 *    
 * \return  ( 0) =  inicializacion exitosa.
 * \return  (-1) =  error en la inicializacion.   
 */
int adv_arrayInit (sAdvertisement* nombre_array, int length);




int adv_arrayRecords (sAdvertisement* nombre_array, int length);
int adv_loadData (sAdvertisement* nombre_array, int length, char* data1, int* data2, int* data3, char* data4);
int adv_modifyData (sAdvertisement* nombre_array, int index, int* data3);
int adv_downData (sAdvertisement* nombre_array, int index);



int adv_searchIndexById (sAdvertisement* nombre_array, int length, char* id);
int adv_getData (sAdvertisement* nombre_array, int index, sAdvertisement* dataTarget);
int adv_searchIndexById2 (sAdvertisement* nombre_array, int length, int id);

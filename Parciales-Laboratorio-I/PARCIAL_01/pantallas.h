#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED

    #define MAX_INTENTOS_REINGRESOS 3
    #define MAX_CHARS_NOMBRES 51
    #define MAX_CHARS_DIRECCIONES 51

    #define TYPE_LCD 0
    #define TYPE_LED 1

    //flag estado slot scr
    #define SCR_EMPTY 0
    #define SCR_TAKEN 1
    #define SCR_DOWN  2

    typedef struct
    {
        int scr_slot;
        int scr_ID;

        int   scr_type;
        char  name[MAX_CHARS_NOMBRES];
        char  adress[MAX_CHARS_DIRECCIONES];
        float price;

    }sScreen;

#endif // PANTALLAS_H_INCLUDED

int scr_arrayInit (sScreen* nombre_array, int length);
int scr_searchIndexById (sScreen* nombre_array, int length, int id);

int scr_loadData (sScreen* nombre_array, int length, int data1, char* data2, char* data3, float data4);
int scr_modifyData (sScreen* nombre_array, int length, int id, int data1, char* data2, char* data3, float data4);
//int scr_downData (sScreen* nombre_array, int id);
//int scr_printData (sScreen* nombre_array, int index);


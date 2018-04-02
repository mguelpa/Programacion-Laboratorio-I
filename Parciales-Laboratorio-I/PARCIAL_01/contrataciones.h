#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

    //flag estado slot contratacion
    #define RENTAL_EMPTY 0
    #define RENTAL_TAKEN 1
    #define RENTAL_ENDED 2

    #define INCIDENT_EMPTY 0
    #define INCIDENT_INCOURSE 1
    #define INCIDENT_SOLVED 2
    #define INCIDENT_UNSOLVED 3

    #define CAUSE_ACV 0
    #define CAUSE_INFARTO 1
    #define CAUSE_GRIPE 2


    typedef struct{
        int rent_slot; //(CALL_EMPTY 0) (CALL_TAKEN 1) (CALL_ENDED 2)
        int rent_ID;
        int screen_ID;

        int screen_status; //(INCIDENT_INCOURSE 1) (INCIDENT_SOLVED 2)
        int incident_cause;
        int incident_startLapse;
        int incident_finalLapse;

    }sRental;

#endif // LLAMADOS_H_INCLUDED

//int scr_arrayInit (sRental* nombre_array, int length);
//int scr_searchIndexById (sRental* nombre_array, int length, int id);
//int call_loadCall (sRental* nombre_array, int length, int asoc_ID, int data1, int data2);
//int call_downCall (sRental* nombre_array, int index, int data1, int data2);
//int call_printData (sRental* nombre_array, int index);

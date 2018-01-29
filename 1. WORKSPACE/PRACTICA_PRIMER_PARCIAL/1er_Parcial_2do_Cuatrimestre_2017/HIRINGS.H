#ifndef HIRINGS_H_INCLUDED
#define HIRINGS_H_INCLUDED

    #define MAX_CHAR_CUIT 13 //20
    #define MAX_CHAR_FILES 20

    #define AD_FREE  0
    #define AD_TAKEN 2
    #define AD_DOWN -1

    typedef struct{
        int ad_advertID;
        int ad_adStatus;


        int ad_clientID;
        int ad_productID;
        int ad_duration;
        char ad_files[MAX_CHAR_FILES +1];
    }Advertisement;

#endif // HIRINGS_H_INCLUDED


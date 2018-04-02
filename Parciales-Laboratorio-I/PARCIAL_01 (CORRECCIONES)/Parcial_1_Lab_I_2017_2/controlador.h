#include "pantallas.h"
#include "publicaciones.h"
#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED



#endif // COMMANDS_H_INCLUDED

int cont_loadScreen (sScreen* nombre_array, int length);
int cont_modifyScreen (sScreen* nombre_array, int length);
int cont_downScreen (sScreen* nombre_array, int length);

int cont_newAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cont_modifyAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cont_deleteAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

int cont_listAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

int cont_listClientsAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cont_billing (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

void cont_cheater (sScreen* nombre_array1, sAdvertisement* nombre_array2);

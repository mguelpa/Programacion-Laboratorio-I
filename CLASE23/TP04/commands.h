#include "pantallas.h"
#include "publicaciones.h"
#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED



#endif // COMMANDS_H_INCLUDED

int cmd_loadScreen (sScreen* nombre_array, int length);
int cmd_modifyScreen (sScreen* nombre_array, int length);
int cmd_downScreen (sScreen* nombre_array, int length);

int cmd_newAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cmd_modifyAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cmd_deleteAd (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

int cmd_listAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

int cmd_listClientsAds (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);
int cmd_billing (sScreen* nombre_array1, int length1, sAdvertisement* nombre_array2, int length2);

void cmd_cheater (sScreen* nombre_array1, sAdvertisement* nombre_array2);

#include "ArrayList.h"

#ifndef _ADS
#define _ADS

    typedef struct
    {
        int advertID;
        int adStatus;
        int clientID;
        int productID;
        int duration;
        char files[MAX_CHAR_FILES];
    } Ads;

#endif// _ADS

Ads* ads_new(int advertID,int adStatus,int clientID,int productID,int duration,char* files);
void ads_delete(Ads* this);
int ads_setAdvertID(Ads* this,int advertID);
int ads_setAdStatus(Ads* this,int adStatus);
int ads_setClientID(Ads* this,int clientID);
int ads_setProductID(Ads* this,int productID);
int ads_setDuration(Ads* this,int duration);
int ads_setFiles(Ads* this,char* files);
int ads_getAdvertID(Ads* this);
int ads_getAdStatus(Ads* this);
int ads_getClientID(Ads* this);
int ads_getProductID(Ads* this);
int ads_getDuration(Ads* this);
char* ads_getFiles(Ads* this);
Ads* ads_findByAdvertID(ArrayList* pArray,int advertID);
Ads* ads_findByAdStatus(ArrayList* pArray,int adStatus);
Ads* ads_findByClientID(ArrayList* pArray,int clientID);
Ads* ads_findByProductID(ArrayList* pArray,int productID);
Ads* ads_findByDuration(ArrayList* pArray,int duration);
Ads* ads_findByFiles(ArrayList* pArray,char* files);

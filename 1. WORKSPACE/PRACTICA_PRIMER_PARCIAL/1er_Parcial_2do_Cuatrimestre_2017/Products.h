#include "ArrayList.h"

#ifndef PRODUCTS_H_INCLUDED
#define PRODUCTS_H_INCLUDED

    #define MAX_CHAR_TITLES 50
    #define MAX_CHAR_DESCRIPTION 50
    #define MAX_CHAR_ADRESS 50

    typedef struct
    {
        int productID;
        int prodStatus;
        char title [MAX_CHAR_TITLES +1];

        int type;
        char description [MAX_CHAR_DESCRIPTION +1];
        char adress [MAX_CHAR_ADRESS +1];
        float price;

    }Product;

#endif // PRODUCTS_H_INCLUDED

#define PRODUCT_ACTIVE 0
#define PRODUCT_INACTIVE -1

Product* prod_new (int id, int status, int type, char* title, char* description, char* adress, float price);
Product* prod_findById (ArrayList* list, int id);
int prod_delete (Product* this);

int prod_setID(Product* this, int id);
int prod_setStatus (Product* this, int status);
int prod_getID (Product* this);
int prod_getStatus (Product* this);

void prod_debugShow (ArrayList* list);
int prod_hardCode (ArrayList* list);






int prod_setTitle(Product* this, char* titulo);
int prod_setType (Product* this, int type);
int prod_setDescription (Product*, char* description);
int prod_setAdress (Product*, char* adress);
int prod_setPrice (Product*, float price);

char* prod_getTitle (Product* this);
int prod_getType (Product* this);
char* prod_getDescription (Product* this);
char* prod_getAdress (Product* this);
float prod_getPrice (Product* this);






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hirings.h"
#include "ArrayList.h"

////////////////////////////////////////////////////////////
// GENERAR ENCONTRAR Y BORRAR ELEMENTO                    //
////////////////////////////////////////////////////////////
Advertisement* ad_new (int advertID, int adStatus, int clientID, int prodID, char* description, char* adress, float price)
{
    Advertisement* newProduct = malloc ( sizeof(Advertisement) );


    prod_setID (newProduct, id);
    prod_setStatus (newProduct, status);

    prod_setType (newProduct, type);
    prod_setTitle (newProduct, title);
    prod_setDescription (newProduct, description);
    prod_setAdress (newProduct, adress);
    prod_setPrice (newProduct, price);

    return newProduct;
}
Product* prod_findById (ArrayList* list, int id)
{
    void* retorno = NULL;
    Product* thisProduct;
    int i;

    for(i=0; i<al_len(list); i++)
    {
        thisProduct = al_get(list, i);
        if( thisProduct->productID == id )
        {
            retorno = thisProduct;
        }
    }
    return retorno;
}
int prod_delete (Product* this)
{
    int retorno = -1;

    if(this != NULL)
    {
        free (this);
        retorno = 0;
    }
    return retorno;
}



////////////////////////////////////////////////////////////
//SETERS                                                  //
////////////////////////////////////////////////////////////
int prod_setID (Product* this, int id)
{
    int retorno = -1;

    if(this != NULL && id > -1)
    {
        this->productID = id;
        retorno = 0;
    }
    return retorno;
}
int prod_setStatus (Product* this, int status)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->prodStatus = status;
        retorno = 0;
    }
    return retorno;
}


int prod_setTitle (Product* this, char* title)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy (this->title, title);
        retorno = 0;
    }
    return retorno;
}
int prod_setType (Product* this, int type)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->type = type;
        retorno = 0;
    }
    return retorno;
}
int prod_setDescription (Product* this, char* description)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy (this->description, description);
        retorno = 0;
    }
    return retorno;
}
int prod_setAdress (Product* this, char* adress)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy (this->adress, adress);
        retorno = 0;
    }
    return retorno;
}
int prod_setPrice (Product* this, float price)
{
    int retorno = -1;

    if(this != NULL)
    {
        this->price = price;
        retorno = 0;
    }
    return retorno;
}



////////////////////////////////////////////////////////////
//GETERS                                                  //
////////////////////////////////////////////////////////////
int prod_getID (Product* this)
{
    return this-> productID;
}
int prod_getStatus (Product* this)
{
    return this-> prodStatus;
}


char* prod_getTitle (Product* this)
{
    return this-> title;
}
int prod_getType (Product* this)
{
    return this-> type;
}
char* prod_getDescription (Product* this)
{
    return this-> description;
}
char* prod_getAdress (Product* this)
{
    return this-> description;
}
float prod_getPrice (Product* this)
{
    return this-> price;
}

////////////////////////////////////////////////////////////
//HARDCODE Y CONTROL DE DATOS                             //
////////////////////////////////////////////////////////////
int prod_hardCode (ArrayList* list)
{
//    int subjectID [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int subStatus [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//
//    char name [10][50] = {"maxi", "ana", "ale", "oski", "viky", "euge", "tomy", "martin", "pablo", "lean"};
//    char surname [10][50] = {"maxi", "ana", "ale", "oski", "viky", "euge", "tomy", "martin", "pablo", "lean"};
//
//    //int  age [10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
//    //char dni [10][MAX_CHARS_DNI] = {"111", "222", "333", "444", "555", "666", "777", "888", "999", "100"};
//    //float salary [10] = {5000, 6000, 7000, 8000, 9000, 1000, 2000, 3000, 4000, 5000};
//
//    Product* newSubject;
//    int i;
//
//    for(i=0; i<10; i++)
//    {
//        newSubject = (Product*)malloc ( sizeof(Product) );
//
//        prod_setID(newSubject, subjectID[i]);
//        prod_setStatus(newSubject, subStatus[i]);
//
//        //sub_setName(newSubject, name[i]);
//        //sub_setSurname(newSubject, surname[i]);
//
//        //sub_setAge(newSubject, age[i]);
//        //sub_setDni(newSubject, dni[i]);
//        //sub_setSalary(newSubject, salary[i]);
//
//        al_add(list, newSubject);
//    }

    return 0;
}
void prod_debugShow (ArrayList* list)
{
    Product* auxiliar;
    int i;

    for(i=0; i<al_len(list); i++)
    {
        auxiliar = al_get (list, i);
        printf("productID: %d\n", prod_getID(auxiliar));
        printf("prodStatus: %d\n", prod_getStatus(auxiliar));
        printf("type: %d\n", prod_getType(auxiliar));
        printf("title: %s\n", prod_getTitle(auxiliar));
        printf("description: %s\n", prod_getDescription(auxiliar));
        printf("adress: %s\n", prod_getAdress(auxiliar));
        printf("price: %.2f\n\n", prod_getPrice(auxiliar));
    }
}

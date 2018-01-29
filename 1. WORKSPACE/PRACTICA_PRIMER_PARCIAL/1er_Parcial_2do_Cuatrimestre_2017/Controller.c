#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"

#include "DataManager.h"
#include "Interface.h"
#include "Products.h"
#include "Subjects.h"

//#include "Inscripciones.h"

//////////////////////////////////////////////////
// FUNCIONES LISTA PRODUCTOS                    //
//////////////////////////////////////////////////
static ArrayList* productList;
static int productNextID = 0;

static int getProductNewID ();
static int setProductNewID (int id);

static int getProductNewID ()
{
    return productNextID++;
}
static int setProductNewID (int id)
{
    productNextID = id;
    return 0;
}
//////////////////////////////////////////////////
// FUNCIONES LISTA SUBJECTS                     //
//////////////////////////////////////////////////
static ArrayList* subjectsList;
static int subjectNextID = 0;

static int getSubjectNewID ();
static int setSubjectNewID (int id);

static int getSubjectNewID ()
{
    return subjectNextID++;
}
static int setSubjectNewID (int id)
{
    subjectNextID = id;
    return 0;
}

//////////////////////////////////////////////////
// INICIALIZACION DE LISTAS Y MENU              //
//////////////////////////////////////////////////
void ctrl_init()
{
    productList = al_newArrayList();
    setProductNewID (dm_readAllProducts(productList) +1);

    subjectsList = al_newArrayList();
    setSubjectNewID (dm_readAllSubjects(subjectsList) +1);



    intr_showMenu();
}

//////////////////////////////////////////////////
// ALTAS                                        //
//////////////////////////////////////////////////
int ctrl_loadProduct (int type, char* title, char* description, char* adress, float price)
{
    Product* auxiliar;
    auxiliar = prod_new (getProductNewID(), PRODUCT_ACTIVE, type, title, description, adress, price);

    al_add (productList, auxiliar);
    dm_saveAllProducts (productList);
    return 0;
}
int ctrl_loadSubject (char* name, char* surname/*,int age,char* dni,float salary*/)
{
    Subject* auxiliar;

    auxiliar = sub_new (getSubjectNewID(), SUB_ACTIVE, name, surname/*, age, dni, salary*/);

    al_add (subjectsList, auxiliar);
    dm_saveAllSubjects (subjectsList);
    return 0;
}
//////////////////////////////////////////////////
// MODIFICACIONES                               //
//////////////////////////////////////////////////
int ctrl_modifyProduct (int id, int type, char* title, char* description, char* adress, float price)
{
    int retorno = -1;
    Product* auxiliar;

    auxiliar = prod_findById (productList, id);

    if(auxiliar != NULL)
    {
        prod_setType(auxiliar, type);
        prod_setTitle(auxiliar, title);
        prod_setDescription(auxiliar, description);
        prod_setAdress(auxiliar, adress);
        prod_setPrice(auxiliar, price);

        dm_saveAllProducts(productList);
        retorno = 0;
    }
    return retorno;
}
int ctrl_modifySubject (int id, char* name, char* surname/*,int age,char* dni,float salary*/)
{
    int retorno = -1;
    Subject* auxiliar;

    auxiliar = sub_findById (subjectsList, id);

    if(auxiliar != NULL)
    {
        sub_setName(auxiliar, name);
        sub_setSurname(auxiliar, surname);

        //sub_setAge(auxiliar, age);
        //sub_setDni(auxiliar, dni);
        //sub_setSalary(auxiliar, salary);

        dm_saveAllSubjects (subjectsList);
    }
    return retorno;
}
//////////////////////////////////////////////////
// BAJAS                                        //
//////////////////////////////////////////////////
int ctrl_deleteProduct (int id)
{
    int retorno = -1;
    Product* auxiliar = prod_findById (productList, id);

    if(auxiliar != NULL)
    {
        prod_setStatus (auxiliar, PRODUCT_INACTIVE);
        dm_saveAllProducts(productList);
    }
    return retorno;
}
int ctrl_deleteSubject (int id)
{
    int retorno = -1;
    Subject* auxiliar = sub_findById (subjectsList, id);

    if(auxiliar != NULL)
    {
        sub_setStatus (auxiliar, SUB_ACTIVE);
        dm_saveAllSubjects (subjectsList);
    }
    return retorno;
}
//////////////////////////////////////////////////
// check data                                   //
//////////////////////////////////////////////////
int ctrl_checkProduct (int id)
{
    int retorno = -1;
    Product* auxiliar;

    auxiliar = prod_findById (productList, id);

    if(auxiliar != NULL && prod_getStatus(auxiliar) == PRODUCT_ACTIVE)
    {
        retorno = 0;
    }
    return retorno;
}
int ctrl_checkSubject (int id)
{
    int retorno = -1;
    Subject* auxiliar;

    auxiliar = sub_findById (subjectsList, id);

    if(auxiliar != NULL && sub_getStatus(auxiliar) == SUB_ACTIVE)
    {
        retorno = 0;
    }
    return retorno;
}
void ctrl_debugShowAll()
{
    prod_debugShow (productList);
    sub_debugShow (subjectsList);
}

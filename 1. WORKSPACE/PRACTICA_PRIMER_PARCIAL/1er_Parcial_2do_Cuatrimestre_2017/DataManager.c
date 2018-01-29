#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "DataManager.h"

#include "Products.h"
#include "Subjects.h"
//#include "Inscripciones.h"


//////////////////////////////////////////////////
// GENERAR ARCHIVOS                             //
//////////////////////////////////////////////////
int dm_saveAllProducts (ArrayList* productList)
{
    int i, retorno = -1;
    void* pProduct = NULL;

    FILE* productsBin = fopen (ARCHIVO_PRODUCTOS, "wb");


    if( productsBin != NULL )
    {
        for(i=0; i<al_len (productList); i++)
        {
            pProduct = al_get (productList, i);

            fwrite (pProduct, sizeof (Product), 1, productsBin);

            retorno = 0;
        }
    }
    fclose (productsBin);
    return retorno;
}
int dm_saveAllSubjects (ArrayList* listaSubjects)
{
    int i, retorno = -1;
    void* pSubject = NULL;

    FILE* subjectsBin = fopen (ARCHIVO_SUBJECTS, "wb");


    if( subjectsBin != NULL )
    {
        for(i=0; i<al_len (listaSubjects); i++)
        {
            pSubject = al_get (listaSubjects, i);

            fwrite (pSubject, sizeof (Subject), 1, subjectsBin);

            retorno = 0;
        }
    }
    fclose (subjectsBin);
    return retorno;
}
//////////////////////////////////////////////////
// LEER ARCHIVOS                                //
//////////////////////////////////////////////////
int dm_readAllProducts (ArrayList* productList)
{
    int retorno = -1;
    int maxId = 0;

    Product auxiliar;
    Product* pProduct = NULL;

    FILE* productsBin = fopen (ARCHIVO_PRODUCTOS, "rb");

    if( productsBin != NULL )
    {
        do
        {
            if( fread (&auxiliar, sizeof(Product), 1, productsBin) == 1)
            {
                pProduct = prod_new (auxiliar.productID, auxiliar.prodStatus, auxiliar.type, auxiliar.title, auxiliar.description, auxiliar.adress, auxiliar.price);

                al_add (productList, pProduct);

                if(auxiliar.productID > maxId)
                {
                    maxId = auxiliar.productID;
                }
                retorno = maxId;
            }

        }
        while( !feof(productsBin) );
        fclose (productsBin);
    }
    return retorno;
}
int dm_readAllSubjects (ArrayList* listaSubjects)
{
    int retorno = -1;
    int maxId = 0;

    Subject auxiliar;
    Subject* pSubject = NULL;

    FILE* subjectsBin = fopen (ARCHIVO_SUBJECTS, "rb");

    if( subjectsBin != NULL )
    {
        do
        {
            if( fread (&auxiliar, sizeof(Subject), 1, subjectsBin) == 1)
            {
                pSubject = sub_new (auxiliar.subjectID, auxiliar.subStatus, auxiliar.name, auxiliar.surname/*, auxiliar.age, auxiliar.dni, auxiliar.salary*/);

                al_add (listaSubjects, pSubject);

                if( auxiliar.subjectID > maxId )
                {
                    maxId = auxiliar.subjectID;
                }
                retorno = maxId;
            }

        }
        while( !feof(subjectsBin) );

        fclose (subjectsBin);
    }
    return retorno;
}

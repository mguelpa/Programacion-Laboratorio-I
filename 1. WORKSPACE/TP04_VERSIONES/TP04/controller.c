#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs.h"
#include "ArrayList.h"
#include "affiliate.h"
#include "controller.h"



static int id = 0;

static int asoc_idGen (int* prevId);

////////////////////////////////////////////////////////////////////////////////
static int asoc_idGen(int* prevId)
{
    *prevId += 1;
    return *prevId;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_newAffiliate ( ArrayList* list )
{
    int retorno = -1;

    sAsociado* nuevoSocio = affi_newElement();


    if( ctrl_validateData(nuevoSocio) == 0 )
    {
        al_add(list, nuevoSocio);
        nuevoSocio = affi_newElement();
        retorno = 0;
    }
    else
    {
        free(nuevoSocio);
        printf("no se gaurdaron los datos ingresados");
        retorno = -1;
    }

    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_validateData(sAsociado* pElement)
{
    int retorno = -1;

    //Buffers para validar datos obtenidos
    char  auxData1[MAX_CHARS_NOMBRES +1]; //char  nombre;
    char  auxData2[MAX_CHARS_NOMBRES +1]; //char  apellido;
    int   auxData3;                       //int   edad;
    char  auxData4[MAX_CHARS_DNI +1];     //char  dni;

    if (pElement != NULL )
    {
        /* obtencion de nombre */
        if (input_getAnumericStr ("NOMBRE: ", "\t** El nombre debe estar compuesto de 5 a 50 caracteres. **\n\n", 3, 2, MAX_CHARS_NOMBRES, auxData1) == 0)
        {
            /* obtencion de apellido */
            if (input_getAnumericStr ("APELLIDO: ", "\t** El nombre debe estar compuesto de 5 a 50 caracteres. **\n\n", 3, 2, MAX_CHARS_NOMBRES, auxData2) == 0)
            {
                /* obtencion de edad */
                if (input_getInt ("EDAD: ", "\t** la edad debe estar comprendida entre 13 y 68 años. **\n\n", 3, 13, 68, &auxData3) == 0)
                {
                    /* obtencion de dni */
                    if (input_getAnumericStr ("DNI: ", "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", 3, 2, MAX_CHARS_DNI, auxData4) == 0)
                    {
                        if ( ctrl_setData (pElement, auxData1, auxData2, &auxData3, auxData4) == 0 )
                        {
                            retorno  = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_setData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4)
{
    int retorno = -1;

    if(pElement != NULL)
    {
        retorno = asoc_idGen(&id);
        if(retorno > 0)
        {
            (pElement)->status = SLT_LOAD;
            (pElement)->id     = retorno;

            strcpy ((pElement)->nombre,   data1);
            strcpy ((pElement)->apellido, data2);
                    (pElement)->edad   = *data3;
            strcpy ((pElement)->dni,      data4);
            retorno = 0;
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_modifyAffiliate ( ArrayList* list )
{
    int retorno = -1;
    int idBox = 0;
    sAsociado* aux = NULL;

    if (list != NULL)
    {   /* solicito id*/
        if (input_getInt ("ingrese el id del cliente: ", "\t** el id de la pantalla debe ser mayor a 0 **\n\n", 3, 0, 1000000, &idBox) == 0)
        {
            /* busco id */
            aux = ctrl_getElementById( list, idBox );
            if (aux != NULL)
            {
                if( ctrl_modifyData(aux) == 0 )
                {
                    retorno = 0;
                }
                else
                {
                    printf("no se gaurdaron los datos ingresados");
                    retorno = -1;
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_modifyData (sAsociado* pElement)
{
    int retorno = -1;

    //Buffers para validar datos obtenidos
    char  auxData1[MAX_CHARS_NOMBRES +1]; //char  nombre;
    char  auxData2[MAX_CHARS_NOMBRES +1]; //char  apellido;
    int   auxData3;                       //int   edad;
    char  auxData4[MAX_CHARS_DNI +1];     //char  dni;


    if (pElement != NULL)
    {
        /* obtencion de nombre */
        if (input_getAnumericStr ("NOMBRE: ", "\t** El nombre debe estar compuesto de 5 a 50 caracteres. **\n\n", 3, 2, MAX_CHARS_NOMBRES, auxData1) == 0)
        {
            /* obtencion de apellido */
            if (input_getAnumericStr ("APELLIDO: ", "\t** El nombre debe estar compuesto de 5 a 50 caracteres. **\n\n", 3, 2, MAX_CHARS_NOMBRES, auxData2) == 0)
            {
                /* obtencion de edad */
                if (input_getInt ("EDAD: ", "\t** la edad debe estar comprendida entre 13 y 68 años. **\n\n", 3, 13, 68, &auxData3) == 0)
                {
                    /* obtencion de dni */
                    if (input_getAnumericStr ("DNI: ", "\t** la direccion debe estar comprendida de 5 a 20 caracteres. **\n\n", 3, 2, MAX_CHARS_DNI, auxData4) == 0)
                    {
                        if ( ctrl_resetData (pElement, auxData1, auxData2, &auxData3, auxData4) == 0 )
                        {
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_resetData (sAsociado* pElement, char* data1, char* data2, int* data3, char* data4)
{
    int retorno = -1;

    if(pElement != NULL)
    {
        strcpy ((pElement)->nombre,   data1);
        strcpy ((pElement)->apellido, data2);
                (pElement)->edad   = *data3;
        strcpy ((pElement)->dni,      data4);
        retorno = 0;
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
void ctrl_debugShow(sAsociado* pElement)
{
    if(pElement != NULL)
    {
        printf("status:   %d\n", pElement->status);
        printf("id:       %d\n", pElement->id);

        printf("nombre:   %s\n", pElement->nombre);
        printf("apellido: %s\n", pElement->apellido);
        printf("edad:     %d\n", pElement->edad);
        printf("dni:      %s\n", pElement->dni);
    }
}
////////////////////////////////////////////////////////////////////////////////
sAsociado* ctrl_getElementById (ArrayList* list, unsigned int id)
{
    sAsociado* returnAux = NULL;
    int i;

    if(list != NULL)
    {
        for(i=0; i<list->size; i++)
        {
            returnAux = *(list->pElements+i);
            if( returnAux->id == id)
            {
                return returnAux;
            }
        }
        returnAux = NULL;
    }
    return returnAux;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_downAffiliate (ArrayList* list)
{
    int retorno = -1;
    int idBox = 0;
    //sAsociado* aux = NULL;
    int index;

    if(list != NULL)
    {
        retorno = input_getInt("Ingrese el id de la pantalla: ", "\t** el id debe ser mayor a 0 **\n", 3, 1, 99999, &idBox);
        if(retorno == 0)
        {
            index = ctrl_searchIndexById( *(list->pElements), list->size, idBox);
            if (index > -1)
            {
                al_remove(list, index);
            }
            else
            {
                printf("El ID ingresado no corresponde a ningun asociado\n");
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////
int ctrl_searchIndexById (sAsociado* list, int length, int id)
{
    int index = -1;

    if(list != NULL)
    {
        for(index = 0; index < length; index++)
        {
            if(list->status == SLT_LOAD)
            {
                if( (list->id+index) == id)
                {
                    return index;
                }
            }
        }
    }
    return index;
}
////////////////////////////////////////////////////////////////////////////////

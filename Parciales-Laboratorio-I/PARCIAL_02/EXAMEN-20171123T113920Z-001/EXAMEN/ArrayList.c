#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp (ArrayList* this);
int expand (ArrayList* this, int index);
int contract (ArrayList* this, int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//__________________________


ArrayList* al_newArrayList (void)
{
    ArrayList* retorno = NULL;

    ArrayList* this;
    void* pElements;

    this  = (ArrayList *)malloc ( sizeof(ArrayList) );

    if( this != NULL )
    {

        pElements  = malloc( sizeof(void*) * AL_INITIAL_VALUE );


        if(pElements != NULL)
        {
            this->pElements       = pElements;
            this->reservedSize    = AL_INITIAL_VALUE;
            this->size            = 0;

            this->add             = al_add;
            this->len             = al_len;
            this->contains        = al_contains;

            this->set             = al_set;
            this->remove          = al_remove;
            this->clear           = al_clear;

            this->get             = al_get;
            this->clone           = al_clone;
            this->push            = al_push;

            this->isEmpty         = al_isEmpty;
            this->indexOf         = al_indexOf;
            this->pop             = al_pop;

            this->subList         = al_subList;
            this->containsAll     = al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort            = al_sort;

            retorno = this;
        }
        else
        {
            free(this);
        }
    }
    return retorno;
}
ArrayList* al_clone (ArrayList* this)
{
    ArrayList* returnAux = NULL;

    if(this != NULL)
    {
        returnAux = this;
    }
    return returnAux;
}
ArrayList* al_subList (ArrayList* this, int from, int to)
{
    void* returnAux = NULL;
    int i;

    if( this != NULL && this->pElements != NULL)
    {
        if(from > -1 && from < this->size && to > 0 && to <= this->size && from < to)
        {
            returnAux = al_newArrayList();
            for(i = from; i < to; i++)
            {
                if (al_get(this, i) != NULL)
                {
                    al_add( returnAux, al_get(this, i) );
                }
            }
        }
    }
    return returnAux;
}
int al_deleteArrayList (ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->size == 0)
        {
            returnAux = 0;
            free(this);
        }
        else
        {
            returnAux = 1;
            free(this);
        }
    }
    return returnAux;
}



int al_add ( ArrayList* this, void* pElements )
{
    int returnAux = -1;

    if( this != NULL && pElements != NULL )
    {
        if(this->size ==  this->reservedSize)
        {
            if ( resizeUp(this) == -1 )
            {
                return -1;
            }
        }

        *( (this->pElements) + (this->size) ) = pElements;
        this->size++;

        returnAux = 0;
    }
    return returnAux;
}
int al_push (ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL)
    {
        if(index > -1 && index <= this->size)
        {
            if(index < this->size-1)
            {
                expand(this, index);
                *(this->pElements+index) = pElement;
                returnAux  = 0;
            }
            else
            {
                al_add(this, pElement);
                returnAux = 0;
            }
        }
    }
    return returnAux;
}
int al_set (ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL && pElement != NULL)
    {
        if(index >= 0 && index < this->size)
        {
            *(this->pElements + index) = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


int al_remove (ArrayList* this, int index)
{
    int returnAux = -1;

    if(this != NULL && index > -1 && index < this->size)
    {
        if(contract(this, index) == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}
int al_clear (ArrayList* this)
{
    int returnAux = -1;
    void* adress;

    if (this != NULL && this->size > 0)
    {
        adress = (void**) realloc( this->pElements, sizeof(void*) * AL_INITIAL_VALUE);
        if (adress != NULL )
        {
            free(this->pElements);
            this->pElements = adress;
            returnAux = 0;
        }
        this->size = 0;
        this->reservedSize = AL_INITIAL_VALUE;
    }
    return returnAux;
}


int al_indexOf (ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            if(*(this->pElements+i) == pElement )
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}
void* al_get (ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < this->size)
    {
        returnAux = *(this->pElements+index);
    }
    return returnAux;
}
void* al_pop (ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index > -1 && index <= this->size)
    {
        returnAux = *(this->pElements+index);
        contract(this, index);
    }
    return returnAux;
}



int al_isEmpty (ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->size > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int al_contains (ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->size; i++)
        {
            if(pElement == *(this->pElements+i))
            {
                returnAux = 1;
                break;
            }
            returnAux = 0;
        }
    }
    return returnAux;
}
int al_containsAll (ArrayList* this, ArrayList* this2)
{
    int returnAux = -1;
    int i, j;
    int flag = 0;

    if(this != NULL && this2 != NULL)
    {
        for(i = 0; i<al_len(this2); i++)
        {
            for(j = 0; j<al_len(this); j++)
            {
                if( *(this2->pElements+i) == *(this->pElements+j))
                {
                    flag++;
                }
            }
        }
        if (flag == this2->size)
        {
            returnAux = 1;
        }
        else if (flag>0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}
int al_len (ArrayList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}



int resizeUp (ArrayList* this)
{
    int returnAux = -1;
    void* auxiliar;

    if(this != NULL)
    {
        auxiliar = realloc( this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));
        if (auxiliar != NULL)
        {
            this->pElements = auxiliar;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
    }
    return returnAux;
}
int resizeDown (ArrayList* this)
{
    int returnAux = -1;
    void* auxList = NULL;
    int resize;

    if(this != NULL)
    {
        resize = (this->reservedSize - this->size);
        auxList = realloc (this->pElements, sizeof(void*) * resize);

        if(auxList != NULL)
        {
            this->size = resize;
            this->pElements = auxList;
            returnAux = 1;
        }
    }
    return returnAux;
}
int expand (ArrayList* this, int index)
{
    int returnAux = -1;
    int i;

    if (this != NULL && index >= 0 && index < this->size)
    {
        if ( this->size == this->reservedSize)
        {
            resizeUp(this);
        }

        this->size += 1;

        for(i = this->size-2; i>=index; i--)
        {
            *(this->pElements+i+1) = *(this->pElements+i);
        }

        returnAux = 0;
    }
    return returnAux;
}
int contract (ArrayList* this, int index)
{
    int returnAux = -1;
    int i;

    if (this != NULL && index >= 0 && index < this->size)
    {
        for (i = index; i < this->size; i++)
        {
            *(this->pElements+i) = *(this->pElements+i+1);
        }
        this->size--;

        if ((this->reservedSize - this->size) > AL_INCREMENT)
        {
            resizeDown(this);
        }
        returnAux = 0;
    }
    return returnAux;
}



int al_sort (ArrayList* this, int (*pFunc)(void*, void*), int order)
{
    int returnAux = -1;
    int i, j;

    void* auxpElement;


    if(this != NULL && (*pFunc) != NULL)
    {
        if(order == 1)
            order = -1;
        else if (order == 0)
            order = 1;
        else
            return -1;

        for(i=1; i<al_len(this); i++)
        {
            auxpElement = *(this->pElements+i);
            j = i-1;

            while(j >= 0 && order == pFunc( auxpElement, *(this->pElements+j)))
            {
                *(this->pElements+j+1) = *(this->pElements+j);
                j--;
            }
            *(this->pElements+j+1) = auxpElement;
        }
        returnAux = 0;
    }
    return returnAux;
}
void al_map (ArrayList* this, void (*func)(void*))
{
    int i;
    void* pElement;
    for(i=0; i<al_len(this); i++)
    {
        pElement = al_get(this, i);
        func(pElement);
    }
}

//////////////////////////////////////////////////////////////////

int al_debugShow (ArrayList* this)
{
    int i;
    for(i=0; i < this->size; i++)
    {
        printf("%p numero %d de %d\n", *(this->pElements+i), i, this->size);
    }
    return 0;
}

ArrayList* al_filter (ArrayList* listIn, int(*functionFilter)(void*))
{
    int i;
    void* pElement;
    ArrayList* listOut = NULL;

    listOut = al_newArrayList();

    if(listOut != NULL)
    {
        for(i=0; i<al_len(listIn); i++)
        {
            pElement = al_get(listIn, i);

            if(functionFilter(pElement) == 1)
            {
                al_add(listOut, pElement);
            }
        }
    }
    return listOut;
}

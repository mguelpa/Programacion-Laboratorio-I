#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/**********************************************************************
 * \brief   Allocate a new arrayList with AL_INITIAL_VALUE elements.
 *
 * \param   void
 *
 * \return  ArrayList* Return (NULL) if Error [can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
    ArrayList* al_newArrayList(void)
    {
        ArrayList* retorno = NULL;





        ArrayList* this;
             void* pElements;


        this  = (ArrayList *)malloc ( sizeof(ArrayList) );
        // puntero a la nueva variable �lista�



        if( this != NULL )
        {

            pElements  = malloc( sizeof(void*) * AL_INITIAL_VALUE );
            // puntero a la �lista� contenida
            // dentro de la nueva varible (lista)

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
////////////////////////////////////////////////////////////////////////////////

/************************************************************************
 * \brief  Add an element to arrayList and if is
 *         nessesary resize the array
 *
 * \param  pList ArrayList* Pointer to arrayList
 * \param  pElement   void* Pointer to element
 *
 * \return int Return ( 0) if Ok
 *                    (-1) if Error [pList or pElement are NULL pointer]
 */
    int al_add( ArrayList* this, void* pElements )
    {
        int returnAux = -1;


        if( this != NULL && pElements != NULL )
        {

        //puntero apuntando a un elemento
            *( (this->pElements) + (this->size) ) = pElements;
            //  this->pElements    [this->size]   = pElements;

            this->size++;
            returnAux = 0;


            if(this->size ==  this->reservedSize)
            {
                if ( resizeUp(this) == -1 )
                {
                    returnAux = -1;
                }
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/***********************************************
 * \brief  Delete arrayList
 *
 * \param  pList ArrayList* Pointer to arrayList
 *
 * \return ( 0) if Ok
 *         (-1) if Error [pList is NULL pointer]
 *
 */
    int al_deleteArrayList( ArrayList* this )
    {
        int returnAux = -1;



        if( this != NULL )
        {
            if( this->size == 0 )
            {
                returnAux = 0;
                free( this->pElements );
            }
            else
            {
                returnAux = 1;
                free( this->pElements );
                //free( this );
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/***********************************************
 * \brief  Delete arrayList
 * \param  pList ArrayList* Pointer to arrayList
 * \return length of array
 *         (-1) if Error [pList is NULL pointer]
 *
 */
    int al_len(ArrayList* this)
    {
        int returnAux = -1;

        if(this != NULL)
        {
            returnAux = this->size;
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////


/***********************************************************
 * \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < this->size)
    {
        returnAux = *(this->pElements+index);
    }
    return returnAux;
}


/***************************************************************
 * \brief  Find if pList contains at least one element pElement
 *
 * \param  pList ArrayList* Pointer to arrayList
 * \param  pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one
 *                         element pElement
 */
    int al_contains(ArrayList* this, void* pElement)
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
////////////////////////////////////////////////////////////////////////////////


/***********************************************************************
 * \brief  Set a element in pList at index position
 * \param  pList ArrayList* Pointer to arrayList
 * \param  index int Index of the element
 * \param  pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
    int al_set(ArrayList* this, int index, void* pElement)
    {
        int returnAux = -1;

        if (this != NULL && pElement != NULL)
        {
            if(index >= 0 && index < this->size)
            {
                *(this->pElements+ index) = pElement;
                returnAux = 0;
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/**************************************************
 *\brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
    int al_remove(ArrayList* this, int index)
    {
        int returnAux = -1;

        if(this != NULL && index > -1)
        {
            returnAux = 0;
            free(*(this->pElements+index));
            //free(this->pElements+index);
            this->size--;

        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/**********************************************************
 * \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
    int al_clear(ArrayList* this)
    {
        int returnAux = -1;

        if(this != NULL && this->size > 0)
        {
            free(this->pElements);
            this->size = 0;
            returnAux = 0;
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/***********************************************************************
 * \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
    ArrayList* al_clone(ArrayList* this)
    {
        ArrayList* returnAux = NULL;
        int i;
        void* aux;

        if(this != NULL)
        {
            returnAux = al_newArrayList();

            if(returnAux != NULL)
            {
                for(i=0; i<al_len(this); i++)
                {
                    aux = al_get(this, i);
                    al_add(returnAux, aux);
                }
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/************************************************************
 * \brief  Inserts the element at the specified position
 * \param  pList ArrayList* Pointer to arrayList
 * \param  index int Index of the element
 * \param  pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
    int al_push(ArrayList* this, int index, void* pElement)
    {
        int returnAux = -1;
        int i;

        if(this != NULL && pElement != NULL)
        {
            if(index > -1 && index <= this->size)
            {
                if(this->size ==  this->reservedSize)
                {
                    if ( resizeUp(this) == -1 )
                    {
                        return -1;
                    }
                }

                for(i = this->size-2; i>=index; i--)
                {
                    *(this->pElements+i+1) = *(this->pElements+i);
                }

                *(this->pElements+index) = pElement;
                  this->size++;
                returnAux = 0;
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////


/****************************************************************************
 * \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
    int al_indexOf(ArrayList* this, void* pElement)
    {
        int returnAux = -1;
        int i;

        if(this != NULL && pElement != NULL)
        {
            for(i=0; i<al_len(this); i++)
            {
                if( *(this->pElements+i) == pElement )
                {
                    returnAux = i;
                    break;
                }
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
    int al_isEmpty(ArrayList* this)
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
////////////////////////////////////////////////////////////////////////////////



/*****************************************************************************
 * \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
    void* al_pop(ArrayList* this, int index)
    {
        void* returnAux = NULL;

        if(this != NULL && index > -1 && index < al_len(this))
        {
            returnAux = *(this->pElements+index);
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
 * \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
    ArrayList* al_subList(ArrayList* this, int from, int to)
    {
        void* returnAux = NULL;


        ArrayList* auxiliar;
        int newSize;
        int i, j;


        if( this != NULL && this->pElements != NULL)
        {
            if(from > -1 && from <= this->size && to > -1 && to <= this->size && from <= to)
            {
                newSize = ((from - to) * -1) +1;
                auxiliar = al_newArrayList();

                j = from;
                for(i=0; i<=newSize; i++)
                {
                    if(auxiliar->size == auxiliar->reservedSize)
                    {
                        if ( resizeUp(auxiliar) == -1 )
                        {
                            return NULL;
                        }
                    }

                    *(auxiliar->pElements+i) = *(this->pElements+j);
                    auxiliar->size++;
                    j++;
                }
                returnAux = auxiliar;
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////

/***************************************************************************
 * \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */

    int al_containsAll(ArrayList* this, ArrayList* this2)
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
////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
 * \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - ( 0) if ok
 */
    int al_sort(ArrayList* this, int (*pFunc)(void*, void*), int order)
    {
        int returnAux = -1;
        int i, j;

        void* auxpElement;

        if(this != NULL && (*pFunc) != NULL)
        {
            for(i=0; i<size; i++)
            {
                (*pFunc)((this->pElements+i), (this->pElements+i), order)

                auxpElement = (this->pElements+i);
            }


            returnAux = 0;
        }

        return returnAux;
    }


/****************************************************************************************
 * \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - ( 0) if ok
 */
    int resizeUp(ArrayList* this)
    {
        int returnAux = -1;
        void* auxiliar;
        if(this != NULL)
        {
            auxiliar = realloc(this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));
            if (auxiliar != NULL)
            {
                this->pElements = auxiliar;
                this->reservedSize = this->reservedSize + AL_INCREMENT;
                returnAux = 0;
            }
        }
        return returnAux;
    }
////////////////////////////////////////////////////////////////////////////////











/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;

    return returnAux;
}



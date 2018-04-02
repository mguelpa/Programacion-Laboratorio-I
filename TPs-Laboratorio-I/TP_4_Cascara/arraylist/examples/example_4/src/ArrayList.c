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
//__________________________


////////////////////////////////////////////////////////////////////////////////
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
 * \param  pList ArrayList* Pointer to arrayList
 * \param  index int Index of the element
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
////////////////////////////////////////////////////////////////////////////////
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
                *(this->pElements + index) = pElement;
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

        if(this != NULL && index > -1 && index < this->size)
        {
            if(contract(this, index) == 0)
            {
                returnAux = 0;
            }
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

        if(this != NULL)
        {
            returnAux = this;
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
                if(*(this->pElements+i) == pElement )
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
        if(this != NULL && index > -1 && index <= this->size)
        {
            returnAux = *(this->pElements+index);
            contract(this, index);
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

////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////
/****************************************************************************************
 * \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - ( 0) if ok
 */
    int resizeDown(ArrayList* this)
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
////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************
 * \brief  Expand an array list
 * \param  pList ArrayList* Pointer to arrayList
 * \param  index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
    int expand(ArrayList* this, int index)
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
////////////////////////////////////////////////////////////////////////////////
/****************************************************************************
 * \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
    int contract(ArrayList* this, int index)
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
////////////////////////////////////////////////////////////////////////////////
void al_debugShow(ArrayList* this)
{
    int i;
    for(i=0; i < this->size; i++)
    {
        printf("%p numero %d de %d\n", *(this->pElements+i), i, this->size);
    }
}
////////////////////////////////////////////////////////////////////////////////

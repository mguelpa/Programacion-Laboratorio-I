#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED
typedef struct
{
    int size;
    int r_size;
    void *pElements;
}ArrayList;
#endif // ARRAYLIST_H_INCLUDED
ArrayList* al_new(void);
int al_add(ArrayList* pArray, void *element);

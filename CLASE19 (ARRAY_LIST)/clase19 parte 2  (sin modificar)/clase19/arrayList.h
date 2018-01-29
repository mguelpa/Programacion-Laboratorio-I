#ifndef __ARRAYLIST
#define __ARRAYLIST
typedef struct
{
    int size;
    int rSize;
    void **pElements;
}ArrayList;
#endif // __ARRAYLIST

#define INIT_SIZE 10

ArrayList* al_new(void);
int al_add(ArrayList* pArray,void *element);
void al_debugShow(ArrayList* pArray);




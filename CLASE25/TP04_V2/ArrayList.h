#ifndef __ARRAYLIST
#define __ARRAYLIST

    struct ArrayList{

        void** pElements;
        int size;
        int reservedSize;

        int     (*add)();
        int     (*len)();
        int     (*contains)();
        int     (*set)();
        int     (*remove)();
        int     (*clear)();
        int     (*push)();
        int     (*indexOf)();
        int     (*isEmpty)();
        void*   (*get)();
        void*   (*pop)();
        int     (*containsAll)();
        int     (*sort)();
        struct ArrayList* (*clone)();
        struct ArrayList* (*subList)();
        int     (*deleteArrayList)();

    }typedef ArrayList;

#endif

  // Private function
    int resizeUp (ArrayList* this);
    int expand (ArrayList* this,int index);
    int contract (ArrayList* this,int index);
//___________________________________________

int al_indexOf (ArrayList* this, void* pElement);
int al_isEmpty (ArrayList* this);


ArrayList* al_newArrayList (void);
ArrayList* al_clone (ArrayList* this);
ArrayList* al_subList (ArrayList* this, int from, int to);



int al_add (ArrayList* this, void* pElement);
int al_deleteArrayList (ArrayList* this);
int al_clear (ArrayList* this);




void* al_get (ArrayList* this, int index);
int al_set (ArrayList* this, int index, void* pElement);
int al_remove (ArrayList* this, int index);


void* al_pop (ArrayList* this, int index);
int al_push (ArrayList* this, int index, void* pElement);
int al_sort (ArrayList* this, int (*pFunc)(void*, void*), int order);



int al_len (ArrayList* this);
int al_contains (ArrayList* this, void* pElement);
int al_containsAll (ArrayList* this, ArrayList* this2);



//int resizeUp (ArrayList* this);
//int expand (ArrayList* this, int index);
//int contract (ArrayList* this, int index);
void al_debugShow(ArrayList* this);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"

////////////////////////////////////////
static ArrayList* listaX;
static int proximoIdX=0;
static int getNewIdX();
static int setNewIdX(int id);

void cont_init()
{
    listaX = al_newArrayList();
    setNewIdX(dm_readAllX(listaX) + 1);
    vista_mostrarMenu();
}



////////////////////////////////////////
// para cada entidad                  //
////////////////////////////////////////
static int getNewIdX()
{
    return proximoIdX++;
}
static int setNewIdX(int id)
{
    proximoIdX = id;
    return 0;
}

int cont_altaX (char* a,char* b,int c)
{
    return 0;
}
int cont_bajaX (int id)
{
    return 0;
}
int cont_modificarX (int id, char* a,char* b,int c)
{
    return 0;
}


int cont_listarX ()
{
    //vista_mostrarX(nominaX);
    return 0;
}
int cont_ordenarX ()
{
    return 0;
}
////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

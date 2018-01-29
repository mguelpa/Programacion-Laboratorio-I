#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Servicio.h"
#include "DataManager.h"

int dm_saveAllClientes(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pSocio=al_get(pArrayClientes,i);
            fwrite(pSocio,sizeof(Cliente),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
    return retorno;
}

int dm_readAllClientes(ArrayList* pArrayClientes)
{
    int retorno=-1;
    Cliente auxSocio;
    int maxId=0;
    Cliente* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_CLIENTES,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Cliente),1,pArchivoSocios)==1)
            {
                pSocio=cliente_new(auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.id,auxSocio.estado);
                al_add(pArrayClientes,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
    return retorno;
}


int dm_saveAllServicios(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;
    FILE* pArchivoSocios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pSocio=al_get(pArrayServicios,i);
            fwrite(pSocio,sizeof(Servicio),1,pArchivoSocios);
            retorno=0;
        }
    }
    fclose(pArchivoSocios);
    return retorno;
}


int dm_readAllServicios(ArrayList* pArrayServicios)
{
    int retorno=-1;
    Servicio auxServicio;
    int maxId=0;
    Servicio* pServ=NULL;
    FILE* pF=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pF!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicio),1,pF)==1)
            {
                pServ=serv_new(auxServicio.id);

                al_add(pArrayServicios,pServ);
                if(auxServicio.id>maxId)
                {
                    maxId=auxServicio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pF));
        fclose(pF);
    }
    return retorno;
}
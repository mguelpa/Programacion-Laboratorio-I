#include <stdio.h>
#include <stdlib.h>

#include "Validaciones.h"
#include "Inputs.h"
#include "ArrayList.h"
#include "DataManager.h"

#include "Cliente.h"
#include "Alquiler.h"

int dm_saveAllX(ArrayList* pArrayX)
{
    //int i;
    int retorno=-1;
 /*
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoSocios!=NULL)
    {
        for(i=0;i<al_len(pArraySocios);i++)
        {
            pSocio=al_get(pArraySocios,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoSocios);
            retorno=0;
        }

    }
    fclose(pArchivoSocios);
*/

/*

 int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* pEmployees=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            pEmployees=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", employee_getId(pEmployees),employee_getName(pEmployees), employee_getLastName(pEmployees), employee_getAge(pEmployees), employee_getType(pEmployees));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;


*/
    return retorno;
}
int dm_readAllX(ArrayList* pArrayX)
{
    int retorno=-1;
 /*
    Socio auxSocio;
    int maxId=0;
    Socio* pSocio=NULL;
    FILE* pArchivoSocios=fopen(ARCHIVO_SOCIOS,"rb");

    if(pArchivoSocios!=NULL)
    {
        do{
            if(fread(&auxSocio,sizeof(Socio),1,pArchivoSocios)==1)
            {
                pSocio=socio_new(auxSocio.id,auxSocio.nombre,auxSocio.apellido,auxSocio.dni,auxSocio.estado);
                al_add(pArraySocios,pSocio);
                if(auxSocio.id>maxId)
                {
                    maxId=auxSocio.id;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoSocios));
        fclose(pArchivoSocios);
    }
*/
/*
    FILE *pFile;
	Employee* auxEmployee;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("data.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarDescripcion(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarInt(var5)!=-1)
				{
					auxEmployee=employee_new(atoi(var1), var2, var3,atoi(var4), atoi(var5));
					al_add(nominaEmployees, auxEmployee);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;

*/
    return retorno;
}



int dm_saveAllClientes(ArrayList* listaClientes)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("data.csv","w");
    void* pCliente=NULL;




    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,dni,status\n");
        for(i=0;i<al_len(listaClientes);i++)
        {
            pCliente=al_get(listaClientes,i);
            fprintf(pFile, "%d,%s,%s,%s,%d\n", cliente_getIdCliente(pCliente), cliente_getNombre(pCliente), cliente_getApellido(pCliente), cliente_getDni(pCliente), cliente_getEstado(pCliente));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
int dm_readAllClientes(ArrayList* listaClientes)
{
    FILE *pFile;
	Cliente* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("data.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarInt(var1)!=-1 &&
                   val_validarString(var2) != -1 &&
                   val_validarString(var3) != -1 &&
                   val_validarInt(var4) != -1 &&
                   val_validarInt(var5) != -1)
				{
					auxiliar = cliente_new(atoi(var1), var2, var3, var4, atoi(var5));

					al_add(listaClientes, auxiliar);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}





int dm_saveAllAlquileres(ArrayList* listaAlquileres)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("alquileres.csv","w");
    void* pAlquiler=NULL;




    if(pFile!=NULL)
    {
		fprintf(pFile,"idCliente,idEquipo,tiempoReal,tiempoEstimado,idAlquiler, estado\n");

        for(i=0;i<al_len(listaAlquileres);i++)
        {
            pAlquiler=al_get(listaAlquileres,i);
            fprintf(pFile, "%d,%d,%d,%d,%d,%d\n", alquiler_getIdCliente(pAlquiler),
                                                  alquiler_getIdEquipo(pAlquiler),
                                                  alquiler_getTiempoReal(pAlquiler),
                                                  alquiler_getTiempoEstimado(pAlquiler),
                                                  alquiler_getIdAlquiler(pAlquiler),
                                                  alquiler_getEstado(pAlquiler));
            retorno=0;
        }
    }
    fclose(pFile);
    return retorno;
}
int dm_readAllAlquileres(ArrayList* listaAlquileres)
{
    FILE *pFile;
	Alquiler* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50];

    pFile = fopen("alquileres.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6) >0)
			{
				if(valid_verifyStrNumbr(var1) == 0 &&
                   valid_verifyStrNumbr(var2) == 0 &&
                   valid_verifyStrNumbr(var3) == 0 &&
                   valid_verifyStrNumbr(var4) == 0 &&
                   valid_verifyStrNumbr(var5) == 0 &&
                   valid_verifyStrNumbr(var6) == 0)
				{
					auxiliar = alquiler_new(atoi(var1), atoi(var2), atoi(var3), atoi(var4), atoi(var5), atoi(var6));

					al_add(listaAlquileres, auxiliar);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}


#include <stdio.h>
#include <stdlib.h>

#include "ArrayList.h"
#include "DataManager.h"

int dm_saveAllX(ArrayList* pListaX)
{
    int retorno=-1;
/*
    int i;

    FILE* pArchivoX=fopen(ARCHIVO_SOCIOS,"wb");
    void* pSocio=NULL;
    if(pArchivoX!=NULL)
    {
        for(i=0;i<al_len(pListaX);i++)
        {
            pSocio=al_get(pListaX,i);
            fwrite(pSocio,sizeof(Socio),1,pArchivoX);
            retorno=0;
        }

    }
    fclose(pArchivoX);
*/

/*

    int i;
    int retorno=-1;
    FILE* pFile=fopen("out.csv","w");
    void* auxiliar=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(list);i++)
        {
            auxiliar=al_get(list,i);
            fprintf(pFile, "%d,%s,%s,%d,%d\n", employee_get(auxiliar), employee_get(auxiliar), employee_get(auxiliar));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;


*/
    return retorno;
}
int dm_readAllX(ArrayList* pListaX)
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

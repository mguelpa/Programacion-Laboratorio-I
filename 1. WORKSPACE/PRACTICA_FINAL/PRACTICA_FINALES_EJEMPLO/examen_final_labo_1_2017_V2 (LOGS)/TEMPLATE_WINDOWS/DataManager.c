#include <stdio.h>
#include <stdlib.h>

#include "Validaciones.h"
#include "Inputs.h"


#include "ArrayList.h"
#include "DataManager.h"

#include "LogEntry.h"
#include "Service.h"


int dm_saveAllX(ArrayList* pArrayX)
{
    int retorno=-1;
/*
    int i;

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




int dm_saveAllLogEntry(ArrayList* pArrayLogEntry)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("ARCHIVO_1.txt","w");

    void* LogEntry=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"date,time,serviceID,gravedad,msg\n");
        for(i=0;i<al_len(pArrayLogEntry);i++)
        {
            LogEntry=al_get(pArrayLogEntry,i);
            fprintf(pFile, "%s,%s,%d,%d,%s\n", logEntry_getDate(LogEntry),logEntry_getTime(LogEntry),logEntry_getServiceID(LogEntry),logEntry_getGravedad(LogEntry),logEntry_getMsg(LogEntry));
            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
int dm_readAllLogEntry(ArrayList* pArrayLogEntry)
{
    int retorno=-1;
    FILE *pFile;
	LogEntry* auxiliar;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("ARCHIVO_1.txt","r");

	if(pFile!=NULL)
    {
		//fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,serviceID,gravedad,msg);
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
//				if(valid_verifyStrNumbr(serviceID)!=-1 &&
//                   valid_verifyStrNumbr(gravedad)!=-1 &&
//                   valid_verifyString(msg)!=-1)
//				{
					auxiliar=logEntry_new(var1,var2,atoi(var3),atoi(var4),var5);
					al_add(pArrayLogEntry, auxiliar);
					retorno=0;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);

	}
    return retorno;
}


int dm_saveAllService(ArrayList* pArrayService)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("ARCHIVO_2.txt","w");
    void* auxiliar=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,age,type\n");
        for(i=0;i<al_len(pArrayService);i++)
        {
            auxiliar=al_get(pArrayService,i);
            fprintf(pFile, "%d,%s,%s\n", service_getId(auxiliar),service_getName(auxiliar),service_getEmail(auxiliar));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
int dm_readAllService(ArrayList* pArrayService)
{
    FILE *pFile;
	Service* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50];

    pFile = fopen("ARCHIVO_2.txt","r");

	if(pFile!=NULL)
    {
		//fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3);
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3) >0)
			{
//				if(val_validarInt(var1)!=-1 &&
//                   valid(var2)!=-1 &&
//                   val_validarDescripcion(var3)!=-1)
//				{
					auxiliar=service_new(atoi(var1), var2, var3);
					al_add(pArrayService, auxiliar);
					retorno=0;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);




	}
	return retorno;
}


int dm_saveErrorMsg(LogEntry* auxiliar, Service* auxiliar2)
{
    int retorno=-1;

    FILE* pFile=fopen("errors.txt","a");
    if(pFile!=NULL)
    {
        //Fecha Hora Nombre servicio Mensaje de error E-mail soporte
        fprintf(pFile, "%s;%s;%s;%s;%s\n", logEntry_getDate(auxiliar), logEntry_getTime(auxiliar), service_getName(auxiliar2), logEntry_getMsg(auxiliar), service_getEmail(auxiliar2));
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

int dm_saveWarnings(LogEntry* auxiliar, Service* auxiliar2)
{
    int retorno=-1;

    FILE* pFile=fopen("warnings.txt","a");
    if(pFile!=NULL)
    {
        fprintf(pFile, "%s;%s;%s;%s;%s\n", logEntry_getDate(auxiliar), logEntry_getTime(auxiliar), service_getName(auxiliar2), logEntry_getMsg(auxiliar), service_getEmail(auxiliar2));
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

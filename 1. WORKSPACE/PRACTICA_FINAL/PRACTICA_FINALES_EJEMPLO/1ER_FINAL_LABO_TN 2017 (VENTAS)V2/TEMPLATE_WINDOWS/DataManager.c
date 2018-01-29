#include <stdio.h>
#include <stdlib.h>

#include "inputs.h"
#include "ArrayList.h"
#include "DataManager.h"

#include "Cliente.h"
#include "Venta.h"

int dm_saveAllClientes(ArrayList* listaCliente)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("clientes.txt","w");
    void* pCliente=NULL;




    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,dni,status\n");
        for(i=0;i<al_len(listaCliente);i++)
        {
            pCliente=al_get(listaCliente,i);
            fprintf(pFile, "%d,%s,%s,%s,%d\n", cliente_getClientID(pCliente), cliente_getNombre(pCliente), cliente_getApellido(pCliente), cliente_getDni(pCliente), cliente_getClientStatus(pCliente));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
int dm_readAllClientes(ArrayList* listaCliente)
{
    FILE *pFile;
	Cliente* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("clientes.txt","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
//				if(valid_verifyStrNumbr(var1)!=-1 &&
//                   valid_verifyStrNumbr(var2) != -1 &&
//                   valid_verifyString(var3) != -1 &&
//                   valid_verifyString(var4) != -1 &&
//                   valid_verifyStrNumbr(var5) != -1)
//				{
					auxiliar = cliente_new(atoi(var1), atoi(var5), var2, var3, var4);

					al_add(listaCliente, auxiliar);
					retorno=0;
//				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}

int dm_saveAllVentas (ArrayList* listaVenta)
{
    int i;
    int retorno=-1;

    FILE* pFile=fopen("ventas.txt","w");
    void* pVenta=NULL;




    if(pFile!=NULL)
    {
		fprintf(pFile,"ventaID,ventaStatus,clientID,productID,cantidad\n");

        for(i=0;i<al_len(listaVenta);i++)
        {
            pVenta=al_get(listaVenta,i);
            fprintf(pFile, "%d,%d,%d,%d,%d\n", venta_getVentaID(pVenta), venta_getVentaStatus(pVenta), venta_getClientID(pVenta), venta_getProductID(pVenta), venta_getCantidad(pVenta));
            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}
int dm_readAllVentas (ArrayList* listaVenta)
{
    FILE *pFile;
	Venta* auxiliar;
	int retorno=-1;

    char var1[50],var2[50],var3[50],var4[50],var5[50];

    pFile = fopen("ventas.txt","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(valid_verifyStrNumbr(var1)!=-1 &&
                   valid_verifyStrNumbr(var2)!=-1 &&
                   valid_verifyStrNumbr(var3)!=-1 &&
                   valid_verifyStrNumbr(var4)!=-1 &&
                   valid_verifyStrNumbr(var5)!=-1)
				{
					auxiliar = venta_new(atoi(var1), atoi(var2), atoi(var3), atoi(var4), atoi(var5));
					al_add(listaVenta, auxiliar);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
	return retorno;
}

int dm_genrarArchivoInforme (ArrayList* listaVenta, ArrayList* listaCliente)
{
    int i, j;
    float decimal = 0.5;
    int retorno=-1;

    FILE* pFile=fopen("informe.txt","w");
    void* pVenta=NULL;
    void* pCliente=NULL;

    if(pFile!=NULL)
    {
        fprintf(pFile,"ID_venta\tnombre_cliente\tapellido_cliente\tdni_cliente\tcodigo_producto\tmonto_facturado\n");

        for(i=0; i<al_len(listaCliente); i++)
        {
            pCliente=al_get(listaCliente,i);
            if(pCliente!=NULL && cliente_getClientStatus(pCliente) == CLIENTE_ESTADO_COMPRA)
            {

                for(j=0; j<al_len(listaVenta); j++)
                {
                    pVenta = al_get(listaVenta, j);
                    if(venta_getClientID(pVenta) == cliente_getClientID(pCliente))
                    {
                        fprintf(pFile, "%d\t\t%s\t\t%s\t\t\t%s\t%d\t\t%.2f\n", venta_getVentaID(pVenta),cliente_getNombre(pCliente),cliente_getApellido(pCliente),cliente_getDni(pCliente),venta_getProductID(pVenta),decimal);
                    }
                }
            }
        }
        retorno=0;

    }
    fclose(pFile);

    return retorno;
}

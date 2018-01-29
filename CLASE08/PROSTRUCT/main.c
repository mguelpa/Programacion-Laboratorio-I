#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTPROD 5

#define LEN_NOM 50
#define LEN_DES 200


typedef struct
{
    char nombre[LEN_NOM];
    char descripcion[LEN_DES];
    float precio;
    int isEmpty;
}sProducto;

int InicializarArray(sProducto *Producto)
{
    int retorno=-1;
    int i;
    for(i=0;i<CANTPROD;i++)
    {
        Producto[i].isEmpty=-1;
    }
    retorno=0;
    return retorno;
}

int ValidarFloat(char *flotante){return 0;}

int CargaStruct(char *SolicitudC1,char *SolicitudC2,char *SolicitudC3,sProducto *Producto,int rango)
{
    char flotante[10];
    printf("CARGA LISTA\n\n");
    int i;
    char Seguir='S';
    do
    {
        for(i=0;i<rango;i++)
        {
        printf(SolicitudC1);
        fgets(Producto[i].nombre,LEN_NOM,stdin);
        Producto[i].nombre[LEN_NOM-1]='\n';
        printf(SolicitudC2);
        fgets(Producto[i].descripcion,LEN_DES,stdin);
        Producto[i].descripcion[LEN_DES-1]='\n';
        printf(SolicitudC3);
        fgets(flotante,10,stdin);
        if(ValidarFloat(flotante)==0)
        {
            Producto[i].precio=atof(flotante);
        }
        Producto[i].isEmpty=1;//cargado
        if(MensajeYESNO("DESEA CONTINUAR CARGANDO??")==1) //SI LA RESPUESTA ES NEGATIVA
        {
            Seguir='N';
        }
        //system("cls");
        }
    }while(Seguir=='S');

    return 0;
}

int MostrarProductos(sProducto *Prod,int rango)
{
    int i;
    for(i=0;i<rango;i++)
    {
        printf("PRODUCTO %d\n",i+1);
        printf("NOMBRE: %s\n",Prod[i].nombre);
        printf("DESCRIPCION: %s\n",Prod[i].descripcion);
        printf("PRECIO: $%.2f\n\n",Prod[i].precio);
    }
    return 0;
}

int LengtCadena(char *Cadena)
{
    int a=0;
    while(Cadena[a]!='\0')
    {
        a++;
    }
    return a;
}

int MensajeYESNO(char Mensaje[])
{
    char Respuesta;
    int len = LengtCadena(Mensaje);

    if(Mensaje[len-1]=='?')
    {
        printf("\n\n%s S/N",Mensaje);
    }
    else
    {
        printf("\n\n%s? S/N",Mensaje);
    }
    scanf(" %s",&Respuesta);
    if((Respuesta=='S') || (Respuesta=='s'))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    sProducto Prod[CANTPROD];
    InicializarArray(Prod);
    CargaStruct("NOMBRE PRODUCTO: ","DESCRIPCION: ","PRECIO: ",Prod,CANTPROD);
    printf("*MOSTRAMOS LISTA CARGADA*\n\n");
    MostrarProductos(Prod,CANTPROD);
    return 0;
}

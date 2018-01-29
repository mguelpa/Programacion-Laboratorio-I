#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***************************************************************.
 *                        GET FLOAT
 *\brief  Solicita un numero al usuario y devuelve el resultado
 *\param  "mensaje" es el mensaje a ser mostrado
 *\return es el numero ingresado por el usuario
 **************************************************************/
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);

    return auxiliar;

}
/***************************************************************
 *                       GET INT                               *
 *\brief  Solicita un numero al usuario y devuelve el resultado
 *\param  "mensaje" es el mensaje a ser mostrado
 *\return es el numero ingresado por el usuario
 **************************************************************/
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    return auxiliar;
}
/***************************************************************
 *                       GET CHAR                              *
 *\brief  Solicita un numero al usuario y devuelve el resultado
 *\param  "mensaje" es el mensaje a ser mostrado
 *\return es el numero ingresado por el usuario
 **************************************************************/
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);

    fflush(stdin); //limpiar "standard input" (teclado)

    scanf("%c", &auxiliar);

    return auxiliar;
}
/*********************************************************************************
 *                       GENERADOR NUMERO ALEATORIO                              *
 *\brief  Genera un numero aleatorio
 *\param  desde un numero aleatorio minimo
 *\param  hasta un numero aleatorio maximo
 *\param  iniciar indica si se trata del primer numero solicitado, 1 indica que si
 *\return retorna el numero aleatorio generado
 ********************************************************************************/
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
    {
        srand(time(NULL));
    }
    return desde + (rand() % (hasta +1 - desde));
}
/**************************************************
 *              VERIFICADOR NUMERICO              *
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *************************************************/
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/************************************************************
 *                 VERIFICADOR ALFABETICO                   *
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 ***********************************************************/
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
/************************************************************************
 *                      VERIFICADOR ALFANUMERICO                        *
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 ***********************************************************************/
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}
/********************************************************************
 *                    VERIFICADOR TELEFONOS                         *
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *******************************************************************/
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
/**********************************************************
*          NO IMPORTA EL INGRESO MODIFICA S O N
*  Funcion usada para verificar el ingreso de caracteres.  
*  - Chequea que solo sean admitidas las letras S o N.
*  - Se se le pasa void y devuelve un entero sin signo
*    0 si se ingreso la N
*    1 si se ingreso la S
***********************************************************/
unsigned int verificaSN(void)
{
  char letra;
  
  printf("\nElija una opcion S/N?");
  
  letra = toupper( getche() );
  
  while( !( (letra == 'S') || (letra == 'N') ) )
  {
    printf("\nHa ingresado opcion no valida...\nReingrese una opcion(S/N)");

    letra = toupper( getche() );
  }

  return (letra == 'S');
}
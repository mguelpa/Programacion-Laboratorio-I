#include <stdio.h>
#include <stdlib.h>

/***************************************************************
 *                     SOLICITA OPERANDO                       *
 *\brief
 *\param
 *\return
 **************************************************************/
float ingresaOprando(char solicitud[])
{
    float numero;
    printf("%s", solicitud);
    scanf("%f", &numero);

    return numero;
}

/***************************************************************
 *                     CALCULA SUMA                            *
 *\brief
 *\param
 *\return
 **************************************************************/
float sumar(float a, float b)
{
    float suma;
    suma = a + b;
    return suma;
}

/***************************************************************
 *                     CALCULA RESTA                           *
 *\brief
 *\param
 *\return
 **************************************************************/
float restar(float a, float b)
{
    float resta;
    resta = a - b;
    return resta;
}

/***************************************************************
 *                    CALCULA COCIENTE                         *
 *\brief
 *\param
 *\return
 **************************************************************/
float dividir(float a, float b)
{
    float cociente;
    cociente = a / b;
    return cociente;
}
/***************************************************************
 *                    CALCULA PRODUCTO                         *
 *\brief
 *\param
 *\return
 **************************************************************/
float multiplicar(float a, float b)
{
    float producto;
    producto = a * b;
    return producto;
}
/***************************************************************
 *                  CALCULA EL FACTORIAL                       *
 *\brief
 *\param
 *\return
 **************************************************************/
float calcularFactorial(float a)
{
    float factorial;

    if(a == 1)
    {
        return 1;
    }
    factorial = a* calcularFactorial(a-1);

    return (factorial);
}


int tomarDatos(char solicitud[], char mensajeError[], int intentos,  float* dato)
{
    float aux;
    int contador = 0;
    int retorno;
    char respuesta = 'n';

    printf("%s", solicitud);
    scanf("%f", &aux);

    if((aux < 'a' || aux > 'z') && (aux < 'A' || aux > 'Z'))
    {
        *dato = aux;
        retorno = 0;
    }
    else
    {
        do
        {
            do
            {
                contador++;
                printf("%s", mensajeError);
                scanf("%f", &aux);
            }while(((aux > 'a' || aux < 'z') && (aux > 'A' || aux < 'Z')) || (contador < intentos));

            if(contador < intentos)
            {
                *dato = aux;
                retorno = 0;
            }
            else
            {
                printf("desea seguir intentando? S para continuar N para salir");
                scanf("%c", &respuesta);
                if(respuesta == 'n')
                retorno = -1;
            }
        }while(respuesta != 'n');
    }
    return retorno;
}


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
int calcularFactorial(int a)
{
    int factorial;

    if(a == 1)
    {
        return 1;
    }
    factorial = a* calcularFactorial(a-1);

    return (factorial);
}

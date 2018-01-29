/////////////////////////////////////////////////////////////////
////EJERCICIO 02 // FUNCION CALCULA DIVISION POR REFERENCIA
/////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//int divide(float* resultado, float dividendo, float divisor); //se pude poner solo el tipo y no el nombre
//                                                              //int divide(float*, float, float);
//int main()
//{
//    float resultado;
//    float numero1;
//    float numero2;
//
//    printf("Ingrese el primer numero: ");
//    scanf("%f", &numero1);
//
//    printf("Ingrese el segundo numero: ");
//    scanf("%f", &numero2);
//
//    if(divide(&resultado, numero1, numero2) == -1)
//    {
//        printf("No es posible dividir por 0");
//    }
//    else
//    {
//        printf("El resultado de la division es: %.2f\n", resultado);
//    }
//    return 0;
//}
///***********************************************************
// * \brief funcion que calcula la division
// * \param cociente
// * \param
// * \param
// * \return (0) para OK y (-1) para error
// ***********************************************************/
//int divide(float* resultado, float dividendo, float divisor)
//{
//    int retorno = -1;
//
//    if(divisor != 0)
//    {
//        *resultado = dividendo/divisor;
//        retorno = 0;
//        //printf("no es posible dividir por 0\n");
//    }
//    return retorno;
//}
//
//
//////////////////////////////////////////////////////////////////////////
////EJERCICIO 02 // FUNCION CALCULA TODAS LAS OPERACIONES POR REDFERENCIA
//////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//#include <stdlib.h>
//
//int calcular(float* resultadoSum, float* resultadoRes, float* resultadoMul, float* resultadoDiv, float operando1, float operando2);
//
//int main()
//{
//    float resultadoSum;
//    float resultadoRes;
//    float resultadoMul;
//    float resultadoDiv;
//
//    float numero1;
//    float numero2;
//
//    printf("Ingrese el primer numero: ");
//    scanf("%f", &numero1);
//
//    printf("Ingrese el segundo numero: ");
//    scanf("%f", &numero2);
//
//    if(calcular(&resultadoSum, &resultadoRes, &resultadoMul, &resultadoDiv, numero1, numero2))
//    {
//        printf("Error. No es posible dividir por 0.\n");
//    }
//    else
//    {
//        printf("El resultado es: %.2f\n", resultadoDiv);
//    }
//    printf("El resulatdo de la suma es: %.2f\n", resultadoSum);
//    printf("El resulatdo de la resta es: %.2f\n", resultadoRes);
//    printf("El resulatdo de la multiplicacion es: %.2f\n", resultadoMul);
//
//    return 0;
//}
///***********************************************************
// * \brief funcion que calcula la division
// * \param cociente
// * \param
// * \param
// * \return (0) para OK y (-1) para error
// ***********************************************************/
//int calcular(float* resultadoSum, float* resultadoRes, float* resultadoMul, float* resultadoDiv, float operando1, float operando2)
//{
//    *resultadoSum = operando1 + operando2;
//    *resultadoRes = operando1 - operando2;
//    *resultadoMul = operando1 * operando2;
//
//    int retorno = -1;
//
//    if(operando2 != 0)
//    {
//        *resultadoDiv = operando1/operando2;
//        retorno = 0;
//    }
//    return retorno;
//}

//////////////////////////////////////////////////////////////////////////////////////////////
//EJERCICIO 03 // FUNCION CALCULA TODAS LAS OPERACIONES POR REDFERENCIA CON #defines y switch
//////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#define SUMA     0
#define RESTA    1
#define PRODUCTO 2
#define DIVISION 3

int calculadora2(float numero1, float numero2, char operacion, float* resultado);

int main()
{
    float numero1;
    float numero2;

    float resultSuma;
    float resultResta;
    float resultProducto;
    float resultDivision;

    printf("Ingrese el primer numero : ");
    scanf("%f",&numero1);

    printf("Ingrese el segundo numero : ");
    scanf("%f",&numero2);

    calculadora2(numero1, numero2, SUMA, &resultSuma);
    printf("\nEl resulatado de la suma es : %.2f\n", resultSuma);

    calculadora2(numero1, numero2, RESTA, &resultResta);
    printf("El resulatado de la resta es : %.2f\n", resultResta);

    calculadora2(numero1, numero2, PRODUCTO, &resultProducto);
    printf("El resulatado de la multiplicacion es : %.2f\n", resultProducto);

    if(calculadora2(numero1, numero2, DIVISION, &resultDivision) == -1)
    {
        printf("Error. No es posible dividir por 0!!!\n");
    }
    else
    {
        printf("El resultado de la division es: %.2f\n", resultDivision);
    }
    return 0;
}
/** \brief Divide
 *
 * \param resultado resultado de la di....
 * \param
 * \param
 * \return (0) SIN ERRORES / (-1) ERROR / (-2) ERROR DE COMANDO
 *
 */

int calculadora2(float numero1, float numero2, char operacion, float* resultado)
{
    int retorno = -1;

    switch(operacion)
    {
        case SUMA:

                *resultado = numero1 + numero2;
                retorno = 0;

            break;

        case RESTA:

                *resultado = numero1 - numero2;
                retorno = 0;

            break;

        case PRODUCTO:

                *resultado = numero1 - numero2;
                retorno = 0;

            break;

        case DIVISION:

                if(numero2 != 0)
                {
                    *resultado = numero1 / numero2;
                    retorno = 0;
                }

            break;

        default:

            retorno = -2;
    }

    return retorno;
}


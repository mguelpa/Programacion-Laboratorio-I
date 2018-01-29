#include <stdio.h>
#include <stdlib.h>

int calcula(float* resultadoSum, float* resultadoRes, float* resultadoMul, float* resultadoDiv, float operando1, float operando2);

int main()
{
    float resultadoSum;
    float resultadoRes;
    float resultadoMul;
    float resultadoDiv;

    float numero1;
    float numero2;

    printf("ingrese el primer numero: ");
    scanf("%f", &numero1);

    printf("ingrese el segundo numero: ");
    scanf("%f", &numero2);

    calcula(&resultadoSum, &resultadoRes, &resultadoMul, &resultadoDiv, numero1, numero2);

        printf("el resulatdo de la suma es: %.2f", resultadoSum);
        printf("el resulatdo de la suma es: %.2f", resultadoRes);
        printf("el resulatdo de la suma es: %.2f", resultadoMul);



    if(calcula(&resultadoDiv, numero1, numero2) == -1)
    {
        printf("error");
    }
    else
    {
        printf("el resultado es: %.2f\n", resultado);
    }
    return 0;
}

/** \brief funcion que calcula la division
 *
 * \param cociente
 * \param
 * \param
 * \return (0) para OK y (-1) para error
 *
 */
int calcula(float* resultadoSum, float* resultadoRes, float* resultadoMul, float* resultadoDiv, float operando1, float operando2)
{
    *resultadoSum = operando1 + operando2;
    *resultadoRes = operando1 - operando2;
    *resultadoMul = operando1 * operando2;

    int retorno = -1;

    if(operando2 != 0)
    {
        *resultado = operando1/operando2;
        retorno = 0;
    }
    return retorno;
}

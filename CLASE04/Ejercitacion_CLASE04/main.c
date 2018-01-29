//////////////////////////////////////////////////////////////////////
//EJERCICIO 04 // FUNCION CALCULA TODAS LAS OPERACIONES (BIBLIOTECAS)
//////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#include "calculadora.h"
#include "consola.h"

int main()
{
    float numero1;
    float numero2;

    float resultSuma;
    float resultResta;
    float resultProducto;
    float resultDivision;


    if( obtenerNumero("Ingrese el primer numero: ", "Ingrese un numero dentro del rango especificado: ", "desea continuar intentando? S/N: ", 3, &numero1, 0, 100) == -1 )
    {
        exit(0);
    }

    obtenerNumero("Ingrese el segundo numero: ", "Ingrese un numero dentro del rango especificado: ", "desea continuar intentando? S/N: ", 3, &numero2, 0, 100);





//    if(obtenerNumero("Ingrese el primer numero: \n", &numero1, 0, 100) == 0)
//    {
//        printf("Error.\n");
//    }
//
//    if(obtenerNumero("Ingrese el segundo numero: \n", &numero2, 0, 100) == -1)
//    {
//        printf("Error.\n");
//    }

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

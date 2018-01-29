#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i;
    float num = 0;
    float neg = 0;
    float pos = 0;
    float sumNeg = 0;
    float sumPos = 0;
    float promedioNeg = 0;
    float promedioPos = 0;

    for(i=0; i<MAX; i++)
    {
        printf("ingrese un numero: ");
        scanf("%f", &num);

        if(num < 0)
        {
            neg++;
            sumNeg = num + sumNeg;
        }
        else
        {
            pos++;
            sumPos = num + sumPos;
        }
    }
    if(neg > 0)
    {
        promedioNeg = (float)sumNeg / neg; //castear la variable para que la tome como float en ese momento

    }

    if(pos > 0)
    {
        promedioNeg = (float)sumNeg / neg; //castear la variable para que la tome como float en ese momento

    }
    promedioPos = (float)sumPos / pos;
    printf("\nla cantidad de positivos es %.0f y la cantidad de negativos %.0f\n", pos, neg);
    printf("\nEl promedio de los positivos es %.2f y el promedio de los negativos %.2f", promedioPos, promedioNeg);
    return 0;
}

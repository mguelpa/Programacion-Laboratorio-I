//#include <stdio.h>
//#include <stdlib.h>
//
//int miPrintf(char cadena[]);
//
//int main()
//{
//    char cadena[] = {'h','o','l','a','\0'};
//
//    miPrintf(cadena);
//
//    printf("Hello world!\n");
//    return 0;
//}
//
//int miPrintf(char cadena[])
//{
//    int i = 0;
//    int flagEncontreFinal = 0;
//    char caracter;
//
//    while(flagEncontreFinal == 0)
//    {
//        char caracter = cadena[i];
//
//        if(caracter != 0)
//        {
//            printf("%c", caracter);
//        }
//        else
//        {
//            flagEncontreFinal = 1;
//        }
//        i++;
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int ordenar(int numeros[], int len);
//
//int main()
//{
//    int i;
//    int numeros[5]= {6, 8, 4, 5, 1};
//
//    ordenar(numeros, 5);
//
//    for(i=0; i<5; i++)
//    {
//        printf("%d\n", numeros[i]);
//    }
//    return 0;
//}
//
//int ordenar(int numeros[], int len)
//{
//    int aux;
//    int i = 0;
//    int flagCambieAlgo = 0;
//
//    do
//    {
//        for(i=0; i<len-1; i++)
//        {
//            if(numeros[i] < numeros[i+1])
//            {
//                flagCambieAlgo = 1;
//
//                aux = numeros[i];
//                numeros[i] = numeros[i+1];
//                numeros[i+1] = aux;
//            }
//        }
//    }
//    while(flagCambieAlgo==1);
//
//    return 0;
//}

for(i=1; i<cantidad; i++)
{
    aux = a[i];
    for(j=i-1; j<=0; j--)
    {
        if(aux < aux[j])
        {
            a[j+1] = a[j];
        }
        else
        {
            aux[j+1] = aux;
            break;
        }
    }
}









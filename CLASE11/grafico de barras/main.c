#include <stdio.h>
#include <stdlib.h>


int main()
{
    int valueA = 9; // +18
    int valueB = 12; // 19 a 35
    int valueC = 5; // +35

    int max;

    int i;
    int flag = 0;

    /* DETERMINACION DEL MAYOR */

    if(valueA > valueB && valueA > valueC){
        max = valueA;
    }
    else if(valueB > valueA && valueB > valueC){
        max = valueB;
    }
    else{
        max = valueC;
    }




    /* IMPRESION DEL GRAFICO */

    for(i = max; i > 0; i--)
    {

        printf("%02d|", i); //The 0 means to pad the field using zeros and the 2 means
                            //that the field is two characters wide, so for any numbers
                            //that take less than 2 characters to display, it will be
                            //padded with a 0.

        if(i <= valueA){
            printf(" *");
        }

        if(i <= valueB){
            flag = 1;
            printf("\t   *");
        }

        if(i <= valueC){

            if(flag == 0)
                printf("\t\t   * ");

            if(flag == 1)
                printf("\t   * ");
        }

        printf("\n"); //---> For each iteration prints a line of points and ends with a line break
    }
    printf("--+-------------------\n");
    printf("  |<18| |19-35|  |>35|");

    return 0;
}

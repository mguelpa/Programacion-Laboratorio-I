#include <stdio.h>
#include <stdlib.h>
/*
id,first_name,last_name,is_empty
1,Eric,Knight,false
*/
int main()
{

    FILE *pFile,*pFileW;
    int i=0;
    char var1[50],var3[50],var2[50],var4[50];

    pFile = fopen("data.csv","r");
    pFileW = fopen("data2.csv","w");

    if(pFile != NULL)
        printf("SIIIIIIIIIIIIIIIII");

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        fprintf(pFileW,"%s-%s-%s-%s\n",var1,var2,var3,var4);
        i++;
        if(i > 20)
            break;

    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    
    FILE *pArchivo;



    char textoLinea[50];

    pArchivo = fopen("archivo.txt","r");
    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
            //fread(textoLinea, sizeof(char), 50, pArchivo);
            if(fgets(textoLinea, 50, pArchivo) != NULL)
            printf("---> %s\n", textoLinea);
        }
    }
    else{
        printf("\nEl archivo no puede ser abierto");
    }
    fclose(pArchivo);


    printf("Hello world!\n");
    return 0;
}

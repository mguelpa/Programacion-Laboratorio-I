#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getDynamicString (void);

int main()
{
    int i;
    char* str;
    int a = 1;

    while(a == 1)
    {
        i = 0;
        str = (char*) malloc(sizeof(char) * 5);
        printf("%p\n", &str);
        printf("%s\n", str);



        str = getDynamicString();
        while (str[i] != '\0')
        {
            printf("%02d - %p - %c\n", i+1, &str[i], str[i]);
            i++;
        }
        printf("%02d - %p - %d\n",i+1, &str[i], str[i]);
        printf("%s\n", str);

        free(str);
        printf("%p - ", &str);
        printf("%c\n", *str);




        printf("continuar?\n");
        scanf("%d", &a);
    }
    return 0;
}

char* getDynamicString (void)
{
    int i=0;
    char* string;
    int length;

    if((string = (char*) malloc(sizeof(char) * 5)) != NULL)
    {
        printf("%p\n", string);
        printf("ingrese un texto: ");
        fflush(stdin);
        fgets(string, 5, stdin);

        length = strlen(string);
        string = (char*)realloc(string, sizeof(char) * (length+1)); //realloc de len (cantidad de letras) + 1  byte por caracter terminador
        while (string[i] != '\0')
        {
            printf("%02d - %p - %c\n", i+1, &string[i], string[i]);
            i++;
        }
        printf("%02d - %p - %d\n\n",i+1, &string[i], string[i]);


        return string;

    }
    else
    {
        printf("no hay espacio en memoria!!");
        exit(0);
    }

    return NULL;
}

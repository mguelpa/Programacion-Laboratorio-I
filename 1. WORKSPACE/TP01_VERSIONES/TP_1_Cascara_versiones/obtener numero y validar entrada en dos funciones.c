int obtenerNumero(char solicitud[], double* numero)
{
    char cadena[20];
    int retorno;
    double convertido;

    printf("%s", solicitud);
    fflush(stdin);
    scanf("%s", cadena);

    if(validarEntrada(cadena, &convertido) == -1)
    {
        printf("Error. Ingrese un numero valido");
        retorno = -1;
    }
    else
    {
        printf("El numero se ha cargado de manera exitosa");
        retorno = 0;
    }
    return retorno;
}

int validarEntrada(char str[20], double* numero)
{
    //char cadena[20];
    int retorno;
    int i=0;

    while(str[i] != '\0')
    {
        if(str[i] < '.' || str[i] > '9' || str[i] == '/')
            retorno = -1;
        i++;
    }
    retorno = 0;
        *numero = atof(str);
    return retorno;
}

#include <stdio.h>
#include <stdlib.h>

/*
// PUNTERO ES UN NUMERO
void funcion(void)
{
}
int main()
{
    int a=5;
    int b=7;
    int puntero;

    puntero = (int)&a;
    printf("puntero a a:0x%x\n",puntero);

    puntero = (int)&b;
    printf("puntero a b:0x%x\n",puntero);

    puntero = (int)funcion;
    printf("puntero a funcion:0x%x\n",puntero);

    puntero = malloc(8);
    printf("puntero a heap:0x%x\n",puntero);

    return 0;
}
*/

/*
// PASAJE POR REFERENCIA/VALOR
void funcion(int p)
{
    printf("recibi la referencia 0x%x en la funcion\n",p);

}
int main()
{
    int a=5;
    int puntero;

    puntero = (int)&a;
    funcion(puntero);

    printf("a vale:%d\n",a);

    return 0;
}
*/


/*
// ACCESO A VALOR DE PUNTERO
void funcion(int p)
{
    printf("recibi la referencia 0x%x en la funcion\n",p);
    float* punteroInt = (float*)p;
    printf("puntero int vale 0x%x\n",punteroInt);
    *punteroInt = 9;
}
int main()
{
    int a=5;
    int puntero;

    puntero = (int)&a;
    funcion(puntero);

    printf("a vale:%d\n",a);

    return 0;
}
*/

/*
// TIPO DE DATO PUNTERO
void funcion(int* punteroInt)
{
    printf("puntero int vale 0x%x\n",punteroInt);
    *punteroInt = 9;
}
int main()
{
    int a=5;
    int* puntero;

    puntero = &a;
    //funcion(puntero);
    //funcion(&a);
    funcion(&a,&b,&c);

    printf("a vale:%d\n",a);

    return 0;
}
*/


/*
// CADENAS
int main()
{
    char cadena[8]="hola";
    char cadena2[]="hola";
    char* cadena3 = "hola";
    char* cadena4="hola2";

    printf("direccion cadena : 0x%x\n",cadena);
    printf("direccion cadena2: 0x%x\n",cadena2);
    printf("direccion cadena3: 0x%x\n",cadena3);
    printf("direccion cadena4: 0x%x\n",cadena4);

    cadena[0]='J';
    cadena3[0]='J';

    printf("%s\n",cadena);
    printf("%s\n",cadena2);
    printf("%s\n",cadena3);
    printf("%s\n",cadena4);


    //cadena3[0]='J';
    //printf("%s",cadena3);

    return 0;
}
*/

/*
// VARIABLES GLOBALES
int global;
int main()
{
    int local;
    char* cadena = "hola";

    printf("direccion var local : 0x%x\n",&local);
    printf("direccion var global: 0x%x\n",&global);
    printf("direccion var cadena: 0x%x\n",cadena);

    return 0;
}*/

/*
// RETORNOS
void calculo(float a, float b,float* pRes)
{
    float resultado;

    resultado = a/b;
    //return &resultado;
    *pRes = resultado;
}
int funcion2(int a)
{
    int i;
    for(i=0; i<10; i++)
        a+=i;
    return a;
}
int main()
{
    float a=5.0;
    float b=7.0;
    float* pResultado;

    //pResultado = calculo(a,b);
    float aux;
    calculo(a,b,&aux);
    //calculo(a,b,pResultado);
    funcion2(27);

    float r = *pResultado;
    printf("resultado: %f\n",r);

    return 0;
}
*/

/*
// Ejercicio: STRUCTS
struct S_Persona
{
    int edad;
    char nombre[20];
};
typedef struct S_Persona Persona;

int cargarPersona(Persona* pPersona)
{
    pPersona->edad = 9;

    //(*pPersona).edad = 9;

    //Persona aux = *pPersona;
    //aux.edad = 88;
    //*pPersona = aux;

    return 1;
}
void printPersona(Persona* pPersona)
{

}
int main()
{
    Persona persona;


    if(cargarPersona(&persona))
    {
        printf("Error en la carga");
    }
    else
    {
        printf("Carga correcta");
        printPersona(&persona);
    }

    return 0;
}
*/

/*
// ARITMETICA
int main()
{
    char cadena[11]="hola mundo";
    char* p;
    int i;


    p = cadena;
    for(i=0; i<11;i++)
    {
        //printf("%c\n",*p);
        //p++;
        printf("%c\n",p[i]);
    }


    unsigned short* pS = cadena;
    for(i=0; i<11;i++)
    {
        printf("%c\n",*pS);
        pS++;
    }

    return 0;
}
*/

/*
// LISTA STRUCTS
struct S_Persona
{
    int edad;
    char nombre[20];
};
typedef struct S_Persona Persona;


int main()
{
    Persona personas[10];
    int i;
    Persona* p;
    p = personas;

    // Ejemplo 1
    for(i=0; i<10; i++)
    {
        p->edad = i;
        p++;
    }

    for(i=0; i<10; i++)
        printf("%d\n",personas[i].edad);

    // Ejemplo 2
    //char* pI = personas;
    //for(i=0; i<10; i++){
    //    printf("%d\n",*pI);
    //    pI++;
    //}

    return 0;
}
*/

// ARRAY DE PUNTEROS
/*
Declarar un array de Personas y otro array de
punteros del tipo Persona.

1) Cargar el array de punteros con las
direcciones de cada item del array de
personas.
2) Ordenar el array de punteros por edad
*/
/*
Persona array[10];
Persona* arrayp[10];

Persona p1;

arrayp[5] = &p1;
*/









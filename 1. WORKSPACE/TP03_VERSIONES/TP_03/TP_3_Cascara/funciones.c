#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"
#include "funciones.h"
#include "movies.h"

///////////////////////////////////////////////////////////////////////////////
int func_agregarPelicula(EMovie* nombre_array, int length)
{
    int retorno = -1;

    char auxData1[MAX_CHARS_TITULOS +1];
    char auxData2[MAX_CHARS_GENEROS +1];
    int  auxData3;
    char auxData4[MAX_CHARS_DESCRIPCIONES +1];
    int  auxData5;
    char auxData6[MAX_CHARS_LINKS +1];



    if (input_getTitles ("\n   TITULO: ", "\t\t** el titulo debe poseer de 2 a 20 caracteres **\n", MAX_REINGRESOS, 2, MAX_CHARS_TITULOS, auxData1) == 0)
    {
        if (input_getAnumericStr ("   GENERO: ", "\t\t** el genero debe poseer de 2 a 20 caracteres **\n", MAX_REINGRESOS, 2, MAX_CHARS_GENEROS, auxData2) == 0)
        {
            if (input_getInt ("   DURACION (minutos): ", "\t\t** duracion de pelicula fuera de rango **\n", MAX_REINGRESOS, 5, 240, &auxData3) == 0)
            {
                if (input_getTitles ("   DESCRIPCION: ", "\t\t** la descripcion debe poseer de 5 a 50 caracteres **\n", MAX_REINGRESOS, 5, MAX_CHARS_DESCRIPCIONES, auxData4) == 0)
                {
                    if (input_getInt ("   PUNTAJE: ", "** la puntuacion va de 1 a 5 **\n", MAX_REINGRESOS, 1, 5, &auxData5) == 0)
                    {
                        if (input_getLiks ("\n   Link imagen: ", "\t\t** el link de la imagen no puede superar los 50 caracteres **\n", MAX_REINGRESOS, 0, MAX_CHARS_LINKS, auxData6) == 0)
                        {
                            emov_loadData (nombre_array, length, auxData1, auxData2, &auxData3, auxData4, &auxData5, auxData6);
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int func_modificarPelicula(EMovie* nombre_array, int length)
{
    int retorno = -1;
    int code;
    int slot;

    char auxData1[MAX_CHARS_TITULOS +1];
    char auxData2[MAX_CHARS_GENEROS +1];
    int  auxData3;
    char auxData4[MAX_CHARS_DESCRIPCIONES +1];
    int  auxData5;
    char auxData6[MAX_CHARS_LINKS +1];


    if (input_getInt ("   Ingrese el codigo de la pelicula a modificar: ",
                      "El codigo ingresado no pertenece al rango admitido",
                       3, 1, length, &code) == 0)
    {
        slot = emov_searchIndexByID(nombre_array, length, &code);
        if (slot > -1)
        {
            if (input_getTitles ("\n   TITULO: ", "\t\t** el titulo debe poseer de 2 a 20 caracteres **\n", MAX_REINGRESOS, 2, MAX_CHARS_TITULOS, auxData1) == 0)
            {
                if (input_getAnumericStr ("   GENERO: ", "\t\t** el genero debe poseer de 2 a 20 caracteres **\n", MAX_REINGRESOS, 2, MAX_CHARS_GENEROS, auxData2) == 0)
                {
                    if (input_getInt ("   DURACION (minutos): ", "\t\t** duracion de pelicula fuera de rango **\n", MAX_REINGRESOS, 5, 240, &auxData3) == 0)
                    {
                        if (input_getTitles ("   DESCRIPCION: ", "\t\t** la descripcion debe poseer de 5 a 50 caracteres **\n", MAX_REINGRESOS, 5, MAX_CHARS_DESCRIPCIONES, auxData4) == 0)
                        {
                            if (input_getInt ("   PUNTAJE: ", "** la puntuacion va de 1 a 5 **\n", MAX_REINGRESOS, 1, 5, &auxData5) == 0)
                            {
                                if (input_getLiks ("\n   Link imagen: ", "\t\t** el link de la imagen no puede superar los 50 caracteres **\n", MAX_REINGRESOS, 0, MAX_CHARS_LINKS, auxData6) == 0)
                                {
                                    emov_modifyData (nombre_array, slot, auxData1, auxData2, &auxData3, auxData4, &auxData5, auxData6);
                                    func_generarPagina(nombre_array, length);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int func_borrarPelicula(EMovie* nombre_array, int length)
{
    int retorno = -1;
    int code    = -1;
    int index   = -1;

    if (nombre_array != NULL && length > 0)
    {
        if (input_getInt ("ingrese el codigo de la pelicula a eliminar: ",
                          "El codigo ingresado no pertenece al rango admitido",
                           3, 1, length, &code) == 0)
        {
            index = emov_searchIndexByID(nombre_array, length, &code);
            if (index > -1)
            {
                emov_downData (nombre_array, index);
                func_generarPagina(nombre_array, length);
                retorno = 0;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int func_generarPagina(EMovie* nombre_array, int length)
{
    int retorno = -1;

    char html[MAX_CHARS_HTML +1] = {
    "<!DOCTYPE html>\
    <html lang='en'>\
    <head>\
    <meta charset='utf-8'>\
    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
    <meta name='viewport' content='width=device-width, initial-scale=1'>\
    <title>Lista peliculas</title>\
    <link href='css/bootstrap.min.css' rel='stylesheet'>\
    <link href='css/custom.css' rel='stylesheet'>\
    </head>\
    <body>\
    <div class='container'>\
    <div class='row'>\
    <article class='col-md-4 article-intro'>\
    <a href='#'>\
    <img class='img-responsive img-rounded' src='%s' alt=''>\
    </a>\
    <h3>\
    <a href='#'>%s</a>\
    </h3>\
    <ul>\
    <li>Genero: %s</li>\
    <li>Puntaje:  %d</li>\
    <li>Duracion: %d minutos</li>\
    <li>Codigo: %d</li>\
    </ul>\
    <p>%s</p>\
    </article>\
    </div>\
    </div>\
    <script src='js/jquery-1.11.3.min.js'></script>\
    <script src='js/bootstrap.min.js'></script>\
    <script src='js/ie10-viewport-bug-workaround.js'></script>\
    <script src='js/holder.min.js'></script>\
    </body>\
    </html>"
    };

    FILE* file;
    int i;

    if (nombre_array != NULL && length > 0)
    {

        file = fopen("index.html", "w");

        if(file == NULL)
        {
            printf("\nNo se pudo abrir el archivo\n");
            exit(0);
        }
        else
        {
            for (i=0; i<length; i++)
            {
                if( (nombre_array+i)->emov_slot == MOVIE_TAKEN )
                {
                    fprintf(file, html, (nombre_array+i)->linkImagen,
                                        (nombre_array+i)->titulo,
                                        (nombre_array+i)->genero,
                                        (nombre_array+i)->puntaje,
                                        (nombre_array+i)->duracion,
                                        (nombre_array+i)->emov_code,
                                        (nombre_array+i)->descripcion );
                }
            }
            retorno = 0;
        }
        fclose(file);
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////


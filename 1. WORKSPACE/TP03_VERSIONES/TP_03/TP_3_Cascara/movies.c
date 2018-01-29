#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

#include "movies.h"

static int emov_searchEmptySlot (EMovie* nombre_array, int length);
static int emov_idGen (EMovie* nombre_array, int length);

///////////////////////////////////////////////////////////////////////////////
int emov_arrayInit (EMovie* nombre_array, int length)
{
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            (nombre_array+i)->emov_slot = MOVIE_EMPTY;
            (nombre_array+i)->emov_code = MOVIE_EMPTY;

            (nombre_array+i)->duracion  = MOVIE_EMPTY;
            (nombre_array+i)->puntaje   = MOVIE_EMPTY;

    strncpy((nombre_array+i)->titulo, "xxxxxxxxxxxxxxxxxxxx", MAX_CHARS_TITULOS +1);
    strncpy((nombre_array+i)->genero, "xxxxxxxxxxxxxxxxxxxx", MAX_CHARS_GENEROS +1);
    strncpy((nombre_array+i)->descripcion, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", MAX_CHARS_DESCRIPCIONES +1);
    strncpy((nombre_array+i)->linkImagen,  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx", MAX_CHARS_LINKS +1);
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
static int emov_searchEmptySlot (EMovie* nombre_array, int length)
{
    int index = -1;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if((nombre_array+index)->emov_slot == MOVIE_EMPTY)
            {
                return index;
            }
        }
        index = -1;
    }
    return index;
}
///////////////////////////////////////////////////////////////////////////////
int emov_searchIndexByID (EMovie* nombre_array, int length, int* code)
{
    int retorno = -1;
    int index;

    if(nombre_array != NULL && length > 0)
    {
        for(index = 0; index < length; index++)
        {
            if((nombre_array+index)->emov_code == *code)
            {
                return index;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
static int emov_idGen (EMovie* nombre_array, int length)
{
    int retorno = -2;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i = 0; i < length; i++)
        {
            if( (nombre_array+i)->emov_code > retorno )
            {
                retorno = (nombre_array+i)->emov_code;
            }
        }
    }
    return retorno +1;
}
///////////////////////////////////////////////////////////////////////////////
int emov_arrayRecords (EMovie* nombre_array, int length)
{
    char estado[3][30] = {"Espacio libre", "Pelicula vigente", "Pelicula dada de baja"};
    int retorno = -1;
    int i;

    if(nombre_array != NULL && length > 0)
    {
        for (i=0; i<length; i++)
        {
            printf("******************************************************************\n");
            printf(" FICHA PELICULA : %d\n\n", (nombre_array+i)->emov_code);
            printf(" ESPACIO:        %s\t\t", estado[(nombre_array+i)->emov_slot]);
            printf(" CODIGO:         %d\n\n", (nombre_array+i)->emov_code);
            printf(" TITULO:         %s\n\n", (nombre_array+i)->titulo);
            printf(" GENERO:         %s\n\n", (nombre_array+i)->genero);
            printf(" DURACION:       %d (minutos)\n\n", (nombre_array+i)->duracion);
            printf(" DESCRIPCION:\n"/*%s\n", (nombre_array+i)->descripcion*/);
            output_justifyParagraph((nombre_array+i)->descripcion);
            printf("\n\n PUNTAJE:        %d\n\n", (nombre_array+i)->puntaje);
            printf(" LINK JPG.:\n"/*%s\n", (nombre_array+i)->linkImagen*/);
            output_justifyParagraph((nombre_array+i)->linkImagen);
            printf("\n\n");
            retorno = 0;
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int emov_loadData (EMovie* nombre_array, int length, char* data1, char* data2, int* data3, char* data4, int* data5, char* data6)
{
    int retorno = -1;
    int slot;
    int code;

    if (nombre_array != NULL && length > 0)
    {
        slot = emov_searchEmptySlot(nombre_array, length);
        if (slot > -1)
        {
            code = emov_idGen(nombre_array, length);
            if (code > 0)
            {
                (nombre_array+slot)->emov_slot = MOVIE_TAKEN;
                (nombre_array+slot)->emov_code = code;

                strncpy ( (nombre_array+slot)->titulo,      data1, MAX_CHARS_TITULOS +1);
                strncpy ( (nombre_array+slot)->genero,      data2, MAX_CHARS_GENEROS +1);
                          (nombre_array+slot)->duracion =  *data3;
                strncpy ( (nombre_array+slot)->descripcion, data4, MAX_CHARS_DESCRIPCIONES +1);
                          (nombre_array+slot)->puntaje =   *data5;
                strncpy ( (nombre_array+slot)->linkImagen,  data6, MAX_CHARS_LINKS +1);

                retorno = 0;
            }
        }
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int emov_modifyData (EMovie* nombre_array, int index, char* data1, char* data2, int* data3, char* data4, int* data5, char* data6)
{
    int retorno = -1;
    if (nombre_array != NULL && index > -1)
    {
        strncpy ( (nombre_array+index)->titulo,      data1, MAX_CHARS_TITULOS +1);
        strncpy ( (nombre_array+index)->genero,      data2, MAX_CHARS_GENEROS +1);
                  (nombre_array+index)->duracion =  *data3;
        strncpy ( (nombre_array+index)->descripcion, data4, MAX_CHARS_DESCRIPCIONES +1);
                  (nombre_array+index)->puntaje =   *data5;
        strncpy ( (nombre_array+index)->linkImagen,  data6, MAX_CHARS_LINKS +1);
        retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
int emov_downData (EMovie* nombre_array, int index)
{
    int retorno = -1;

    if (nombre_array != NULL && index > -1)
    {
        (nombre_array+index)->emov_slot = MOVIE_DOWN;
        retorno = 0;
    }
    return retorno;
}
///////////////////////////////////////////////////////////////////////////////
void emov_cheater (EMovie* nombre_array1)
{
    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 1 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+0)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+0)->emov_code   = 1;

    strcpy ((nombre_array1+0)->titulo,"Rocky");
    strcpy ((nombre_array1+0)->genero,"Drama");
            (nombre_array1+0)->duracion = 178;
    strcpy ((nombre_array1+0)->descripcion,"Rocky Balboa, a small-time boxer, gets a supremely rare chance to fight heavy-weight champion Apollo Creed in a bout in which he strives to go the distance for his self-respect.");
            (nombre_array1+0)->puntaje = 9;
    strcpy ((nombre_array1+0)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BMTY5MDMzODUyOF5BMl5BanBnXkFtZTcwMTQ3NTMyNA@@._V1_SY1000_CR0,0,666,1000_AL_.jpg");

    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 2 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+01)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+01)->emov_code   = 2;

    strcpy ((nombre_array1+01)->titulo,"Ghostbusters");
    strcpy ((nombre_array1+01)->genero,"Action");
            (nombre_array1+01)->duracion = 105;
    strcpy ((nombre_array1+01)->descripcion,"Three former parapsychology professors set up shop as a unique ghost removal service.");
            (nombre_array1+01)->puntaje = 7;
    strcpy ((nombre_array1+01)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BMTkxMjYyNzgwMl5BMl5BanBnXkFtZTgwMTE3MjYyMTE@._V1_SY1000_CR0,0,650,1000_AL_.jpg");

    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 3 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+02)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+02)->emov_code   = 3;

    strcpy ((nombre_array1+02)->titulo,"Back to the Future");
    strcpy ((nombre_array1+02)->genero,"Fantasy");
            (nombre_array1+02)->duracion = 176;
    strcpy ((nombre_array1+02)->descripcion,"Marty McFly, a seventeen-year-old high school student, is accidentally sent thirty years into the past in a time-travelling DeLorean invented by his close friend, the maverick scientist Doc Brown.");
            (nombre_array1+02)->puntaje = 9;
    strcpy ((nombre_array1+02)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BZmU0M2Y1OGUtZjIxNi00ZjBkLTg1MjgtOWIyNThiZWIwYjRiXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_SY1000_CR0,0,643,1000_AL_.jpg");

    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 4 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+03)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+03)->emov_code   = 4;

    strcpy ((nombre_array1+03)->titulo,"Die unendliche Geschichte");
    strcpy ((nombre_array1+03)->genero,"Fantasy");
            (nombre_array1+03)->duracion = 162;
    strcpy ((nombre_array1+03)->descripcion,"A troubled boy dives into a wondrous fantasy world through the pages of a mysterious book.");
            (nombre_array1+03)->puntaje = 7;
    strcpy ((nombre_array1+03)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BZWRmZjFhZDEtN2Y5NC00ZTZkLTg4MWUtMjM5ZjNiY2M2OTBlXkEyXkFqcGdeQXVyMTMxMTY0OTQ@._V1_.jpg");

    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 5 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+04)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+04)->emov_code   = 5;

    strcpy ((nombre_array1+04)->titulo,"Mortal Kombat");
    strcpy ((nombre_array1+04)->genero,"Action");
            (nombre_array1+04)->duracion = 161;
    strcpy ((nombre_array1+04)->descripcion,"Three unknowing martial artists are summoned to a mysterious island to compete in a tournament whose outcome will decide the fate of the world.");
            (nombre_array1+04)->puntaje = 9;
    strcpy ((nombre_array1+04)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BNzJhYjYxMTctNmY4My00NGIzLThmN2MtYjgwMjlmZWNjMTJlL2ltYWdlL2ltYWdlXkEyXkFqcGdeQXVyMTQxNzMzNDI@._V1_.jpg");

    ////////////////////////////////////////////////////////////
    //                    /* PELICULA 6 */                    //
    ////////////////////////////////////////////////////////////
            (nombre_array1+05)->emov_slot = MOVIE_TAKEN;
            (nombre_array1+05)->emov_code   = 6;

    strcpy ((nombre_array1+05)->titulo,"The Lord of the Rings: The Fellowship of the Ring");
    strcpy ((nombre_array1+05)->genero,"Fantasy");
            (nombre_array1+05)->duracion = 3;
    strcpy ((nombre_array1+05)->descripcion,"A meek Hobbit from the Shire and eight companions set out on a journey to destroy the powerful One Ring and save Middle Earth from the Dark Lord Sauron.");
            (nombre_array1+05)->puntaje = 9;
    strcpy ((nombre_array1+05)->linkImagen,"https://images-na.ssl-images-amazon.com/images/M/MV5BN2EyZjM3NzUtNWUzMi00MTgxLWI0NTctMzY4M2VlOTdjZWRiXkEyXkFqcGdeQXVyNDUzOTQ5MjY@._V1_SY999_CR0,0,673,999_AL_.jpg");

///////////////////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////////////////

#include "movies.h"
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED
/**************************************************************
 * \brief  funcion utilizada para validar los datos antes de
 *         cargarlos en el array, llama a distintas funciones
 *         para calcular indice, id, y validar datos.
 *
 * \param    1. se pasa nombre del array a modificar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = carga correcta.
 * \return (-1) = error en la carga.
 */
    int func_agregarPelicula(EMovie* nombre_array, int length);


/**************************************************************
 * \brief  funcion utilizada para validar los datos antes de
 *         modificarlos en el array, llama a distintas funciones
 *         para calcular indice, y validar datos.
 *
 * \param    1. se pasa nombre del array a modificar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = carga correcta.
 * \return (-1) = error en la carga.
 */
    int func_modificarPelicula(EMovie* nombre_array, int length);

/**************************************************************
 * \brief  funcion utilizada para realizar una baja logica
 *         de manera que los datos queden guardados en la hstoria
 *         pero no se muestren en el archivo.
 *
 * \param    1. se pasa nombre del array a modificar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = baja correcta.
 * \return (-1) = error en la baja.
 */
    int func_borrarPelicula(EMovie* nombre_array, int length);

/**************************************************************
 * \brief  funcion utilizada para generar un archivo html con
 *         todos los datos cargados en el array con estado
 *         vigente.
 *
 * \param    1. se pasa nombre del array a modificar.
 * \param    2. se pasa el limite del array.
 *
 * \return ( 0) = geracion del archivo correcta.
 * \return (-1) = error en la generacon del archivo.
 */
    int func_generarPagina(EMovie* nombre_array, int length);

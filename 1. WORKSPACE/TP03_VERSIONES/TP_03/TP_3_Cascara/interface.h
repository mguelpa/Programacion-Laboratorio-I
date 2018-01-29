#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#endif // INTERFACE_H_INCLUDED

/*****************************************************************************
 * \brief   Funcion utilizada para modificar el caracter LF impuesto por windows
 *          antes del terminador '\0', dicho caracter genera problemas de
 *          incompatibilidad.
 *
 * \param       1. solcitud al usuario
 * \param       2. buffer a analizar
 * \param       3. tamaño del buffer
 * \param       4. puntero al archivo "stdin".
 */
    void input_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName);

/*****************************************************************************
 * \brief   Funcion utilizada para preguntar al usuario si desea "continuar"
 *              - Chequea que solo sean admitidas las letras "s" o "n".
 *              - utiliza funcion tolower contenida en <ctype.h>
 *
 * \param       1. pregunta al usuario
 * \param       2. mensaje Error max intentos
 * \param       3. cantidad de intentos
 * \param       4. variable donde cargar la letra ingresada correctamente
 *
 * \return      (0) letra cargada correctamente (-1) supero cantidad intentos
 */
    int input_continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si numero obtenido esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas.
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getInt (char* request, char* errorMsg, int attemps, int min, int max, int* target);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si numero obtenido esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas.
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getNumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);


/******************************************************************
 * \brief   Funcion utilizada para verificar que los caracteres
 *          ingresados esten dentro de los admitidos.
 *
 * \param   1. string a veriricar.
 *
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    int valid_verifyStrNumbr (char* buffer);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si numero obtenido esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas.
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getFloat (char* request, char* errorMsg, int attemps, int min, int max, float* target);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si numero obtenido esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas.
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getFloatStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);


/******************************************************************
 * \brief   Funcion utilizada para verificar que los caracteres
 *          ingresados esten dentro de los admitidos.
 *
 * \param   1. string a veriricar.
 *
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    int valid_verifyStrFloat (char* str);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si la cantidad de caracteres esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getAnumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);


/******************************************************************
 * \brief   Funcion utilizada para verificar que los caracteres
 *          ingresados esten dentro de los admitidos.
 *
 * \param   1. string a veriricar.
 *
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    int valid_verifyAnumeric (char* str);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si la cantidad de caracteres esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getLiks (char* request, char* errorMsg, int attemps, int min, int max, char* target);


/******************************************************************
 * \brief   Funcion utilizada para verificar que los caracteres
 *          ingresados esten dentro de los admitidos.
 *
 * \param   1. string a veriricar.
 *
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    int valid_verifyLinks (char* str);


/******************************************************************
 * \brief   Funcion utilizada para solicitar un tipo de dato, calcula
 *           si la cantidad de caracteres esta dentro del rango admitido,
 *           y muestra por pantalla distintos mensajes segun el tipo de
 *           error producido en funciones internas
 *
 * \param   1. solicitud a mostrar por pantalla.
 * \param   2. mensaje de error generico.
 * \param   3. cantidad de re ingresos admitidos.
 * \param   4. minimo admitido.
 * \param   5. maximo admitido.
 * \param   6. buffer donde cargar los datos una vez validados.
 *
 * \return  ( 0) =  carga de datos exitosa.
 * \return  (-1) =  error en la carga de datos no se modifica
 *                  espacio.
 *
 */
    int input_getTitles (char* request, char* errorMsg, int attemps, int min, int max, char* target);


/******************************************************************
 * \brief   Funcion utilizada para verificar que los caracteres
 *          ingresados esten dentro de los admitidos.
 *
 * \param   1. string a veriricar.
 *
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    int valid_verifyTitles (char* str);


/******************************************************************
 * \brief   Funcion utilizada para justificar las lineas a 50
 *           caracteres.
 * \return  ( 0) =  caracteres validos.
 * \return  (-1) =  caracteres invalidos.
 *
 */
    void output_justifyParagraph (char* text);

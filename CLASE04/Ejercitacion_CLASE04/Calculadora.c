
#include "calculadora.h"


/** \brief Divide
 *
 * \param resultado resultado de la di....
 * \param
 * \param
 * \return (0) SIN ERRORES / (-1) ERROR / (-2) ERROR DE COMANDO
 *
 */

int calculadora2(float numero1, float numero2, char operacion, float* resultado)
{
    int retorno = -1;

    switch(operacion)
    {
        case SUMA:

                *resultado = numero1 + numero2;
                retorno = 0;

            break;

        case RESTA:

                *resultado = numero1 - numero2;
                retorno = 0;

            break;

        case PRODUCTO:

                *resultado = numero1 - numero2;
                retorno = 0;

            break;

        case DIVISION:

                if(numero2 != 0)
                {
                    *resultado = numero1 / numero2;
                    retorno = 0;
                }

            break;

        default:

            retorno = -2;
    }

    return retorno;
}

//static int funcionPrivada(int x, int y)
//{
//    return 8;
//}

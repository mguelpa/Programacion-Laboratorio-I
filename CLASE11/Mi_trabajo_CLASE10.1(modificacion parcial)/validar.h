#include "producto.h"

void myFgets(char* buffer, int length, FILE* archivo);

int val_getName(char* destino, char* solicitud, char* mensajeError, int intentos, int limite);
int val_getPrice(char* destino, char* solicitud, char* mensajeError, int intentos, int limite);
int val_getUnsignedInt(char* destino, char* solicitud, char* mensajeError, int intentos, int length);

int val_validateName(char* strNombre);
int val_validatePrice(char* strPrice);
int val_validateUnsignedInt(char* strUnsignedInt);

int continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);

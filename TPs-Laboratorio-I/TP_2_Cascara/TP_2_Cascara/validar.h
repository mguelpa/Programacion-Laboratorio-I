#include "funciones.h"

int val_getName (char* destino, int limite, char* solicitud, char* mensajeError, int intentos);
int val_getAge (char* target, int length, char* request, char* errorMsg, char* errorMsg2, int attempts);
int val_getUnsignedInt (char* target, int length, char* request, char* errorMsg, int attempts);

int val_validateName (char* strNombre);
int val_validateAge (char* strAge);
int val_validateUnsignedInt (char* strUnsignedInt);

int continuar (char* solicitud, char* msjIntentos, int intentos, char* buffer);
void fgetsSwitchLF (char* str, int length, FILE* fileName);

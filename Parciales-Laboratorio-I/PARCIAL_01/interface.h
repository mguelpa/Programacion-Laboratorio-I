#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#endif // INTERFACE_H_INCLUDED

 void interface_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName);
 int interface_continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);

 int interface_getInt (char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, int* target);
 int interface_getNumericStr (char* request, char* errorMsg, int attemps, char* target);
 int validate_verifyStrNumbr (char* buffer);

 int interface_getNames(char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, char* target);
 int interface_getAlfabeticStr (char* request, char* input);
 int validate_verifyStrName (char* buffer);

int interface_getAlfaNumericNames (char* request, char* errorMsg, char* errorMsg2, int attemps, int min, int max, char* target);
int interface_getAlfaNumericStr (char* request, char* errorMsg, int attemps, char* target);
int validate_verifyStrAlfaNumeric (char* str);


int interface_getFloat(char* request, char* errorMsg, char* errorMsg2, int attemps, float min, float max, float* target);
int interface_getFloatStr (char* request, char* errorMsg, char* errorMsg2, int attemps, float min, float max, char* target);
int validate_verifyStrFloat (char* buffer);


#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED
void input_fgetsSwitchLF (char* request, char* targetStr, int length, FILE* fileName);
int input_continuar(char* solicitud, char* msjIntentos, int intentos, char* buffer);

int input_getInt (char* request, char* errorMsg, int attemps, int min, int max, int* target);
int input_getNumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);
int valid_verifyStrNumbr (char* buffer);


int input_getFloat (char* request, char* errorMsg, int attemps, int min, int max, float* target);
int input_getFloatStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);
int valid_verifyStrFloat (char* str);

int input_getAnumericStr (char* request, char* errorMsg, int attemps, int min, int max, char* target);
int valid_verifyAnumeric (char* str);


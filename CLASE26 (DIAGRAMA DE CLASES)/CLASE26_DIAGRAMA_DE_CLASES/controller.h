#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

void cont_init ();
int cont_altaSocio (char* nombre, char* apellido, char* dni);
int cont_bajaSocio (int);
int cont_modificarSocio (char* nombre, char* apellido, char* dni, int id, int estado);
int cont_listarSocios ();

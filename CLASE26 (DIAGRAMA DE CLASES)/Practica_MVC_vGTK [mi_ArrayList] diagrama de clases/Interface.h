#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#endif // INTERFACE_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"

int  intr_init (int idioma);

int  intr_mostrarMenu();
void intr_mostrarError (char* msj);

void intr_mostrarSocios (ArrayList* ListaSocios);
void intr_mostrarServicios (ArrayList* ListaServicios);
void intr_mostrarInscripciones (ArrayList* ListaInscripciones);

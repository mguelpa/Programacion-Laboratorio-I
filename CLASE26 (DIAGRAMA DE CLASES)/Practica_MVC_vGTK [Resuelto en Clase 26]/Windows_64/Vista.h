#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"



int  vista_init (int idioma);
int  vista_mostrarMenu ();
void vista_mostrarError (char*);


void vista_mostrarSocios (ArrayList* pListaSocios);
void vista_mostrarServicios (ArrayList* pListaServicios);
void vista_mostrarInscripciones (ArrayList* pListaInscripciones);

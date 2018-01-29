#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n1. Listar Cliente\n2. Alta Cliente\n3.Baja Cliente\n4. Modifica Cliente\n5. Ordena Cliente\n6. Nuevo Alquiler\n7. Fin Alquiler\n8. Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"


int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarError(char * mensaje);




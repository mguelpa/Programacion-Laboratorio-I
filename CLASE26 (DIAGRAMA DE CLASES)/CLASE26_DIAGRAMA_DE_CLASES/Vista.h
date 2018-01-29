#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define MENU_PPAL_ES "1. Listar Empleados\n\
2. Agregar un elemento\n\
3. Elimina un elemento\n\
4. Edita un elemento\n\
5. Salir\n\
6. Mostrar socios guardados"

#define MENU_PPAL_EN "\n1. List Employees\n2. Add an item\n3. Edit an item\n4. Delete an item \n5. Exit \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"
#define MENU_PPAL_ERROR_EN "\nINVALID OPTION\n"

#define VISTA_IDIOMA_ES 0


int vista_init (int idioma);
int vista_mostrarMenu ();
void vista_mostrarSocios (ArrayList* pListaSocios);
void vista_mostrarError (char *);
int vista_mostrarSociosGuardados ();

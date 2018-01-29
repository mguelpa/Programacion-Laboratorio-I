#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define MENU_PPAL_ES "1. Mostrar Clientes.\n2. Alta Clientes.\n3. Baja Clientes.\n4. Editar Clientes.\n5. Ordenar Clientes.\n6. Nuevo Alquiler.\n7. Finalizar Alquiler.\n8. Informes.\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"

int vista_mostrarMenu();
void vista_mostrarCliente(ArrayList* listaClientes);
void mostrarError(char * mensaje);
void vista_mostrarAlquileres(int idCliente);

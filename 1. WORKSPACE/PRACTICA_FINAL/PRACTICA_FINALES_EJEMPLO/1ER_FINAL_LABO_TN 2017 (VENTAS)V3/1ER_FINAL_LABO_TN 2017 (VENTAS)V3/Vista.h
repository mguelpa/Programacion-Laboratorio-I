#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define MENU_PPAL_ES "1. Listado Cliente.\n2. Alta Cliente.\n3. Baja Cliente.\n4. Modificacion Cliente.\n5. Nueva Venta.\n6. Anular Venta.\n7. Informar Ventas.\n8. Informar Ventas Por Producto.\n9. Generar Informe De Ventas.\n10.Informar Cantidad De Ventas Por Clientes.\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"

int vista_mostrarMenu();
void vista_mostrarCliente(ArrayList* pListaCliente);
void vista_mostrarVentas(int idClinete);

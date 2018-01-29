#define ARCHIVO_SOCIOS "x.bin"

int dm_saveAllClientes(ArrayList* listaCliente);
int dm_readAllClientes(ArrayList* listaCliente);

int dm_saveAllVentas (ArrayList* listaVenta);
int dm_readAllVentas (ArrayList* listaVenta);
int dm_genrarArchivoInforme (ArrayList* listaVenta, ArrayList* listaCliente);



#define ARCHIVO_CLIENTES "clientes.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"

int dm_saveAllClientes(ArrayList* pArraySocios);
int dm_readAllClientes(ArrayList* pArraySocios);
int dm_readAllServicios(ArrayList* pArrayServicios);
int dm_saveAllServicios(ArrayList* pArrayServicios);
int dm_exportarServiciosTecnicos(ArrayList* listaCliente, ArrayList* listaServicios, char* fecha);

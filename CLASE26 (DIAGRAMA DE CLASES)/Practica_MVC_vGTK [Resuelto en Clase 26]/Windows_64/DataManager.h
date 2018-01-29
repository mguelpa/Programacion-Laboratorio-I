#define ARCHIVO_SOCIOS "socios.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_INSCRIPCIONES "inscripciones.bin"


int dm_saveAllSocios (ArrayList* listaSocios);
int dm_readAllSocios (ArrayList* listaSocios);

int dm_saveAllServicios (ArrayList* listaServicios);
int dm_readAllServicios (ArrayList* listaServicios);

int dm_saveAllLinkages (ArrayList* listaInscripciones);
int dm_readAllLinkages (ArrayList* listaInscripciones);

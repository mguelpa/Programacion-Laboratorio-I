#define ARCHIVO_SUBJECTS "subjects.bin"
#define ARCHIVO_SERVICIOS "servicios.bin"
#define ARCHIVO_INSCRIPCIONES "inscripciones.bin"

int dm_saveAllSubjects (ArrayList* listaSubjects);
int dm_readAllSubjects (ArrayList* listaSubjects);

int dm_saveAllServicios (ArrayList* listaServicios);
int dm_readAllServicios (ArrayList* listaServicios);

int dm_saveAllInscripciones (ArrayList* listaInscripciones);
int dm_readAllInscripciones (ArrayList* listaInscripciones);

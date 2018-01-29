#define ARCHIVO_SUBJECTS "subjects.bin"
#define ARCHIVO_PRODUCTOS "products.bin"
//#define ARCHIVO_INSCRIPCIONES "inscripciones.bin"

int dm_saveAllProducts (ArrayList* productList);
int dm_readAllProducts (ArrayList* productList);

int dm_readAllSubjects (ArrayList* listaSubjects);
int dm_saveAllSubjects (ArrayList* listaSubjects);

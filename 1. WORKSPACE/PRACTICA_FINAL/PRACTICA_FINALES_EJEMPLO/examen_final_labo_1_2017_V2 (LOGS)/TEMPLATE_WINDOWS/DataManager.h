#include "LogEntry.h"
#include "Service.h"
#define ARCHIVO_SOCIOS "x.bin"

int dm_saveAllX(ArrayList* pArrayX);
int dm_readAllX(ArrayList* pArrayX);

int dm_saveAllLogEntry(ArrayList* pArrayLogEntry);
int dm_readAllLogEntry(ArrayList* pArrayLogEntry);

int dm_saveAllService(ArrayList* pArrayService);
int dm_readAllService(ArrayList* pArrayService);

int dm_saveErrorMsg(LogEntry* auxiliar, Service* auxiliar2);
int dm_saveWarnings(LogEntry* auxiliar, Service* auxiliar2);

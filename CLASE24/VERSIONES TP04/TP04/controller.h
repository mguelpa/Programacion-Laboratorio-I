#include "ArrayList.h"
#include "affiliate.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

void ctrl_init(void);
int ctrl_validateData(sAsociado* pElement);
int ctrl_newAffiliate(ArrayList* list);
int ctrl_setData(sAsociado* pElement, char* data1, char* data2, int* data3, char* data4);
void ctrl_debugShow(sAsociado* pElement);
sAsociado* ctrl_getElementById (ArrayList* list, unsigned int id);
int ctrl_modifyData(sAsociado* pElement);
int ctrl_resetData(sAsociado* pElement, char* data1, char* data2, int* data3, char* data4);
int ctrl_modifyAffiliate(ArrayList* list);
int ctrl_downAffiliate (ArrayList* list);
int ctrl_searchIndexById (sAsociado* list, int length, int id);

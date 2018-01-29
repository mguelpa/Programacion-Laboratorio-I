#include "ArrayList.h"
#include "affiliate.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#endif // CONTROLLER_H_INCLUDED

int ctrl_validateData(sAsociado* pElement);
int ctrl_newAffiliate(ArrayList* list);

void ctrl_debugShow(sAsociado* pElement);

int ctrl_modifyData(sAsociado* pElement);
int ctrl_modifyAffiliate(ArrayList* list);

int ctrl_downAffiliate (ArrayList* list);

void ctrl_init();
int ctrl_loadProduct (int type, char* title, char* description, char* adress, float price);
int ctrl_modifyProduct (int id, int type, char* title, char* description, char* adress, float price);
int ctrl_deleteProduct (int id);
int ctrl_checkProduct (int id);


int ctrl_loadSubject (char* name, char* surname/*,int age,char* dni,float salary*/);
int ctrl_modifySubject (int id, char* name, char* surname/*,int age,char* dni,float salary*/);
int ctrl_deleteSubject (int id);

int ctrl_checkSubject (int id);




void ctrl_debugShowAll();

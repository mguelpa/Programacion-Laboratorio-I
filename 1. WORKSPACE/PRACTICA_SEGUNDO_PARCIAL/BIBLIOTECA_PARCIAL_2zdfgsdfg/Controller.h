void ctrlr_init();

int ctrlr_altaSubject (char* name, char* surname/*,int age,char* dni,float salary*/);
int ctrlr_altaServicio (char* name, char* description/*,int age,char* dni,float salary*/);
int ctrlr_altaInscripcion (int serviceID, int memberID);

int ctrlr_modificarSubject (int id, int status, char* name, char* surname/*,int age,char* dni,float salary*/);
int ctrlr_modificarServicio (int id, int status, char* title, char* description/*,int age,char* dni,float salary*/);
int ctrlr_modificarInscripcion (int id, int status);

int ctrlr_bajaSubject (int id);
int ctrlr_bajaServicio (int id);
int ctrlr_bajaInscripcion (int id);

int ctrlr_checkSubject (int id);
int ctrlr_checkServicio (int id);

int ctrlr_listarSubjects ();
int ctrlr_listarServicios ();
int ctrlr_listarInscripciones ();




void ctrlr_init();

int ctrlr_altaSocio (char* nombre, char* apellido ,char* dni);
int ctrlr_altaServicio (char* nombre, char* descripcion);
int ctrlr_altaInscripcion (int serviceID, int memberID);

int ctrlr_modificarSocio (char* nombre, char* apellido, char* dni, int id, int estado);
int ctrlr_modificarServicio (char* titulo, char* descripcion, int id, int estado);
int ctrlr_modificarInscripcion (int id, int status);

int ctrlr_bajaSocio (int id);
int ctrlr_bajaServicio (int id);
int ctrlr_bajaInscripcion (int id);





int ctrlr_listarSocios ();
int ctrlr_listarServicios ();
int ctrlr_listarInscripciones ();

int ctrlr_checkSocio(int id);
int ctrlr_checkServicio(int id);

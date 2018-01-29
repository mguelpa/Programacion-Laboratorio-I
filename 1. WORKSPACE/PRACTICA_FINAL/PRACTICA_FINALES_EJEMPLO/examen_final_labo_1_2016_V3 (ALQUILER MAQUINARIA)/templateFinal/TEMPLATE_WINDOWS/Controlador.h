void cont_init();

int cont_altaX (char* a,char* b,int c);
int cont_bajaX (int id);
int cont_modificarX (int id, char* a,char* b,int c);

int cont_listarX ();
int cont_ordenarX ();

int cont_altaCliente (char* a,char* b,char* c);
int cont_bajaCliente (int id);
int cont_modificarCliente (int id, char* a,char* b,char* c);
int cont_existeCliente (int id);


int cont_listarCliente ();
int cont_ordenarCliente ();

int cont_altaAlquiler (int a, int b, int c);
int cont_bajaAlquiler (int id, int tiempoReal);
int cont_listarAlquiler();
int cont_existeAlquiler (int id, int idAlquiler);

int cont_asociadoConMasAlquileres ();
int cont_equipoMasAlquilado();
int cont_tiempoPromedioDeAlquilerXEquipo();

int cont_imprimirCamposAlquiler(int idClinete);

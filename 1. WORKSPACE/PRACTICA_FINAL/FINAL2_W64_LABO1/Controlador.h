

void cont_init(void);

int cont_altaCliente (char* nombre,char* apellido,char* dni);

int cont_bajaCliente (int);

int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id);

int cont_listarClientes (void);

int cont_importarClientes();

int cont_existeCliente (int id);

int cont_altaServicio(int idCliente,char* idProducto,float costoReparacion,char* fecha);

int cont_exportarServiciosTecnicos(char* fecha);



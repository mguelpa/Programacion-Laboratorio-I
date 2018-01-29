void cont_init();

int cont_altaCliente (char* nombre,char* apellido,char* dni);
int cont_bajaCliente (int id);
int cont_modificarCliente (int id, char* a,char* b,char* c);

int cont_existeCliente(int id);
int cont_listarCliente ();
int cont_ordenarCliente ();

int cont_altaVenta(int idCliente, int idProducto, int cantidad);
int cont_bajaVenta(int id);
int cont_existeVenta(int id);
int cont_imprimirCamposVentaPorIdCliente(int idCliente);
int cont_imprimirCamposVentaPorIdProducto(int idProducto);

int cont_mostrarVentasPorCliente();
int cont_mostrarVentasPorProducto();
int cont_genrarArchivoInforme();
int cont_sumarComprasPorIdCliente(idCliente)



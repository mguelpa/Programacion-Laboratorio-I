#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Socio.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"

#include <gtk/gtk.h>


static int idiomaVista = VISTA_IDIOMA_ES;

static void opcionAlta (GtkWidget *widget,gpointer   data);
static void opcionBaja (GtkWidget *widget,gpointer   data);
static void opcionModificacion (GtkWidget *widget,gpointer   data);
static void opcionListado (GtkWidget *widget,gpointer   data);


static GtkWidget       *window;
static GtkBuilder      *builderSecondaryWindow;


static void on_window_main_destroy()
{
    gtk_main_quit();
}



int vista_init (int idioma)
{
    idiomaVista = idioma;
    gtk_init(0, 0);
    return 0;
}

int vista_mostrarMenu()
{
    GtkBuilder* builder;
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "./ventana.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

    GtkWidget *button;
    button = GTK_WIDGET(gtk_builder_get_object(builder, "btnList"));
    g_signal_connect (button, "clicked", G_CALLBACK (opcionListado), NULL);

    button = GTK_WIDGET(gtk_builder_get_object(builder, "btnAdd"));
    g_signal_connect (button, "clicked", G_CALLBACK (opcionAlta), NULL);


    g_signal_connect (window, "delete-event", G_CALLBACK (on_window_main_destroy), NULL);

    gtk_widget_show(window);
    gtk_main(); // bloqueante

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Socio* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
    {
        auxSocio = al_get(pListaSocios,i);
        printf("NOMBRE: %s- ID: %d\n",soc_getNombre(auxSocio),soc_getId(auxSocio));
    }
}


void mostrarError(char *);



//******* ALTA eventos **************************************************************************************
static void finIngresoAlta (GtkWidget *widget,gpointer   data)
{
	GtkWidget* entry;
	char* textName;
	char* textSurname;
	char* textDNI;

	printf("Tengo los datos, doy de alta un socio\r\n");

	entry = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "txtName"));
  	textName = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "txtSurname"));
  	textSurname = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	entry = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "txtDni"));
  	textDNI = (char*)gtk_entry_get_text(GTK_ENTRY(entry));

	// validar
	//...

	cont_altaSocio(textName,textSurname,textDNI);

	cont_listarSocios(); //debug

	// cierro la ventana
	GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "window_main"));
	gtk_window_close((GtkWindow*)window);

	g_object_unref (G_OBJECT (builderSecondaryWindow)); // liberamos builder de la ventana


}

static void opcionAlta (GtkWidget *widget,gpointer   data)
{
	printf("Se elegio agregar\r\n");

    	builderSecondaryWindow = gtk_builder_new();
    	gtk_builder_add_from_file (builderSecondaryWindow, "./ventanaAgregar.glade", NULL);

	//gtk_builder_connect_signals(builderSecondaryWindow, NULL);

	GtkWidget *button;
    	button = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "btnOk"));
    	g_signal_connect (button, "clicked", G_CALLBACK (finIngresoAlta), NULL);

	GtkWidget* window = GTK_WIDGET(gtk_builder_get_object(builderSecondaryWindow, "window_main"));
	gtk_widget_show(window);

}
//_________________________________________________________________________________________________________

//******* LISTA eventos **************************************************************************************
static void finListado (GtkWidget *widget,gpointer   data)
{
}
static void opcionListado (GtkWidget *widget,gpointer   data)
{
	printf("Se elegio listar\r\n");
}
//_________________________________________________________________________________________________________

//******* ELMINAR eventos **************************************************************************************
static void finIngresoBaja (GtkWidget *widget,gpointer   data)
{
}
static void opcionBaja (GtkWidget *widget,gpointer   data)
{
	printf("Se elegio eliminar\r\n");
}
//_________________________________________________________________________________________________________


//******* EDITAR eventos **************************************************************************************
static void finIngresoModificacion (GtkWidget *widget,gpointer   data)
{
}
static void opcionModificacion (GtkWidget *widget,gpointer   data)
{
	printf("Se elegio editar\r\n");
}
//_________________________________________________________________________________________________________

/*
static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaSocio(auxNombre,auxApellido,auxDni);

}

static void opcionBaja()
{

}

static void opcionModificacion()
{

}

static void opcionListado()
{
    cont_listarSocios();
}
*/

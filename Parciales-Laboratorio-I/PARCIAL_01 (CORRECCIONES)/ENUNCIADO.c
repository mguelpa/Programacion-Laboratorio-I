char menu[12][84] = {

	"**********************************************************************************",
	"*                            PUBLICACIONES PANTALLAS                             *",
	"**********************************************************************************",
	"* 1. Alta de pantalla.    4. Contratar publicidad.     7. Consulta facturación.  *",
	"*                                                                                *",
	"* 2. Modificar datos      5. Modificar publicación.    8. Listar contrataciones. ​*",
	"*    de pantalla.                                                                *",
	"*                                                                                *",
	"* 3. Baja de pantalla.    6. Cancelar contratación.    9. Listar​ ​pantallas​.      *",
	"*                                                                                *",
	"* 10. Informes.           11. Salir.                                             *",
	"**********************************************************************************",
};
/* 
1. Alta de pantalla: 

	   Se solicitan al usuario los datos de la pantalla, 
	   para que el sistema pueda​ ​funcionar​ ​se​ ​deberá​ ​
	   generar​ ​un​ ​ID​ ​único​ ​para​ ​cada​ ​pantalla.


2. Modificar datos de pantalla:

		Se ingresa el ID delapantalla, permitiendo 
		modificar sus datos.

3. Baja de pantalla: 

		Se ingresa el ID del apantalla, se eliminará 
		la pantalla junto con todas las​ ​contrataciones​ ​
		de​ ​publicidad​ ​para​ ​esta​ ​pantalla. 

4. Contratar una publicidad: ​

   
	Se listaran todas las pantallas y se le pedirá 
	al usuario que elija la pantalla donde se quiere 
	publicar, ingresando su ID. Luego se pedirán los 
	datos asociados a la publicidad: cuit del cliente, 
	cantidad de días que dura la publicación y nombre​ 
	​del​ ​archivo​ ​de​ ​video​ ​(p.ej.​ ​Video1.avi). 
											

5. Modificar condiciones de publicación:​


		Se pedirá que se ingrese el cuit del cliente y se 
		listaran todas las pantallas de video que el cliente
		tiene contratadas mostrando todossus campos. 
		Luego de ingresar el ID de la pantalla, sepermitirá 
		modificar la cantidad de días contratados​ ​para​ ​la​ ​misma. 

6. Cancelar contratación: ​

		Sepedirá que se ingrese el cuit del cliente y se 
		listaran todas las pantallas de video que el cliente 
		tiene contratadas mostrando todos sus campos. Luego 
		ingresar​ ​el​ ​ID​ ​de​ ​la​ ​pantalla​ ​de​ ​la​ ​cual​ ​se​ ​quiere​ ​
		cancelar​ ​la​ ​contratación.

7. Consulta facturación: 

		Se deberá ingresar el cuit del cliente y sedeberá 
		listar el importe a​ ​pagar​ ​por​ ​cada​ ​contratación.

8. Listar contrataciones: ​
	
		Se deberán listar las contrataciones indicando 
		nombre de la pantalla,​ ​nombre​ ​de​ ​video,​ ​cantidad​
		de​ ​días​ ​y​ ​cuit​ ​de​ ​cliente. 

9. Listar​ ​pantallas:​ ​​

		Se​ ​deberán​ ​listar​ ​las​ ​pantallas​ ​existentes​ ​
		indicando​ ​todos​ ​sus​ ​campos.

10. Informar: 

	a. Lista​ ​de​ ​cada​ ​cliente​ ​con​ ​cantidad​ ​de​ ​
	   contrataciones​ ​e​ ​importe​ ​a​ ​pagar​ ​por​ ​cada​ ​una.

	b. Cliente​ ​con​ ​importe​ ​más​ ​alto​ ​a​ ​facturar​
	   ​(si​ ​hay​ ​más​ ​de​ ​uno​ ​indicar​ ​el​ ​primero).


Nota​ ​0​ ​:​ ​El​ ​sistema​ ​soportará​ ​una​ ​capacidad​ ​máxima​ ​de​ ​100​ ​pantallas​ ​y​ ​1000​ ​contrataciones  

Nota 1: Se deberán desarrollar bibliotecas por cada entidad las cuales contendrán las 
		funciones​ ​(Alta,​ ​Baja,​ ​Modificar,​ ​etc.).​ ​Los​ ​informes​ ​deberán​ ​estar​ ​en​ ​una​ ​biblioteca​ ​aparte. 

Nota 2: El código deberá tener comentarios con la documentación de cada una de las 
		funciones​ ​y​ ​respetar​ ​las​ ​reglas​ ​de​ ​estilo​ ​de​ ​la​ ​cátedra.  */

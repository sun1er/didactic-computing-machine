#include<iostream>
#include "libro.h"
#include "persona.h"
#include "biblioteca.h"
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
	
	
	libro a("El principito", "Saint Pier", "Adolescente", "Disponible", 0);
	libro b("Vuelta al mundo en 80 dias", "Verne", "Novela", "Disponible", 1);
	
	ofstream datos_libros("datos_libros.dat", std::ios::binary | std::ios::trunc);
	a.guardar_en_binario(datos_libros);
	b.guardar_en_binario(datos_libros);
	
	persona p1("gonzalo", "heinzen", "1234", "sarmiento", "esperanza", "dsadas", 29, 9, 2003);
	persona p2("asd", "das", "12234", "belgrano", "pujato", "aaaaa", 30, 9, 2003);
	
	
	ofstream datos_personas("datos_personas.dat", std::ios::binary | std::ios::trunc);
	
	p1.guardar_en_binario(datos_personas);
	p2.guardar_en_binario(datos_personas);
	
	biblioteca biblio("datos_personas.dat", "datos_libros.dat");
	
	libro c("Los cuatro acuerdos", "Ruiz", "Desarrollo personal", "Disponible");
	biblio.agregar_libro(c);
	
	cout<<biblio.ver_cant_libros()<<endl;
	
	cout<<a.ver_id()<<endl;
	
	cout<<"Cantidad de socios: "<<biblio.ver_cant_socios()<<endl;
	
	persona p3("maca", "delbino", "3941923", "donnet 1164", "esperanza", "dsadas", 31, 7, 2002);
	
	biblio.agregar_socio(p3);
	
	cout<<"Cantidad de socios: "<<biblio.ver_cant_socios()<<endl;
	
	biblio.eliminar_socio(2);
	
	cout<<"Cantidad de socios: "<<biblio.ver_cant_socios()<<endl;
	
	biblio.guardar();
	
	
	
	
	/*biblioteca mi_biblioteca("datos.dat");*/
	
//	persona p3("aaa", "bbb", "123", "dasdas", "dsadas", "dsa", 29, 10, 2010);
	
	
	
	
	/*mi_biblioteca.agregar_socio(p3);*/
//	cout<<"Cantidad de socios: "<<mi_biblioteca.ver_cant_socios()<<endl;
//	
//	
//	cout << mi_biblioteca.guardar();
//	
//	
//	
//	
//	libro librito("", "heinzen", "cualquiera", "disponible", 1);
//
//	cout<<librito.ver_titulo()<<endl;
//	cout<<librito.ver_autor()<<endl;
//	cout<<librito.ver_genero()<<endl;
//	cout<<librito.ver_estado()<<endl;
//	cout<<librito.validar_datos();
//	
//	persona p("gonzalo", "heinzen", "3496517087", "sarmiento 1469", "esperanza", "gonzalowheinzen@gmail.com", 29, 9, 2003);
//	cout<<p.validar_datos();
//	cout<<p.ver_nombre()<<endl;
//	cout<<p.ver_apellido()<<endl;
//	cout<<p.ver_telefono()<<endl;
//	cout<<p.ver_direccion()<<endl;
//	cout<<p.ver_localidad()<<endl;
//	cout<<p.ver_email()<<endl;
//	cout<<p.ver_dia_nac()<<endl;
//	cout<<p.ver_mes_nac()<<endl;
//	cout<<p.ver_anio_nac()<<endl;
//	
//	
//	
	
	
	system("pause");
	return 0;
	
}

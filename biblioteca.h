#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <vector>
#include "libro.h"
#include "persona.h"
using namespace std;

class biblioteca {
private:
	std::string nombre_archivo_socios;
	std::string nombre_archivo_arreglo;
	std::vector<persona> socios;
	std::vector<libro> arreglo;
	
public:
	biblioteca(std::string nombre_archivo_personas, std::string nombre_archivo_libros);
	
	void cargar_datos_libros();
	void cargar_datos_personas();
	void modificar_persona(int indice, const persona &nueva_persona);
	bool guardar_datos_libros();
	bool guardar_datos_personas();
	persona &operator [](int &i);
	persona &verPersona(int &i);
	libro &verLibro(int& i);
	void agregar_libro(libro &l);
	void eliminar_libro(int i);
	int ver_cant_libros();
	void agregar_socio(const persona&p);
	void eliminar_socio(int i);
	int ver_cant_socios();
	vector<int> BuscarApellidoYNombre(std::string parte, int pos_desde);
	vector<int> BuscarLibro(std::string parte, int pos_desde);
	std::string GetPersona(int i) const;
	void modificar_libro(int indice, const libro& nuevo_libro);
	vector<persona>&obtener_personas();
	vector<libro>&obtener_libros();
	void modificar_personas(const std::vector<persona>& nuevas_personas);
	int buscar_por_dni(int dni);
	persona devolver_persona(int i);
};

#endif


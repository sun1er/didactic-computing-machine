#include "libro.h"
#include <fstream>
#include <cstring>
#include <string>
#include "utils.h"
using namespace std;
/**Implementaciones de la clase libro **/

libro::libro(std::string a_titulo, std::string a_autor, std::string a_genero, std::string a_estado, int a_id) {
	titulo = a_titulo;
	autor = a_autor;
	genero = a_genero;
	estado = a_estado;
	id = a_id; /// -1 seria equivalente a no asignado
}
int libro::ver_id()const{
	return id;
}

void libro::asignar_id(int a_id){
	id = a_id;
}

std::string libro::ver_titulo()const{
	return titulo;
}
std::string libro::ver_autor()const{
	return autor;
}
std::string libro::ver_genero(){
	return genero;
}

std::string libro::ver_estado(){
	return estado;
}

	std::string libro::validar_datos() {
		std::string errores;
		if (titulo.empty()) {
			errores += "El título no puede estar vacío.\n";
		}
		if (autor.empty()) {
			errores += "El autor no puede estar vacío.\n";
		} else if (!es_valido_texto(autor)) {
			errores += "El autor solo puede contener letras y espacios.\n";
		}
		if (genero.empty()) {
			errores += "El género no puede estar vacío.\n";
		} else if (!es_valido_texto(genero)) {
			errores += "El género solo puede contener letras y espacios.\n";
		}
		if (estado.empty()) {
			errores += "El estado no puede estar vacío.\n";
		}
		return errores;
	}
void libro::leer_desde_binario(std::ifstream &archivo){
	registro_libro reg;
	archivo.read(reinterpret_cast<char*>(&reg), sizeof(reg));
	titulo=reg.titulo;
	autor=reg.autor;
	genero=reg.genero;
	estado=reg.estado;
	id=reg.id;
}

void libro::guardar_en_binario(std::ofstream &archivo){
	registro_libro reg;
	strcpy(reg.titulo,titulo.c_str());
	strcpy(reg.autor,autor.c_str());
	strcpy(reg.genero,genero.c_str());
	strcpy(reg.estado,estado.c_str());
	reg.id = id;
	archivo.write(reinterpret_cast<char*>(&reg), sizeof(reg));
}
void libro::modificar_titulo(const std::string& nuevoTitulo) {
	titulo = nuevoTitulo;
}

void libro::modificar_autor(const std::string& nuevoAutor) {
	autor = nuevoAutor;
}

void libro::modificar_genero(const std::string& nuevoGenero) {
	genero = nuevoGenero;
}

void libro::modificar_estado(const std::string& nuevoEstado) {
	estado = nuevoEstado;
}

void libro::modificar_id(long nuevoID) {
	id = nuevoID;
}


bool libro::es_valido_texto(const std::string &texto) {
	for (char c : texto) {
		if (!std::isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}
	

bool criterio_comparacion_Titulo(const libro &l1, const libro &l2) {
	std::string tit1=l1.ver_titulo();
	std::string tit2=l2.ver_titulo();
	pasar_a_minusculas(tit1);
	pasar_a_minusculas(tit2);
	return tit1<tit2;
}

bool criterio_comparacion_Id(const libro& l1, const libro& l2) {
	return l1.ver_id()<l2.ver_id();
}

bool criterio_comparacion_Autor(const libro &l1, const libro&l2) {
	std::string tit1=l1.ver_autor();
	std::string tit2=l2.ver_autor();
	pasar_a_minusculas(tit1);
	pasar_a_minusculas(tit2);
	return tit1<tit2;
}


#include "biblioteca.h"
#include <fstream>
#include <string>
#include "libro.h"
#include "persona.h"
#include <vector>
#include "utils.h"
#include <iostream>
#include <wx/wx.h>
#include <wx/msgdlg.h>
using namespace std;


biblioteca::biblioteca(std::string nombre_archivo_personas, std::string nombre_archivo_libros){
	nombre_archivo_arreglo = nombre_archivo_libros;
	nombre_archivo_socios = nombre_archivo_personas;
	cargar_datos_personas();
	cargar_datos_libros();
}

void biblioteca::cargar_datos_personas(){

	std::ifstream archivo(nombre_archivo_socios.c_str(), std::ios::binary | std::ios::ate);
	if(archivo.is_open()){
		int tamanio_archivo = archivo.tellg();
		int cant_personas = tamanio_archivo/sizeof(registro_persona);
		socios.resize(cant_personas);
		archivo.seekg(0, std::ios::beg);
		for(int i=0; i<cant_personas; ++i){
			socios[i].leer_desde_binario(archivo);
		}
		archivo.close();
	}
}

void biblioteca::cargar_datos_libros(){
	std::ifstream archivo(nombre_archivo_arreglo.c_str(), std::ios::binary | std::ios::ate);
	if(archivo.is_open()){
		int tamanio_archivo = archivo.tellg();
		int cant_libros = tamanio_archivo/sizeof(registro_libro);
		arreglo.resize(cant_libros);
		archivo.seekg(0, std::ios::beg);
		for(int i=0; i<arreglo.size(); ++i){
			arreglo[i].leer_desde_binario(archivo);
		}
		archivo.close();
	}
}
persona& biblioteca::operator[](int &i) {
	return socios[i];
}
persona& biblioteca::verPersona(int &i){
	return socios[i];
}

bool biblioteca::guardar_datos_personas(){
	int cant_socios = socios.size();
	std::ofstream archivo(nombre_archivo_socios.c_str(), std::ios::binary | std::ios::trunc);
	if (!archivo.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo para escribir." << std::endl;
		return false;
	}
	for (int i = 0; i < socios.size(); ++i) {
		std::string errores = socios[i].validar_datos();
		if (!errores.empty()) {
			std::cerr << "Error en los datos de la persona " << i << ": " << errores << std::endl;
			archivo.close();
			return false;
		}
		if (!socios[i].guardar_en_binario(archivo)) {
			std::cerr << "Error al guardar los datos de la persona " << i << std::endl;
			archivo.close();
			return false;
		}
	}
	archivo.close();
	if (archivo.fail()) {
		std::cerr << "Error al cerrar el archivo después de escribir." << std::endl;
		return false;
	}
	return true;
}
bool biblioteca::guardar_datos_libros(){
	int cant_libros = arreglo.size();
	ofstream archivo(nombre_archivo_arreglo.c_str(), std::ios::binary | std::ios::trunc);
	if(!archivo.is_open()){
		return false;
	}
	for(int i=0; i<arreglo.size(); ++i){
		arreglo[i].guardar_en_binario(archivo);
	}
	archivo.close();
	return true;
}


void biblioteca::agregar_libro(libro &l){
	if(arreglo.size()!=0){
		int ultimo = (arreglo.size()-1); 
		int nuevo_id = (arreglo[ultimo].ver_id()+1);  
		l.asignar_id(nuevo_id);
		arreglo.push_back(l);
	} else{
		l.asignar_id(0); 
	}
}

void biblioteca::eliminar_libro(int i){
	arreglo.erase(arreglo.begin()+i);
}
	

int biblioteca::ver_cant_libros(){
	return arreglo.size();
}
	

void biblioteca::agregar_socio(const persona &p){
	for(int i = 0; i < socios.size(); ++i){
		if(p.ver_dni() == socios[i].ver_dni()){
			wxMessageBox("No se pudo agregar, el DNI ya está registrado.", "Error", wxICON_ERROR); 
			return;
		}
	}
	socios.push_back(p);
	wxMessageBox("Ha sido agregado a la lista.", "Listo!", wxOK);
}
void biblioteca::eliminar_socio(int i){
	socios.erase(socios.begin()+i);
}


int biblioteca::ver_cant_socios(){
	return socios.size();	
}
vector<int> biblioteca::BuscarApellidoYNombre(std::string parte, int pos_desde) {
	vector<int> resultado;
	if (parte.empty()) {
		return resultado;
	}

	pasar_a_minusculas(parte);
	
	int cant = ver_cant_socios();
	if (pos_desde < 0 || pos_desde >= cant) {
		return resultado; 
	}
	
	for (int i = 0; i<cant; ++i) {
		persona &p = socios[i];
		std::string apenom=p.getNombreCompleto();
		pasar_a_minusculas(apenom);
		if(apenom.find(parte)!= std::string::npos){
			resultado.push_back(i);
		}
	}
	
	return resultado; 
}

libro &biblioteca::verLibro (int &i) {
	return arreglo[i];
}
std::string biblioteca::GetPersona(int i) const {
	if (i >= 0 && i < socios.size()) {
		return socios[i].getNombreCompleto(); 
	} else {
		return ""; 
	}
}



vector<int> biblioteca::BuscarLibro (std::string parte, int pos_desde) {
	vector<int> resultado;
	if(parte.empty()){
		return resultado;
	}
	
	pasar_a_minusculas(parte);
	
	int cant = ver_cant_libros();
	
	if (pos_desde < 0 || pos_desde >= cant) {
		return resultado; 
	}

	for (int i=0; i<cant; ++i) {
		libro &L = arreglo[i];
		std::string nombre_libro = L.ver_titulo();
		pasar_a_minusculas(nombre_libro);
		if (nombre_libro.find(parte)!=std::string::npos){
			resultado.push_back(i);
		}
	}
	
	return resultado;
	
}

void biblioteca::modificar_persona(int indice, const persona &nueva_persona) {
	if (indice >= 0 && indice < socios.size()) {
		socios[indice] = nueva_persona;
	}
}
void biblioteca::modificar_libro(int indice, const libro& nuevo_libro) {
	if (indice >= 0 && indice < arreglo.size()) {
		arreglo[indice] = nuevo_libro;
	} else {
		std::cerr << "Error: Índice de libro fuera de rango." << std::endl;
	}
}

vector<persona>& biblioteca::obtener_personas ( ) {
		return socios;
	}
vector<libro>& biblioteca::obtener_libros ( ) {
	return  arreglo;
}
void biblioteca::modificar_personas(const std::vector<persona>& nuevas_personas) {
	socios = nuevas_personas;
}

int biblioteca::buscar_por_dni(int dni) {
	for(size_t i=0; i<socios.size(); ++i){
		if(dni == devolver_persona(i).ver_dni()){
		return i; /// Retorna el indice de la persona dentro del vector
		}
	return -1; /// En caso que no encuentre el dni retorna -1 
	}
}

persona biblioteca::devolver_persona (int i) {
	return socios[i];
}


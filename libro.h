#ifndef LIBRO_H
#define LIBRO_H
#include <string>
#include <fstream>
#include "libro.h"

struct registro_libro{
	char titulo[256];
	char autor[256];
	char genero[256];
	char estado[256];
	int id;	
};

class libro {
private:
	std::string titulo;
	std::string autor;
	std::string genero;
	std::string estado;
	int id;
	
public:
	libro(std::string titulo="", std::string autor="", std::string genero="", std::string estado="", int id=-1);
	int ver_id()const;
	void asignar_id(int a_id);
	std::string ver_titulo()const;
	std::string ver_autor()const;
	std::string ver_genero();
	std::string ver_estado();
	std::string validar_datos();
	void modificar_titulo(const std::string& nuevoTitulo);
	void modificar_autor(const std::string& nuevoAutor);
	void modificar_genero(const std::string& nuevoGenero);
	void modificar_estado(const std::string& nuevoEstado);
	void modificar_id(long nuevoID);
	void leer_desde_binario(std::ifstream &archivo);
	void guardar_en_binario(std::ofstream &archivo);
	bool es_valido_texto(const std::string& texto);
	
	
	
};

bool criterio_comparacion_Titulo(const libro &l1,const libro &l2);
bool criterio_comparacion_Id(const libro &l1,const libro &l2);
bool criterio_comparacion_Autor(const libro &l1,const libro &l2);

#endif


/**
Declaraciones de todo lo necesario para trabajar con la clase Persona

Este archivo define la clase Persona, las funciones auxiliares para compararlas
y el struct que hace de intermediario para guardar y leer en archivo binarios.
**/
#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <fstream>

/**
En los binarios no se debe guardar ni escribir objetos string porque al ser
dinamicos contienen punteros y lo que en realidad se guardaria seria el
puntero y no la informacion a la que apunta. Esta estructura sirve de 
intermediaria para guardar y escribir los datos de una persona.
**/
struct registro_persona {
	char nombre[256];
	char apellido[256];
	char telefono[256];
	char direccion[256];
	char localidad[256];
	char email[256];
	int dia_nac, mes_nac, anio_nac;
	int dni;
};


/**
Clase que representa a una persona. 

Contiene los atributos que se guardan de cada persona, metodos para definirlos
y modificarlos, para validar los datos, y para guardar o escribir en archivos
binarios.

**/

class persona{
	
private:
	
	// datos de una persona
	std::string nombre; ///< nombres de la persona
	std::string apellido; ///< apellido de la persona
	std::string telefono; ///< telefono de la persona
	std::string direccion; ///< direccion de la persona
	std::string localidad; ///< localidad donde vive la persona
	std::string email; ///< direccion de correo electronico de la persona
	int dia_nac; ///< dia de la fecha de naciemiento
	int mes_nac; ///< mes de la fecha de naciemiento
	int anio_nac; ///< año de la fecha de naciemiento 
	int dni;
	
public:
	
	// construir un obejto con los datos
	/// Inicializa los datos de una persona
	persona(std::string a_nombre="", std::string a_apellido="", std::string a_telefono="",
			std::string a_direccion="", std::string a_localidad="", std::string a_email="", 
			int a_dia=0, int a_mes=0, int a_anio=0, int dni=0);
	
	/// Valida que los datos cargados sean correctos y suficientes
	std::string validar_datos();
	
	// obtener los datos guardados
	std::string ver_nombre() const; ///< devuelve el nombre de la persona
	std::string ver_apellido() const; ///< devuelve el apellido de la persona
	std::string ver_direccion() const; ///< devuelve la direccion de la persona
	std::string ver_localidad() const; ///< devuelve la localidad de la persona
	std::string ver_telefono() const; ///< devuelve el telefono de la persona
	std::string ver_email() const; ///< devuelve la direccion de correo electronico de la persona
	int ver_dia_nac() const; ///< devuelve el dia de nacimiento de la persona
	int ver_mes_nac() const; ///< devuelve el mes de nacimiento de la persona
	int ver_anio_nac() const; ///< devuelve el anio de nacimiento de la persona
	int ver_dni() const;
	
	// modificar los datos
	void modificar_nombre(std::string a_nombre); ///< actualiza el nombre de la persona
	void modificar_apellido(std::string a_apellido); ///< actualiza el apellido de la persona
	void modificar_direccion(std::string a_direccion); ///< actualiza la direccion de la persona
	void modificar_localidad(std::string a_localidad); ///< actualiza la localidad de la persona
	void modificar_telefono(std::string a_telefono); ///< actualiza el telefono de la persona
	void modificar_email(std::string a_email); ///< actualiza la direccion de correo electronico de la persona
	
	void modificar_dia_nac(int nuevoDia);
	
	void modificar_mes_nac(int nuevoMes);
	
	void modificar_anio_nac(int nuevoAnio);
	
	void modificar_dni(int nuevodni);
	
	
	
	std::string getNombreCompleto() const;	
	
	/// guarda su registro en un archivo binario
	bool guardar_en_binario(std::ofstream &archivo);
	/// lee su registro desde un archivo binario
	void leer_desde_binario(std::ifstream &archivo);
	bool es_valido_texto(const std::string& texto); 
	bool es_valido_texto_numeros(const std::string& texto);
	bool operator==(const persona& other) ;
	bool operator<(const persona& other);
		
};

// crirerios para comparar dos personas
bool contiene_solo_digitos(const std::string& str);
bool criterio_comparacion_apellido_y_nombre(const persona &p1, const persona &p2);
bool criterio_comparacion_direccion(const persona &p1, const persona &p2);
bool criterio_comparacion_telefono(const persona &p1, const persona &p2);
bool criterio_comparacion_email(const persona &p1, const persona &p2);
bool criterio_comparacion_localidad( persona &p1, persona &p2);
bool criterio_comparacion_dni(const persona &p1,const persona &p2);
#endif


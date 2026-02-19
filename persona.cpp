
#include <fstream>
#include <cstring>
#include "persona.h"
#include "utils.h"
#include "string_conv.h"
#include "biblioteca.h"


persona::persona(std::string a_nombre, std::string a_apellido, std::string a_telefono,
				 std::string a_direccion, std::string a_localidad, std::string a_email, 
				 int a_dia, int a_mes, int a_anio, int a_dni) 
{
	nombre=a_nombre;
	apellido=a_apellido;
	telefono=a_telefono;
	email=a_email;
	localidad=a_localidad;
	direccion=a_direccion;
	dia_nac=a_dia;
	mes_nac=a_mes;
	anio_nac=a_anio;
	dni = a_dni;
}

std::string persona::ver_nombre() const {
	return nombre; 
}

std::string persona::ver_apellido() const {
	return apellido; 
}

std::string persona::ver_direccion() const { 
	return direccion; 
}

std::string persona::ver_localidad() const { 
	return localidad; 
}

std::string persona::ver_telefono() const { 
	return telefono; 
}

std::string persona::ver_email() const { 
	return email; 
}

int persona::ver_dia_nac() const { 
	return dia_nac; 
}

int persona::ver_mes_nac() const { 
	return mes_nac; 
}

int persona::ver_anio_nac() const { 
	return anio_nac; 
}
int persona::ver_dni ( ) const {
	return dni;
}
bool persona::operator==(const persona& other) {
	// Comparación basada en el DNI
	return dni == other.dni;
}

bool persona::operator<(const persona& other) {
	// Comparación basada en el DNI
	return dni < other.dni;
}

void persona::modificar_nombre(std::string a_nombre) { 
	nombre=a_nombre; 
}

void persona::modificar_apellido(std::string a_apellido) { 
	apellido=a_apellido; 
}

void persona::modificar_direccion(std::string a_direccion) { 
	direccion=a_direccion; 
}

void persona::modificar_localidad(std::string a_localidad) {
	localidad=a_localidad; 
}

void persona::modificar_telefono(std::string a_telefono) { 
	telefono=a_telefono; 
}

void persona::modificar_email(std::string a_email) { 
	email=a_email; 
}


bool persona::guardar_en_binario(std::ofstream &archivo) {
	registro_persona reg;
	strcpy(reg.nombre, nombre.c_str());
	strcpy(reg.apellido, apellido.c_str());
	strcpy(reg.telefono, telefono.c_str());
	strcpy(reg.direccion, direccion.c_str());
	strcpy(reg.localidad, localidad.c_str());
	strcpy(reg.email, email.c_str());
	reg.anio_nac = anio_nac;
	reg.mes_nac = mes_nac;
	reg.dia_nac = dia_nac;
	reg.dni=dni;
	if (archivo.write((char*)&reg, sizeof(reg))) {
		return true;
	} else {
		return false;
	}
}
void persona::leer_desde_binario(std::ifstream &archivo) {
	registro_persona reg;
	archivo.read(reinterpret_cast<char*>(&reg), sizeof(reg));
	nombre = reg.nombre;
	apellido = reg.apellido;
	telefono = reg.telefono;
	direccion = reg.direccion;
	localidad = reg.localidad;
	email = reg.email;
	anio_nac = reg.anio_nac;
	mes_nac = reg.mes_nac;
	dia_nac = reg.dia_nac;
	dni=reg.dni;
}

std::string persona::validar_datos() {
	std::string errores;
	if (nombre.empty()) errores += "El nombre no puede estar vacío.\n";
	if (nombre.size() > 256) errores += "El nombre es demasiado largo.\n";
	if (!es_valido_texto(nombre)) errores += "El nombre solo puede contener letras.\n";
	if (apellido.empty()) errores += "El apellido no puede estar vacío.\n";
	if (apellido.size() > 256) errores += "El apellido es demasiado largo.\n";
	if (!es_valido_texto(apellido)) errores += "El apellido solo puede contener letras.\n";
	if (telefono.size() > 256) errores += "El teléfono es demasiado largo.\n";
	if (!es_valido_texto_numeros(telefono)) errores += "El teléfono solo puede contener números.\n";
	if (direccion.size() > 256) errores += "La dirección es demasiado larga.\n";
	if (localidad.size() > 256) errores += "La localidad es demasiado larga.\n";
	if (!es_valido_texto(localidad)) errores += "La localidad solo puede contener letras.\n";
	if (email.size() > 256) errores += "El correo electrónico es demasiado largo.\n";
		if (dia_nac < 1 || dia_nac > 31) errores += "El día de nacimiento debe estar entre 1 y 31.\n";
		if (mes_nac < 1 || mes_nac > 12) errores += "El mes de nacimiento debe estar entre 1 y 12.\n";
		if (anio_nac < 1900 || anio_nac > 2024) errores += "El año de nacimiento no puede ser menor a 1900 o mayor a 2024.\n";
		if (dni>100000000) errores += "El dni es demasiado largo.\n";
		if (dni<1000000) errores += "El dni es demasiado corto.\n";
	return errores;
}

bool contiene_solo_digitos(const std::string& str) {
	return str.find_first_not_of("0123456789") == std::string::npos;
}

bool criterio_comparacion_apellido_y_nombre(const persona &p1, const persona &p2) {
	std::string s1 = p1.ver_apellido() + ", " + p1.ver_nombre();
	std::string s2 = p2.ver_apellido() + ", " + p2.ver_nombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1 < s2;
}

bool criterio_comparacion_direccion(const persona &p1, const persona &p2) {
	std::string s1 = p1.ver_direccion();
	std::string s2 = p2.ver_direccion();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}


bool criterio_comparacion_telefono(const persona &p1, const persona &p2) {
	std::string s1 = p1.ver_telefono();
	std::string s2 = p2.ver_telefono();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

bool criterio_comparacion_localidad(persona &p1, persona &p2) {
	std::string s1 = p1.ver_localidad();
	std::string s2 = p2.ver_localidad();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1 < s2;
}
bool criterio_comparacion_dni(const persona &p1,const persona &p2){
	return p1.ver_dni() < p2.ver_dni();
}
bool criterio_comparacion_email(const persona &p1, const persona &p2) {
	std::string s1 = p1.ver_email();
	std::string s2 = p2.ver_email();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;	
}

std::string persona::getNombreCompleto ( ) const {
	return nombre + " " + apellido;
}

void persona::modificar_dia_nac (int nuevoDia) {
	dia_nac=nuevoDia; 
}

void persona::modificar_mes_nac (int nuevoMes) {
	 
	mes_nac=nuevoMes; 
}

void persona::modificar_anio_nac (int nuevoAnio) {
	anio_nac=nuevoAnio; 
}

void persona::modificar_dni (int nuevodni) {
	dni = nuevodni;
}

bool persona::es_valido_texto(const std::string& texto) {
	for (char c : texto) {
		if (!std::isalpha(c) && c != ' ') {
			return false;
		}
	}
	return true;
}

bool persona::es_valido_texto_numeros(const std::string& texto) {
	for (char c : texto) {
		if (!std::isdigit(c) && c != ' ') {
			return false;
		}
	}
	return true;
}




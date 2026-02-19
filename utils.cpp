/**
* En este archivo van las funciones generales. Es decir, las que no son 
* particulares de ninguna clase.
**/

#include "utils.h"
#include <algorithm>

/**
* Funcion auxiliar para las utilizar en las comparaciones y busquedas de modo
* que no importe si los nombres estan en mayusculas o minusculas.
**/
void pasar_a_minusculas(std::string &s) {
	std::transform(s.begin(), s.end(), s.begin(),
				   [](unsigned char c) { return std::tolower(c); });
}

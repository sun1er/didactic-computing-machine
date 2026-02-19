#include "hijaModificar.h"
#include "biblioteca.h"
#include "persona.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <string>
#include "HijaPrincipal.h"
using namespace std;


hijaModificar::hijaModificar(wxWindow *parent, biblioteca *biblio, persona &p,HijaPrincipal *padre,int indice) 
	: BaseModificar(parent), m_biblioteca(biblio), m_persona(p),m_padre(padre),m_indice_persona(indice) {
	txt_nomb->SetValue(wxString(m_persona.ver_nombre()));
	txt_ape->SetValue(wxString(m_persona.ver_apellido()));
	txt_tel->SetValue(wxString(m_persona.ver_telefono()));
	txt_dire->SetValue(wxString(m_persona.ver_direccion()));
	txt_localidad->SetValue(wxString(m_persona.ver_localidad()));
	txt_mail->SetValue(wxString(m_persona.ver_email()));
	txt_dia->SetValue(wxString(std::to_string(m_persona.ver_dia_nac())));
	txt_mes->SetValue(wxString(std::to_string(m_persona.ver_mes_nac())));
	txt_anio->SetValue(wxString(std::to_string(m_persona.ver_anio_nac())));
	txt_edit->SetValue(wxString(std::to_string(m_persona.ver_dni())));
}


hijaModificar::~hijaModificar() {
	
}


void hijaModificar::clickCancel( wxCommandEvent& event )  {
	Close();
}

void hijaModificar::clickConfirm( wxCommandEvent& event )  {
	// Obtener los valores de los controles de la interfaz de usuario
	wxString nuevoNombre = txt_nomb->GetValue().Trim();
	wxString nuevoApellido = txt_ape->GetValue().Trim();
	wxString nuevoTelefono = txt_tel->GetValue().Trim();
	wxString nuevaDireccion = txt_dire->GetValue().Trim();
	wxString nuevaLocalidad = txt_localidad->GetValue().Trim();
	wxString nuevoEmail = txt_mail->GetValue().Trim();
	wxString strDia = txt_dia->GetValue().Trim();
	wxString strMes = txt_mes->GetValue().Trim();
	wxString strAnio = txt_anio->GetValue().Trim();
	wxString strdni = txt_edit->GetValue().Trim();
	
	if (!contiene_solo_digitos(std::string(wx_to_std(strDia))) ||
		!contiene_solo_digitos(std::string(wx_to_std(strMes))) ||
		!contiene_solo_digitos(std::string(wx_to_std(strAnio)))) {
		wxMessageBox("El día, mes y año de nacimiento deben contener solo dígitos.", "Error", wxICON_ERROR);
		return;
	}
		if (!contiene_solo_digitos(std::string(wx_to_std(strdni)))) {
			wxMessageBox("El dni solo puede contener digitos.", "Error", wxICON_ERROR);
			return;
		}
		
		int nuevoDNI = std::stoi(wx_to_std(strdni));
		for (int i = 0; i < m_biblioteca->ver_cant_socios(); ++i) {
			if (i != m_indice_persona && m_biblioteca->verPersona(i).ver_dni() == nuevoDNI) {
				wxMessageBox("El DNI ingresado ya está registrado en otra persona.", "Error", wxICON_ERROR);
				return;
			}
		}
		
		// Crear una nueva instancia de persona con los datos actualizados
		persona nuevaPersona = m_persona; // Copia la persona existente
		nuevaPersona.modificar_nombre(wx_to_std(nuevoNombre));
		nuevaPersona.modificar_apellido(wx_to_std(nuevoApellido));
		nuevaPersona.modificar_telefono(wx_to_std(nuevoTelefono));
		nuevaPersona.modificar_direccion(wx_to_std(nuevaDireccion));
		nuevaPersona.modificar_localidad(wx_to_std(nuevaLocalidad));
		nuevaPersona.modificar_email(wx_to_std(nuevoEmail));
		nuevaPersona.modificar_dia_nac(std::stoi(wx_to_std(strDia)));
		nuevaPersona.modificar_mes_nac(std::stoi(wx_to_std(strMes)));
		nuevaPersona.modificar_anio_nac(std::stoi(wx_to_std(strAnio)));
		nuevaPersona.modificar_dni(nuevoDNI);
		
		std::string errores = nuevaPersona.validar_datos();
		if (!errores.empty()) {
			wxMessageBox(std_to_wx(errores), "Error de Validación", wxICON_ERROR);
			return;
		}
		
		m_biblioteca->modificar_persona(m_indice_persona, nuevaPersona);
		m_biblioteca->guardar_datos_personas();
		m_padre->refrescar_grilla();
		EndModal(wxID_OK);
}


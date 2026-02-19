#include "HijaAgregar.h"
#include "persona.h"
#include <string>
#include "string_conv.h"
#include "biblioteca.h"
#include <wx/msgdlg.h>
using namespace std;

HijaAgregar::HijaAgregar(wxWindow *parent,biblioteca *Biblio) : BaseAgregar(parent),m_biblioteca(Biblio) {
	
}

void HijaAgregar::ClickbotGuardar( wxCommandEvent& event )  {
	string nombre=wx_to_std(M_nomb->GetValue());
	string apellido=wx_to_std(M_apellido->GetValue());
	string telefono=wx_to_std(M_telefono->GetValue());
	string direccion=wx_to_std(M_direccion->GetValue());
	string localidad=wx_to_std(M_localidad->GetValue());
	string email=wx_to_std(M_mail->GetValue());
	long dia,mes,anio,dni;
	M_dia->GetValue().ToLong(&dia);
	M_mes->GetValue().ToLong(&mes);
	M_anio->GetValue().ToLong(&anio);
	m_textDNI->GetValue().ToLong(&dni);
	persona p(nombre,apellido,telefono,direccion,localidad,email,dia,mes,anio,dni);
	string error= p.validar_datos();
	if(error.empty()){
	m_biblioteca->agregar_socio(p);
m_biblioteca->guardar_datos_personas();
	EndModal(1);
	}else{
		wxMessageBox(error,"Error",wxOK|wxICON_ERROR);
	}
}

void HijaAgregar::ClickbotCancelar( wxCommandEvent& event )  {
	EndModal(0);
}


HijaAgregar::~HijaAgregar ( ) {
	
}






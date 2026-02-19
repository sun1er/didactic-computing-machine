#include "HijaAgregarLibro.h"
#include "libro.h"
#include "biblioteca.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>
using namespace std;

HijaAgregarLibro::HijaAgregarLibro(wxWindow *parent,biblioteca *biblio) : BaseAgregarLibro(parent),m_biblioteca(biblio) {
	
}

void HijaAgregarLibro::clickCancelLibro( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaAgregarLibro::ClickGuardarLibro( wxCommandEvent& event )  {
	string titulo=wx_to_std(m_titulo->GetValue());
	string autor=wx_to_std(m_autor->GetValue());
	string genero=wx_to_std(m_genero->GetValue());
long id;
	string estado="Disponible";
	libro l(titulo,autor,genero,estado,id);
	string error= l.validar_datos();
	if(error.empty()){
		m_biblioteca->agregar_libro(l);
		m_biblioteca->guardar_datos_libros();
		EndModal(1);
	}else{
		wxMessageBox(error,"Error",wxOK|wxICON_ERROR);
	}
}


HijaAgregarLibro::~HijaAgregarLibro() {
	
}


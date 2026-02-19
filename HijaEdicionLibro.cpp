#include "HijaEdicionLibro.h"
#include "libro.h"
#include <wx/string.h>
#include "hijaPrestamos.h"
#include <wx/msgdlg.h>
#include "string_conv.h"

HijaEdicionLibro::HijaEdicionLibro(wxWindow *parent, biblioteca* biblio,libro &L,HijaPrestamos* presta,int &indice) : BaseEdicionLibro(parent),m_biblioteca(biblio),m_libro(L),m_prestamo(presta),m_indice_libro(indice){
	m_text_titulo->SetValue(wxString(m_libro.ver_titulo()));
	m_text_autor->SetValue(wxString(m_libro.ver_autor()));
	m_text_genero->SetValue(wxString(m_libro.ver_genero()));
//	m_text_id->SetValue(wxString(std::to_string(m_libro.ver_id())));
//	m_text_estado->SetValue(wxString(m_libro.ver_estado()));
}

void HijaEdicionLibro::ClickCancelar_edicion_libro( wxCommandEvent& event )  {
	EndModal(0);
}

void HijaEdicionLibro::clickConfirmarEdicionLibro( wxCommandEvent& event )  {
	wxString nuevotitulo = m_text_titulo->GetValue().Trim();
	wxString nuevoAutor =m_text_autor->GetValue().Trim();
	wxString nuevoGenero = m_text_genero->GetValue().Trim();
//	wxString nuevaId = m_text_id->GetValue().Trim();
//	wxString nuevoEstado =m_text_estado->GetValue().Trim();
		libro nuevolibro = m_libro; 
		nuevolibro.modificar_titulo(wx_to_std(nuevotitulo));
		nuevolibro.modificar_autor(wx_to_std(nuevoAutor));
		nuevolibro.modificar_genero(wx_to_std(nuevoGenero));
//		nuevolibro.modificar_id (std::stoi(wx_to_std(nuevaId)));
//		nuevolibro.modificar_estado(wx_to_std(nuevoEstado));
		std::string errores = nuevolibro.validar_datos();
		if (!errores.empty()) {
			wxMessageBox(std_to_wx(errores), "Error de Validación", wxICON_ERROR);
			return;
		}
		
		// Modificar la persona existente en la biblioteca
		m_biblioteca->modificar_libro(m_indice_libro, nuevolibro);
		
		// Guardar los datos actualizados en el archivo
		m_biblioteca->guardar_datos_libros();
		
		// Refrescar la grilla para mostrar los cambios
		m_prestamo->refrescar_grilla_prestamos();
		
		
		// Cerrar la ventana después de confirmar los cambios
		EndModal(wxID_OK);
}


HijaEdicionLibro::~HijaEdicionLibro() {
	
}


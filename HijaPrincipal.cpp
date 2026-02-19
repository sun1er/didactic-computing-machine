#include "HijaPrincipal.h"
#include "HijaAgregar.h"
#include <wx/msgdlg.h>
#include "string_conv.h"
#include "hijaPrestamos.h"
#include "persona.h"
#include "hijaModificar.h"
#include <wx/choicdlg.h>
#include "HijaAgregarLibro.h"
#include "HijaDevolucion.h"
#include <algorithm>
using namespace std;


HijaPrincipal::HijaPrincipal(biblioteca *Biblioteca) : BasePrincipal(nullptr),m_biblioteca(Biblioteca)
{
 refrescar_grilla();
 int numfila = m_grilla->GetNumberRows();
 int numCol = m_grilla->GetNumberCols();
 for (int fila = 0; fila < numfila; ++fila) {
	 for (int col = 0; col < numCol; ++col) {
		 m_grilla->SetReadOnly(fila, col);
	 }
 }
 m_busqueda->Bind(wxEVT_TEXT, &HijaPrincipal::buscar_en_grilla, this);
}
void HijaPrincipal::clickprestamo( wxCommandEvent& event )  {
	int fila_seleccionada = m_grilla->GetGridCursorRow();
	if (fila_seleccionada != wxNOT_FOUND) {
		persona& selectedPerson = m_biblioteca->verPersona(fila_seleccionada);
		HijaPrestamos prestamosWindow(this, m_biblioteca, selectedPerson);
		prestamosWindow.ShowModal();
	} else {
		wxMessageBox("Por favor, seleccione una persona de la grilla para realizar un préstamo.", "Error", wxICON_ERROR);
	}

}

void HijaPrincipal::Clickbotoneliminar( wxCommandEvent& event )  {
	int f=m_grilla->GetGridCursorRow();/// averiguo en que fila esta seleccionada la grilla
	m_biblioteca->eliminar_socio(f);
	int x=wxMessageBox("¿Esta seguro que desea eliminar este registro? ","Advertencia",wxYES_NO|wxICON_QUESTION);
if(x==wxYES){
	m_biblioteca->guardar_datos_personas();
refrescar_grilla();
}
}
void HijaPrincipal::refrescar_grilla ( ) {
	if (m_grilla->GetNumberRows() != 0) {
		m_grilla->DeleteRows(0, m_grilla->GetNumberRows());
	}
	for (int i = 0; i < m_biblioteca->ver_cant_socios(); ++i) {
		persona &p = m_biblioteca->verPersona(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i, 0, p.ver_apellido() + ", " + p.ver_nombre());
		m_grilla->SetCellValue(i, 1,(wxString(std::to_string(p.ver_dni()))));
		m_grilla->SetCellValue(i, 2, p.ver_telefono());
		m_grilla->SetCellValue(i, 3, p.ver_email());
		m_grilla->SetCellValue(i, 4, p.ver_localidad());
	}
	m_grilla->EnableEditing(false);///para evitar que se edite la grilla
}
void HijaPrincipal::ClickBotonAgregar( wxCommandEvent& event )  {
	HijaAgregar win(this,m_biblioteca);
	
	if(win.ShowModal()==1)
		refrescar_grilla();
	}
void HijaPrincipal::buscar_en_grilla(wxCommandEvent& event) {
	auto terminoBusqueda = m_busqueda->GetValue();
	if (terminoBusqueda.IsEmpty()) {
		refrescar_grilla();
	} else {
		vector<int> res = m_biblioteca->BuscarApellidoYNombre(wx_to_std(terminoBusqueda), 0);
		actualizar_grilla_con_resultados(res);
	}
}
void HijaPrincipal::actualizar_grilla_con_resultados(vector<int>& resultados) {
	/// Oculta todas las filas de la grilla
	for (int i = 0; i < m_grilla->GetNumberRows(); ++i) {
		m_grilla->HideRow(i);
	}
	for (int i = 0; i < resultados.size(); ++i) {
		persona p = m_biblioteca->verPersona(resultados[i]);
		m_grilla->SetCellValue(i, 0, p.ver_apellido() + ", " + p.ver_nombre());
		m_grilla->SetCellValue(i, 1,(wxString(std::to_string(p.ver_dni()))));
		m_grilla->SetCellValue(i, 2, p.ver_telefono());
		m_grilla->SetCellValue(i, 3, p.ver_email());
		m_grilla->SetCellValue(i, 4, p.ver_localidad());
		m_grilla->ShowRow(i);
	}
}
void HijaPrincipal::ClickModificar(wxCommandEvent& event) {
	int filaSeleccionada = m_grilla->GetGridCursorRow();
	if (filaSeleccionada != wxNOT_FOUND && filaSeleccionada >= 0 && filaSeleccionada < m_grilla->GetNumberRows()) {
		persona selectedPerson = m_biblioteca->verPersona(filaSeleccionada);
		hijaModificar modifica(this, m_biblioteca, selectedPerson, this, filaSeleccionada);
		if (modifica.ShowModal() == wxID_OK) {
			refrescar_grilla();
		}
	} else {
		wxMessageBox("Por favor, seleccione una persona de la grilla para modificar sus datos.", "Error", wxICON_ERROR);
	}
}
void HijaPrincipal::onModificacion (wxCommandEvent & event) {
	refrescar_grilla();
}
void HijaPrincipal::click_agre_libro( wxCommandEvent& event )  {
	HijaAgregarLibro win(this,m_biblioteca);
win.ShowModal();
}

void HijaPrincipal::clickDevolver( wxCommandEvent& event )  {
	HijaDevolucion win(this,m_biblioteca,m_person);
	win.ShowModal();
}

void HijaPrincipal::clickOrdenarPor( wxCommandEvent& event )  {
	vector<persona>& vec_per = m_biblioteca->obtener_personas();
	int seleccion = m_choice->GetSelection();
	switch (seleccion) {
	case 0: 
		break;
	case 1: 
		std::sort(vec_per.begin(), vec_per.end(), criterio_comparacion_apellido_y_nombre);
		break;
	case 2: 
		std::sort(vec_per.begin(), vec_per.end(), criterio_comparacion_localidad);
		break;
	case 3: 
		std::sort(vec_per.begin(), vec_per.end(),criterio_comparacion_dni);
		break;
	default:
		break;
	}
	refrescar_grilla();
}

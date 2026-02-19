#include "HijaPrestamos.h"
#include "biblioteca.h"
#include "libro.h"
#include <string>
#include "string_conv.h"
#include <wx/msgdlg.h>
#include "HijaAgregarLibro.h"
#include "persona.h"
#include "HijaEdicionLibro.h"

using namespace std;

HijaPrestamos::HijaPrestamos(wxWindow *parent,biblioteca *biblio, persona &pers) : BasePrestamos(parent),m_biblioteca(biblio), m_persona(pers) {
	refrescar_grilla_prestamos();
	int numfila = m_grilla_Prestamos->GetNumberRows();
	int numCol = m_grilla_Prestamos->GetNumberCols();
	for (int fila = 0; fila < numfila; ++fila) {
		for (int col = 0; col < numCol; ++col) {
			m_grilla_Prestamos->SetReadOnly(fila, col);
		}
	}
	m_busqueda_libro->Bind(wxEVT_TEXT, &HijaPrestamos::ClickBotonBUSCAR, this);
}
HijaPrestamos::~HijaPrestamos() {
	
}
void HijaPrestamos::ClickBotonBUSCAR( wxCommandEvent& event )  {
	wxString terminoBusqueda = m_busqueda_libro->GetValue();
	
	if (!terminoBusqueda.IsEmpty()) {
		vector<int> res = m_biblioteca->BuscarLibro(wx_to_std(terminoBusqueda), 0);
		actualizar_grilla_con_resultados_libros(res);
	} else {
		// Si el término de búsqueda está vacío, refrescar la grilla con todos los libros
		refrescar_grilla_prestamos();
	}
}
void HijaPrestamos::actualizar_grilla_con_resultados_libros(vector<int>& resultados) {
	/// Oculta todas las filas de la grilla
	for (int i = 0; i < m_grilla_Prestamos->GetNumberRows(); ++i) {
		m_grilla_Prestamos->HideRow(i);
	}
	// Agregar las nuevas filas correspondientes a los resultados de la búsqueda
	for (int i = 0; i < resultados.size(); ++i) {
		int libroIndex = resultados[i]; // Obtener el índice del libro en la biblioteca
		libro &L = m_biblioteca->verLibro(libroIndex); // Acceder al libro utilizando el índice
		int rowIndex = m_grilla_Prestamos->GetNumberRows(); // Obtener el índice de la próxima fila disponible en la grilla
		m_grilla_Prestamos->AppendRows(); // Agregar una nueva fila a la grilla
		m_grilla_Prestamos->SetCellValue(rowIndex, 0, L.ver_titulo());
		m_grilla_Prestamos->SetCellValue(rowIndex, 1, L.ver_autor());
		m_grilla_Prestamos->SetCellValue(rowIndex, 2, L.ver_estado());
		m_grilla_Prestamos->SetCellValue(rowIndex, 3, wxString(std::to_string(L.ver_id())));
	}
}



void HijaPrestamos::clickCANCELAR( wxCommandEvent& event )  {
	EndModal(0);
}
void HijaPrestamos::ClickConfirmar( wxCommandEvent& event )  {
	int fila_seleccionada = m_grilla_Prestamos->GetGridCursorRow();
	if (fila_seleccionada >= 0 && fila_seleccionada < m_biblioteca->ver_cant_libros()) {
		libro& libro_sele = m_biblioteca->verLibro(fila_seleccionada);
		libro_sele.modificar_estado("Rentado por: "+m_persona.getNombreCompleto());
		if (!m_biblioteca->guardar_datos_libros()) {
			wxMessageBox("Error al guardar los cambios en el archivo de libros.", "Error", wxICON_ERROR);
			return;
		}
		refrescar_grilla_prestamos();
	} else {
		wxMessageBox("Por favor, seleccione un libro de la grilla de préstamos.", "Error", wxICON_ERROR);
	}
}


void HijaPrestamos::refrescar_grilla_prestamos ( ) {
	if(m_grilla_Prestamos->GetNumberRows()!=0)
		m_grilla_Prestamos->DeleteRows(0,m_grilla_Prestamos->GetNumberRows());
	for(int i=0;i<m_biblioteca->ver_cant_libros();++i){
		libro &L=m_biblioteca->verLibro(i);
		m_grilla_Prestamos->AppendRows();
		m_grilla_Prestamos->SetCellValue(i,0,L.ver_titulo());
		m_grilla_Prestamos->SetCellValue(i,1,L.ver_autor());
		m_grilla_Prestamos->SetCellValue(i,2,L.ver_estado());
		m_grilla_Prestamos->SetCellValue(i, 3, wxString(std::to_string(L.ver_id())));
	}
	m_grilla_Prestamos->EnableEditing(false);
}

void HijaPrestamos::click_Eliminar_libro( wxCommandEvent& event )  {
	int fila_seleccionada = m_grilla_Prestamos->GetGridCursorRow();
	if (fila_seleccionada >= 0 && fila_seleccionada < m_biblioteca->ver_cant_libros()) {
		auto pregunta = "¿Está seguro que desea eliminar el libro seleccionado?";
		auto titulo = "Eliminar Libro";
		int estilo = wxYES_NO | wxICON_QUESTION;
		int respuesta = wxMessageBox(pregunta, titulo, estilo);
		if (respuesta == wxYES) {
			m_biblioteca->eliminar_libro(fila_seleccionada);
			m_biblioteca->guardar_datos_libros();
			refrescar_grilla_prestamos();
		}
	} else {
		wxMessageBox("Por favor seleccione un libro para eliminar.", "Error", wxOK | wxICON_ERROR);
	}
}
void HijaPrestamos::clickEditarLibro( wxCommandEvent& event )  {
	int filaSeleccionada = m_grilla_Prestamos->GetGridCursorRow();
	if (filaSeleccionada != wxNOT_FOUND && filaSeleccionada >= 0 && filaSeleccionada < m_grilla_Prestamos->GetNumberRows()) {
		libro libro_seleccionado = m_biblioteca->verLibro(filaSeleccionada);
		HijaEdicionLibro modifyDialog(this, m_biblioteca, libro_seleccionado,this,filaSeleccionada);
		if (modifyDialog.ShowModal() == wxID_OK) {
			refrescar_grilla_prestamos();
		}
	} else {
		wxMessageBox("Por favor, seleccione una persona de la grilla para modificar sus datos.", "Error", wxICON_ERROR);
	}
}


void HijaPrestamos::click_ordenar_libros( wxCommandEvent& event )  {
	vector<libro>& vec_libro = m_biblioteca->obtener_libros();
	int seleccion = m_choice2->GetSelection();
	switch (seleccion) {
	case 0: 
		break;
	case 1: 
		std::sort(vec_libro.begin(), vec_libro.end(), criterio_comparacion_Titulo);
		break;
	case 2: 
		std::sort(vec_libro.begin(), vec_libro.end(), criterio_comparacion_Id);
		break;
	case 3: 
		std::sort(vec_libro.begin(), vec_libro.end(),criterio_comparacion_Autor);
		break;
	default:
		break;
	}
	refrescar_grilla_prestamos();
}



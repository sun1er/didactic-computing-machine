#include "HijaDevolucion.h"
#include "libro.h"
#include "persona.h"
#include <wx/msgdlg.h>
#include "string_conv.h"

HijaDevolucion::HijaDevolucion(wxWindow *parent,biblioteca* biblio,persona &pers) : BaseDevolucion(parent),m_biblioteca(biblio),m_persona(pers) {
	refrescar_grilla_Devolucion();
	int numRows = m_grilla_devolucion->GetNumberRows();
	int numCols = m_grilla_devolucion->GetNumberCols();
	for (int row = 0; row < numRows; ++row) {
		for (int col = 0; col < numCols; ++col) {
			m_grilla_devolucion->SetReadOnly(row, col);///esta fila establece la grilla para solo lectura, no se puede editar
		}
	}
	M_buscar_libro->Bind(wxEVT_TEXT, &HijaDevolucion::ClickBuscarDevolcion, this);
}

void HijaDevolucion::ClickBuscarDevolcion( wxCommandEvent& event )  {
	wxString terminoBusqueda = M_buscar_libro->GetValue();
	if (!terminoBusqueda.IsEmpty()) {
		vector<int> res = m_biblioteca->BuscarLibro(wx_to_std(terminoBusqueda), 0);
		actualizar_grilla_con_resultados_libros(res);
	} else {
		refrescar_grilla_Devolucion();
	}
}
void HijaDevolucion::actualizar_grilla_con_resultados_libros(vector<int>& resultados) {
	/// Oculta todas las filas de la grilla
	for (int i = 0; i < m_grilla_devolucion->GetNumberRows(); ++i) {
		m_grilla_devolucion->HideRow(i);
	}
	for (int i = 0; i < resultados.size(); ++i) {
		int libro_ = resultados[i]; 
		libro &L = m_biblioteca->verLibro(libro_); 
		int fila = m_grilla_devolucion->GetNumberRows(); 
		m_grilla_devolucion->AppendRows(); 
		m_grilla_devolucion->SetCellValue(fila, 0, L.ver_titulo());
		m_grilla_devolucion->SetCellValue(fila, 1, L.ver_autor());
		m_grilla_devolucion->SetCellValue(fila, 2, L.ver_estado());
		m_grilla_devolucion->SetCellValue(fila, 3, wxString(std::to_string(L.ver_id())));
	}
}






void HijaDevolucion::ClickConfirmDevolucion( wxCommandEvent& event )  {
	int fila_seleccionada = m_grilla_devolucion->GetGridCursorRow();
	
	if (fila_seleccionada >= 0 && fila_seleccionada < m_biblioteca->ver_cant_libros()) {
		libro& libro_seleccionado= m_biblioteca->verLibro(fila_seleccionada);
		libro_seleccionado.modificar_estado("Disponible.");
		if (!m_biblioteca->guardar_datos_libros()) {
			wxMessageBox("Error al guardar los cambios en el archivo de libros.", "Error", wxICON_ERROR);
			return;
		}
		refrescar_grilla_Devolucion();
	} else {
		wxMessageBox("Por favor, seleccione un libro de la grilla de préstamos.", "Error", wxICON_ERROR);
	}
}
void HijaDevolucion::ClickSalirDevolucion( wxCommandEvent& event )  {
	EndModal(0);
}

HijaDevolucion::~HijaDevolucion() {
	
}
void HijaDevolucion::refrescar_grilla_Devolucion ( ) {
	if(m_grilla_devolucion->GetNumberRows()!=0)
		m_grilla_devolucion->DeleteRows(0,m_grilla_devolucion->GetNumberRows());
	for(int i=0;i<m_biblioteca->ver_cant_libros();++i){
		libro &L=m_biblioteca->verLibro(i);
		m_grilla_devolucion->AppendRows();
		m_grilla_devolucion->SetCellValue(i,0,L.ver_titulo());
		m_grilla_devolucion->SetCellValue(i,1,L.ver_autor());
		m_grilla_devolucion->SetCellValue(i,2,L.ver_estado());
		m_grilla_devolucion->SetCellValue(i, 3, wxString::FromDouble(L.ver_id()));
	}
}
void HijaDevolucion::ordenar_por_devolucion( wxCommandEvent& event )  {
	vector<libro>& vec_libro = m_biblioteca->obtener_libros();
	int seleccion = m_choice3->GetSelection();
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
	refrescar_grilla_Devolucion();
}


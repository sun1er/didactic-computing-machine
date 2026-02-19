#ifndef HIJAPRESTAMOS_H
#define HIJAPRESTAMOS_H
#include "wxfb_project.h"
#include "biblioteca.h"
#include "persona.h"

class HijaPrestamos : public BasePrestamos {
	
private:
	biblioteca *m_biblioteca;
	persona m_persona;
protected:
	void click_ordenar_libros( wxCommandEvent& event )  override;
	void clickEditarLibro( wxCommandEvent& event )  override;
	void click_Eliminar_libro( wxCommandEvent& event )  override;
	
	void ClickBotonBUSCAR( wxCommandEvent& event ) override;
	void clickCANCELAR( wxCommandEvent& event )  override;
	void ClickConfirmar( wxCommandEvent& event )  override;
public:
	void refrescar_grilla_prestamos();
	void actualizar_grilla_con_resultados_libros(vector<int>& resultados);
	
	HijaPrestamos(wxWindow *parent,biblioteca *Biblio,persona &pers);
	~HijaPrestamos();
};

#endif


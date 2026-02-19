#ifndef HIJAPRINCIPAL_H
#define HIJAPRINCIPAL_H
#include "wxfb_project.h"
#include "biblioteca.h"
#include "persona.h"

class HijaPrincipal : public BasePrincipal {
	
private:
	
protected:
	void clickOrdenarPor( wxCommandEvent& event )  override;
	void clickDevolver( wxCommandEvent& event )  override;
	void click_agre_libro( wxCommandEvent& event )  override;
	void ClickModificar( wxCommandEvent& event )  override;
	void buscar_en_grilla(wxCommandEvent& event) override;
	void ClickBotonAgregar( wxCommandEvent& event )  override;
	void clickprestamo( wxCommandEvent& event )  override;
	void Clickbotoneliminar( wxCommandEvent& event )  override;
	void onModificacion(wxCommandEvent& event);
	biblioteca *m_biblioteca;
   persona m_person;
public:
	void refrescar_grilla();
	void actualizar_grilla_con_resultados(vector<int>& resultados);
	HijaPrincipal(biblioteca *Biblio);
	
};

#endif


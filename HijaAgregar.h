#ifndef HIJAAGREGAR_H
#define HIJAAGREGAR_H
#include "wxfb_project.h"
#include "biblioteca.h"

class HijaAgregar : public BaseAgregar {
	
private:
	biblioteca *m_biblioteca;
protected:
	void clickCancelLibro( wxCommandEvent& event )  ;
	void ClickGuardarLibro( wxCommandEvent& event ) ;
	void ClickbotGuardar( wxCommandEvent& event )  override;
	void ClickbotCancelar( wxCommandEvent& event )  override;
	
	
public:
	HijaAgregar(wxWindow *parent,biblioteca *Biblio);
	~HijaAgregar();
	
};

#endif


#ifndef HIJAAGREGARLIBRO_H
#define HIJAAGREGARLIBRO_H
#include "wxfb_project.h"
#include "biblioteca.h"

class HijaAgregarLibro : public BaseAgregarLibro {
	
private:
	biblioteca *m_biblioteca;
protected:
	void clickCancelLibro( wxCommandEvent& event )  override;
	void ClickGuardarLibro( wxCommandEvent& event )  override;
	
public:
	HijaAgregarLibro(wxWindow *parent,biblioteca *biblio);
	~HijaAgregarLibro();
};

#endif


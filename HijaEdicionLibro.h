#ifndef HIJAEDICIONLIBRO_H
#define HIJAEDICIONLIBRO_H
#include "wxfb_project.h"
#include "biblioteca.h"
#include "libro.h"
#include "hijaPrestamos.h"

class HijaEdicionLibro : public BaseEdicionLibro {
	
private:
	biblioteca *m_biblioteca;
	libro m_libro;
	HijaPrestamos *m_prestamo;
	int m_indice_libro;
protected:
	void ClickCancelar_edicion_libro( wxCommandEvent& event )  override;
	void clickConfirmarEdicionLibro( wxCommandEvent& event )  override;
	
public:
	HijaEdicionLibro(wxWindow *parent, biblioteca* biblio, libro &L,HijaPrestamos *presta,int &indice);
	~HijaEdicionLibro();
};

#endif


#ifndef HIJAMODIFICAR_H
#define HIJAMODIFICAR_H
#include "wxfb_project.h"
#include "biblioteca.h"
#include "persona.h"
#include "HijaPrincipal.h"


class hijaModificar : public BaseModificar {
	
private:
	biblioteca *m_biblioteca;
	persona m_persona;
	HijaPrincipal* m_padre;
	int m_indice_persona;
protected:
	void clickCancel( wxCommandEvent& event )  override;
	void clickConfirm( wxCommandEvent& event )  override;
	// Declaración de un nuevo evento personalizado
	// Método para enviar el evento después de guardar los cambios
	void enviarEventoModificacion();
public:
	hijaModificar(wxWindow *parent,biblioteca *biblio,persona &p,HijaPrincipal *padre,int indice);
	~hijaModificar();
};

#endif


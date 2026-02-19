#ifndef HIJADEVOLUCION_H
#define HIJADEVOLUCION_H
#include "wxfb_project.h"
#include "biblioteca.h"
#include "persona.h"

class HijaDevolucion : public BaseDevolucion {
	
private:
	biblioteca *m_biblioteca;
	persona m_persona;
protected:
	void ordenar_por_devolucion( wxCommandEvent& event )  override;
	void ClickBuscarDevolcion( wxCommandEvent& event )  override;
	void ClickConfirmDevolucion( wxCommandEvent& event )  override;
	void ClickSalirDevolucion( wxCommandEvent& event )  override;
public:
	void refrescar_grilla_Devolucion ( );
	void actualizar_grilla_con_resultados_libros(vector<int>& resultados);
	HijaDevolucion(wxWindow *parent,biblioteca *biblio,persona &pers);
	~HijaDevolucion();
};

#endif


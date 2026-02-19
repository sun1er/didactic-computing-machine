#include <wx/image.h>
#include "Application.h"
#include "HijaPrincipal.h"
#include "biblioteca.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_biblioteca=new biblioteca("datos_personas.dat","datos_libros.dat");
	HijaPrincipal *win = new HijaPrincipal(m_biblioteca);
	win->Show();
	return true;
}


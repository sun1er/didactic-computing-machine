#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "biblioteca.h"

class Application : public wxApp {
	biblioteca *m_biblioteca;
	
public:
	
	virtual bool OnInit();
};

#endif

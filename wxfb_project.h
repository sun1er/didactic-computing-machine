///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class BasePrincipal
///////////////////////////////////////////////////////////////////////////////
class BasePrincipal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText29;
		wxChoice* m_choice;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_busqueda;
		wxButton* m_button6;
		wxButton* m_button21;
		wxGrid* m_grilla;
		wxButton* m_button4;
		wxButton* m_button5;
		wxButton* m_button17;
		wxButton* m_button7;

		// Virtual event handlers, override them in your derived class
		virtual void clickOrdenarPor( wxCommandEvent& event ) { event.Skip(); }
		virtual void buscar_en_grilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_agre_libro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickprestamo( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickDevolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void Clickbotoneliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1361,609 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~BasePrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseEdicionLibro
///////////////////////////////////////////////////////////////////////////////
class BaseEdicionLibro : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText30;
		wxStaticText* m_staticText25;
		wxTextCtrl* m_text_titulo;
		wxStaticText* m_staticText26;
		wxTextCtrl* m_text_autor;
		wxStaticText* m_staticText27;
		wxTextCtrl* m_text_genero;
		wxButton* m_button24;
		wxButton* m_button25;

		// Virtual event handlers, override them in your derived class
		virtual void ClickCancelar_edicion_libro( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickConfirmarEdicionLibro( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseEdicionLibro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 633,374 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BaseEdicionLibro();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseDevolucion
///////////////////////////////////////////////////////////////////////////////
class BaseDevolucion : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText24;
		wxGrid* m_grilla_devolucion;
		wxStaticText* m_staticText34;
		wxChoice* m_choice3;
		wxTextCtrl* M_buscar_libro;
		wxButton* m_button19;
		wxButton* m_button20;

		// Virtual event handlers, override them in your derived class
		virtual void ordenar_por_devolucion( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarDevolcion( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickConfirmDevolucion( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalirDevolucion( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseDevolucion( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 879,520 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BaseDevolucion();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseModificar
///////////////////////////////////////////////////////////////////////////////
class BaseModificar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText231;
		wxStaticText* m_staticText16;
		wxTextCtrl* txt_nomb;
		wxStaticText* m_staticText18;
		wxTextCtrl* txt_ape;
		wxStaticText* m_staticText30;
		wxTextCtrl* txt_edit;
		wxStaticText* m_staticText19;
		wxTextCtrl* txt_tel;
		wxStaticText* m_staticText21;
		wxTextCtrl* txt_dire;
		wxStaticText* m_staticText22;
		wxTextCtrl* txt_localidad;
		wxStaticText* m_staticText23;
		wxTextCtrl* txt_mail;
		wxStaticText* m_staticText24;
		wxTextCtrl* txt_dia;
		wxTextCtrl* txt_mes;
		wxTextCtrl* txt_anio;
		wxButton* m_bot_cancelar;
		wxButton* m_bot_confirm;

		// Virtual event handlers, override them in your derived class
		virtual void clickCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickConfirm( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseModificar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 739,451 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BaseModificar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BasePrestamos
///////////////////////////////////////////////////////////////////////////////
class BasePrestamos : public wxDialog
{
	private:

	protected:
		wxGrid* m_grilla_Prestamos;
		wxButton* m_button22;
		wxStaticText* m_staticText33;
		wxTextCtrl* m_busqueda_libro;
		wxButton* m_button19;
		wxButton* m_button18;
		wxButton* m_button21;
		wxStaticText* m_staticText32;
		wxChoice* m_choice2;

		// Virtual event handlers, override them in your derived class
		virtual void click_Eliminar_libro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonBUSCAR( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickConfirmar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickCANCELAR( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickEditarLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_ordenar_libros( wxCommandEvent& event ) { event.Skip(); }


	public:

		BasePrestamos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 902,589 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BasePrestamos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregar
///////////////////////////////////////////////////////////////////////////////
class BaseAgregar : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText25;
		wxStaticText* m_staticText3;
		wxTextCtrl* M_nomb;
		wxStaticText* m_staticText31;
		wxTextCtrl* M_apellido;
		wxStaticText* m_staticText29;
		wxTextCtrl* m_textDNI;
		wxStaticText* m_staticText32;
		wxTextCtrl* M_telefono;
		wxStaticText* m_staticText33;
		wxTextCtrl* M_direccion;
		wxStaticText* m_staticText34;
		wxTextCtrl* M_localidad;
		wxStaticText* m_staticText35;
		wxTextCtrl* M_mail;
		wxStaticText* m_staticText36;
		wxTextCtrl* M_dia;
		wxTextCtrl* M_mes;
		wxTextCtrl* M_anio;
		wxButton* m_button10;
		wxButton* m_button11;

		// Virtual event handlers, override them in your derived class
		virtual void ClickbotGuardar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickbotCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseAgregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 731,387 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BaseAgregar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class BaseAgregarLibro
///////////////////////////////////////////////////////////////////////////////
class BaseAgregarLibro : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText22;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_titulo;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_autor;
		wxStaticText* m_staticText18;
		wxTextCtrl* m_genero;
		wxButton* m_button18;
		wxButton* m_button19;

		// Virtual event handlers, override them in your derived class
		virtual void clickCancelLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardarLibro( wxCommandEvent& event ) { event.Skip(); }


	public:

		BaseAgregarLibro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 655,386 ), long style = wxDEFAULT_DIALOG_STYLE );

		~BaseAgregarLibro();

};


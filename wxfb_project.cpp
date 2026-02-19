///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

BasePrincipal::BasePrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 128, 128, 128 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Ordenar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer3->Add( m_staticText29, 0, wxALL, 5 );

	wxString m_choiceChoices[] = { wxT("-"), wxT("Nombre y Apellido"), wxT("Localidad"), wxT("Dni") };
	int m_choiceNChoices = sizeof( m_choiceChoices ) / sizeof( wxString );
	m_choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceNChoices, m_choiceChoices, 0 );
	m_choice->SetSelection( 0 );
	bSizer3->Add( m_choice, 0, wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre : "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer3->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar Socio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Agregar Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 5 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 313 );
	m_grilla->SetColSize( 1, 250 );
	m_grilla->SetColSize( 2, 205 );
	m_grilla->SetColSize( 3, 228 );
	m_grilla->SetColSize( 4, 250 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	m_grilla->SetColLabelValue( 1, wxT("DNI") );
	m_grilla->SetColLabelValue( 2, wxT("Telefono") );
	m_grilla->SetColLabelValue( 3, wxT("E-mail") );
	m_grilla->SetColLabelValue( 4, wxT("Localidad") );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Editar Socio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("Realizar Prestamo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button5, 0, wxALL, 5 );

	m_button17 = new wxButton( this, wxID_ANY, wxT("Realizar Devolucion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button17, 0, wxALL, 5 );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Eliminar Socio"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button7, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BasePrincipal::clickOrdenarPor ), NULL, this );
	m_busqueda->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BasePrincipal::buscar_en_grilla ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAgregar ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::click_agre_libro ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickModificar ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickprestamo ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickDevolver ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::Clickbotoneliminar ), NULL, this );
}

BasePrincipal::~BasePrincipal()
{
	// Disconnect Events
	m_choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BasePrincipal::clickOrdenarPor ), NULL, this );
	m_busqueda->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BasePrincipal::buscar_en_grilla ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickBotonAgregar ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::click_agre_libro ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::ClickModificar ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickprestamo ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::clickDevolver ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrincipal::Clickbotoneliminar ), NULL, this );

}

BaseEdicionLibro::BaseEdicionLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Edicion de Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	m_staticText30->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer75->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer61->Add( bSizer75, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Titulo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	m_staticText25->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer62->Add( m_staticText25, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_text_titulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( m_text_titulo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer61->Add( bSizer62, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Autor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	m_staticText26->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer64->Add( m_staticText26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_text_autor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer64->Add( m_text_autor, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer63->Add( bSizer64, 1, wxEXPAND, 5 );


	bSizer61->Add( bSizer63, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Genero"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	m_staticText27->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer66->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_text_genero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( m_text_genero, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer65->Add( bSizer66, 1, wxEXPAND, 5 );


	bSizer61->Add( bSizer65, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );


	bSizer67->Add( bSizer68, 1, wxEXPAND, 5 );


	bSizer61->Add( bSizer67, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );


	bSizer69->Add( bSizer70, 1, wxEXPAND, 5 );


	bSizer61->Add( bSizer69, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );

	m_button24 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( m_button24, 0, wxALL, 5 );

	m_button25 = new wxButton( this, wxID_ANY, wxT("Confirmar y Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( m_button25, 0, wxALL, 5 );


	bSizer61->Add( bSizer74, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer61 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button24->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEdicionLibro::ClickCancelar_edicion_libro ), NULL, this );
	m_button25->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEdicionLibro::clickConfirmarEdicionLibro ), NULL, this );
}

BaseEdicionLibro::~BaseEdicionLibro()
{
	// Disconnect Events
	m_button24->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEdicionLibro::ClickCancelar_edicion_libro ), NULL, this );
	m_button25->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseEdicionLibro::clickConfirmarEdicionLibro ), NULL, this );

}

BaseDevolucion::BaseDevolucion( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Devolucion de Libros"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	m_staticText24->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer55->Add( m_staticText24, 1, wxALL|wxEXPAND, 5 );


	bSizer54->Add( bSizer55, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );

	m_grilla_devolucion = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla_devolucion->CreateGrid( 5, 4 );
	m_grilla_devolucion->EnableEditing( true );
	m_grilla_devolucion->EnableGridLines( true );
	m_grilla_devolucion->EnableDragGridSize( false );
	m_grilla_devolucion->SetMargins( 0, 0 );

	// Columns
	m_grilla_devolucion->SetColSize( 0, 298 );
	m_grilla_devolucion->SetColSize( 1, 217 );
	m_grilla_devolucion->SetColSize( 2, 231 );
	m_grilla_devolucion->SetColSize( 3, 113 );
	m_grilla_devolucion->EnableDragColMove( false );
	m_grilla_devolucion->EnableDragColSize( true );
	m_grilla_devolucion->SetColLabelValue( 0, wxT("Titulo") );
	m_grilla_devolucion->SetColLabelValue( 1, wxT("Autor") );
	m_grilla_devolucion->SetColLabelValue( 2, wxT("Estado") );
	m_grilla_devolucion->SetColLabelValue( 3, wxT("ID") );
	m_grilla_devolucion->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla_devolucion->EnableDragRowSize( true );
	m_grilla_devolucion->SetRowLabelSize( 0 );
	m_grilla_devolucion->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla_devolucion->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer56->Add( m_grilla_devolucion, 1, wxALL|wxEXPAND, 5 );


	bSizer54->Add( bSizer56, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Ordenar por :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer58->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choice3Choices[] = { wxT("-"), wxT("Titulo"), wxT("ID"), wxT("Autor") };
	int m_choice3NChoices = sizeof( m_choice3Choices ) / sizeof( wxString );
	m_choice3 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice3NChoices, m_choice3Choices, 0 );
	m_choice3->SetSelection( 0 );
	bSizer58->Add( m_choice3, 0, wxALL, 5 );

	M_buscar_libro = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( M_buscar_libro, 1, wxALL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_button19, 0, wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_button20, 0, wxALL, 5 );


	bSizer57->Add( bSizer58, 1, wxEXPAND, 5 );


	bSizer54->Add( bSizer57, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer54 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_choice3->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseDevolucion::ordenar_por_devolucion ), NULL, this );
	M_buscar_libro->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseDevolucion::ClickBuscarDevolcion ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseDevolucion::ClickConfirmDevolucion ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseDevolucion::ClickSalirDevolucion ), NULL, this );
}

BaseDevolucion::~BaseDevolucion()
{
	// Disconnect Events
	m_choice3->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BaseDevolucion::ordenar_por_devolucion ), NULL, this );
	M_buscar_libro->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BaseDevolucion::ClickBuscarDevolcion ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseDevolucion::ClickConfirmDevolucion ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseDevolucion::ClickSalirDevolucion ), NULL, this );

}

BaseModificar::BaseModificar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 192, 192, 192 ) );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText231 = new wxStaticText( this, wxID_ANY, wxT("Modificar Socio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText231->Wrap( -1 );
	m_staticText231->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Malgun Gothic") ) );

	bSizer54->Add( m_staticText231, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer53->Add( bSizer54, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer36->Add( bSizer53, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer37->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	txt_nomb = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( txt_nomb, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer36->Add( bSizer37, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer42->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	txt_ape = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( txt_ape, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer41->Add( bSizer42, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer78->Add( m_staticText30, 0, wxALL, 5 );

	txt_edit = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer78->Add( txt_edit, 1, wxALL, 5 );


	bSizer77->Add( bSizer78, 1, wxEXPAND, 5 );


	bSizer36->Add( bSizer77, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer44->Add( m_staticText19, 0, wxALL, 5 );

	txt_tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer44->Add( txt_tel, 1, wxALL, 5 );


	bSizer43->Add( bSizer44, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer43, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer46->Add( m_staticText21, 0, wxALL, 5 );

	txt_dire = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( txt_dire, 1, wxALL, 5 );


	bSizer45->Add( bSizer46, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer45, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Localidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer48->Add( m_staticText22, 0, wxALL, 5 );

	txt_localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( txt_localidad, 1, wxALL, 5 );


	bSizer47->Add( bSizer48, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer47, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("E-Mail"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer50->Add( m_staticText23, 0, wxALL, 5 );

	txt_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( txt_mail, 1, wxALL, 5 );


	bSizer49->Add( bSizer50, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer49, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Nacimiento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer52->Add( m_staticText24, 0, wxALL, 5 );

	txt_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( txt_dia, 0, wxALL, 5 );

	txt_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( txt_mes, 0, wxALL, 5 );

	txt_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( txt_anio, 0, wxALL, 5 );


	bSizer51->Add( bSizer52, 0, wxEXPAND, 5 );


	bSizer36->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );

	m_bot_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_bot_cancelar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_bot_confirm = new wxButton( this, wxID_ANY, wxT("Confirmar y Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( m_bot_confirm, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer36->Add( bSizer56, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer36 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_bot_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseModificar::clickCancel ), NULL, this );
	m_bot_confirm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseModificar::clickConfirm ), NULL, this );
}

BaseModificar::~BaseModificar()
{
	// Disconnect Events
	m_bot_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseModificar::clickCancel ), NULL, this );
	m_bot_confirm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseModificar::clickConfirm ), NULL, this );

}

BasePrestamos::BasePrestamos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_grilla_Prestamos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla_Prestamos->CreateGrid( 0, 4 );
	m_grilla_Prestamos->EnableEditing( true );
	m_grilla_Prestamos->EnableGridLines( true );
	m_grilla_Prestamos->EnableDragGridSize( false );
	m_grilla_Prestamos->SetMargins( 0, 0 );

	// Columns
	m_grilla_Prestamos->SetColSize( 0, 274 );
	m_grilla_Prestamos->SetColSize( 1, 221 );
	m_grilla_Prestamos->SetColSize( 2, 178 );
	m_grilla_Prestamos->SetColSize( 3, 128 );
	m_grilla_Prestamos->EnableDragColMove( false );
	m_grilla_Prestamos->EnableDragColSize( true );
	m_grilla_Prestamos->SetColLabelValue( 0, wxT("Título") );
	m_grilla_Prestamos->SetColLabelValue( 1, wxT("Autor") );
	m_grilla_Prestamos->SetColLabelValue( 2, wxT("Estado") );
	m_grilla_Prestamos->SetColLabelValue( 3, wxT("ID") );
	m_grilla_Prestamos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla_Prestamos->EnableDragRowSize( true );
	m_grilla_Prestamos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla_Prestamos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_grilla_Prestamos->SetFont( wxFont( 11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial Narrow") ) );
	m_grilla_Prestamos->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSizer25->Add( m_grilla_Prestamos, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Eliminar Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button22, 0, wxALL, 5 );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Buscar :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer26->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_busqueda_libro = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_busqueda_libro, 1, wxALL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button19, 0, wxALL, 5 );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Listo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( m_button18, 0, wxALL, 5 );


	bSizer25->Add( bSizer26, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Editar Libro"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( m_button21, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Ordenar por :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer60->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choice2Choices[] = { wxT("-"), wxT("Titulo"), wxT("ID"), wxT("Autor"), wxEmptyString };
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	bSizer60->Add( m_choice2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer59->Add( bSizer60, 0, 0, 5 );


	bSizer25->Add( bSizer59, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer25 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::click_Eliminar_libro ), NULL, this );
	m_busqueda_libro->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BasePrestamos::ClickBotonBUSCAR ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::ClickConfirmar ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::clickCANCELAR ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::clickEditarLibro ), NULL, this );
	m_choice2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BasePrestamos::click_ordenar_libros ), NULL, this );
}

BasePrestamos::~BasePrestamos()
{
	// Disconnect Events
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::click_Eliminar_libro ), NULL, this );
	m_busqueda_libro->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( BasePrestamos::ClickBotonBUSCAR ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::ClickConfirmar ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::clickCANCELAR ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BasePrestamos::clickEditarLibro ), NULL, this );
	m_choice2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( BasePrestamos::click_ordenar_libros ), NULL, this );

}

BaseAgregar::BaseAgregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Agregar Socio nuevo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	m_staticText25->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Arial") ) );

	bSizer60->Add( m_staticText25, 0, wxALL, 5 );


	bSizer59->Add( bSizer60, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer5->Add( bSizer59, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );

	M_nomb = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( M_nomb, 1, wxALL|wxEXPAND, 5 );


	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Apellido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer61->Add( m_staticText31, 0, wxALL, 5 );

	M_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( M_apellido, 1, wxALL|wxEXPAND, 5 );


	bSizer51->Add( bSizer61, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer76->Add( m_staticText29, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer76->Add( m_textDNI, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer75->Add( bSizer76, 1, wxEXPAND, 5 );


	bSizer51->Add( bSizer75, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Telefono: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer62->Add( m_staticText32, 0, wxALL, 5 );

	M_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( M_telefono, 1, wxALL, 5 );


	bSizer52->Add( bSizer62, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer63->Add( m_staticText33, 0, wxALL, 5 );

	M_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( M_direccion, 1, wxALL, 5 );


	bSizer53->Add( bSizer63, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Localidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer64->Add( m_staticText34, 0, wxALL, 5 );

	M_localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer64->Add( M_localidad, 1, wxALL, 5 );


	bSizer54->Add( bSizer64, 0, wxEXPAND, 5 );


	bSizer53->Add( bSizer54, 0, wxEXPAND, 5 );


	bSizer52->Add( bSizer53, 1, wxEXPAND, 5 );


	bSizer51->Add( bSizer52, 1, wxEXPAND, 5 );


	bSizer5->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("E-mail :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer65->Add( m_staticText35, 0, wxALL, 5 );

	M_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer65->Add( M_mail, 1, wxALL, 5 );


	bSizer55->Add( bSizer65, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText36 = new wxStaticText( this, wxID_ANY, wxT("Fecha Nacimiento:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer66->Add( m_staticText36, 0, wxALL, 5 );

	M_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( M_dia, 0, wxALL, 5 );

	M_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( M_mes, 0, wxALL, 5 );

	M_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( M_anio, 0, wxALL, 5 );


	bSizer56->Add( bSizer66, 1, 0, 5 );


	bSizer55->Add( bSizer56, 0, wxEXPAND, 5 );


	bSizer5->Add( bSizer55, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );

	m_button10 = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer77->Add( m_button10, 0, wxALL, 5 );

	m_button11 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer77->Add( m_button11, 0, wxALL, 5 );


	bSizer5->Add( bSizer77, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickbotGuardar ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickbotCancelar ), NULL, this );
}

BaseAgregar::~BaseAgregar()
{
	// Disconnect Events
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickbotGuardar ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregar::ClickbotCancelar ), NULL, this );

}

BaseAgregarLibro::BaseAgregarLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Agregar nuevo Libro:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	m_staticText22->SetFont( wxFont( 14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Malgun Gothic") ) );

	bSizer52->Add( m_staticText22, 0, wxALL, 5 );


	bSizer51->Add( bSizer52, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer38->Add( bSizer51, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Titulo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	m_staticText16->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer39->Add( m_staticText16, 0, wxALL, 5 );

	m_titulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_titulo, 1, wxALL, 5 );


	bSizer38->Add( bSizer39, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Autor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer41->Add( m_staticText17, 0, wxALL, 5 );

	m_autor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( m_autor, 1, wxALL, 5 );


	bSizer40->Add( bSizer41, 1, wxEXPAND, 5 );


	bSizer38->Add( bSizer40, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Genero"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	m_staticText18->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, wxT("Arial") ) );

	bSizer43->Add( m_staticText18, 0, wxALL, 5 );

	m_genero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_genero, 1, wxALL, 5 );


	bSizer42->Add( bSizer43, 1, wxEXPAND, 5 );


	bSizer38->Add( bSizer42, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );


	bSizer44->Add( bSizer45, 1, wxEXPAND, 5 );


	bSizer38->Add( bSizer44, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );


	bSizer46->Add( bSizer47, 1, wxEXPAND, 5 );


	bSizer38->Add( bSizer46, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer49->Add( m_button18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Confirmar y Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer49->Add( m_button19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer48->Add( bSizer49, 0, wxALIGN_RIGHT, 5 );


	bSizer38->Add( bSizer48, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer38 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregarLibro::clickCancelLibro ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregarLibro::ClickGuardarLibro ), NULL, this );
}

BaseAgregarLibro::~BaseAgregarLibro()
{
	// Disconnect Events
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregarLibro::clickCancelLibro ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BaseAgregarLibro::ClickGuardarLibro ), NULL, this );

}

#include "ClassDialog.hpp"

//(*InternalHeaders(ClassDialog)
#include <wx/xrc/xmlres.h>
//*)

//(*IdInit(ClassDialog)
//*)

BEGIN_EVENT_TABLE(ClassDialog,wxDialog)
	//(*EventTable(ClassDialog)
	//*)
END_EVENT_TABLE()

ClassDialog::ClassDialog(wxWindow* parent)
{
	//(*Initialize(ClassDialog)
	wxXmlResource::Get()->LoadObject(this,parent,_T("ClassDialog"),_T("wxDialog"));
	//*)
}

ClassDialog::~ClassDialog()
{
	//(*Destroy(ClassDialog)
	//*)
}


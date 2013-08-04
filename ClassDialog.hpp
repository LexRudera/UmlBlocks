#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H

//(*Headers(ClassDialog)
#include <wx/dialog.h>
//*)

class ClassDialog: public wxDialog
{
	public:

		ClassDialog(wxWindow* parent);
		virtual ~ClassDialog();

		//(*Declarations(ClassDialog)
		//*)

	protected:

		//(*Identifiers(ClassDialog)
		//*)

	private:

		//(*Handlers(ClassDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif

#ifndef UMLCANVAS_H
#define UMLCANVAS_H

#include <wx/wxsf/wxShapeFramework.h>
#include "UmlEditor.h"
#include "UmlMember.h"
#include "UmlClass.h"
#include "UmlQuickEditPopup.h"

class UmlEditor;
class UmlCanvas : public wxSFShapeCanvas {
public:
	UmlCanvas(wxSFDiagramManager* manager, UmlEditor* editor);
	~UmlCanvas();

	void OnLeftDown(wxMouseEvent& event);
	void OnLeftDoubleClick (wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent& event);
	void OnRightDown(wxMouseEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnConnectionFinished(wxSFLineShape* connection);
	void OnMouseWheel(wxMouseEvent& event);
	void OnBeginDrag(const wxPoint &pos);
protected:
private:
	DECLARE_EVENT_TABLE()
	// Gotta love a complex quick edit dialog feature, spanning across many individual function. Them pointers. Dumb notes incoming!:
	// Double click, see if you want it created and shown.
	// Click anywhere and the box disappears and gets destroyed without changes
	// Press enter and the box will disappear, change the data according to the dialog and destroy it
	UmlQuickEditPopup* EditDiag;
};

#endif // UMLCANVAS_H

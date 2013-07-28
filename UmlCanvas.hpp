#ifndef UMLCANVAS_HPP
#define UMLCANVAS_HPP

#include <wx/wxsf/wxShapeFramework.h>
#include "UmlEditor.hpp"
#include "Member.hpp"
#include "Class.hpp"
#include "QuickEditPopup.hpp"

class UmlEditor;
class UmlCanvas : public wxSFShapeCanvas {
public:
	UmlCanvas(wxSFDiagramManager* manager, UmlEditor* editor);
	~UmlCanvas();

	// Events
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
	QuickEditPopup* EditDiag = 0;
	UmlEditor* m_Editor;
};

#endif // UMLCANVAS_HPP

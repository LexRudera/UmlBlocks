#ifndef UMLCANVAS_H
#define UMLCANVAS_H

#include <wx/wxsf/wxShapeFramework.h>
#include "UmlEditor.h"
#include "UmlMember.h"
#include "UmlClass.h"
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
};

#endif // UMLCANVAS_H

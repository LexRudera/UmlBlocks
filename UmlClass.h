#ifndef UMLCLASS_H
#define UMLCLASS_H

#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/wxsf/DiagramManager.h>
#include <wx/wxsf/RectShape.h>

class UmlClass : public wxSFRectShape {
public:
	UmlClass(wxRealPoint pos, wxSFDiagramManager* man);
	virtual ~UmlClass();
	virtual void Draw(wxDC& dc);
protected:
	virtual void DrawSelected(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
private:
	wxString MemberVariables[];
	wxString MemberFunctions[];
};

#endif // UMLCLASS_H

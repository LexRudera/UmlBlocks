#ifndef UMLCLASS_H
#define UMLCLASS_H

#include <wx/gdicmn.h>
#include <list>
//#include <wx/wxsf/DiagramManager.h>
#include <wx/wxsf/ShapeBase.h>
#include "UmlMemberVar.h"
#include "UmlMemberFunc.h"

class UmlClass : public wxSFShapeBase {
public:
    XS_DECLARE_CLONABLE_CLASS(UmlClass);

    UmlClass();
	UmlClass(wxRealPoint pos, wxSFDiagramManager* man);
	UmlClass(const UmlClass& obj);
	void Create(wxString ClassName);
	virtual ~UmlClass();
    virtual wxRect GetBoundingBox();
    void AddVariable(wxString Name, wxString Type, Accessibility Access = Public, int Pointer = 0, bool Reference = false, bool Static = false);
    void RemoveVariable();
    void AddFunction(wxString Name, wxString Type, Accessibility Access = Public, std::list<UmlMemberVar> Parameters = 0, bool Static = false);
    void RemoveFunction();
protected:
    virtual void DrawNormal(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawHighlighted(wxDC& dc);
private:
    wxPen BorderColour;
    wxBrush FillColour;
    wxFont Font;
	wxCoord MinTextWidth;
	wxCoord VarFieldHeight;
	wxCoord FuncFieldHeight;

    wxString ClassName;
	std::list<UmlMemberVar> MemberVariables;
	std::list<UmlMemberFunc> MemberFunctions;
	wxString Comments;

    void UpdateShapeSize(wxDC* dc);
    void DrawShape(wxDC* dc);
};

#endif // UMLCLASS_H

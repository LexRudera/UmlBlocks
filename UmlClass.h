#ifndef UMLCLASS_H
#define UMLCLASS_H

#include <wx/gdicmn.h>
#include <vector>
//#include <wx/wxsf/DiagramManager.h>
#include <wx/wxsf/ShapeBase.h>
#include "UmlMemberVar.h"
#include "UmlMemberFunc.h"

class UmlClass : public wxSFShapeBase {
public:
    XS_DECLARE_CLONABLE_CLASS(wxSFRectShape);

    UmlClass(void);
	UmlClass(wxRealPoint pos, wxSFDiagramManager* man);
	UmlClass(const UmlClass& obj);
	virtual ~UmlClass();
    virtual wxRect GetBoundingBox();
    void AddVariable();
    void RemoveVariable();
    void AddFunction();
    void RemoveFunction();
protected:
    virtual void DrawNormal(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawHighlighted(wxDC& dc);
private:
    wxPen BorderColour;
    wxBrush FillColour;
	wxRealPoint VarRectSize;
	wxRealPoint FuncRectSize;
	std::vector<UmlMemberVar> MemberVariables;
	std::vector<UmlMemberFunc> MemberFunctions;

    void UpdateShapeSize();
    void DrawShape(wxDC* dc);
};

#endif // UMLCLASS_H

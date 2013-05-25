#ifndef Class_HPP
#define Class_HPP

#include <wx/gdicmn.h>
#include <list>
//#include <wx/wxsf/DiagramManager.h>
#include <wx/wxsf/ShapeBase.h>
#include "MemberVar.hpp"
#include "MemberFunc.hpp"

class Class : public wxSFShapeBase {
public:
    XS_DECLARE_CLONABLE_CLASS(Class);

    Class();
	Class(wxRealPoint pos, wxSFDiagramManager* man);
	Class(const Class& obj);
	void Create(wxString ClassName);
	virtual ~Class();
    virtual wxRect GetBoundingBox();
    void AddVariable(wxString Name, wxString Type, Accessibility Access = Public, int Pointer = 0, bool Reference = false, bool Static = false);
    void RemoveVariable();
    void AddFunction(wxString Name, wxString Type, Accessibility Access = Public, std::list<MemberVar> Parameters = 0, bool Static = false);
    void RemoveFunction();
    Member* GetMemberAtPosition(const wxPoint& Pos);
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
	std::list<MemberVar> MemberVariables;
	std::list<MemberFunc> MemberFunctions;
	wxString Comments;

    void UpdateShapeSize(wxDC* dc);
    void DrawShape(wxDC* dc);
};

#endif // Class_HPP

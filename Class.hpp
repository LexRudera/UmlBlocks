#ifndef Class_HPP
#define Class_HPP

#include <wx/gdicmn.h>
#include <vector>
//#include <wx/wxsf/DiagramManager.h>
#include <wx/wxsf/ShapeBase.h>
#include "MemberFunc.hpp"

class Class : public wxSFShapeBase {
public:
    XS_DECLARE_CLONABLE_CLASS(Class);

    Class();
	Class(wxRealPoint pos, wxSFDiagramManager* man);
	Class(const Class& obj);
	void Init(const wxString& ClassName);
	virtual ~Class();
    virtual wxRect GetBoundingBox();
    void AddVariable(const MemberVar& m);
    void AddVariable(const wxString& Name, const wxString& Type, Accessibility Access = Public, int Pointer = 0, bool Reference = false, bool Static = false);
    void RemoveVariable();
    void AddFunction(const MemberFunc& m);
    void AddFunction(const wxString& Name, const wxString& Type, Accessibility Access = Public, std::vector<MemberVar>* Parameters = 0, bool Static = false);
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
	std::vector<MemberVar> MemberVariables;
	std::vector<MemberFunc> MemberFunctions;
	wxString Comments;

    void UpdateShapeSize(wxDC* dc);
    void DrawShape(wxDC* dc);
};

#endif // Class_HPP

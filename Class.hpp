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

    void UpdateFunctions(const std::vector<MemberFunc>& a_funcs);
    void UpdateVariables(const std::vector<MemberVar>& a_vars);
    const std::vector<MemberFunc>& GetFunctions() const {return m_MemberFunctions;}
    const std::vector<MemberVar>& GetVariables() const {return m_MemberVariables;}

    Member* GetMemberAtPosition(const wxPoint& Pos);
protected:
    virtual void DrawNormal(wxDC& dc);
	virtual void DrawHover(wxDC& dc);
	virtual void DrawHighlighted(wxDC& dc);
private:
    wxPen m_BorderColour;
    wxBrush m_FillColour;
    wxFont m_Font;
	wxCoord m_MinTextWidth;
	wxCoord m_VarFieldHeight;
	wxCoord m_FuncFieldHeight;
	bool m_SizeRefresh = true;
	wxRect m_Size;

    wxString m_ClassName;
	std::vector<MemberVar> m_MemberVariables;
	std::vector<MemberFunc> m_MemberFunctions;
	wxString m_Description;

    void UpdateShapeSize(wxDC* dc);
    void DrawShape(wxDC* dc);
};

#endif // Class_HPP

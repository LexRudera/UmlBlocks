#include "Class.hpp"
#include <sdk.h>
#include "wx/wxsf/ShapeCanvas.h"
#include "wx/wxsf/CommonFcn.h"
//#include <wx/wx.h>

using namespace wxSFCommonFcn;

XS_IMPLEMENT_CLONABLE_CLASS(Class, wxSFShapeBase);

Class::Class() : wxSFShapeBase() {
	//BorderColour = wxPen(wxColour(0, 0, 0));
	//FillColour = wxBrush(wxColour(255, 255, 255));
	//MinTextWidth = 3;
}

// Keep this around. You never know.
/*Class::Class(wxRealPoint pos, wxSFDiagramManager* man): wxSFShapeBase(pos, man)
{
    BorderColour = wxPen(wxColour(0, 0, 0));
    FillColour = wxBrush(wxColour(255, 255, 255));
	Manager::Get()->GetLogManager()->Log(wxT("ctor"));
}*/

Class::Class(const Class& obj) : wxSFShapeBase(obj) {
	//BorderColour = wxPen(wxColour(0, 0, 0));
	//FillColour = wxBrush(wxColour(255, 255, 255));
	//MinTextWidth = 3;
	//Font = wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL,)
}

Class::~Class() {
	//dtor
}

void Class::Init(const wxString& Name) {
	m_BorderColour = wxPen(wxColour(0, 0, 0));
	m_FillColour = wxBrush(wxColour(255, 255, 255));
	m_MinTextWidth = 3;
	// For Luna's sake, keep this font assignment! All the text width calculations randomly freak out without it.
	m_Font = wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	m_ClassName = Name;
}

// This function is called over and over again, as long as the mouse is even inside the diagram.
// Keep tough calculations away from here.
wxRect Class::GetBoundingBox() {
	return wxRect(Conv2Point(GetAbsolutePosition()), wxSize(m_Width,50));
}

// This function evaluates and updates the size of the boxes, that contains the class members.
void Class::UpdateShapeSize(wxDC* dc) {
	// Check if size calculations is wanted
	if (!m_SizeRefresh)
		return;
	m_SizeRefresh = false;
	// Initialize evaluation of text sizes.
	wxCoord EvalWidth;
	// Evaluate the size of the title.
	dc->GetTextExtent(m_ClassName, &EvalWidth, 0);
	if (EvalWidth > m_MinTextWidth)
		m_MinTextWidth = EvalWidth;

	// Evaluate the size of the variables
	if (!m_MemberVariables.empty()) // In case there is nothing, why even bother trying. Also against potential errors in the list iterator
        for(std::vector<MemberVar>::const_iterator i = m_MemberVariables.begin(); i != m_MemberVariables.end(); ++i) {
            dc->GetTextExtent(i->GetName(), &EvalWidth, 0);
            if (EvalWidth > m_MinTextWidth)
                m_Width = EvalWidth;
        }
	// Evaluate the size of the functions
	if (!m_MemberFunctions.empty())
        for(std::vector<MemberFunc>::const_iterator i = m_MemberFunctions.begin(); i != m_MemberFunctions.end(); ++i) {
            dc->GetTextExtent(i->GetName(), &EvalWidth, 0);
            if (EvalWidth > m_MinTextWidth)
                m_Width = EvalWidth;
        }

	// Apply width limiter
	if ( m_WidthLimit !=0 && m_Width > m_WidthLimit)
		m_Width = m_WidthLimit;

	// Set size
	m_Size.SetWidth(m_Width);
	m_Size.SetHeight(30+m_VarFieldHeight+m_FuncFieldHeight);
}

// This function is only called when the mouse does anything with the shape.
// Entering it, clicking it, moving it, that sorta stuff. It isn't call a billion
// times per second like GetBoundingBox is, so more tough calculations is
void Class::DrawShape(wxDC* dc) {
	// Setting a font to prevent random errors in the UpdateShapeSize function
	dc->SetFont(m_Font);
	UpdateShapeSize(dc); // Self explaining

	// Class name field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(m_MinTextWidth+10,30));
	// Function field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,30), wxSize(m_MinTextWidth+10,30));
	// Variable field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,60), wxSize(m_MinTextWidth+10,30));
	// Draw class name
	dc->DrawText(m_ClassName, Conv2Point(GetAbsolutePosition())+wxPoint(5,2));
	// Draw Functions
	// Draw Variables
}

void Class::DrawNormal(wxDC& dc) {
	dc.SetPen(m_BorderColour);
	dc.SetBrush(m_FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void Class::DrawHover(wxDC& dc) {
	dc.SetPen(wxPen(m_nHoverColor, 1));
	dc.SetBrush(m_FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void Class::DrawHighlighted(wxDC& dc) {
	dc.SetPen(wxPen(m_nHoverColor, 2));
	dc.SetBrush(m_FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void UpdateFunctions(const std::vector<MemberFunc>& a_funcs) {
}

void UpdateVariables(const std::vector<MemberVar>& a_vars) {
}

Member* Class::GetMemberAtPosition(const wxPoint& a_Pos)
{
    /*wxPoint Pos = wxPoint(a_Pos.x-GetAbsolutePosition().x,a_Pos.y-GetAbsolutePosition().y);

    if (!MemberVariables.empty()) // In case there is nothing, why even bother trying. Also against potential errors in the list iterator
    {
        //for(Member* i = &*MemberVariables.begin(); i != &*MemberVariables.end(); ++i){
        for(std::vector<MemberVar>::iterator i = MemberVariables.begin(); i != MemberVariables.end(); ++i){
            if(i->GetPos().x < Pos.x && i->GetPos().y < Pos.y &&
               i->GetSize().GetWidth() > Pos.x && i->GetSize().GetHeight() > Pos.y)
               return &*i; // Oddest fix thingy ever. The iterator behaves like a pointer, ie. a variable that points to another variable,
               // but is not actually a pointer and does not merely a memory address. Because it behaves like a pointer, it can be dereferenced
               // to the pointed variable and then referenced to a normal pointer. Funky stuff.
        }
    }
	if (!MemberFunctions.empty())
    {
        for(std::vector<MemberFunc>::iterator i = MemberFunctions.begin(); i != MemberFunctions.end(); ++i) {
            if(i->GetPos().x < Pos.x && i->GetPos().y < Pos.y &&
               i->GetSize().GetWidth() > Pos.x && i->GetSize().GetHeight() > Pos.y)
               return &*i;
        }
    }*/
    return 0;
}

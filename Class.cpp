#include "Class.hpp"
#include <sdk.h>
#include "wx/wxsf/ShapeCanvas.h"
#include "wx/wxsf/CommonFcn.h"
#include "Utilities.hpp"
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

Class* Class::Init(const wxString& a_Name) {
	m_BorderColour = wxPen(wxColour(0, 0, 0));
	m_FillColour = wxBrush(wxColour(255, 255, 255));
	m_Width = 10;
	// For Luna's sake, keep this font assignment! All the text width calculations randomly freak out without it.
	m_Font = wxFont(10, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	m_Name = a_Name;
	m_BoundingSize = wxSize(10,10);
	return this;
}

// This function is called over and over again, as long as the mouse is even inside the diagram.
// Keep tough calculations away from here.
wxRect Class::GetBoundingBox() {
	//return wxRect(Conv2Point(GetAbsolutePosition()), wxSize(m_Width,50));
	return wxRect(Conv2Point(GetAbsolutePosition()), m_BoundingSize);
}

// This function evaluates and updates the size of the boxes, that contains the class members.
void Class::UpdateShapeSize(wxDC* dc) {
	// Check if size calculations is wanted
	if (!m_SizeRefresh)
		return;
	m_SizeRefresh = false; // Then let's run it and check it, that it's done.

	// Initialize evaluation of text widths.
	wxCoord EvalWidth;
	// Evaluate the width of the title.
	dc->GetTextExtent(m_Name, &EvalWidth, 0);
	EvalWidth += 10;
	if (EvalWidth > m_Width)
		m_Width = EvalWidth;

	// Evaluate the size of the variables
	if (!m_MemberVariables.empty()) // In case there is nothing, why even bother trying. Also against potential errors in the list iterator
        for(std::vector<MemberVar>::iterator i = m_MemberVariables.begin(); i != m_MemberVariables.end(); ++i) {
            dc->GetTextExtent(i->GetUmlString(), &EvalWidth, 0);
            EvalWidth += 10;
            if (EvalWidth > m_Width)
                m_Width = EvalWidth;
        }
    m_VarFieldHeight = (m_Font.GetPointSize()+2+2)*m_MemberVariables.size()+15;

	// Evaluate the size of the functions
	if (!m_MemberFunctions.empty()) {
        for(std::vector<MemberFunc>::iterator i = m_MemberFunctions.begin(); i != m_MemberFunctions.end(); ++i) {
            dc->GetTextExtent(i->GetUmlString(), &EvalWidth, 0);
            EvalWidth += 10;
            if (EvalWidth > m_Width)
                m_Width = EvalWidth;
        }
    }
    m_FuncFieldHeight = (m_Font.GetPointSize()+2+2)*m_MemberFunctions.size()+15;

	// Apply width limiter
	if ( m_WidthLimit !=0 && m_Width > m_WidthLimit)
		m_Width = m_WidthLimit;

	// Set size
	m_NameField.Set(m_Width, 30);
	m_VarField.Set(m_Width, m_VarFieldHeight);
	m_FuncField.Set(m_Width, m_FuncFieldHeight);
	m_BoundingSize.Set(m_Width, 30+m_VarFieldHeight+m_FuncFieldHeight); // Fast BoundingBox carrier.

	// Calculate name text position
	dc->GetTextExtent(m_Name, &m_NamePos.x, &m_NamePos.y); // Clever. m_NamePos is it's own carrier.
	m_NamePos.x = m_NameField.x/2 - m_NamePos.x/2;
	m_NamePos.y = m_NameField.y/2 - m_NamePos.y/2;
}

// This function is only called when the mouse does anything with the shape.
// Entering it, clicking it, moving it, that sorta stuff. It isn't called a billion
// times per second like GetBoundingBox is, so more tough calculations is
void Class::DrawShape(wxDC* dc) {
	// Setting a font to prevent random errors in the UpdateShapeSize function
	dc->SetFont(m_Font);
	UpdateShapeSize(dc); // Self explaining

	// Class name field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), m_NameField);
	// Function field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0, m_NameField.y-1), m_FuncField);
	// Variable field
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0, m_NameField.y+m_FuncField.y-2), m_VarField);
	// Draw class name
	//dc->DrawText(m_Name, Conv2Point(GetAbsolutePosition())+wxPoint(5,2));
	dc->DrawText(m_Name, Conv2Point(GetAbsolutePosition())+m_NamePos);
	// Draw Functions
	for (int i = 0; i < m_MemberFunctions.size(); i++) {
        dc->DrawText(m_MemberFunctions[i].GetUmlString(), Conv2Point(GetAbsolutePosition())+wxPoint(5, m_NameField.y+5+(m_Font.GetPointSize()+2+2)*i-1));
	}
	// Draw Variables
	for (int i = 0; i < m_MemberVariables.size(); i++) {
        dc->DrawText(m_MemberVariables[i].GetUmlString(), Conv2Point(GetAbsolutePosition())+wxPoint(5, m_NameField.y+m_FuncField.y+5+(m_Font.GetPointSize()+2+2)*i-2));
	}
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

void Class::UpdateFunctions(const std::vector<MemberFunc>& a_funcs) {
m_MemberFunctions = a_funcs;
}

void Class::UpdateVariables(const std::vector<MemberVar>& a_vars) {
m_MemberVariables = a_vars;
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

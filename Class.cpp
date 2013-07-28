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
	Manager::Get()->GetLogManager()->Log(_("Funky Class Dtor"));
}

void Class::Init(const wxString& Name) {
	BorderColour = wxPen(wxColour(0, 0, 0));
	FillColour = wxBrush(wxColour(255, 255, 255));
	MinTextWidth = 3;
	// For Odin's sake, keep this font assignment! All the text width calculations randomly freak out without it.
	Font = wxFont(12, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	ClassName = Name;
}

// This function is called over and over again, as long as the mouse is even inside the diagram.
// Keep tough calculations away from here.
wxRect Class::GetBoundingBox() {

	return wxRect(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
}

// This function evaluates and updates the size of the boxes, that contains the class members.
void Class::UpdateShapeSize(wxDC* dc) {
	// Initialize evaluation of text sizes.
	wxCoord EvalWidth;
	// Evaluate the size of the title.
	dc->GetTextExtent(ClassName, &EvalWidth, 0);
	if (EvalWidth > MinTextWidth)
		MinTextWidth = EvalWidth;

	// Evaluate the size of the variables
	if (!MemberVariables.empty()) // In case there is nothing, why even bother trying. Also against potential errors in the list iterator
        for(std::list<MemberVar>::const_iterator i = MemberVariables.begin(); i != MemberVariables.end(); ++i) {
            dc->GetTextExtent(i->GetName(), &EvalWidth, 0);
            if (EvalWidth > MinTextWidth)
                MinTextWidth = EvalWidth;
        }
	// Evaluate the size of the functions
	if (!MemberFunctions.empty())
        for(std::list<MemberFunc>::const_iterator i = MemberFunctions.begin(); i != MemberFunctions.end(); ++i) {
            dc->GetTextExtent(i->GetName(), &EvalWidth, 0);
            if (EvalWidth > MinTextWidth)
                MinTextWidth = EvalWidth;
        }
}

// This function is only called when the mouse does anything with the shape.
// Entering it, clicking it, moving it, that sorta stuff. It isn't call a billion
// times per second like GetBoundingBox is, so more tough calculations is
void Class::DrawShape(wxDC* dc) {
	// Setting a font to prevent random errors in the UpdateShapeSize function
	dc->SetFont(Font);
	//dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), Conv2Size(m_nRectSize));
	//dc->DrawRectangle(wxRect);
	UpdateShapeSize(dc);
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(MinTextWidth+10,30));
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,30), wxSize(MinTextWidth+10,30));
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,60), wxSize(MinTextWidth+10,30));
	dc->DrawText(ClassName, Conv2Point(GetAbsolutePosition())+wxPoint(5,2));
	Manager::Get()->GetLogManager()->Log(wxT("DShape"));
}

void Class::DrawNormal(wxDC& dc) {
	dc.SetPen(BorderColour);
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void Class::DrawHover(wxDC& dc) {
	dc.SetPen(wxPen(m_nHoverColor, 1));
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void Class::DrawHighlighted(wxDC& dc) {
	dc.SetPen(wxPen(m_nHoverColor, 2));
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void Class::AddVariable(wxString Name, wxString Type, Member::Accessibility Access, int Pointer, bool Reference, bool Static) {
    MemberVar var = MemberVar(Name, Type, Access, Pointer, Reference, Static);
    MemberVariables.push_back(var);
}

void Class::AddFunction(wxString Name, wxString Type, Member::Accessibility Access, std::list<MemberVar> Parameters, bool Static) {
    MemberFunc func = MemberFunc(Name, Type, Access, Parameters, Static);
    MemberFunctions.push_back(func);
}

void Class::RemoveVariable() {

}

void Class::RemoveFunction() {

}

Member* Class::GetMemberAtPosition(const wxPoint& a_Pos)
{
    wxPoint Pos = wxPoint(a_Pos.x-GetAbsolutePosition().x,a_Pos.y-GetAbsolutePosition().y);

    if (!MemberVariables.empty()) // In case there is nothing, why even bother trying. Also against potential errors in the list iterator
    {
        //for(Member* i = &*MemberVariables.begin(); i != &*MemberVariables.end(); ++i){
        for(std::list<MemberVar>::iterator i = MemberVariables.begin(); i != MemberVariables.end(); ++i){
            if(i->GetPos().x < Pos.x && i->GetPos().y < Pos.y &&
               i->GetSize().GetWidth() > Pos.x && i->GetSize().GetHeight() > Pos.y)
               return &*i; // Oddest fix thingy ever. The iterator behaves like a pointer, ie. a variable that points to another variable,
               // but is not actually a pointer and does not merely a memory address. Because it behaves like a pointer, it can be dereferenced
               // to the pointed variable and then referenced to a normal pointer. Funky stuff.
        }
    }
	if (!MemberFunctions.empty())
    {
        for(std::list<MemberFunc>::iterator i = MemberFunctions.begin(); i != MemberFunctions.end(); ++i) {
            if(i->GetPos().x < Pos.x && i->GetPos().y < Pos.y &&
               i->GetSize().GetWidth() > Pos.x && i->GetSize().GetHeight() > Pos.y)
               return &*i;
        }
    }
    return 0;
}

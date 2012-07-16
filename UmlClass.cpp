#include "UmlClass.h"
#include <sdk.h>
#include "wx/wxsf/ShapeCanvas.h"
#include "wx/wxsf/CommonFcn.h"
//#include <wx/wx.h>

using namespace wxSFCommonFcn;

XS_IMPLEMENT_CLONABLE_CLASS(UmlClass, wxSFShapeBase);

UmlClass::UmlClass(void) : wxSFShapeBase()
{
    BorderColour = wxPen(wxColour(0, 0, 0));
    FillColour = wxBrush(wxColour(255, 255, 255));
}

/*UmlClass::UmlClass(wxRealPoint pos, wxSFDiagramManager* man): wxSFShapeBase(pos, man)
{
    BorderColour = wxPen(wxColour(0, 0, 0));
    FillColour = wxBrush(wxColour(255, 255, 255));
	Manager::Get()->GetLogManager()->Log(wxT("ctor"));
}*/

UmlClass::UmlClass(const UmlClass& obj) : wxSFShapeBase(obj)
{
    BorderColour = wxPen(wxColour(0, 0, 0));
    FillColour = wxBrush(wxColour(255, 255, 255));
}

UmlClass::~UmlClass() {
	//dtor
}

wxRect UmlClass::GetBoundingBox()
{
	// Evaluations to determine how large the class shape is.
	UpdateShapeSize();
    return wxRect(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
}

void UmlClass::UpdateShapeSize()
{

}

void UmlClass::DrawShape(wxDC* dc)
{
	//dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), Conv2Size(m_nRectSize));
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(100,30));
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,30), wxSize(100,30));
	dc->DrawRectangle(Conv2Point(GetAbsolutePosition())+wxSize(0,60), wxSize(100,30));
}

void UmlClass::DrawNormal(wxDC& dc)
{
	dc.SetPen(BorderColour);
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void UmlClass::DrawHover(wxDC& dc)
{
	dc.SetPen(wxPen(m_nHoverColor, 1));
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

void UmlClass::DrawHighlighted(wxDC& dc)
{
	dc.SetPen(wxPen(m_nHoverColor, 2));
	dc.SetBrush(FillColour);
	//dc.DrawRectangle(Conv2Point(GetAbsolutePosition()), wxSize(50,50));
	DrawShape(&dc);
	dc.SetBrush(wxNullBrush);
	dc.SetPen(wxNullPen);
}

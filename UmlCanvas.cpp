#include "UmlCanvas.hpp"
#include <sdk.h>

BEGIN_EVENT_TABLE(UmlCanvas, wxSFShapeCanvas)
	EVT_KEY_DOWN(UmlCanvas::OnKeyDown)
END_EVENT_TABLE()

UmlCanvas::UmlCanvas(wxSFDiagramManager* manager, UmlEditor* editor)
	: wxSFShapeCanvas(manager, editor, wxID_ANY, wxDefaultPosition, editor->GetSize(), wxHSCROLL | wxVSCROLL | wxSTATIC_BORDER) {
	editor->SetCanvas(this);
	//AddStyle(sfsGRID_USE);
	//AddStyle(sfsGRID_SHOW);
	SetGridLineMult(5);
	SetGridStyle(wxSHORT_DASH);
	AddStyle(sfsGRADIENT_BACKGROUND);
	SetGradientFrom(sfdvSHAPECANVAS_GRADIENT_FROM);
	SetGradientTo(sfdvSHAPECANVAS_GRADIENT_TO);
	GetDiagramManager()->ClearAcceptedShapes();
	GetDiagramManager()->AcceptShape(wxT("All"));

	m_Editor = editor;
}

UmlCanvas::~UmlCanvas() {
}

void UmlCanvas::OnRightDown(wxMouseEvent& event) {
}

void UmlCanvas::OnMouseWheel(wxMouseEvent& event) {
}

void UmlCanvas::OnLeftDown(wxMouseEvent& event) {
	wxSFShapeCanvas::OnLeftDown(event);
	HideAllHandles();
	if(EditDiag != 0)
    {
        EditDiag->Show(false);
        EditDiag->Destroy();
    }
}

void UmlCanvas::OnLeftDoubleClick(wxMouseEvent& event) {
    //wxSFShapeCanvas::OnLeftDoubleClick(event);
    //Member* ClickedMember = static_cast<Class*>(GetShapeAtPosition(event.GetPosition()))->GetMemberAtPosition(event.GetPosition());
    Class* ClickedClass = static_cast<Class*>(GetShapeAtPosition(event.GetPosition()));
    if (ClickedClass != 0)
    {
        Member* ClickedMember = ClickedClass->GetMemberAtPosition(event.GetPosition());
        if (ClickedMember != 0)
        {
            //EditDiag = new QuickEditPopup(event.GetPosition(),ClickedMember->GetMemberGroup());
            //EditDiag->Show(true);
        }
    }
}

void UmlCanvas::OnLeftUp(wxMouseEvent& event) {
	wxSFShapeCanvas::OnLeftUp(event);
	HideAllHandles();
	GetMultiselectionBox().ShowHandles(false);
}

void UmlCanvas::OnKeyDown(wxKeyEvent& event){
    if(event.GetKeyCode() == WXK_DELETE){
        ShapeList sl;
        GetSelectedShapes(sl);
        GetDiagramManager()->RemoveShapes(sl);
        Refresh(false);
    }
    if(event.GetKeyCode() == WXK_EXECUTE) // I expect Execute being the Enter button
    {

    }
}

void UmlCanvas::OnConnectionFinished(wxSFLineShape* connection) {
}

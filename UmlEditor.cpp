#include "UmlEditor.hpp"

BEGIN_EVENT_TABLE(UmlEditor, EditorBase)
	EVT_SIZE(UmlEditor::OnSize)
END_EVENT_TABLE()

UmlEditor::UmlEditor(wxWindow* parent, const wxString& filename)
	: EditorBase(parent, filename) {
	m_rRealtime = false;
}

UmlEditor::~UmlEditor() {
	//dtor
}

void UmlEditor::OnSize(wxSizeEvent& event) {
	m_pCanvas->SetSize(this->GetSize());
}

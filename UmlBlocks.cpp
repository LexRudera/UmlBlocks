#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "UmlBlocks.h"

#include "UmlCanvas.h"
#include "UmlClass.h"
#include "UmlNewEntityDialog.h"
// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace {
PluginRegistrant<UmlBlocks> reg(_T("UmlBlocks"));
}


int NewUmlMenuOptionId = wxNewId();
int NewClassMenuOptionId = wxNewId();
int RevEngiMenuOptionId = wxNewId();
int GenCodeMenuOptionId = wxNewId();
int SaveBmpMenuOptionId = wxNewId();
// events handling
BEGIN_EVENT_TABLE(UmlBlocks, cbPlugin)
	EVT_MENU(NewUmlMenuOptionId, UmlBlocks::NewUmlMenuOptionFunc)
	EVT_MENU(NewClassMenuOptionId, UmlBlocks::NewClassMenuOptionFunc)
	EVT_MENU(RevEngiMenuOptionId, UmlBlocks::RevEngiMenuOptionFunc)
	EVT_MENU(GenCodeMenuOptionId, UmlBlocks::GenCodeMenuOptionFunc)
	EVT_MENU(SaveBmpMenuOptionId, UmlBlocks::SaveBmpMenuOptionFunc)
END_EVENT_TABLE()

// constructor
UmlBlocks::UmlBlocks() {
	// Make sure our resources are available.
	// In the generated boilerplate code we have no resources but when
	// we add some, it will be nice that this code is in place already ;)
	if(!Manager::LoadResource(_T("UmlBlocks.zip"))) {
		NotifyMissingFile(_T("UmlBlocks.zip"));
	}
}

// destructor
UmlBlocks::~UmlBlocks() {
}

void UmlBlocks::OnAttach() {
	// do whatever initialization you need for your plugin
	// NOTE: after this function, the inherited member variable
	// m_IsAttached will be TRUE...
	// You should check for it in other functions, because if it
	// is FALSE, it means that the application did *not* "load"
	// (see: does not need) this plugin...
	Manager::Get()->RegisterEventSink(cbEVT_EDITOR_SWITCHED, new cbEventFunctor<UmlBlocks, CodeBlocksEvent>(this, &UmlBlocks::EditorFileSwitched));
}

void UmlBlocks::OnRelease(bool appShutDown) {
	// do de-initialization for your plugin
	// if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
	// which means you must not use any of the SDK Managers
	// NOTE: after this function, the inherited member variable
	// m_IsAttached will be FALSE...
}

int UmlBlocks::Configure() {
	//create and display the configuration dialog for your plugin
	cbConfigurationDialog dlg(Manager::Get()->GetAppWindow(), wxID_ANY, _("Your dialog title"));
	cbConfigurationPanel* panel = GetConfigurationPanel(&dlg);
	if (panel) {
		dlg.AttachConfigurationPanel(panel);
		PlaceWindow(&dlg);
		return dlg.ShowModal() == wxID_OK ? 0 : -1;
	}
	return -1;
}

void UmlBlocks::BuildMenu(wxMenuBar* menuBar) {
	// Lex: This is a section that can often be the cause of a start up crash

	// Multiline version of the sake of better understanding of the code
	//NewFileMenu = menuBar->GetMenu(menuBar->FindMenu(wxT("File")));
	//NewFileMenu = NewFileMenu->FindItem(NewFileMenu->FindItem(wxT("New")))->GetSubMenu();

	NewFileMenu = menuBar->GetMenu(menuBar->FindMenu(wxT("File")))->FindItem(menuBar->GetMenu(menuBar->FindMenu(wxT("File")))->FindItem(wxT("New")))->GetSubMenu();

	// The whole find the "Class..." entry ID process won't work properly, so now shit's hardcoded instead.
	NewFileMenu->Insert(/*NewFileMenu->FindItem(wxT("Class..."))+1*/ 3, NewUmlMenuOptionId, wxT("Uml Diagram..."),wxT("Uml Diagram"),false);
	Manager::Get()->GetLogManager()->Log(wxT("MENUBAR DEBUG END"));

	//UML Menu
	UMLMenu = new wxMenu(wxT(""));
	menuBar->Insert(menuBar->FindMenu(wxT("Build"))+1, UMLMenu,wxT("Uml"));
	UMLMenu->Append(NewUmlMenuOptionId,wxT("New Uml Diagram..."),wxT("Create a new Uml Diagram"));
	UMLMenu->AppendSeparator();
	UMLMenu->Append(NewClassMenuOptionId,wxT("New Class..."),wxT("Create a new Class"));
	UMLMenu->AppendSeparator();
	UMLMenu->Append(RevEngiMenuOptionId,wxT("Reverse Engineer..."),wxT("Reverse engineer code"));
	UMLMenu->Append(GenCodeMenuOptionId,wxT("Generate Code..."),wxT("Generate code from diagram"));
	UMLMenu->Append(SaveBmpMenuOptionId,wxT("Save BMP..."),wxT("Create and save a BMP Image"));

	DeactivateUmlTools();
}

void UmlBlocks::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data) {
	//Some library module is ready to display a pop-up menu.
	//Check the parameter \"type\" and see which module it is
	//and append any items you need in the menu...
	//TIP: for consistency, add a separator as the first item...
	NotImplemented(_T("UmlBlocks::BuildModuleMenu()"));
}

bool UmlBlocks::BuildToolBar(wxToolBar* toolBar) {
	//The application is offering its toolbar for your plugin,
	//to add any toolbar items you want...
	//Append any items you need on the toolbar...
	NotImplemented(_T("UmlBlocks::BuildToolBar()"));

	// return true if you add toolbar items
	return false;
}

void UmlBlocks::NewUmlMenuOptionFunc(wxCommandEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("New Uml Menu Option Function Invoked"));
	new UmlCanvas(new wxSFDiagramManager(), new UmlEditor(Manager::Get()->GetAppWindow(),wxT("Untitled.cbd")));
}

void UmlBlocks::NewClassMenuOptionFunc(wxCommandEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("New Uml Class Option Function Invoked"));
	UmlNewEntityDialog* dlg = new UmlNewEntityDialog(1);
	if ( dlg->ShowModal() == wxID_OK ) {
	}
	dlg->Destroy();
	//new UmlClass(wxRealPoint(50,50), static_cast<UmlEditor*>(Manager::Get()->GetEditorManager()->GetActiveEditor())->GetCanvas()->GetDiagramManager());
	static_cast<UmlEditor*>(Manager::Get()->GetEditorManager()->GetActiveEditor())->GetCanvas()->GetDiagramManager()->AddShape(CLASSINFO(UmlClass),wxPoint(50,50));
	static_cast<UmlEditor*>(Manager::Get()->GetEditorManager()->GetActiveEditor())->GetCanvas()->Refresh(false);
}

void UmlBlocks::RevEngiMenuOptionFunc(wxCommandEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("Rev Engi Menu Option Function Invoked"));
}

void UmlBlocks::GenCodeMenuOptionFunc(wxCommandEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("Gen Code Menu Option Function Invoked"));
}

void UmlBlocks::SaveBmpMenuOptionFunc(wxCommandEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("Save Bmp Menu Option Function Invoked"));
}

void UmlBlocks::EditorFileSwitched(CodeBlocksEvent& event) {
	Manager::Get()->GetLogManager()->Log(wxT("Editor Switched File"));
	if (Manager::Get()->GetEditorManager()->GetActiveEditor()->GetTitle().EndsWith(wxT(".cbd"))) {
		Manager::Get()->GetLogManager()->Log(wxT("File is a diagram"));
		ActivateUmlTools();
	} else {
		Manager::Get()->GetLogManager()->Log(wxT("File is a text"));
		DeactivateUmlTools();
	}
}

void UmlBlocks::ActivateUmlTools() {
	Manager::Get()->GetLogManager()->Log(wxT("Tools Activated"));
	UMLMenu->Enable(NewClassMenuOptionId,true);
	UMLMenu->Enable(RevEngiMenuOptionId,true);
	UMLMenu->Enable(GenCodeMenuOptionId,true);
	UMLMenu->Enable(SaveBmpMenuOptionId,true);
}

void UmlBlocks::DeactivateUmlTools() {
	Manager::Get()->GetLogManager()->Log(wxT("Tools Deactivated"));
	UMLMenu->Enable(NewClassMenuOptionId,false);
	UMLMenu->Enable(RevEngiMenuOptionId,false);
	UMLMenu->Enable(GenCodeMenuOptionId,false);
	UMLMenu->Enable(SaveBmpMenuOptionId,false);
}

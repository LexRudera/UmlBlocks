#include "UmlClassDialog.h"

UmlClassDialog::UmlClassDialog()
{
    //ctor
    Create();
}

UmlClassDialog::~UmlClassDialog()
{
    //dtor
}

void UmlClassDialog::Create()
{
    wxDialog::Create(Manager::Get()->GetAppWindow(),Manager::Get()->GetAppWindow()->GetId(),wxT("New Class"),wxDefaultPosition,wxSize(625,720));
    CreateControls();
}

void UmlClassDialog::CreateControls()
{
    // Just some quick notes.
    // Three boxes side by side. each X point being 5, 210, 415
    // For a box beneith, the Y point is the above box Y point + above box height + 5

    // How the hell do i make and initialize the array inside the function parameters?
    // I've got no idea and have to make a seperate temporary array variable. Makes everything more messy than it already is.
    wxString ListOptions[] ={_("Funk"),_("Herp"),_("Derp")};
    // herp derp idunnoanymore
    wxString AccessOptions[] ={_("Public"),_("Protected"),_("Private")};
    wxString InheriSelectorOptions[] ={_("Funk"),_("Herp"),_("Derp")};

    // Declaration and description elements
    DeclareSBox = new wxStaticBox(this,wxID_ANY,_("Class Declaration"),wxPoint(5,5),wxSize(200,160));
    new wxStaticText(DeclareSBox,wxID_ANY,_("Class name"),wxPoint(10,20));
    ClassNameBox = new wxTextCtrl(DeclareSBox,wxID_ANY,wxEmptyString,wxPoint(10,35),wxSize(175,-1));
    new wxStaticText(DeclareSBox,wxID_ANY,_("Description/comments"),wxPoint(10,60));
    DescriptionBox = new wxTextCtrl(DeclareSBox,wxID_ANY,wxEmptyString,wxPoint(10,75),wxSize(175,75),wxTE_MULTILINE);

    // Class inheritance elements
    InheritSBox = new wxStaticBox(this,wxID_ANY,_("Class Inheritance"),wxPoint(5,170),wxSize(200,260));
    InheritList = new wxListBox(InheritSBox, wxID_ANY,wxPoint(10,20),wxSize(175,75),3,ListOptions,wxLB_SINGLE|wxLB_NEEDED_SB);
    new wxButton(InheritSBox, wxID_ANY,_("Add"),wxPoint(10,100),wxSize(75,-1));
    new wxButton(InheritSBox, wxID_ANY,_("Delete"),wxPoint(110,100),wxSize(75,-1));
    new wxStaticText(InheritSBox,wxID_ANY,_("Class"),wxPoint(10,130));
    InheriSelector = new wxChoice(InheritSBox,wxID_ANY,wxPoint(10,145),wxSize(175,-1),3,InheriSelectorOptions);
    new wxStaticText(InheritSBox,wxID_ANY,_("External"),wxPoint(10,170));
    InheriExternal = new wxTextCtrl(InheritSBox,wxID_ANY,wxEmptyString,wxPoint(10,185),wxSize(175,-1));
    new wxStaticText(InheritSBox,wxID_ANY,_("Access"),wxPoint(10,210));
    InheriAccess = new wxChoice(InheritSBox,wxID_ANY,wxPoint(10,225),wxSize(175,-1),3,AccessOptions);
    InheriAccess->SetSelection(0);

    // Class attributes elements
    AttribuSBox = new wxStaticBox(this,wxID_ANY,_("Class Attributes"),wxPoint(5,435),wxSize(200,45));
    AbstractCheckbox = new wxCheckBox(AttribuSBox,wxID_ANY,_("Abstract"),wxPoint(10,20));
    AbstractCheckbox->Enable(false);

    // Member variable elements
    MemVariSBox = new wxStaticBox(this,wxID_ANY,_("Member Variables"),wxPoint(415,5),wxSize(200,395));
    VarList = new wxListBox(MemVariSBox, wxID_ANY,wxPoint(10,20),wxSize(175,100),3,ListOptions,wxLB_SINGLE|wxLB_NEEDED_SB);
    new wxButton(MemVariSBox, wxID_ANY,_("Add"),wxPoint(10,125),wxSize(75,-1));
    new wxButton(MemVariSBox, wxID_ANY,_("Delete"),wxPoint(110,125),wxSize(75,-1));
    new wxStaticText(MemVariSBox,wxID_ANY,_("Name"),wxPoint(10,155));
    VarName = new wxTextCtrl(MemVariSBox,wxID_ANY,wxEmptyString,wxPoint(10,170),wxSize(175,-1));
    new wxStaticText(MemVariSBox,wxID_ANY,_("Type"),wxPoint(10,195));
    VarType = new wxTextCtrl(MemVariSBox,wxID_ANY,wxEmptyString,wxPoint(10,210),wxSize(175,-1));
    new wxStaticText(MemVariSBox,wxID_ANY,_("Access"),wxPoint(10,235));
    VarAccess = new wxChoice(MemVariSBox,wxID_ANY,wxPoint(10,250),wxSize(175,-1),3,AccessOptions);
    VarAccess->SetSelection(0);
    VarReference = new wxCheckBox(MemVariSBox,wxID_ANY,_("Reference"),wxPoint(10,280));
    VarPointer = new wxCheckBox(MemVariSBox,wxID_ANY,_("Pointer"),wxPoint(10,300));
    VarPointAmount = new wxSpinCtrl(MemVariSBox,wxID_ANY,_("Pointing Amount"),wxPoint(10,320),wxSize(175,-1),wxSP_ARROW_KEYS,1,100,1);
    VarConstant = new wxCheckBox(MemVariSBox,wxID_ANY,_("Const"),wxPoint(10,350));
    VarStatic = new wxCheckBox(MemVariSBox,wxID_ANY,_("Static"),wxPoint(10,370));

    // Member function elements
    MemFuncSBox = new wxStaticBox(this,wxID_ANY,_("Member Functions"),wxPoint(210,5),wxSize(200,685));
    FuncList = new wxListBox(MemFuncSBox, wxID_ANY,wxPoint(10,20),wxSize(175,100),3,ListOptions,wxLB_SINGLE|wxLB_NEEDED_SB);
    new wxButton(MemFuncSBox, wxID_ANY,_("Add"),wxPoint(10,125),wxSize(75,-1));
    new wxButton(MemFuncSBox, wxID_ANY,_("Delete"),wxPoint(110,125),wxSize(75,-1));
    new wxStaticText(MemFuncSBox,wxID_ANY,_("Name"),wxPoint(10,155));
    FuncName = new wxTextCtrl(MemFuncSBox,wxID_ANY,wxEmptyString,wxPoint(10,170),wxSize(175,-1));
    new wxStaticText(MemFuncSBox,wxID_ANY,_("Type"),wxPoint(10,195));
    FuncType = new wxTextCtrl(MemFuncSBox,wxID_ANY,wxEmptyString,wxPoint(10,210),wxSize(175,-1));
    new wxStaticText(MemFuncSBox,wxID_ANY,_("Access"),wxPoint(10,235));
    FuncAccess = new wxChoice(MemFuncSBox,wxID_ANY,wxPoint(10,250),wxSize(175,-1),3,AccessOptions);
    FuncAccess->SetSelection(0);
        FuncParameterSubBox = new wxStaticBox(MemFuncSBox,wxID_ANY,_("Parameters"),wxPoint(10,275),wxSize(175,355)); // Ends at 630
        ParaList = new wxListBox(FuncParameterSubBox, wxID_ANY,wxPoint(10,20),wxSize(150,75),3,ListOptions,wxLB_SINGLE|wxLB_NEEDED_SB);
        new wxButton(FuncParameterSubBox, wxID_ANY,_("Add"),wxPoint(10,100),wxSize(65,-1));
        new wxButton(FuncParameterSubBox, wxID_ANY,_("Delete"),wxPoint(95,100),wxSize(65,-1));
        new wxStaticText(FuncParameterSubBox,wxID_ANY,_("Name"),wxPoint(10,130));
        ParaName = new wxTextCtrl(FuncParameterSubBox,wxID_ANY,wxEmptyString,wxPoint(10,145),wxSize(150,-1));
        new wxStaticText(FuncParameterSubBox,wxID_ANY,_("Type"),wxPoint(10,170));
        ParaType = new wxTextCtrl(FuncParameterSubBox,wxID_ANY,wxEmptyString,wxPoint(10,185),wxSize(150,-1));
        ParaReference = new wxCheckBox(FuncParameterSubBox,wxID_ANY,_("Reference"),wxPoint(10,215));
        ParaPointer = new wxCheckBox(FuncParameterSubBox,wxID_ANY,_("Pointer"),wxPoint(10,235));
        ParaPointAmount = new wxSpinCtrl(FuncParameterSubBox,wxID_ANY,_("Pointing Amount"),wxPoint(10,255),wxSize(150,-1),wxSP_ARROW_KEYS,1,100,1);
        ParaConstant = new wxCheckBox(FuncParameterSubBox,wxID_ANY,_("Const"),wxPoint(10,285));
        new wxStaticText(FuncParameterSubBox,wxID_ANY,_("Type"),wxPoint(10,305));
        ParaDefaultArg = new wxTextCtrl(FuncParameterSubBox,wxID_ANY,wxEmptyString,wxPoint(10,320),wxSize(150,-1));
    FuncVirtual = new wxCheckBox(MemFuncSBox,wxID_ANY,_("Virtual"),wxPoint(10,640));
    FuncPure = new wxCheckBox(MemFuncSBox,wxID_ANY,_("Pure Virtual"),wxPoint(10,660));

    // Some last "OK", "Cancel" buttons and such
    new wxButton(this,wxID_ANY,_("Ok"),wxPoint(500,600));
    new wxButton(this,wxID_ANY,_("Cancel"),wxPoint(500,630));

    // Dude, i fucking love scrollbars!
    //SetScrollbar(wxVERTICAL,0,16,50);
    // Dude, shit doesn't work out of the box. Screw it.
}

UmlClassDialog::UmlClassDialog(const UmlClassDialog& other)
{
    //copy ctor
}

UmlClassDialog& UmlClassDialog::operator=(const UmlClassDialog& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

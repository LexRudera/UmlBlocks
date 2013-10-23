#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H

#include <vector>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include "MemberVar.hpp"
#include "MemberFunc.hpp"
#include <sdk.h> // Code::Blocks SDK
class ClassDialog: public wxDialog
{
public:
    ClassDialog(wxWindow* parent);
    ~ClassDialog();

    // Accessors
    wxString GetClassName() { return XRCCTRL(*this, "txtClassName", wxTextCtrl)->GetValue(); }
    wxString GetClassDescription() { return XRCCTRL(*this, "txtClassDesc", wxTextCtrl)->GetValue(); }
    const std::vector<MemberVar>& GetVariableList() { return m_Variables; }
    const std::vector<MemberFunc>& GetFunctionList() { return m_Functions; }
    const std::vector<wxString>& GetInheritanceList() { return m_Inherited; }
protected:
private:
	// Containers
	std::vector<MemberVar> m_Variables;
	std::vector<MemberFunc> m_Functions;
	std::vector<wxString> m_Inherited;

	// Variables
	int m_SelectedParamItem = -1;
	int m_SelectedMemberItem = -1;
	MemberGroup m_SelectedMemberList;

    // Controls
    wxListBox* m_lstVars,
			  *m_lstFuncs,
			  *m_lstInherit,
			  *m_lstParams;
    wxButton* m_btnCreate,
			 *m_btnCancel,
			 *m_btnInheritDel,
			 *m_btnInheritAdd,
			 *m_btnVarNew,
			 *m_btnVarDel,
			 *m_btnVarUp,
			 *m_btnVarDown,
			 *m_btnFuncNew,
			 *m_btnFuncDel,
			 *m_btnFuncUp,
			 *m_btnFuncDown,
			 *m_btnParamsNew,
			 *m_btnParamsDel,
			 *m_btnParamsUp,
			 *m_btnParamsDown;
	wxTextCtrl* m_txtClassName,
			   *m_txtInheritExtClass,
			   *m_txtClassDesc,
			   *m_txtMemberName,
			   *m_txtMemberExtType,
			   *m_txtParamsName,
			   *m_txtParamsExtType,
			   *m_txtParamsDefVal;
	wxChoice* m_chcInheritClass,
			 *m_chcMemberType,
			 *m_chcMemberAccess,
			 *m_chcParamsType;
	wxCheckBox* m_chkAttAbstract,
			   *m_chkMemberArray,
			   *m_chkMemberStatic,
			   *m_chkMemberConst,
			   *m_chkMemberPointer,
			   *m_chkMemberReference,
			   *m_chkMemberVirtual,
			   *m_chkMemberPVirtual,
			   *m_chkParamsStatic,
			   *m_chkParamsConst,
			   *m_chkParamsArray,
			   *m_chkParamsPointer,
			   *m_chkParamsReference;
	wxSpinCtrl* m_spcMemberArraySize,
			   *m_spcMemberPointerDpth,
			   *m_spcParamsPointerDpth;
	wxStaticText* m_sxtInheritExtClass,
				 *m_sxtMemberExtType,
				 *m_sxtMemberArraySize,
				 *m_sxtMemberPointerDpth,
				 *m_sxtParams,
				 *m_sxtParamsName,
				 *m_sxtParamsType,
				 *m_sxtParamsExtType,
				 *m_sxtParamsDefVal,
				 *m_sxtParamsPointerDpth;

	// Functions
	inline void SelectMember( MemberGroup l, int selection); // Selects a member
	void SelectParameter(int selection); // Selects a parameter
	void LoadMember(); // Loads selected member
	void SaveMember(); // Saves selected member
	void LoadParameter(); // Loads selected parameter
	void SaveParameter(); // Saves selected parameter
	void CreateMember(MemberGroup l); // Creates new empty class
	void DeleteMember(MemberGroup l, int i); // Deletes a specific member on chosen list
	void CreateParameter(); // Creates new empty parameter
	void DeleteParameter(int i); // Deletes a specific member on chosen list

    // Events
    void OnVarsListBox(wxCommandEvent& event);
    void OnFuncsListBox(wxCommandEvent& event);
    void OnInheritListBox(wxCommandEvent& event);
    void OnParamsListBox(wxCommandEvent& event);

    void OnCreateBtn(wxCommandEvent& event);
    void OnCancelBtn(wxCommandEvent& event);
    void OnInheritDelBtn(wxCommandEvent& event);
    void OnInheritAddBtn(wxCommandEvent& event);
    void OnVarsNewBtn(wxCommandEvent& event);
    void OnVarsDelBtn(wxCommandEvent& event);
    void OnVarsUpBtn(wxCommandEvent& event);
    void OnVarsDownBtn(wxCommandEvent& event);
    void OnFuncsNewBtn(wxCommandEvent& event);
    void OnFuncsDelBtn(wxCommandEvent& event);
    void OnFuncsUpBtn(wxCommandEvent& event);
    void OnFuncsDownBtn(wxCommandEvent& event);
    void OnParamsNewBtn(wxCommandEvent& event);
    void OnParamsDelBtn(wxCommandEvent& event);
    void OnParamsUpBtn(wxCommandEvent& event);
    void OnParamsDownBtn(wxCommandEvent& event);

    void OnInheritChoice(wxCommandEvent& event);
    void OnMemberTypeChoice(wxCommandEvent& event);
    void OnMemberAccessChoice(wxCommandEvent& event);
    void OnParamsTypeChoice(wxCommandEvent& event);

    void OnMemberPointerCheck(wxCommandEvent& event);
    void OnMemberRefCheck(wxCommandEvent& event);
    void OnMemberArrayCheck(wxCommandEvent& event);
    void OnParamsPointerCheck(wxCommandEvent& event);
    void OnParamsRefCheck(wxCommandEvent& event);
    void OnMemberVirtualCheck(wxCommandEvent& event);

    void OnClose(wxCloseEvent& event);

    DECLARE_EVENT_TABLE()
};

#endif

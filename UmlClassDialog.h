#ifndef UMLCLASSDIALOG_H
#define UMLCLASSDIALOG_H

#include <sdk.h>
#include <list>
//#include <wx/string.h>
#include <wx/Dialog.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include "UmlMemberFunc.h"
#include "UmlMemberVar.h"
class UmlClassDialog : public wxDialog
{

    public:
        /** Default constructor */
        UmlClassDialog();
        /** Default destructor */
        virtual ~UmlClassDialog();
        /** Copy constructor
         *  \param other Object to copy from
         */
        UmlClassDialog(const UmlClassDialog& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        UmlClassDialog& operator=(const UmlClassDialog& other);
    protected:
    private:
        void Create();
        void CreateControls();
        // Member C-style arrays is pure virtual hell. Har har. very funny. But seriously, what the shit.
        //wxString AccessOptions[];

        std::list<UmlMemberFunc> Functions;
        std::list<UmlMemberVar> Variables;

        wxStaticBox* DeclareSBox;
        wxTextCtrl* ClassNameBox;
        wxTextCtrl* DescriptionBox;

        wxStaticBox* InheritSBox;
        wxListBox* InheritList;
        wxChoice* InheriSelector;
        wxTextCtrl* InheriExternal;
        wxChoice* InheriAccess;

        wxStaticBox* AttribuSBox;
        wxCheckBox* AbstractCheckbox;

        wxStaticBox* MemVariSBox;
        wxListBox* VarList;
        wxTextCtrl* VarName;
        wxTextCtrl* VarType;
        wxChoice* VarAccess;
        wxCheckBox* VarReference;
        wxCheckBox* VarPointer;
        wxSpinCtrl* VarPointAmount;
        wxCheckBox* VarConstant;
        wxCheckBox* VarStatic;

        wxStaticBox* MemFuncSBox;
        wxListBox* FuncList;
        wxTextCtrl* FuncName;
        wxTextCtrl* FuncType;
        wxChoice* FuncAccess;
            wxStaticBox* FuncParameterSubBox;
            wxListBox* ParaList;
            wxTextCtrl* ParaName;
            wxTextCtrl* ParaType;
            wxCheckBox* ParaReference;
            wxCheckBox* ParaPointer;
            wxSpinCtrl* ParaPointAmount;
            wxCheckBox* ParaConstant;
            wxTextCtrl* ParaDefaultArg;
        wxCheckBox* FuncVirtual;
        wxCheckBox* FuncPure;
};

#endif // UMLCLASSDIALOG_H

#ifndef ClassDIALOG_HPP
#define ClassDIALOG_HPP

#include <sdk.h>
#include <list>
//#include <wx/string.h>
#include <wx/Dialog.h>
#include <wx/statbox.h>
#include <wx/textctrl.h>
#include "MemberFunc.hpp"
#include "MemberVar.hpp"
class ClassDialog : public wxDialog
{

    public:
        /** Default constructor */
        ClassDialog();
        /** Default destructor */
        virtual ~ClassDialog();
        /** Copy constructor
         *  \param other Object to copy from
         */
        ClassDialog(const ClassDialog& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        ClassDialog& operator=(const ClassDialog& other);
    protected:
    private:
        void Create();
        void CreateControls();
        // Member C-style arrays is pure virtual hell. Har har. very funny. But seriously, what the shit.
        //wxString AccessOptions[];

        std::list<MemberFunc> Functions;
        std::list<MemberVar> Variables;

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

#endif // ClassDIALOG_HPP

#ifndef UMLMEMBERVAR_H
#define UMLMEMBERVAR_H

#include <wx/String.h>
#include "UmlMemberGlobals.h"
#include "UmlMember.h"
class UmlMemberVar : public UmlMember
{
    public:
        /** Default constructor */
        UmlMemberVar(wxString Name, wxString Type, Accessibility Access = Public, int Pointer = 0, bool Reference = false, bool Static = false);
        UmlMemberVar(const UmlMemberVar&);
        /** Default destructor */
        virtual ~UmlMemberVar();
        void RefreshData(UmlClassDialog*);
        ClassMemberGroup GetMemberGroup(){return Variable;}
    protected:
    private:
        int Pointer;
        bool Reference;
        bool FuncArg;
        wxString DefaultArg;
};
#endif // UMLMEMBERVAR_H

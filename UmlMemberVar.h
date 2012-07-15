#ifndef UMLMEMBERVAR_H
#define UMLMEMBERVAR_H

#include <wx/String.h>
#include "UmlMemberGlobals.h"

class UmlMemberVar
{
    public:
        /** Default constructor */
        UmlMemberVar();
        UmlMemberVar(const UmlMemberVar&);
        /** Default destructor */
        virtual ~UmlMemberVar();
    protected:
    private:
        wxString Type;
        wxString Name;
        bool Static;
        Accessibility Access;
        bool FuncArg;
        int Pointer;
        bool Reference;
};
#endif // UMLMEMBERVAR_H

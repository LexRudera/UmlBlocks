#ifndef UMLMEMBERFUNC_H
#define UMLMEMBERFUNC_H

#include <vector>
#include <wx/String.h>
#include "UmlMemberGlobals.h"
#include "UmlMemberVar.h"

class UmlMemberFunc
{
    public:
        /** Default constructor */
        UmlMemberFunc();
        UmlMemberFunc(const UmlMemberFunc&);
        /** Default destructor */
        virtual ~UmlMemberFunc();
    protected:
    private:
        wxString Type;
        wxString Name;
        bool Static;
        Accessibility Access;
        std::vector<UmlMemberVar> Arguments;
};
#endif // UMLMEMBERFUNC_H

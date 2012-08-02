#ifndef UMLMEMBERFUNC_H
#define UMLMEMBERFUNC_H

#include <list>
#include <wx/String.h>
#include "UmlMemberGlobals.h"
#include "UmlMemberVar.h"
#include "UmlMember.h"
class UmlMemberFunc : public UmlMember
{
    public:
        /** Default constructor */
        UmlMemberFunc(wxString Name, wxString Type, Accessibility Access = Public, std::list<UmlMemberVar> Parameters = 0, bool Static = false);
        UmlMemberFunc(const UmlMemberFunc&);
        /** Default destructor */
        virtual ~UmlMemberFunc();
        void RefreshData(UmlClassDialog*);
    protected:
    private:
        bool Constructor;
        bool Destructor;
        bool Virtual;
        bool PureVirtual;
        std::list<UmlMemberVar> Arguments;
};
#endif // UMLMEMBERFUNC_H

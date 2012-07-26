#ifndef UMLMEMBER_H
#define UMLMEMBER_H
#include <wx/string.h>
#include "UmlMemberGlobals.h"
#include "UmlClassDialog.h"

class UmlMember
{
    public:
        /** Default constructor */
        UmlMember();
        /** Default destructor */
        virtual ~UmlMember();
        wxString GetName() const {return Name;}
        wxString GetType() const {return Type;}
        Accessibility GetAccess() const {return Access;}
        bool IsStatic() const {return Static;}
        bool IsConst() const {return Const;}
        virtual void RefreshData(UmlClassDialog*)=0;
    protected:
    private:
        wxString Name;
        wxString Type;
        Accessibility Access;
        bool Static;
        bool Const;
};

#endif // UMLMEMBER_H

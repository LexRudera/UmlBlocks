#ifndef UMLQUICKEDITDIALOG_H
#define UMLQUICKEDITDIALOG_H

#include <wx/Popupwin.h>
#include "UmlMemberGlobals.h"

class UmlQuickEditPopup : public wxPopupTransientWindow
{
    public:
        /** Default constructor */
        UmlQuickEditPopup(const wxPoint& a_Position, const ClassMemberGroup& a_MemGroup);
        /** Default destructor */
        virtual ~UmlQuickEditPopup();
    protected:
    private:
};

#endif // UMLQUICKEDITDIALOG_H

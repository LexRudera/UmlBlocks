#ifndef UMLQUICKEDITDIALOG_HPP
#define UMLQUICKEDITDIALOG_HPP

#include <wx/Popupwin.h>
#include "MemberGlobals.hpp"

class QuickEditPopup : public wxPopupTransientWindow
{
    public:
        /** Default constructor */
        QuickEditPopup(const wxPoint& a_Position, const ClassMemberGroup& a_MemGroup);
        /** Default destructor */
        virtual ~QuickEditPopup();
    protected:
    private:
};

#endif // UMLQUICKEDITDIALOG_HPP

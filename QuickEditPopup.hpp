#ifndef UMLQUICKEDITDIALOG_HPP
#define UMLQUICKEDITDIALOG_HPP

#include <wx/Popupwin.h>

class QuickEditPopup : public wxPopupTransientWindow
{
    public:
        /** Default constructor */
        QuickEditPopup(const wxPoint& a_Position);
        /** Default destructor */
        virtual ~QuickEditPopup();
    protected:
    private:
};

#endif // UMLQUICKEDITDIALOG_HPP

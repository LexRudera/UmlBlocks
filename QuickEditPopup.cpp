#include "QuickEditPopup.hpp"
#include <sdk.h>

QuickEditPopup::QuickEditPopup(const wxPoint& a_Position, const ClassMemberGroup& a_MemGroup):wxPopupTransientWindow(Manager::Get()->GetAppWindow())
{
    //ctor
    Position(a_Position,wxSize(50,50));
}

QuickEditPopup::~QuickEditPopup()
{
    //dtor
}

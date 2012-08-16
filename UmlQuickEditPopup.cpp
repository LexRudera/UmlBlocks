#include "UmlQuickEditPopup.h"
#include <sdk.h>

UmlQuickEditPopup::UmlQuickEditPopup(const wxPoint& a_Position, const ClassMemberGroup& a_MemGroup):wxPopupTransientWindow(Manager::Get()->GetAppWindow())
{
    //ctor
    Position(a_Position,wxSize(50,50));
}

UmlQuickEditPopup::~UmlQuickEditPopup()
{
    //dtor
}

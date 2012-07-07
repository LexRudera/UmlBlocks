#ifndef UMLNEWENTITYDIALOG_H
#define UMLNEWENTITYDIALOG_H

#include <wx/Dialog.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>

class UmlNewEntityDialog : public wxDialog
{
    public:
        UmlNewEntityDialog(int selection);
        virtual ~UmlNewEntityDialog();
        bool Create(int);
        void Initialize();
        void ShowWidgetsA();
        void DeactivateWidgets();
    protected:
    private:
        wxRadioBox* radbox1;
        wxRadioButton* choice11;
        wxRadioButton* choice12;
    };

#endif // UMLNEWENTITYDIALOG_H

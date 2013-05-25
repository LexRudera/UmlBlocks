#ifndef NewEntityDialog_HPP
#define NewEntityDialog_HPP

#include <wx/Dialog.h>
#include <wx/radiobox.h>
#include <wx/radiobut.h>

class NewEntityDialog : public wxDialog
{
    public:
        NewEntityDialog(int selection);
        virtual ~NewEntityDialog();
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

#endif // NewEntityDialogHPP

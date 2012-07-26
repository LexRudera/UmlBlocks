#ifndef UMLCLASSDIALOG_H
#define UMLCLASSDIALOG_H

#include <wx/Dialog.h>

class UmlClassDialog : public wxDialog
{
    public:
        /** Default constructor */
        UmlClassDialog();
        /** Default destructor */
        virtual ~UmlClassDialog();
        /** Copy constructor
         *  \param other Object to copy from
         */
        UmlClassDialog(const UmlClassDialog& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        UmlClassDialog& operator=(const UmlClassDialog& other);
    protected:
    private:

};

#endif // UMLCLASSDIALOG_H

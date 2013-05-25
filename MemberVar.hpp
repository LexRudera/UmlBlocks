#ifndef MemberVAR_HPP
#define MemberVAR_HPP

#include <wx/String.h>
#include "MemberGlobals.hpp"
#include "Member.hpp"
class MemberVar : public Member
{
    public:
        /** Default constructor */
        MemberVar(wxString Name, wxString Type, Accessibility Access = Public, int Pointer = 0, bool Reference = false, bool Static = false);
        MemberVar(const MemberVar&);
        /** Default destructor */
        virtual ~MemberVar();
        void RefreshData(ClassDialog*);
        ClassMemberGroup GetMemberGroup() { return Variable; }
    protected:
    private:
        int Pointer;
        bool Reference;
        bool FuncArg;
        wxString DefaultArg;
};
#endif // MemberVAR_HPP

#ifndef MemberVAR_HPP
#define MemberVAR_HPP

#include <wx/String.h>
#include "Member.hpp"
class MemberVar : public Member
{
    public:
        /** Default constructor */
        MemberVar(wxString Name, wxString Type, Member::Accessibility Access = Member::Public, int Pointer = 0, bool Reference = false, bool Static = false);
        MemberVar(const MemberVar&);
        /** Default destructor */
        virtual ~MemberVar();
    protected:
    private:
        int Pointer;
        bool Reference;
        bool FuncArg;
        wxString DefaultArg;
};
#endif // MemberVAR_HPP

#ifndef MemberFUNC_HPP
#define MemberFUNC_HPP

#include <list>
#include <wx/String.h>
#include "MemberVar.hpp"
#include "Member.hpp"
class MemberFunc : public Member
{
    public:
        /** Default constructor */
        MemberFunc(wxString Name, wxString Type, Member::Accessibility Access = Member::Public, std::list<MemberVar> Parameters = 0, bool Static = false);
        MemberFunc(const MemberFunc&);
        /** Default destructor */
        virtual ~MemberFunc();
    protected:
    private:
        bool Constructor;
        bool Destructor;
        bool Virtual;
        bool PureVirtual;
        std::list<MemberVar> Arguments;
};
#endif // MemberFUNC_HPP

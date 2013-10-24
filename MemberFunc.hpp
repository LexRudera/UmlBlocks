#ifndef MemberFUNC_HPP
#define MemberFUNC_HPP

#include <vector>
#include <wx/String.h>
#include "MemberVar.hpp"
#include "Member.hpp"
class MemberFunc : public Member
{
    public:
        /** Default constructor */
        MemberFunc(const wxString& a_name = wxT("NewFunction"),
				   const wxString& a_type = wxT("int"),
				   Accessibility a_access = Public,
				   const std::vector<MemberVar>& a_parameters = std::vector<MemberVar>(),
				   int a_array = 0,
				   int a_pointer = 0,
				   bool a_reference = false,
				   bool a_static = false,
				   bool a_const = false,
				   bool a_virtual = false,
				   bool a_purevirtual = false);
        //MemberFunc(const MemberFunc&);
        /** Default destructor */
        virtual ~MemberFunc();

        //void UpdateParameters(const std::vector<MemberVar>& newparams) {}
        //const wxString& GetUmlString();

        bool IsVirtual() const {return m_Virtual;}
        bool IsPureVirtual() const {return m_PureVirtual;}

        MemberVar& GetParameter(int a) {return m_Parameters[a];}
        MemberVar& AddParameter(const MemberVar&, int pos = 0);
        void DeleteParameter(unsigned int i);
        unsigned int GetParameterCount() {return m_Parameters.size();}

        void IsVirtual(bool a) {m_Virtual = a; UpdateUmlString();}
        void IsPureVirtual(bool a) {m_PureVirtual = a; UpdateUmlString();}

		virtual MemberGroup GetMemberGroup() { return Functions; }
    protected:
        virtual void CalcUmlString();
    private:
		bool m_Virtual;
        bool m_PureVirtual;
        std::vector<MemberVar> m_Parameters;

        friend class ClassDialog;
};
#endif // MemberFUNC_HPP

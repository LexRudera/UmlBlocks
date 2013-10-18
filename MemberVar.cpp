#include "MemberVar.hpp"
#include "Utilities.hpp"

MemberVar::MemberVar(const wxString& a_name,
					 const wxString& a_type,
					 Accessibility a_access,
					 int a_array,
					 int a_pointer,
					 bool a_reference,
					 bool a_static,
					 bool a_const,
					 const wxString& a_defval)
: Member(a_name, a_type, a_access, a_array, a_pointer, a_reference, a_static, a_const),
m_DefaultVal(a_defval)
{
}

/*MemberVar::MemberVar(const MemberVar& obj)
{

}*/

MemberVar::~MemberVar()
{
    //dtor
}

void MemberVar::UpdateUmlString() {
	Member::UpdateUmlString();
    wxString strng = GetUmlString();

	SetUmlString(strng.insert(strng.size()-2,int_to_string(GetArraySize())));
}

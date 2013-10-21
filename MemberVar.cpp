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
    UpdateUmlString();
}

/*MemberVar::MemberVar(const MemberVar& obj)
{

}*/

MemberVar::~MemberVar()
{
    //dtor
}

void MemberVar::CalcUmlString() {
	Member::CalcUmlString();
    wxString strng = GetUmlString();

	if (IsArray())
		SetUmlString(strng.insert(strng.size()-1,int_to_string(GetArraySize())));
}

#include "MemberFunc.hpp"
#include "Utilities.hpp"

MemberFunc::MemberFunc(const wxString& a_name,
					   const wxString& a_type,
					   Accessibility a_access,
					   const std::vector<MemberVar>& a_parameters,
					   int a_array,
					   int a_pointer,
					   bool a_reference,
					   bool a_static,
					   bool a_const,
					   bool a_virtual,
					   bool a_purevirtual)
: Member(a_name, a_type, a_access, a_array, a_pointer, a_reference, a_static, a_const),
m_Parameters(a_parameters),
m_Virtual(a_virtual),
m_PureVirtual(a_purevirtual)
{
    UpdateUmlString();
}

/*MemberFunc::MemberFunc(const MemberFunc& obj)
{

}*/

MemberFunc::~MemberFunc()
{
    //dtor
}

void MemberFunc::CalcUmlString() {
	Member::CalcUmlString();
    wxString strng = GetUmlString();

	wxString params(wxT("("));
	for (int i = 0; i < m_Parameters.size(); i++) {
		params.Append(m_Parameters[i].GetName() + wxT(":") + m_Parameters[i].GetType());
		if (m_Parameters[i].GetDefaultValue() != wxT(""))
			params.Append(wxT(" = ") + m_Parameters[i].GetDefaultValue());
		params.Append(wxT(", "));
	}
	params.Append(wxT(")"));

if (GetType() == wxT("ctor") || GetType() == wxT("dtor"))
	SetUmlString(strng.append(params));
else
	SetUmlString(strng.insert(strng.First(':')-1,params));
}

MemberVar& MemberFunc::AddParameter(const MemberVar& m, int pos) {
	//if (pos == -1 || pos >= m_Parameters.size())
	//	m_Parameters.push_back(m);
	//else
		m_Parameters.insert(m_Parameters.begin()+pos, m);
	UpdateUmlString();
	return m_Parameters[pos];
}

void MemberFunc::DeleteParameter(unsigned int i) {
	m_Parameters.erase(m_Parameters.begin()+i);
	UpdateUmlString();
}

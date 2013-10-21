#include "Member.hpp"
#include "Utilities.hpp"

Member::Member(const wxString& a_name,
			   const wxString& a_type,
			   Accessibility a_access,
			   int a_array,
			   unsigned int a_pointer,
			   bool a_reference,
			   bool a_static,
			   bool a_const)
: m_Name(a_name),
m_Type(a_type),
m_Access(a_access),
m_PointerDepth(a_pointer),
m_Reference(a_reference),
m_Static(a_static),
m_Const(a_const),
m_ArraySize(a_array)
{
	if (a_pointer != 0) m_Pointer = true;
	else m_Pointer = false;

	if (a_array > 0) m_Array = true;
	else m_Array = false;

		m_UmlString = wxT("undefined");
}

Member::~Member()
{
    //dtor
}

const wxString& Member::GetUmlString() {
	if (m_UmlRefresh) {
		m_UmlRefresh = false;
		CalcUmlString();
	}
	return m_UmlString;
}

void Member::CalcUmlString() {
Log("Member::CalcUmlString()");
	wxString strng(m_Name);
Log("1");
Log(strng.c_str());

	if (m_Const)
		strng.MakeUpper();
Log(strng.c_str());

	/*if (m_Type != wxT("ctor"))
		if (m_Type != wxT("dtor"))
			strng.Append(wxT(" : ") + m_Type);
		else
			strng.Prepend(wxT("~"));*/
Log("2");
	if (m_Type == wxT("ctor")) {
Log("3");
Log(strng.c_str());}
	else if (m_Type == wxT("dtor")){
Log("4");
		strng.Prepend(wxT("~"));
Log(strng.c_str());
	}
	else { //Regular type stuff
Log("5");
		strng.Append(wxT(" : "));
Log(strng.c_str());
		if (m_Static)
			strng.Append(wxT("static "));
Log(strng.c_str());
Log("6");
		if (m_Const)
			strng.Append(wxT("const "));
Log(strng.c_str());

Log("7");
		strng.Append(m_Type);
Log(strng.c_str());
Log("8");
		if (m_Reference)
			strng.Append(wxT("&"));
Log(strng.c_str());
Log("9");
		if (m_Pointer)
			for (int i=0;i<m_PointerDepth;i++)
				strng.Append(wxT("*"));
Log(strng.c_str());
Log("10");
		if (m_Array)
			strng.Append(wxT("[]"));
Log(strng.c_str());

Log("11");
		if (m_Static) {
			strng.Append(wxT("_"));
			strng.Prepend(wxT("_"));
		}
	}
Log(strng.c_str());


Log("12");
	switch (m_Access) {
	case Public:
		strng.Prepend(wxT("+"));
		break;
	case Protected:
		strng.Prepend(wxT("#"));
		break;
	case Private:
		strng.Prepend(wxT("-"));
		break;
	}
Log("13");
Log(strng.c_str());

    m_UmlString = strng;
}

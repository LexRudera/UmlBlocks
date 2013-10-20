#ifndef Member_HPP
#define Member_HPP
#include <wx/string.h>
#include <wx/gdicmn.h>

enum Accessibility{
	Public = 0,
	Protected = 1,
	Private = 2,
};
enum MemberGroup{
	Variables,
	Functions,
};

class Member
{
    public:
        Member(const wxString& a_name = wxT("NewMember"),
			   const wxString& a_type = wxT("void"),
			   Accessibility a_access = Public,
			   int a_array = 0,
			   unsigned int a_pointer = 0,
			   bool a_reference = false,
			   bool a_static = false,
			   bool a_const = false);
        virtual ~Member();

        //virtual const wxString& GetUmlString() const {return m_UmlString;}
        const wxString& GetUmlString();

        const wxString& GetName() const {return m_Name;}
        const wxString& GetType() const {return m_Type;}
        bool IsArray() const {return m_Array;}
        int GetArraySize() const {return m_ArraySize;}
        bool GetArray() const {return m_Array;}
        bool IsStatic() const {return m_Static;}
        bool IsConst() const {return m_Const;}
        bool IsPointer() const {return m_Pointer;}
        int GetPointerDepth() const {return m_PointerDepth;}
        bool IsReference() const {return m_Reference;}
        Accessibility GetAccessLevel() const {return m_Access;}
		virtual MemberGroup GetMemberGroup() = 0;

        void SetName(wxString a) {m_Name = a.Trim(false).Trim(); UpdateUmlString();}
        void SetType(wxString a) {m_Type = a.Trim(false).Trim(); UpdateUmlString();}
        void IsArray(bool a) {m_Array = a; UpdateUmlString();}
        void SetArraySize(int a) {m_ArraySize = a; UpdateUmlString();}
        void SetAccessLevel(Accessibility a) {m_Access = a; UpdateUmlString();}
        void IsPointer(bool a) {m_Pointer = a; UpdateUmlString();}
        void SetPointerDepth(int a) {m_PointerDepth = a; UpdateUmlString();}
        void IsReference(bool a) {m_Reference = a; UpdateUmlString();}
        void IsStatic(bool a) {m_Static = a; UpdateUmlString();}
        void IsConst(bool a) {m_Const = a; UpdateUmlString();}

    protected:
        //virtual void UpdateUmlString();
        void UpdateUmlString() {m_UmlRefresh = true;}
        virtual void CalcUmlString();
        //bool NeedUmlRefresh() {return m_UmlRefresh;}
        //void DoUmlRefresh(bool a = true) {m_UmlRefresh = a;}
        const wxString& GetRawUmlString() {return m_UmlString;}
        void SetUmlString(const wxString& a) {m_UmlString = a;}

    private:
        wxString m_Name;
        wxString m_Type;
        bool m_Array;
        int m_ArraySize;
        Accessibility m_Access;
        bool m_Pointer;
        int m_PointerDepth;
		bool m_Reference;
        bool m_Static;
        bool m_Const;

        wxString m_UmlString;
        bool m_UmlRefresh = true;
};

#endif // Member_HPP

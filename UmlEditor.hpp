#ifndef UMLEDITOR_HPP
#define UMLEDITOR_HPP

#include <EditorBase.h>
#include "UmlCanvas.hpp"
class UmlCanvas;
class UmlEditor : public EditorBase {
public:
	UmlEditor(wxWindow*, const wxString&);
	virtual ~UmlEditor();
	UmlCanvas* GetCanvas() const {
		return m_pCanvas;
	}
	void SetCanvas(UmlCanvas* a) {
		m_pCanvas = a;
	}
	bool IsRealtime() {
		return m_rRealtime;
	}

	void OnSize(wxSizeEvent& event);
protected:
private:
	DECLARE_EVENT_TABLE()
	UmlCanvas* m_pCanvas;
	bool m_rRealtime;
};

#endif // UMLEDITOR_HPP

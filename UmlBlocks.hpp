/***************************************************************
 * Name:      UmlBlocks
 * Purpose:   Code::Blocks plugin
 * Author:    Lex (lex@pulsewave.co)
 * Created:   2012-07-05
 * Copyright: Lex
 * License:   GPL
 **************************************************************/

#ifndef UMLBLOCKS_HPP_INCLUDED
#define UMLBLOCKS_HPP_INCLUDED

// For compilers that support precompilation, includes <wx/wx.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <cbplugin.h> // for "class cbPlugin"

class UmlBlocks : public cbPlugin
{
    public:
        UmlBlocks();
        virtual ~UmlBlocks();
        virtual int Configure();
        virtual int GetConfigurationPriority() const { return 50; }
        virtual int GetConfigurationGroup() const { return cgContribPlugin; }

        /** Return plugin's configuration panel.
          * @param parent The parent window.
          * @return A pointer to the plugin's cbConfigurationPanel. Is is deleted by the caller.
          */
        virtual cbConfigurationPanel* GetConfigurationPanel(wxWindow* parent){ return 0; }

        /** Return plugin's configuration panel for projects.
          * The panel returned from this function will be added in the project's
          * configuration dialog
          * @param parent The parent window.
          * @param project The project that is being edited.
          * @return A pointer to the plugin's cbConfigurationPanel. It is deleted by caller.
          */
        virtual cbConfigurationPanel* GetProjectConfigurationPanel(wxWindow* parent, cbProject* project){ return 0; }
        virtual void BuildMenu(wxMenuBar* menuBar);

        /** This method is called by Code::Blocks core modules (EditorManager,
          * ProjectManager, etc) and is used by the plugin to add any menu
          * items it needs in the module's popup menu. For example, when
          * the user right-clicks on a project file in the project tree,
          * ProjectManager prepares a popup menu to display with context
          * sensitive options for that file. Before it displays this popup
          * menu, it asks all attached plugins (by asking PluginManager to call
          * this method), if they need to add any entries
          * in that menu. This methos is called.\n
          * If the plugin does not need to add items in the menu,
          * just do nothing ;)
          * @param type the module that's preparing a popup menu
          * @param menu pointer to the popup menu
          * @param data pointer to FileTreeData object (to access/modify the file tree)
          */
        virtual void BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data = 0);
        virtual bool BuildToolBar(wxToolBar* toolBar);
    protected:
        virtual void OnAttach();
        virtual void OnRelease(bool appShutDown);

    private:
		// Variables
        wxMenu* NewFileMenu = 0; //Good old file menu
        wxMenu* UMLMenu = 0; //New Menu

		// Functions
        void SetUmlTools(bool);

		// Events
        void NewUmlMenuOptionFunc(wxCommandEvent&);
        void NewClassMenuOptionFunc(wxCommandEvent&);
        void RevEngiMenuOptionFunc(wxCommandEvent&);
        void GenCodeMenuOptionFunc(wxCommandEvent&);
        void SavePngMenuOptionFunc(wxCommandEvent&);
        void EditorFileSwitched(CodeBlocksEvent&);

        DECLARE_EVENT_TABLE();
};

#endif // UMLBLOCKS_HPP_INCLUDED

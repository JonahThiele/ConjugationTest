#ifndef _CONJUCATEFRAME_HPP
#define _CONJUCATEFRAME_HPP


#include "XmlHandler.hpp"
#include <vector>
#include <wx/timer.h>
#include <memory>

class ConjugateFrame : public wxFrame
{
    public:
        ConjugateFrame(const wxChar *title, int xpos, int ypos, int width, int height);

        /** Processes menu File|Open */
        void OnMenuFileOpen(wxCommandEvent &event);
        /** Processes menu File|Save */
        void OnMenuFileSave(wxCommandEvent &event);
        /** Processes menu File|Quit */
        void OnMenuFileQuit(wxCommandEvent &event);
        /** Processes menu About|Info */
        void OnMenuHelpAbout(wxCommandEvent &event);
        /** Checks user input in text boxes */
        void OnSubmit(wxCommandEvent &event);
        /** Times exercise */
        void OnTimer(wxTimerEvent &event);

        

        ~ConjugateFrame();
    protected:

        DECLARE_EVENT_TABLE()
        
    private:
    

        //xml control 
        std::unique_ptr<XmlHandler> m_pXmlHandle;

        //german word control 
        std::unique_ptr<GermanWord> m_pGermanWord;

        //timer control
        wxTimer *m_pTimer;
        wxStaticText *m_pTimerText;
        int seconds = 240;

        // set up the appearance and structure of the main interface.
        wxFlexGridSizer *m_pFlexGridSizer;
        wxBoxSizer *m_pBoxSizer;
        wxPanel *m_pPanel;

        // get txtctrl data back to check if input is correct
        wxTextCtrl *m_pIchCtrl;
        wxTextCtrl *m_pDuCtrl;
        wxTextCtrl *m_pErCtrl;
        wxTextCtrl *m_pSieHerCtrl;
        wxTextCtrl *m_pEsCtrl;
        wxTextCtrl *m_pWirCtrl;
        wxTextCtrl *m_pIhrCtrl;
        wxTextCtrl *m_pSieTheyCtrl;
        wxTextCtrl *m_pSieFormalCtrl;
        wxTextCtrl *m_pBaseWordCtrl;

        //submit button 
        wxButton *m_pSubmitButton;
        bool goNext = false;

        //std::vector<std::string> inputBoxCaptions = { "Ich", "Wir", "Du", "Ihr", "Er", "Sie", "Sie", "Sie(Formal)", "Es"};

        std::vector<wxTextCtrl*> inputBoxList= { m_pIchCtrl, m_pDuCtrl, m_pErCtrl, m_pSieHerCtrl, m_pEsCtrl,
                                     m_pWirCtrl, m_pIhrCtrl, m_pSieTheyCtrl, m_pSieFormalCtrl};

        wxMenuBar *m_pMenuBar;
        wxMenu *m_pFileMenu;
        wxMenu *m_pHelpMenu;
};

#endif //_TEXTFRAME_H
#ifndef _CONJUCATEFRAME_HPP
#define _CONJUCATEFRAME_HPP


#include "XmlHandler.hpp"
#include "ResultsFrame.hpp"
#include <vector>
#include <ostream>
#include <wx/timer.h>
#include <memory>

class ConjugateFrame : public wxFrame
{
    public:
        ConjugateFrame(const wxChar *title, int xpos, int ypos, int width, int height);

        ~ConjugateFrame(){};
    protected:

        //wxDECLARE_EVENT_TABLE();
        
    private:

        /** Processes menu File|Open */
        void OnMenuFileOpen(wxCommandEvent &event);
        /** Processes menu File|Save */
        void OnMenuFileSave(wxCommandEvent &event);
        /** Processes menu File|Quit */
        void OnMenuFileQuit(wxCommandEvent &event);
        /** Processes menu About|Info */
        void OnMenuHelpAbout(wxCommandEvent &event);
        //process appending to xml file
        void OnMenuFileAppend(wxCommandEvent &event);
        /** Checks user input in text boxes */
        void OnSubmit(wxCommandEvent &event);
        /** Times exercise */
        void OnTimer(wxTimerEvent &event);

        //helper function
        void SetupNext();

        //wxDECLARE_EVENT_TABLE();
    
        //xml control 
        std::unique_ptr<XmlHandler> m_pXmlHandle = nullptr;

        //german word control 
        std::unique_ptr<GermanWord> m_pGermanWord = nullptr;

        //finished GermanWords 
        std::vector<std::shared_ptr<GermanWord>> praticedWords;

        //timer control
        wxTimer *m_pTimer;
        wxStaticText *m_pTimerText;
        int seconds = 240;
        bool timeroff = false;

        //description


        // set up the appearance and structure of the main interface.
        wxFlexGridSizer *m_pFlexGridSizer;
        wxBoxSizer *m_pBoxSizer;
        wxPanel *m_pPanel;

        //submit button 
        wxButton *m_pSubmitButton;
        bool goNext = false;
        bool results = false;
        bool saveFileOpen = false;

        wxTextCtrl *m_pDescriptionText;
        wxTextCtrl *m_pBaseWordCtrl;
        wxTextCtrl *m_pIchCtrl;
        wxTextCtrl *m_pWirCtrl;
        wxTextCtrl *m_pDuCtrl;
        wxTextCtrl *m_pIhrCtrl;
        wxTextCtrl *m_pErCtrl;
        wxTextCtrl *m_pSieTheyCtrl;
        wxTextCtrl *m_pSieHerCtrl;
        wxTextCtrl *m_pSieFormalCtrl;
        wxTextCtrl *m_pEsCtrl;

        //std::vector<std::string> inputBoxCaptions = { "Ich", "Wir", "Du", "Ihr", "Er", "Sie", "Sie", "Sie(Formal)", "Es"};

        std::vector<wxTextCtrl*> inputBoxList= { m_pDescriptionText, m_pBaseWordCtrl, m_pIchCtrl, m_pWirCtrl, m_pDuCtrl, m_pIhrCtrl, m_pErCtrl, 
                                                 m_pSieTheyCtrl, m_pSieHerCtrl, m_pSieFormalCtrl, m_pEsCtrl};

        wxMenuBar *m_pMenuBar;
        wxMenu *m_pFileMenu;
        wxMenu *m_pHelpMenu;
    protected:
            DECLARE_EVENT_TABLE();
};

#endif //_TEXTFRAME_H
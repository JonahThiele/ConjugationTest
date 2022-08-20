#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ConjugateFrame.hpp"


ConjugateFrame::ConjugateFrame(const wxChar *title, int xpos, int ypos, int width, int height )
    : wxFrame((wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
    {
        //setting up timer stuff
        
        m_pTimer = new wxTimer(this, wxEVT_TIMER);
        m_pTimer->Start(1000);

        //set up xml stuff
        m_pXmlHandle = new XmlHandler()


        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );
        //m_pPanel = new wxPanel(m_pPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T(""));
        m_pFlexGridSizer = new wxFlexGridSizer(2);

        m_pBaseWordCtrl = new wxTextCtrl(this,  wxID_ANY,  wxT(""), wxDefaultPosition, wxDefaultSize);

        m_pSubmitButton = new wxButton(this, 12, wxT("submit"));

        m_pTimerText = new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize);

        //timer text that changes
        m_pBoxSizer->Add(
            m_pTimerText,
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pBoxSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Base Word"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pBoxSizer->Add(
            m_pBaseWordCtrl,
            wxSizerFlags().Align(0).Shaped().Center().Border(wxALL, 10)
        );



        for(int i = 0; i < 9; i++)
        {
            inputBoxList[i] = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
        }


        // tried to use a loop but it rose an assert "Adding window to the same twice"
        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Ich"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );
        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Wir"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pFlexGridSizer->Add(
            inputBoxList[0],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[1],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        

        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Du"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );
        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Ihr"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pFlexGridSizer->Add(
            inputBoxList[2],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[3],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );

        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Er"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );
        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Sie"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pFlexGridSizer->Add(
            inputBoxList[4],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[5],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );

        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Sie"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );
        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Sie(Formal)"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pFlexGridSizer->Add(
            inputBoxList[6],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[7],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );

        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT("Es"), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );

        //empty static text to push formatting into the right place

        m_pFlexGridSizer->Add(
            new wxStaticText(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize),
            wxSizerFlags().Align(0).Shaped().Center()
        );
        
        m_pFlexGridSizer->Add(
            inputBoxList[8],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        
        
        

        m_pBoxSizer->Add(
            m_pFlexGridSizer,
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );

        m_pBoxSizer->Add(
            m_pSubmitButton,
            wxSizerFlags().Align(0).Center().Border(wxALL, 10)
        );

        SetSizerAndFit(m_pBoxSizer);
        
        

        m_pMenuBar = new wxMenuBar();

        //file menu
        m_pFileMenu = new wxMenu();
        m_pFileMenu->Append(wxID_OPEN, _T("&Open"), _T("Opens an existing file"));
        m_pFileMenu->Append(wxID_SAVE, _("&Save"), _T("Saves the content"));
        m_pFileMenu->AppendSeparator();
        m_pFileMenu->Append(wxID_EXIT, _T("&Quit"), _T("Quit the application"));
        m_pMenuBar->Append(m_pFileMenu, _T("&File"));
        //about menu
        m_pHelpMenu = new wxMenu();
        m_pHelpMenu->Append(wxID_ABOUT, _T("&About"), _T("Shows information about the application"));
        m_pMenuBar->Append(m_pHelpMenu, _T("&Help"));

        SetMenuBar(m_pMenuBar);

        this->Layout();

    }


BEGIN_EVENT_TABLE(ConjugateFrame, wxFrame)
    EVT_MENU(wxID_OPEN, ConjugateFrame::OnMenuFileOpen)
    //EVT_MENU(wxID_SAVE, ConjugateFrame::OnMenuFileSave) add save functionality later
    EVT_MENU(wxID_EXIT, ConjugateFrame::OnMenuFileQuit)
    EVT_MENU(wxID_ABOUT, ConjugateFrame::OnMenuHelpAbout)
    EVT_TIMER(wxEVT_TIMER, ConjugateFrame::OnTimer)
    EVT_BUTTON(12, ConjugateFrame::OnSubmit)
END_EVENT_TABLE()

void ConjugateFrame::OnMenuFileOpen(wxCommandEvent &event)
{
    wxFileDialog *OpenDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);
    if ( OpenDialog->ShowModal() == wxID_OK )
    {
        //set up xml stuff
        m_pXmlHandle = new XmlHandler(OpenDialog->GetPath());
        //grab first german word
        m_pGermanWord firstWord = m_pXmlHandle->getNextWord();

    }
    OpenDialog->Close();
}

void ConjugateFrame::OnMenuFileSave(wxCommandEvent &event)
{
    /*wxFileDialog *SaveDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), _("*.*"), wxFD_SAVE);
    if ( SaveDialog->ShowModal() == wxID_OK)
    {
        //m_pTextCtrl->SaveFile(SaveDialog->GetPath()) ? SetStatusText(_T("Saved")) : SetStatusText("Saved Failed");

    }
    SaveDialog->Close();
    */
   //set up xml stuff

}

void ConjugateFrame::OnMenuFileQuit(wxCommandEvent &event)
{
    Close(false);
}

void ConjugateFrame::OnMenuHelpAbout(wxCommandEvent &event)
{
    wxLogMessage(_T("Simple German Conjugation Tool"));
}

void ConjugateFrame::OnTimer(wxTimerEvent &event)
{
    std::cout << "running timer\n";
    //check if time has ran out
    if(seconds < 0){
        // message and provide some way to restart
    } else {
        //change label to show time to user
        seconds--;
        std::string formatStr = (seconds % 60 > 9) ? ":" : ":0";
        std::string str =  "               " + std::to_string(seconds / 60) + formatStr + std::to_string(seconds % 60);
        wxString time;
        time << str;
        m_pTimerText->SetLabel(time);
    }

}

void ConjugateFrame::OnSubmit(wxCommandEvent &event)
{
    if(goNext)
    {
        //set all of the inputboxes back to black
        for(int i =0; i < 10; i++)
        {
            inputBoxList[i]->SetForegroundColour(*wxBlack);
            inputBoxList[i]->Clear();
        }
        //set the submit button back;
        m_pSubmitButton->SetLabel(wxT("Submit"));
        //get next word
        m_pGermanWord firstWord = m_pXmlHandle->getNextWord();


    } else{
        std::string formattedEntryList[9];
        for(int i = 0; i < 10; i++)
        {
            std::string str;
            wxString wxstr = inputBoxList[i]->GetValue();
            str << wxstr;
            formattedEntryList[i] = str;

        }

        if(m_pGermanWord->checkIfAllInputCorrect(formattedEntryList)) 
        {
            wxMessageDialog *CorrectDialog = new wxMessageDialog(this, _T("You correctly conjugated the word"));

        } else {

            std::vector<std::string> incorrectForms = m_pGermanWord->returnIncorrectForms(formattedEntryList);
            for(int i = 0; i < 10; i++)
            {
                for(int a =0; a <  incorrectForms.size(); a++)
                {
                    if(formattedEntryList[i] == incorrectForms[a])
                    {
                        //show the incorrect word in red next to the correct form in green
                        inputBoxList[i]->SetForegroundColour(*wxRED);
                        inputBoxList[i]->Clear();
                        inputBoxList[i] << formattedEntryList[i];
                        inputBoxList[i]->SetForegroundColour(*wxBlack);
                        inputBoxList[i] << ":" 
                        inputBoxList[i]->SetForegroundColour(*wxGreen);
                        inputBoxList[i] << m_pGermanWord->returnCorrectForms()[i];
                    }
                }
            }

            //set go next so the user can review the words 
            goNext = true;
            //change submit text to go next
            m_pSubmitButton->SetLabel(wxT("Next"));

        }

    }

}
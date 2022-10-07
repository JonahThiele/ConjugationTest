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

        //setting up event stuff
        /*
        Bind(wxEVT_MENU, &ConjugateFrame::OnMenuFileOpen, this, wxID_OPEN);
        //Bind(wxEVT_MENU, &ConjugateFrame::OnMenuFileSave, this, wxID_SAVE); ass save later
        Bind(wxEVT_MENU, &ConjugateFrame::OnMenuFileQuit, this, wxID_EXIT);
        Bind(wxEVT_MENU, &ConjugateFrame::OnMenuHelpAbout, this, wxID_ABOUT);
        Bind(wxEVT_TIMER, &ConjugateFrame::OnTimer, this);
        Bind(wxEVT_BUTTON, &ConjugateFrame::OnMenuFileOpen, this, 12);
        */

        for(int i = 0; i < 9; i++)
        {
            inputBoxList[i] = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
        }



        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );
        //m_pPanel = new wxPanel(m_pPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T(""));
        m_pFlexGridSizer = new wxFlexGridSizer(2);


        inputBoxList[9] = new wxTextCtrl(this,  wxID_ANY,  wxT(""), wxDefaultPosition, wxDefaultSize);

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
            inputBoxList[0],
            wxSizerFlags().Align(0).Shaped().Center().Border(wxALL, 10)
        );



        /*for(int i = 0; i < 9; i++)
        {
            inputBoxList[i] = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
        }*/


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
            inputBoxList[1],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[2],
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
            inputBoxList[3],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[4],
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
            inputBoxList[5],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[6],
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
            inputBoxList[7],
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );
        m_pFlexGridSizer->Add(
            inputBoxList[8],
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
            inputBoxList[9],
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

//convert from macro to binding events due to undefined references 
//ex: warning: creating DT_TEXTREL in a PIE, undefined reference to `vtable for ConjugateFrame'
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
    wxFileDialog *OpenDialog = new wxFileDialog(this, _T("Choose a file"), _(""), _(""), 
                                                        "xml files (*.xml)|*.xml", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if ( OpenDialog->ShowModal() == wxID_OK )
    {
        //set up xml stuff
        //convert from wxstring to std::string
        //std::string filepath = std::string(OpenDialog->GetPath().mb_str());
        //conversion issue between wxstring and std::string
    
        m_pXmlHandle = std::make_unique<XmlHandler>(XmlHandler(OpenDialog->GetPath()));
        //grab first german word pass true bc its the first word
        m_pGermanWord = std::make_unique<GermanWord>(*m_pXmlHandle->getNextWord(true));

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
    //check if time has ran out
    if(seconds < 0){
        // message and provide some way to restart
        wxMessageDialog *dial = new wxMessageDialog(NULL, 
        wxT("Your Time is Up!"), wxT("Timer"), wxOK);
        dial->ShowModal();

        // set sumbit to display results
        results = true;
        goNext = false;
        m_pSubmitButton->SetLabel(wxT("Results"));

        //reset seconds
        seconds = 240;

    } else {
        //change label to show time to user
        seconds--;
        std::string formatStr = (seconds % 60 > 9) ? ":" : ":0";
        std::string str = std::to_string(seconds / 60) + formatStr + std::to_string(seconds % 60);
        wxString time(str);
        //time << str;
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
            inputBoxList[i]->SetDefaultStyle(wxTextAttr(*wxBLACK));
            inputBoxList[i]->Clear();
        }
        //set the submit button back;
        m_pSubmitButton->SetLabel(wxT("Submit"));
        //get next word pass false bc its not the first word
        //figure out how to change copy or change the unique pointer over to something else
        praticedWords.push_back(m_pGermanWord.release());
        m_pGermanWord = m_pXmlHandle->getNextWord(false); 


    } else if(results)
    {
        // call results page
        ResultsFrame *resultsFrame = new ResultsFrame( wxT("Results Page"), 100, 100, 400, 300, praticedWords);
        resultsFrame->Show(true);
        resultsFrame->Raise();
        resultsFrame->SetFocus();
  

        //hide conjugate frame
        this->Show(false);

    } else{
        std::string formattedEntryList[10];
        for(int i = 0; i < 10; i++)
        {
            //std::string str9 = m_pBaseWordCtrl->GetValue().ToStdString();
           //std::cout << "str9:" << str9 << "\n";
          
            wxString wxstr = inputBoxList[i]->GetValue();
            formattedEntryList[i] = wxstr.ToStdString();

        }

        if(m_pGermanWord->checkIfAllInputCorrect(formattedEntryList)) 
        {
            wxMessageDialog *CorrectDialog = new wxMessageDialog(this, _T("You correctly conjugated the word"));

        } else {

            std::vector<std::string> incorrectForms = m_pGermanWord->returnIncorrectForms(formattedEntryList);
            std::vector<std::string> correctForms = m_pGermanWord->returnCorrectForms(formattedEntryList);
            for(int i = 0; i < 10; i++)
            {
                for(int a =0; a <  incorrectForms.size(); a++)
                {
                    if(formattedEntryList[i] == incorrectForms[a])
                    {
                        //show the incorrect word in red next to the correct form in green
                        inputBoxList[i]->Clear();
                        inputBoxList[i]->SetForegroundColour( wxColour(*wxRED));
                        //inputBoxList[i]->SetDefaultStyle(wxTextAttr(*wxRED));

                        std::string userForm = formattedEntryList[i];

                        *inputBoxList[i] << userForm.c_str();
                        //no mid color change
                        //inputBoxList[i]->SetDefaultStyle(wxTextAttr(*wxBLACK));
                        *inputBoxList[i] << ":";
                        // no mid color change 
                        //inputBoxList[i]->SetDefaultStyle(wxTextAttr(*wxGREEN));

                        std::string correctForm = m_pGermanWord->returnCorrectForms()[i];
                        *inputBoxList[i] << correctForm.c_str();
                    }
                }
                for(int b = 0; b < correctForms.size(); b++)
                {
                    if(formattedEntryList[i] == correctForms[b])
                    {
                        inputBoxList[i]->Clear();
                        inputBoxList[i]->SetForegroundColour( wxColour(*wxRED));
                        std::string userForm = formattedEntryList[i];
                        *inputBoxList[i] << userForm.c_str(); 
                    }
                }
            }

            if(m_pGermanWord = m_pXmlHandle->getNextWord(false))
            {
                results = true;
                goNext = false;
                m_pSubmitButton->SetLabel(wxT("Results"));

            } else 
            {
                //set go next so the user can review the words 
                goNext = true;
                results = false;
                //change submit text to go next
                m_pSubmitButton->SetLabel(wxT("Next"));
            }

        }

    }

}
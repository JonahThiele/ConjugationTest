#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ResultsFrame.hpp"

ResultsFrame::ResultsFrame(const wxChar *title, int xpos, int ypos, int width, int height, std::vector<GermanWord*> words)
    : wxFrame((wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
    {
        finishedWords = words;

        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );

        for(int i = 0; i < words.size(); i++)
        {
            wxButton *m_pWordButton = new wxButton(this, wxID_ANY, words[i]->returnNameBaseForm());
            ResultWordList.push_back(m_pWordButton);

            m_pBoxSizer->Add(
            m_pWordButton,
            wxSizerFlags().Align(0).Shaped().Center()
            );

            //connect to handlers
            
            //word->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ResultsFrame::OnButtonClick), NULL, this);
            m_pWordButton->Bind(wxEVT_BUTTON, &ResultsFrame::OnButtonClick, this, i + buttonOffset);
        }

        SetSizerAndFit(m_pBoxSizer);
    
    }
    // figure out what you need to do to get dynamic binding 

void ResultsFrame::OnButtonClick(wxCommandEvent &event)
{
    for(int i = 0; i < finishedWords.size(); i++)
    {
        if(event.GetId() == buttonOffset + i)
        {
            // open new window that shows the incorrect forms
            IncorWordFrame *incorWordFrame = new IncorWordFrame(finishedWords[i]->returnNameBaseForm(), 100, 100, 400, 300, finishedWords[i]);
            incorWordFrame->Show(true);
            incorWordFrame->Raise();
            incorWordFrame->SetFocus();
            //hide conjugate frame
            this->Show(false);
        }
    }
    
}
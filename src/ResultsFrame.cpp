#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ResultsFrame.hpp"

ResultsFrame::ResultsFrame(const wxChar *title, int xpos, int ypos, int width, int height, std::vector<*GermanWord> words)
    : wxFrame((wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
    {
        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );

        for(auto word : words)
        {
            *m_pWordButton = new wxButton(this, wxID_ANY, wxT(word->returnNameBaseForm()));
            ResultWordList.push_back(m_pWordButton);
        }

        for(auto word : ResultWordList)
        {
            m_pBoxSizer->Add(
            word,
            wxSizerFlags().Align(0).Shaped().Center()
            );

            //connect to handlers
            
            word->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(ResultsFrame::OnButtonClick, *wxButton word), NULL, this);
        }

        SetSizerAndFit(m_pBoxSizer);
    
    }
    // figure out what you need to do to get dynamic binding 

ResultsFrame::OnButtonClick(wxCommandEvent &event, *wxButton word)
{
    std::string wordName = word->GetLabel().ToStdString();
    for(auto germanword : words)
    {
        if(germanword->returnNameBaseForm() == wordName)
        {
            // open new window that shows the incorrect words
        }
    }
    
}




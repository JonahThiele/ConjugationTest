#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ResultsFrame.hpp"

ResultsFrame::ResultsFrame(const wxChar *title, wxPoint wpoint, int width, int height, std::vector<std::shared_ptr<GermanWord>> words)
    : wxFrame((wxFrame *) NULL, -1, title, wpoint, wxSize(width, height))
    {
        finishedWords = words;

        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );

        this->SetMinSize(wxSize(150, words.size() * 60));

        for(int i = 0; i < words.size(); i++)
        {
            const int buttonID = buttonOffset + i;
            wxButton *m_pWordButton = new wxButton(this, buttonID, words[i]->returnNameBaseForm());
            ResultWordList.push_back(m_pWordButton);

            m_pBoxSizer->Add(
            ResultWordList[i],
            wxSizerFlags().Center().Expand().Shaped()
            );
        }

       Bind(wxEVT_BUTTON, &ResultsFrame::OnButtonClick, this, buttonOffset, buttonOffset + words.size());

       this->SetSizer(m_pBoxSizer);
       Centre();
       //SetSizerAndFit(m_pBoxSizer);
    
    }
    
void ResultsFrame::OnButtonClick(wxCommandEvent &event)
{
    IncorWordFrame *incorWordFrame = new IncorWordFrame(finishedWords[event.GetId() - buttonOffset]->returnNameBaseForm(), this->GetPosition(), 400, 300, finishedWords[event.GetId() - buttonOffset]);
    incorWordFrame->Show(true);
    incorWordFrame->Raise();
    incorWordFrame->SetFocus();
    //hide conjugate frame
    //this->Show(false);
    
}
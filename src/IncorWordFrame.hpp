#ifndef _INCORWORDFRAME_HPP
#define _INCORWORDFRAME_HPP

#include <vector>
#include <memory>
#include "GermanWord.hpp"

class IncorWordFrame : public wxFrame
{
    public:
        IncorWordFrame(const wxChar *title, wxPoint wpoint, int width, int height, std::shared_ptr<GermanWord> word);

        ~IncorWordFrame(){};
    protected:

        //wxDECLARE_EVENT_TABLE();
        
    private:

        void OnBackClick(wxCommandEvent &event, wxButton *word);

        wxBoxSizer *m_pBoxSizer;
        wxFlexGridSizer *m_pFlexGridSizer;
        //wxPanel *m_pPanel;

        //end and return button 
        wxButton *m_pBackButton;

        std::shared_ptr<GermanWord> germanWord_up_{};

        wxString formList[11];

        wxStaticText * m_pdescriptionText;
        wxStaticText * m_pbaseFormText;
        wxStaticText * m_pichFormText;
        wxStaticText * m_pwirFormText;
        wxStaticText * m_pduFormText;
        wxStaticText * m_pihrFormText;
        wxStaticText * m_perFormText;
        wxStaticText * m_psieTheyFormText;
        wxStaticText * m_psieHerFormText;
        wxStaticText * m_psieFormalFormText;
        wxStaticText * m_pesFormText;

        std::vector<wxStaticText*> labelList = { m_pdescriptionText, m_pbaseFormText, m_pichFormText, m_pwirFormText,
                                                m_pduFormText, m_pihrFormText, m_perFormText, m_psieTheyFormText,
                                                m_psieHerFormText, m_psieFormalFormText, m_pesFormText};

};

#endif 
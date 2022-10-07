#ifndef _INCORWORDFRAME_HPP
#define _INCORWORDFRAME_HPP

#include <vector>
#include "GermanWord.hpp"

class IncorWordFrame : public wxFrame
{
    public:
        ResultsFrame(const wxChar *title, int xpos, int ypos, int width, int height, *GermanWord germanWord);

        ~ResultsFrame(){};
    protected:

        //wxDECLARE_EVENT_TABLE();
        
    private:

        void OnBackClick(wxCommandEvent &event);

        wxBoxSizer *m_pBoxSizer;
        wxFlexGridSizer *m_pFlexGridSizer;
        //wxPanel *m_pPanel;

        //end and return button 
        wxButton *m_pBackButton;

        GermanWord *m_pGermanWord;

        wxString formList[10];

    
    protected:
            DECLARE_EVENT_TABLE();
};

#endif 
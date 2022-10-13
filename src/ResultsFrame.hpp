#ifndef _RESULTSFRAME_HPP
#define _RESULTSFRAME_HPP

#include <vector>
#include "GermanWord.hpp"
#include "IncorWordFrame.hpp"

class ResultsFrame : public wxFrame
{
    public:
        ResultsFrame(const wxChar *title, int xpos, int ypos, int width, int height, std::vector<GermanWord*> words);

        ~ResultsFrame(){};
    protected:

       
    private:

        void OnButtonClick(wxCommandEvent &event);

        wxBoxSizer *m_pBoxSizer;
        //end and return button 
        wxButton *m_pEndReturnButton;
    
        std::vector<wxButton*> ResultWordList;

        std::vector<GermanWord*> finishedWords;

        const int buttonOffset = 45;
        
   
};

#endif 
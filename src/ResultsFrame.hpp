#ifndef _RESULTSFRAME_HPP
#define _RESULTSFRAME_HPP

#include <vector>
#include <memory>
#include "GermanWord.hpp"
#include "IncorWordFrame.hpp"

class ResultsFrame : public wxFrame
{
    public:
        ResultsFrame(const wxChar *title, wxPoint wpoint, int width, int height, std::vector<std::shared_ptr<GermanWord>> words, int time);

        ~ResultsFrame(){};
    protected:

       
    private:

        void OnButtonClick(wxCommandEvent &event);

        wxBoxSizer *m_pBoxSizer;
        //end and return button 
        wxButton *m_pEndReturnButton;
    
        std::vector<wxButton*> ResultWordList;

        std::vector<std::shared_ptr<GermanWord>> finishedWords;

        const int buttonOffset = 30;
        
   
};

#endif 
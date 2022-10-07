#ifndef _RESULTSFRAME_HPP
#define _RESULTSFRAME_HPP

#include <vector>
#include "GermanWord.hpp"

class ResultsFrame : public wxFrame
{
    public:
        ResultsFrame(const wxChar *title, int xpos, int ypos, int width, int height, std::vector<*GermanWord> words);

        ~ResultsFrame(){};
    protected:

        //wxDECLARE_EVENT_TABLE();
        
    private:

        void OnButtonClick(wxCommandEvent &event);

        wxBoxSizer *m_pBoxSizer;
        //wxPanel *m_pPanel;

        //end and return button 
        wxButton *m_pEndReturnButton;
    
        std::vector<WxButton*> ResultWordList;

        /*wxMenuBar *m_pMenuBar;
        wxMenu *m_pFileMenu;
        wxMenu *m_pHelpMenu;
        */
    protected:
            DECLARE_EVENT_TABLE();
};

#endif 
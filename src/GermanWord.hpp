#ifndef _GERMANWORD_HPP
#define _GERMANWORD_HPP

#include <string>
#include <vector>

class GermanWord {
    public:
        GermanWord(std::string FormsFromXml[]);
        ~GermanWord();
        //return list of correct words
        std::string[10] returnCorrectForms(); 
        //return list of incorrect words
        std::vector<std::string> returnIncorrectForms(std::string InputForms[]);
        //return bool if correct
        bool checkIfAllInputCorrect(std::string InputForms[]);


    private:
        wxString baseForm;
        wxString ichForm;
        wxString duForm;
        wxString wirForm;
        wxString sieForm;
        wxString erForm;
        wxString sieTheyForm;
        wxString esForm; 
        wxString sieFormalForm;
        wxString ihrForm;
        wxString checkList[10];

};


#endif
#ifndef _GERMANWORD_HPP
#define _GERMANWORD_HPP

#include <string>
#include <vector>
#include <iterator>

class GermanWord {
    public:
        GermanWord(std::vector<wxString>);
        //empty deconstructor to make linker happy :)
        ~GermanWord() {};
        //return list of correct words
        std::vector<std::string> returnCorrectForms(); 
        //return list of incorrect words
        std::vector<std::string> returnIncorrectForms(std::string InputForms[]);
        //return list of correct words
        std::vector<std::string> returnCorrectForms(std::string InputForms[]);
        //return bool if correct
        bool checkIfAllInputCorrect(std::string InputForms[]);
        //return name 
        wxString returnNameBaseForm() { return baseForm;}
        //return all forms 
        wxString * returnAllForms(){ return checkList;}


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
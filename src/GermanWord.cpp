#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "GermanWord.hpp"

GermanWord::GermanWord(std::vector<wxString> FormsFromXml) 
{
    //maybe write an assert if vector can't fill all of the forms, needs 10 spaces
    description = FormsFromXml[0].ToStdString();
    baseForm = FormsFromXml[1].ToStdString();
    ichForm = FormsFromXml[2].ToStdString();
    wirForm = FormsFromXml[3].ToStdString();
    duForm = FormsFromXml[4].ToStdString();
    ihrForm = FormsFromXml[5].ToStdString();
    erForm = FormsFromXml[6].ToStdString();
    sieTheyForm = FormsFromXml[7].ToStdString();
    sieForm = FormsFromXml[8].ToStdString();
    sieFormalForm = FormsFromXml[9].ToStdString();
    esForm = FormsFromXml[10].ToStdString();

    //add to check list to make it simple to check
    std::string temparray[11];
    for(int i =0; i < 11; i++)
    {
        temparray[i] = FormsFromXml[i];
       
    }
    std::copy(temparray, temparray + 11, checkList);

}

bool GermanWord::checkIfAllInputCorrect(std::string inputList[]) 
{
    for(int i = 0; i < 10; i++)
    {
        
        if(inputList[i].compare(checkList[i + 1]))
            return false;
    }

    return true;  

}

std::vector<std::string> GermanWord::returnIncorrectForms(std::string inputList[])
{
    std::vector<std::string> incorrectList;
    for(int i = 0; i < 10; i++)
    {
        if(inputList[i] != checkList[i + 1]){
            incorrectList.push_back(inputList[i]);
        }
    }
    return incorrectList;
}

std::vector<std::string> GermanWord::returnCorrectForms(std::string inputList[])
{
    std::vector<std::string> incorrectList;
    for(int i = 0; i < 10; i++)
    {
        if(inputList[i] == checkList[i + 1]){
            incorrectList.push_back(inputList[i]);
        }
    }
    return incorrectList;

}

std::vector<std::string> GermanWord::returnCorrectForms()
{
    std::vector<std::string> internalForms(std::begin(checkList), std::end(checkList));
    return internalForms;
}
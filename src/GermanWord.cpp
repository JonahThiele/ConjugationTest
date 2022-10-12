#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "GermanWord.hpp"

GermanWord::GermanWord(std::vector<wxString> FormsFromXml) 
{
    //maybe write an assert if vector can't fill all of the forms, needs 10 spaces

    baseForm = FormsFromXml[0].ToStdString();
    ichForm = FormsFromXml[1].ToStdString();
    wirForm = FormsFromXml[2].ToStdString();
    duForm = FormsFromXml[3].ToStdString();
    ihrForm = FormsFromXml[4].ToStdString();
    erForm = FormsFromXml[5].ToStdString();
    sieTheyForm = FormsFromXml[6].ToStdString();
    sieForm = FormsFromXml[7].ToStdString();
    sieFormalForm = FormsFromXml[8].ToStdString();
    esForm = FormsFromXml[9].ToStdString();

    //add to check list to make it simple to check
    std::string temparray[10];
    for(int i =0; i < 10; i++)
    {
        temparray[i] = FormsFromXml[i];
    }
    std::copy(temparray, temparray + 10, checkList);

}

bool GermanWord::checkIfAllInputCorrect(std::string inputList[]) 
{
    for(int i = 0; i < 10; i++)
    {
        //std::cout << "IN:" << inputList[i] << " CH:" << checkList[i].ToStdString() <<  "\n";
        if(inputList[i].compare(checkList[i]))
            return false;
    }

    return true;  

}

std::vector<std::string> GermanWord::returnIncorrectForms(std::string inputList[])
{
    std::vector<std::string> incorrectList;
    for(int i = 0; i < 10; i++)
    {
        if(inputList[i] != checkList[i]){
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
        if(inputList[i] == checkList[i]){
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
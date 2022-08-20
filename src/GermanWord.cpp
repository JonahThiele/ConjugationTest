#include "GermanWord.hpp"

GermanWord::GermanWord(std::string FormsFromXml[]) 
{
    baseForm = FormsFromXml[0];
    ichForm = FormsFromXml[1];
    wirForm = FormsFromXml[2];
    duForm = FormsFromXml[3];
    ihrForm = FormsFromXml[4];
    erForm = FormsFromXml[5];
    sieTheyForm = FormsFromXml[6];
    sieForm = FormsFromXml[7];
    sieFormalForm = FormsFromXml[8];
    esForm = FormsFromXml[9];

    //add to check list to make it simple to check
    std::string temparray[] = {baseForm, wirForm, duForm, ihrForm, erForm, sieTheyForm, sieForm, sieFormalForm, esForm};
    std::copy(temparray, temparray + 10, checkList);

}

bool GermanWord::checkIfAllInputCorrect(std::string inputList[]) 
{
    for(int i = 0; i < 10; i++)
    {
        if(inputList[i] != checkList[i])
            return false;
    }  

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

std::string[10] GermanWord::returnCorrectForms()
{
    return checkList;
}
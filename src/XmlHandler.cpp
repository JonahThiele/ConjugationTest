#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "XmlHandler.hpp"


XmlHandler::XmlHandler(wxString filename) 
{
    p_mXmlDoc = new wxXmlDocument(filename);

    p_mXmlRoot = p_mXmlDoc->GetRoot();


}

GermanWord XmlHandler::getNextWord(bool FirstWord)
{
    std::vector<wxString> wordForms;
    wxString constructorList[10];

    if(FirstWord)
    {
        // do I need to handle these pointers or will wx widgets take care of it for me?
        p_mXmlCurrentNode = p_mXmlRoot->GetChildren();
        //grab the first base word string
        wxString baseString p_mXmlCurrentNode->GetChildren()->GetContents();
        //add to forms to work with the loop
        wordForms.push_back(baseString);

        wordForms = this->TraverseWord(p_mXmlCurrentNode->GetChildren()->GetNext(), wordForms);

        //add to constructor list
        for(int i = 0; i < 10; i++)
        {
    
            constructorList[i] = wordForms[i];
            
        }

        return GermanWord(constructorList);

    } else {
        // grab the first node
        p_mXmlCurrentNode = p_mXmlRoot->GetNext();
        if(p_mXmlCurrentNode == NULL) 
        {
            return NULL;
        }else {
            //grab the first base word string
            wxString baseString p_mXmlCurrentNode->GetChildren()->GetContents();
            wordForms = this->TraverseWord(p_mXmlCurrentNode->GetChildren()->GetNext(), wordForms);

            for(int i = 0; i < 10; i++)
            {
        
                constructorList[i] = wordForms[i];
            
            }

            return GermanWord(constructorList);
        }



    }
    

}

//recurses through xml and grabs forms
std::vector<wxString> XmlHandler::TraverseWord(wxXmlNode* node, std::vector<wxString> formsList)
{
    if(node != NULL)
    {
        formsList.push_back(node->GetNext()->GetContent());
        //dont know if I can initilaize an array like this
        formsList = TraverseWord(node->GetNext(), formsList);
    }else {
        return formsList;
    }
}
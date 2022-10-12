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

std::unique_ptr<GermanWord> XmlHandler::getNextWord(bool FirstWord)
{
    // empty for easy index
    std::vector<wxString> wordForms = {wxString("0"), wxString("0"), wxString("0"),
                                      wxString("0"), wxString("0"), wxString("0"),
                                      wxString("0"), wxString("0"), wxString("0"),
                                      wxString("0")};
    //wxString constructorList[10];

    if(FirstWord)
    {
        // do I need to handle these pointers or will wx widgets take care of it for me?
        p_mXmlCurrentNode = p_mXmlRoot->GetChildren();
        //grab the first base word string
        wxString baseString = p_mXmlCurrentNode->GetChildren()->GetNodeContent();
        //add to forms to work with the loop
        wordForms[this->indexXml(p_mXmlCurrentNode->GetChildren()->GetName())] = baseString;
        wordForms = this->TraverseWord(p_mXmlCurrentNode->GetChildren(), wordForms);

        auto Word_ptr = std::make_unique<GermanWord>(wordForms);

        return Word_ptr;

    } else if(p_mXmlCurrentNode->GetNext() != nullptr) {
        // grab the next word node
        p_mXmlCurrentNode = p_mXmlCurrentNode->GetNext();
       
        //grab the first base word string
        wxString baseString = p_mXmlCurrentNode->GetChildren()->GetNodeContent();
        wordForms[this->indexXml(p_mXmlCurrentNode->GetChildren()->GetName())] = baseString;
        wordForms = this->TraverseWord(p_mXmlCurrentNode->GetChildren()->GetNext(), wordForms);

        auto Word_ptr = std::make_unique<GermanWord>(wordForms);
        std::cout << Word_ptr->returnNameBaseForm() << "\n";

        return Word_ptr;

    } else {
            //if there is no other branch return
            return std::unique_ptr<GermanWord>(nullptr);
    }
    

}
// how to write a solution that handles empty word forms?

//recurses through xml and grabs forms
std::vector<wxString> XmlHandler::TraverseWord(wxXmlNode* node, std::vector<wxString>& formsList)
{
    if(node->GetNext() != NULL)
    {
        formsList[this->indexXml(node->GetNext()->GetName())] = node->GetNext()->GetNodeContent();

        //dont know if I can initilaize an array like this
        formsList = TraverseWord(node->GetNext(), formsList);
    }

    return formsList;
    
    /*// if the function fails return a pseudo NULL value
    wxString str("NULL");
    std::vector<wxString> returnFail = {str};
    return returnFail;
    */
}

int XmlHandler::indexXml(wxString name)
{
    if(name.IsSameAs(wxT("Base")))
    {
        return 0;

    } else if(name.IsSameAs(wxT("Ich")))
    {
        return 1;

    }else if(name.IsSameAs(wxT("Wir")))
    {
        return 2;

    }else if(name.IsSameAs(wxT("Du")))
    {
        return 3;

    }else if(name.IsSameAs(wxT("Ihr")))
    {
        return 4;

    }else if(name.IsSameAs(wxT("Er")))
    {
        return 5;

    }else if(name.IsSameAs(wxT("SieThey")))
    {
        return 6;

    }else if(name.IsSameAs(wxT("Sie")))
    {
        return 7;

    }else if(name.IsSameAs(wxT("SieFormal")))
    {
        return 8;

    }else 
    {
        //es form;
        return 9;

    }
}
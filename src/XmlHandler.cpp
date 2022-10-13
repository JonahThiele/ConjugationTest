#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "XmlHandler.hpp"


XmlHandler::XmlHandler(wxString filename, bool isNewFile) 
{   
    this->filename = filename;
    p_mXmlDoc = new wxXmlDocument(filename);

    if(isNewFile)
    {
        p_mXmlDoc->SetFileEncoding(wxT("UTF-8"));
        p_mXmlDoc->SetRoot(new wxXmlNode(wxXML_ELEMENT_NODE, wxT("Root")));
        p_mXmlDoc->SetVersion(wxT("1.0"));
    } 

    p_mXmlRoot = p_mXmlDoc->GetRoot();

}

void XmlHandler::SetUpWord(std::vector<wxString> savedForms, wxXmlNode* WordNode)
{

    wxXmlNode * DescriptionNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Description"));
    new wxXmlNode(DescriptionNode, wxXML_TEXT_NODE, wxT("Description"), savedForms[0]);

    wxXmlNode * BaseFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Base"));
    new wxXmlNode(BaseFormNode, wxXML_TEXT_NODE, wxT("Base"), savedForms[1]);

    wxXmlNode * IchFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Ich"));
    new wxXmlNode(IchFormNode, wxXML_TEXT_NODE, wxT("Ich"), savedForms[2]);

    wxXmlNode * WirFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Wir"));
    new wxXmlNode(WirFormNode, wxXML_TEXT_NODE, wxT("Wir"), savedForms[3]);

    wxXmlNode * DuFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Du"));
    new wxXmlNode(DuFormNode, wxXML_TEXT_NODE, wxT("Du"), savedForms[4]);

    wxXmlNode * IhrFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Ihr"));
    new wxXmlNode(IhrFormNode, wxXML_TEXT_NODE, wxT("Ihr"), savedForms[5]);

    wxXmlNode * ErFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Er"));
    new wxXmlNode(ErFormNode, wxXML_TEXT_NODE, wxT("Er"), savedForms[6]);

    wxXmlNode * SieTheyFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("SieThey"));
    new wxXmlNode(SieTheyFormNode, wxXML_TEXT_NODE, wxT("SieThey"), savedForms[7]);

    wxXmlNode * SieFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Sie"));
    new wxXmlNode(SieFormNode, wxXML_TEXT_NODE, wxT("Sie"), savedForms[8]);

    wxXmlNode * SieFormalFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("SieFormal"));
    new wxXmlNode(SieFormalFormNode, wxXML_TEXT_NODE, wxT("SieFormal"), savedForms[9]);

    wxXmlNode * EsFormNode = new wxXmlNode(WordNode, wxXML_ELEMENT_NODE, wxT("Es"));
    new wxXmlNode(EsFormNode, wxXML_TEXT_NODE, wxT("Es"), savedForms[10]);

}

void XmlHandler::WriteWord(std::vector<wxString> savedForms)
{   
    if(p_mXmlRoot->GetChildren() == nullptr)
    {
        wxXmlNode * WordNode = new wxXmlNode(p_mXmlRoot, wxXML_ELEMENT_NODE, wxT("Word"));
        SetUpWord(savedForms, WordNode);
    }else{
        //change if insert does not really work, figure out another way, if it does simply replace this
        wxXmlNode * WordNode = new wxXmlNode(p_mXmlRoot, wxXML_ELEMENT_NODE, wxT("Word"));
        SetUpWord(savedForms, WordNode);
    }

}

void XmlHandler::SaveFile()
{
    p_mXmlDoc->Save(filename);
}

std::unique_ptr<GermanWord> XmlHandler::getNextWord(bool FirstWord)
{
    // empty for easy index
    std::vector<wxString> wordForms = {wxString("0"), wxString("0"), wxString("0"), wxString("0"),
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
        wordForms = this->TraverseWord(p_mXmlCurrentNode->GetChildren(), wordForms);

        auto Word_ptr = std::make_unique<GermanWord>(wordForms);

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
    if(name.IsSameAs(wxT("Description")))
    {
        return 0;

    }else if(name.IsSameAs(wxT("Base")))
    {
        return 1;

    }else if(name.IsSameAs(wxT("Ich")))
    {
        return 2;

    }else if(name.IsSameAs(wxT("Wir")))
    {
        return 3;

    }else if(name.IsSameAs(wxT("Du")))
    {
        return 4;

    }else if(name.IsSameAs(wxT("Ihr")))
    {
        return 5;

    }else if(name.IsSameAs(wxT("Er")))
    {
        return 6;

    }else if(name.IsSameAs(wxT("SieThey")))
    {
        return 7;

    }else if(name.IsSameAs(wxT("Sie")))
    {
        return 8;

    }else if(name.IsSameAs(wxT("SieFormal")))
    {
        return 9;

    }else 
    {
        //es form;
        return 10;

    }
}
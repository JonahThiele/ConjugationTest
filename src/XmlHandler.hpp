#ifndef _XMLHANDLER_HPP
#define _XMLHANDLER_HPP

#include <wx/xml/xml.h>
#include "GermanWord.hpp"
#include <memory>
#include <map>

class XmlHandler {
    public:
        XmlHandler(wxString filename, bool);
        //empty deconstructor to make linker happy :)
        ~XmlHandler(){};

        //return next word
        std::unique_ptr<GermanWord> getNextWord(bool);

        void SetUpWord(std::vector<wxString>, wxXmlNode *);

        void WriteWord(std::vector<wxString>);

        void SaveFile();

        //return correct index to place read xml contents
        int indexXml(wxString xmlName);
       
    private:
        wxXmlDocument * p_mXmlDoc;
        wxXmlNode * p_mXmlRoot;
        //update to traverse tree
        wxXmlNode * p_mXmlCurrentNode;

        wxString filename;

        //recursive wrapper to navigate xml
        std::vector<wxString> TraverseWord(wxXmlNode*, std::vector<wxString>&);


};


#endif
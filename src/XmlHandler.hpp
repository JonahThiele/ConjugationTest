#ifndef _XMLHANDLER_HPP
#define _XMLHANDLER_HPP

#include <wx/xml/xml.h>
#include "GermanWord.hpp"
#include <memory>

class XmlHandler {
    public:
        XmlHandler(wxString filename);

        //return next word
        std::unique_ptr<GermanWord> getNextWord(bool);
       
    private:
        wxXmlDocument * p_mXmlDoc;
        wxXmlNode * p_mXmlRoot;
        //update to traverse tree
        wxXmlNode * p_mXmlCurrentNode;

        //recursive wrapper to navigate xml
        std::vector<wxString> TraverseWord(wxXmlNode*, std::vector<wxString>);


};


#endif
#ifndef _XMLHANDLER_HPP
#define _XMLHANDLER_HPP

#include <wx/xml/xml.h>
#include "GermanWord.hpp"

class XmlHandler {
    public:
        XmlHandler(wxString filename);
        ~XmlHandler();

        //return next word
        GermanWord getNextWord();
       
    private:
        wxXmlDocument * p_mXmlDoc;
        wxXmlNode * p_mXmlRoot;
        //update to traverse tree
        wxXmlNode * p_mXmlCurrentNode;

        //recursive wrapper to navigate xml
        std::vector<wxString> TraverseWord(wxXmlNode*);


};


#endif
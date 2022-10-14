#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "IncorWordFrame.hpp"

IncorWordFrame::IncorWordFrame(const wxChar *title, wxPoint wpoint, int width, int height, std::shared_ptr<GermanWord> word)
    : wxFrame((wxFrame *) NULL, -1, title, wpoint, wxSize(width, height), wxDEFAULT_FRAME_STYLE)
    , germanWord_up_(move(word))
    {
        m_pBoxSizer = new wxBoxSizer( wxVERTICAL );
        m_pFlexGridSizer = new wxFlexGridSizer(2);

        std::vector<wxString> forms = germanWord_up_->returnAllForms();
        for(int i = 0; i < forms.size() ; i++)
        {
            formList[i] = forms[i];
        }

        wxString Description("Description:");
        wxString DescriptionLabel = Description + formList[0];
        labelList[0] = new wxStaticText(this, wxID_ANY, DescriptionLabel, wxDefaultPosition, wxDefaultSize);

        m_pBoxSizer->Add(
            labelList[0],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        wxString BaseForm("Base Word:");
        wxString BaseLabel = BaseForm + formList[1];
        labelList[1] = new wxStaticText(this, wxID_ANY, BaseLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[0])
        {
            labelList[1]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[1]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pBoxSizer->Add(
            labelList[1],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        wxString IchForm("Ich Form:");
        wxString IchLabel = IchForm + formList[2];
        labelList[2] = new wxStaticText(this, wxID_ANY, IchLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[1])
        {
            labelList[2]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[2]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[2],
            wxSizerFlags().Align(0).Shaped().Center()
        );

 
        wxString WirForm("Wir Form:");
        wxString WirLabel = WirForm + formList[3];
        labelList[3] = new wxStaticText(this, wxID_ANY, WirLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[2])
        {
            labelList[3]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[3]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[3],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        wxString DuForm("Du Form:");
        wxString DuLabel = DuForm + formList[4];
        labelList[4] = new wxStaticText(this, wxID_ANY, DuLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[3])
        {
            labelList[4]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[4]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[4],
            wxSizerFlags().Align(0).Shaped().Center()
        );


        wxString IhrForm("Ihr Form:");
        wxString IhrLabel = IhrForm + formList[5];
        labelList[5] = new wxStaticText(this, wxID_ANY, IhrLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[4])
        {
            labelList[5]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[5]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[5],
            wxSizerFlags().Align(0).Shaped().Center()
        );


        wxString ErForm("Er Form:");
        wxString ErLabel = ErForm + formList[6];
        labelList[6] = new wxStaticText(this, wxID_ANY, ErLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[5])
        {
            labelList[6]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[6]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[6],
            wxSizerFlags().Align(0).Shaped().Center()
        );


        wxString SieTheyForm("Sie Form:");
        wxString SieTheyFormLabel = SieTheyForm + formList[7];
        labelList[7] = new wxStaticText(this, wxID_ANY, SieTheyFormLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[6])
        {
            labelList[7]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[7]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[7],
            wxSizerFlags().Align(0).Shaped().Center()
        );


        wxString SieHerForm("Sie Form:");
        wxString SieHerLabel = SieHerForm + formList[8];
        labelList[8] = new wxStaticText(this, wxID_ANY, SieHerLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[7])
        {
            labelList[8]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[8]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[8],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        
        wxString SieFormalForm("Sie Form:");
        wxString SieFormalLabel = SieFormalForm + formList[9];
        labelList[9] = new wxStaticText(this, wxID_ANY, SieFormalLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[8])
        {
            labelList[9]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[9]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[9],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        wxString EsForm("Es Form:");
        wxString EsLabel = EsForm + formList[10];
        labelList[10] = new wxStaticText(this, wxID_ANY, EsLabel, wxDefaultPosition, wxDefaultSize);
        if(germanWord_up_->returnErrorMask()[9])
        {
            labelList[10]->SetForegroundColour( wxColor(*wxRED));
        }else{
            labelList[10]->SetForegroundColour( wxColor(*wxGREEN));
        }


        m_pFlexGridSizer->Add(
            labelList[10],
            wxSizerFlags().Align(0).Shaped().Center()
        );

        m_pBoxSizer->Add(
            m_pFlexGridSizer,
            wxSizerFlags(1).Align(0).Expand().Border(wxALL, 10)
        );

        SetSizerAndFit(m_pBoxSizer);
    }
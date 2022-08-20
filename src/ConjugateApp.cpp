#include "wx/wxprec.h"

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "ConjugateApp.hpp"
#include "ConjugateFrame.hpp"


IMPLEMENT_APP(ConjugateApp)

bool ConjugateApp::OnInit()
{
    ConjugateFrame *frame = new ConjugateFrame( wxT("Conjugation App"), 100, 100, 400, 300);
    frame->Show(TRUE);
    SetTopWindow(frame);
    return true;

}
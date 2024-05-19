#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* mainframe = new MainFrame("CALCOLATRICE");
    mainframe->SetClientSize(310, 430);
    mainframe->SetMinClientSize(wxSize(310, 430));
    mainframe->SetMaxClientSize(wxSize(310, 430));
    mainframe->EnableMinimizeButton(false);
    mainframe->EnableMaximizeButton(false);
    mainframe->SetBackgroundColour(wxColour(0,0,0));
    mainframe->Centre();
    mainframe->Show();
    return true;
}

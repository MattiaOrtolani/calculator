#include <iostream>
#include <cstring>
#include <wx/wx.h>

using namespace std;


class MainFrame : public wxFrame
{
    
public:

    MainFrame(const wxString& title);

private:

    wxDECLARE_EVENT_TABLE();

    void OnButtonClicked0(wxCommandEvent& evt);
    void OnButtonClicked1(wxCommandEvent& evt);
    void OnButtonClicked2(wxCommandEvent& evt);
    void OnButtonClicked3(wxCommandEvent& evt);
    void OnButtonClicked4(wxCommandEvent& evt);
    void OnButtonClicked5(wxCommandEvent& evt);
    void OnButtonClicked6(wxCommandEvent& evt);
    void OnButtonClicked7(wxCommandEvent& evt);
    void OnButtonClicked8(wxCommandEvent& evt);
    void OnButtonClicked9(wxCommandEvent& evt);
    void OnButtonClicked10(wxCommandEvent& evt);
    void OnButtonClicked11(wxCommandEvent& evt);
    void OnButtonClicked12(wxCommandEvent& evt);
    void OnButtonClicked13(wxCommandEvent& evt);
    void OnButtonClicked14(wxCommandEvent& evt);
    void OnButtonClicked15(wxCommandEvent& evt);
    void OnButtonClicked16(wxCommandEvent& evt);
    void OnButtonClicked18(wxCommandEvent& evt);
    void ExtraMenu(wxCommandEvent& evt);
    void OnClose(wxCloseEvent& evt);

    wxPanel* panel;
    wxPanel* panel2;
    wxStaticText* statictext;
};
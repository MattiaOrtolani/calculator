
// versione 1.0.1      |   20 - 1 - 2023

#include "MainFrame.h"
#include "tinyexpr.h"
#include <wx/wx.h>
#include <wx/dcbuffer.h>
//
string result;
char tabella[100];
int i = -1;
bool check_resutl = true;
bool estensione = false;

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)

    EVT_CLOSE(MainFrame::OnClose)

wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{

    wxFont text_box_font(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    wxFont button_font(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);


    panel = new wxPanel(this);
    panel2 = new wxPanel(this);
    panel2->Show(false);

    wxGridSizer* sizer = new wxGridSizer(310,430,0,0);
    sizer->Add(panel2);
    sizer->Add(panel);

    SetSizer(sizer);

    wxButton* button0 = new wxButton(panel, wxID_ANY , "\n0\n", wxPoint(10, 370), wxSize(140, 50));
    button0->SetFont(button_font);
    button0->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button1 = new wxButton(panel, wxID_ANY, "\n1\n", wxPoint (10, 310), wxSize(65, 50));
    button1->SetFont(button_font);
    button1->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button2 = new wxButton(panel, wxID_ANY , "\n2\n", wxPoint(85, 310), wxSize(65, 50));
    button2->SetFont(button_font);
    button2->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button3 = new wxButton(panel, wxID_ANY , "\n3\n", wxPoint(160, 310), wxSize(65, 50));
    button3->SetFont(button_font);
    button3->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button4 = new wxButton(panel, wxID_ANY , "\n4\n", wxPoint(10, 250), wxSize(65, 50));
    button4->SetFont(button_font);
    button4->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button5 = new wxButton(panel, wxID_ANY , "\n5\n", wxPoint(85, 250) , wxSize(65, 50));
    button5->SetFont(button_font);
    button5->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button6 = new wxButton(panel, wxID_ANY , "\n6\n", wxPoint(160, 250), wxSize(65, 50));
    button6->SetFont(button_font);
    button6->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button7 = new wxButton(panel, wxID_ANY , "\n7\n", wxPoint(10, 190), wxSize(65, 50));
    button7->SetFont(button_font);
    button7->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button8 = new wxButton(panel, wxID_ANY , "\n8\n", wxPoint(85, 190), wxSize(65, 50));
    button8->SetFont(button_font);
    button8->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button9 = new wxButton(panel, wxID_ANY , "\n9\n", wxPoint(160, 190), wxSize(65, 50));
    button9->SetFont(button_font);
    button9->SetBackgroundColour(wxColor(57, 75, 111));

    wxButton* button10 = new wxButton(panel, wxID_ANY , "\n=\n", wxPoint(160, 370), wxSize(65, 50));
    button10->SetForegroundColour(wxColor(0,0,0));
    button10->SetFont(button_font);
    button10->SetBackgroundColour(wxColor(118,72,230));

    wxButton* button11 = new wxButton(panel, wxID_ANY , "\n+\n", wxPoint(235, 370), wxSize(65, 50));
    button11->SetForegroundColour(wxColor(0,0,0));
    button11->SetFont(button_font);
    button11->SetBackgroundColour(wxColor(1, 189, 7));

    wxButton* button12 = new wxButton(panel, wxID_ANY , "\n-\n",  wxPoint(235, 310), wxSize(65, 50));
    button12->SetForegroundColour(wxColor(0,0,0));
    button12->SetFont(button_font);
    button12->SetBackgroundColour(wxColor(1, 189, 7));

    wxButton* button13 = new wxButton(panel, wxID_ANY , "\nx\n", wxPoint(235, 250), wxSize(65, 50)); 
    button13->SetForegroundColour(wxColor(0,0,0));
    button13->SetFont(button_font);
    button13->SetBackgroundColour(wxColor(1, 189, 7));

    wxButton* button14 = new wxButton(panel, wxID_ANY, "\n:\n", wxPoint(235, 190), wxSize(65, 50));
    button14->SetForegroundColour(wxColor(0,0,0));
    button14->SetFont(button_font);
    button14->SetBackgroundColour(wxColor(1, 189, 7));

    wxButton* button15 = new wxButton(panel, wxID_ANY , "\nCE\n", wxPoint(85, 130), wxSize(65, 50));
    button15->SetForegroundColour(wxColor(0,0,0));
    button15->SetFont(button_font);
    button15->SetBackgroundColour(wxColor(118,72,230));

    wxButton* button16 = new wxButton(panel, wxID_ANY , "\n<--\n", wxPoint(160, 130), wxSize(140, 50));
    button16->SetForegroundColour(wxColor(0,0,0));
    button16->SetFont(button_font);
    button16->SetBackgroundColour(wxColor(118,72,230));

    wxButton* button17 = new wxButton(panel, wxID_ANY , "\nES\n", wxPoint(10, 130), wxSize(65, 50));
    button17->SetForegroundColour(wxColor(0,0,0));
    button17->SetFont(button_font);
    button17->SetBackgroundColour(wxColor(118,72,230));

//------------------------BOTTONI SCIENTIFICA----------------------

    wxButton* button18 = new wxButton(panel2, wxID_ANY , "\n.\n", wxPoint(10, 10), wxSize(65, 50));
    button18->SetForegroundColour(wxColor(0,0,0));
    button18->SetFont(button_font);
    button18->SetBackgroundColour(wxColor(1, 189, 7));

//------------------------SCHERMO CALCOLATRICE---------------------

    wxStaticBox* box = new wxStaticBox(panel, wxID_ANY, "" , wxPoint(10, 10), wxSize(290, 110));
    box->SetBackgroundColour(wxColor(60, 60, 60));

    statictext = new wxStaticText(box, wxID_ANY, "", wxPoint(5, 70), wxSize(-1, -1));
    statictext->SetFont(text_box_font);

//----------------------DICHIARAZIONI DELLE FUNZIONI----------------


    button0->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked0, this);
    button1->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked1, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked2, this);
    button3->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked3, this);
    button4->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked4, this);
    button5->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked5, this);
    button6->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked6, this);
    button7->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked7, this);
    button8->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked8, this);
    button9->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked9, this);
    button10->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked10, this);
    button11->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked11, this);
    button12->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked12, this);
    button13->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked13, this);
    button14->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked14, this);
    button15->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked15, this);
    button16->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked16, this);
    button17->Bind(wxEVT_BUTTON, &MainFrame::ExtraMenu, this);
    button18->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked18, this);
}

//----------------------QUANDO SI CHIUDE L'APP----------------------

void MainFrame::OnClose(wxCloseEvent& evt)
{
    exit(1);
}

//----------------------------BOTTONE 0------------------------------

void MainFrame::OnButtonClicked0(wxCommandEvent& evt)
{
    bool primo_zero;

    if(check_resutl)
    {
        for(int controllo = i; controllo > -1; controllo--)   //    0,9+6,07
        {
            if(tabella[controllo] == '+' || tabella[controllo] == '-' || tabella[controllo] == '*' || tabella[controllo] == '/')
            {
                for(int controllo2 = i; controllo2 > controllo; controllo2--)
                {
                    if(tabella[controllo] != '0')
                    {
                        if(check_resutl)
                        {
                            i++;
                            tabella[i] = '0';
                            statictext->SetLabel(statictext->GetLabel() + tabella[i]);
                            break;
                        }
                    }

                    if(tabella[controllo2] == '.')
                    {
                        if(check_resutl)
                        {
                            i++;
                            tabella[i] = '0';
                            statictext->SetLabel(statictext->GetLabel() + tabella[i]);
                            break;
                        }
                    }  
                }
            } 
        }    
    }
}

//----------------------------BOTTONE 1------------------------------

void MainFrame::OnButtonClicked1(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '1';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 2------------------------------

void MainFrame::OnButtonClicked2(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '2';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 3------------------------------

void MainFrame::OnButtonClicked3(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '3';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 4------------------------------

void MainFrame::OnButtonClicked4(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '4';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 5------------------------------

void MainFrame::OnButtonClicked5(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '5';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 6------------------------------

void MainFrame::OnButtonClicked6(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '6';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 7------------------------------

void MainFrame::OnButtonClicked7(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '7';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 8------------------------------

void MainFrame::OnButtonClicked8(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '8';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 9------------------------------

void MainFrame::OnButtonClicked9(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        i++;
        tabella[i] = '9';
        statictext->SetLabel(statictext->GetLabel() + tabella[i]);
    }
}

//----------------------------BOTTONE 10-----------------------------

void MainFrame::OnButtonClicked10(wxCommandEvent& evt)
{
    int err;
    const char *operazione = tabella;

    if(i > 0)
    {
        for(int p = 0; p <= i; p++)
        {
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }
        
        float tot = te_interp(operazione, &err);
        result = to_string(tot);

        if(result.find('.') != string::npos)
        {
            result = result.substr(0, result.find_last_not_of('0')+1);

            if(result.find('.') == result.size()-1)
            {
                result = result.substr(0, result.size()-1);
            }
        }

        statictext->SetLabel(statictext->GetLabel() + result);
        check_resutl = false;
    }
}

//----------------------------BOTTONE 11-----------------------------

void MainFrame::OnButtonClicked11(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        if(tabella[i] == '+' || tabella[i] == '-' || tabella[i] == '*' || tabella[i] == '/' || tabella[i] == '.')
        {
        }
        else
        {
            if(i > -1)
            {
                i++;
                tabella[i] = '+';
                statictext->SetLabel(statictext->GetLabel() + tabella[i]);
            }
        }
    }
}

//----------------------------BOTTONE 12-----------------------------

void MainFrame::OnButtonClicked12(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        if(tabella[i] == '+' || tabella[i] == '-' || tabella[i-1] == '*' || tabella[i-1] == '/' || tabella[i] == '.')
        {
        }
        else
        {
            i++;
            tabella[i] = '-';
            statictext->SetLabel(statictext->GetLabel() + tabella[i]);
        }
    }
}

//----------------------------BOTTONE 13-----------------------------

void MainFrame::OnButtonClicked13(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        if(tabella[i] == '+' || tabella[i] == '-' || tabella[i] == '*' || tabella[i] == '/' || tabella[i] == '.')
        {
        }
        else
        {
            if(i > -1)
            {
                i++;
                tabella[i] = '*';
                statictext->SetLabel(statictext->GetLabel() + "x");  
            }
        }
    }  
}

//----------------------------BOTTONE 14-----------------------------

void MainFrame::OnButtonClicked14(wxCommandEvent& evt)
{
    if(check_resutl)
    {
        if(tabella[i] == '+' || tabella[i] == '-' || tabella[i] == '*' || tabella[i] == '/' || tabella[i] == '.')
        {
        }
        else
        {
            if(i > -1)
            {
                i++;
                tabella[i] = '/';
                statictext->SetLabel(statictext->GetLabel() + ":");
                
            }
        }
    }
}

//----------------------------BOTTONE 15-----------------------------

void MainFrame::OnButtonClicked15(wxCommandEvent& evt)
{   
    if(result.empty())
    {
        for(int delate = i; delate >= 0; delate--)
        {
            tabella[delate] = NULL;
            i--;
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }

    }
    else
    {
        for(int delate = i; delate < strlen(tabella); delate--)
        {
            tabella[delate] = NULL;
            i--;
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }

        for(int clear = 0; clear < result.length(); clear++)
        {
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }

        result.clear();

        check_resutl = true;
    }
}

//----------------------------BOTTONE 16-----------------------------

void MainFrame::OnButtonClicked16(wxCommandEvent& evt)
{  
    if(result.empty())
    {
        if(i > -1)
        {   
            if(tabella[i] == '+' || tabella[i] == '-' || tabella[i] == '*' || tabella[i] == '/')
            {
                tabella[i] = NULL;
                i--;
                wxString label = statictext->GetLabel();
                label.RemoveLast();
                statictext->SetLabel(label);
            }
            else
            {
                tabella[i] = NULL;
                i--;
                wxString label = statictext->GetLabel();
                label.RemoveLast();
                statictext->SetLabel(label);
            }
        }
    }
    else
    {
        for(int delate = i; delate < strlen(tabella); delate--)
        {
            tabella[delate] = NULL;
            i--;
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }

        for(int clear = 0; clear < result.length(); clear++)
        {
            wxString label = statictext->GetLabel();
            label.RemoveLast();
            statictext->SetLabel(label);
        }

        result.clear();

        check_resutl = true;
    }
    
}

//----------------------------BOTTONE 18-----------------------------

void MainFrame::OnButtonClicked18(wxCommandEvent& evt)
{
    bool virgola;

    if(i > -1)
    {
        if(tabella[i] == '+' || tabella[i] == '-' || tabella[i] == '*' || tabella[i] == '/' || tabella[i] == '.')
        {
        }
        else
        {
            for(int controllo = i; controllo > -1; controllo--)
            {
                if(tabella[controllo] == '+' || tabella[controllo] == '-' || tabella[controllo] == '*' || tabella[controllo] == '/')
                {
                    for(int controllo2 = controllo; controllo2 <= i; controllo2++)
                    {
                        if(tabella[controllo2] == '.')
                        {
                            virgola = true;
                            break;
                        }
                        else
                        {
                            virgola = false;
                        }
                    }

                    if(virgola == false)
                    {
                        if(check_resutl)
                        {
                            i++;
                            tabella[i] = '.';
                            statictext->SetLabel(statictext->GetLabel() + tabella[i]);
                        }
                    }
                }
                else  
                {
                    for(int controllo2 = i; controllo2 > -1; controllo2--)
                    {
                        if(tabella[controllo2] == '.')
                        {
                            virgola = true;
                            break;
                        }
                        else
                        {
                            virgola = false;
                        }
                    }

                    if(virgola == false)
                    {
                        if(check_resutl)
                        {
                            i++;
                            tabella[i] = '.';
                            statictext->SetLabel(statictext->GetLabel() + tabella[i]);
                        }
                    }
                }
            }
        }
    }
}

//----------------------------EXTRA MENU-----------------------------

void MainFrame::ExtraMenu(wxCommandEvent& evt)
{
    if(estensione == false)
    {
        wxPoint pos = GetPosition();
        int newWidth = GetSize().GetWidth() + 300;
        int newHeight = GetSize().GetHeight();


        SetSize(wxSize(newWidth, newHeight));
        SetPosition(wxPoint(pos.x-150,pos.y));
        panel->SetPosition(wxPoint(150,0));
        panel2->Show(true);




        estensione = true;
    }
    else
    {   
        wxPoint pos = GetPosition();

        SetSize(wxSize(310, 460));
        panel->SetPosition(wxPoint(0,0));
        panel2->Show(false);
        SetPosition(wxPoint(pos.x+150,pos.y));

        estensione = false;
    }
}

//-------------------------------FINE---------------------------------

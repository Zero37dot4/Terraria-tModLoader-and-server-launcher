#include "MainFrame.h"
#include <wx/wx.h>
#include <shellapi.h>

#define myID_OK 50

enum {
	myID_CANCEL = wxID_HIGHEST+1,
	myID_NEXT
};



MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, myID_OK, "Terraria", 
		wxPoint(50, 0), wxSize(200, 50));

	wxButton* button2 = new wxButton(panel, wxID_ANY, "Tmodloader",
		wxPoint(50, 50), wxSize(200, 50));

	wxButton* button3 = new wxButton(panel, myID_CANCEL, "Terraria-Server",
		wxPoint(50, 100), wxSize(200, 50));

	wxButton* button4 = new wxButton(panel, myID_NEXT, "Tmodloader-Server",
		wxPoint(50, 150), wxSize(200, 50));

	wxButton* ups = new wxButton(panel, wxID_ANY, "Upd",
		wxPoint(275, 175), wxSize(25, 25));

	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnButton3Clicked, this);
	button4->Bind(wxEVT_BUTTON, &MainFrame::OnButton4Clicked, this);
	ups->Bind(wxEVT_BUTTON, &MainFrame::upsd, this);
	
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	ShellExecuteA(NULL, "open", "Terraria.exe", NULL, "Terraria", SW_SHOWDEFAULT);
	exit(NULL);
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	ShellExecuteA(NULL, "open", "tmodloader\\start-tModLoader.bat", NULL, NULL, SW_SHOWDEFAULT);
	exit(NULL);
}

void MainFrame::OnButton3Clicked(wxCommandEvent& evt) {
	ShellExecuteA(NULL, "open", "Terraria\\TerrariaServer.exe", NULL, NULL, SW_SHOWDEFAULT);
	exit(NULL);
}

void MainFrame::OnButton4Clicked(wxCommandEvent& evt) {
	ShellExecuteA(NULL, "open", "tmodloader\\start-tModLoaderServer.bat", NULL, NULL, SW_SHOWDEFAULT);
	exit(NULL);
}

void MainFrame::upsd(wxCommandEvent& evt) {
	wxMessageDialog dialog(this, "This will update tModLoader even if it is on the latest version already, are you sure you want to continue?",
		"Warning!", wxYES_NO | wxCANCEL);
	int result = dialog.ShowModal();

	if (result == wxID_YES) {
		ShellExecuteA(NULL, "open", "Bin\\tModLoader Updater.ps1", NULL, NULL, SW_SHOWDEFAULT);
	}
}
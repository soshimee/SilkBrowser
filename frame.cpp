#include "frame.hpp"

enum { ID_Hello = 1 };
wxBEGIN_EVENT_TABLE(SilkBrowserFrame, wxFrame) EVT_MENU(ID_Hello, SilkBrowserFrame::OnHello)
	EVT_MENU(wxID_EXIT, SilkBrowserFrame::OnExit) EVT_MENU(wxID_ABOUT, SilkBrowserFrame::OnAbout)
		wxEND_EVENT_TABLE()

SilkBrowserFrame::SilkBrowserFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	m_browser = wxWebView::New(this, wxID_ANY, "https://random-stuff.netlify.app/", wxDefaultPosition, wxDefaultSize);
	// topsizer->Add(m_browser, wxSizerFlags().Expand().Proportion(1));
}
void SilkBrowserFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void SilkBrowserFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World",
		wxOK | wxICON_INFORMATION);
}
void SilkBrowserFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}
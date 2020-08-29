#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
	std::cout << std::string(ptr, size*nmemb) << std::endl;
	return size*nmemb;
}

// wxWidgets: https://www.wxwidgets.org/ wx-config

int fetch_url() {
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://random-stuff.netlify.app");
		/* example.com is redirected, so we tell libcurl to follow redirection */ 
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		/* Perform the request, res will get the return code */ 
		res = curl_easy_perform(curl);
		/* Check for errors */ 
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

		/* always cleanup */ 
		curl_easy_cleanup(curl);
	}
	return 0;
}

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};
class MyFrame: public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
enum
{
	ID_Hello = 1
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(ID_Hello,   MyFrame::OnHello)
	EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);
bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
	frame->Show( true );
	return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
		: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
					 "Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append( menuFile, "&File" );
	menuBar->Append( menuHelp, "&Help" );
	SetMenuBar( menuBar );
	CreateStatusBar();
	SetStatusText( "Welcome to wxWidgets!" );
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox( "This is a wxWidgets' Hello world sample",
				  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");
}

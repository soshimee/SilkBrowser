#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx-3.0/wx/webview.h>
#endif

class SilkBrowserFrame : public wxFrame
{
public:
	SilkBrowserFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
	wxWebView *m_browser;
	void OnHello(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnAbout(wxCommandEvent &event);
	wxDECLARE_EVENT_TABLE();
};

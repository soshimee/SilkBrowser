#include "app.hpp"
#include "frame.hpp"

bool SilkBrowserApp::OnInit()
{
	SilkBrowserFrame* frame = new SilkBrowserFrame("SilkBrowser", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(SilkBrowserApp);
#include "app.h"
#include "frame.h"

bool SilkBrowserApp::OnInit()
{
	SilkBrowserFrame* frame = new SilkBrowserFrame("SilkBrowser", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(SilkBrowserApp);
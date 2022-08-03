#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
  MainFrame* mainFrame = new MainFrame("C++ GUI Planner");
  mainFrame->SetClientSize(800, 600);
  mainFrame->Center();
  mainFrame->Show();
  return true;
}
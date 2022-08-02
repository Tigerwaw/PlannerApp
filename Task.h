#pragma once
#include <wx/wx.h>
#include <wx/timectrl.h>
#include <iostream>
#include <vector>

using namespace std;

class Task : public wxPanel
{
public:
  Task(wxWindow* parent_panel, const wxSize& size, wxBoxSizer* sizer);

private:
  wxTimePickerCtrl* timePicker;
  wxTextCtrl* textEntry;
};


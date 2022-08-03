#pragma once
#include <wx/wx.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task : public wxPanel
{
public:
  Task(wxWindow* parent_panel, const wxSize& size, wxBoxSizer* sizer);
  string GetTime();
  string GetText();

private:
  wxTimePickerCtrl* timePicker;
  wxTextCtrl* textEntry;
  wxButton* deleteButton;

  string time;
  string text;

  void OnDeleteTaskClick(wxCommandEvent& evt);
  void OnTimeUpdate(wxDateEvent& evt);
  void OnTextUpdate(wxCommandEvent& evt);
};


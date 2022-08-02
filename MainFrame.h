#pragma once
#include <wx/wx.h>
#include <wx/timectrl.h>
#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class MainFrame : public wxFrame
{
public:
  MainFrame(const wxString& title);

protected:
  wxString selected_day = "M";
  vector<Task*> tasks;
  wxPanel* task_panel;
  wxBoxSizer* task_sizer;
  wxBoxSizer* mainframe_sizer;
  wxBoxSizer* daytab_sizer;

private:
  void OnButtonClicked_Monday(wxCommandEvent& evt);
  void OnButtonClicked_Tuesday(wxCommandEvent& evt);
  void OnButtonClicked_Wednesday(wxCommandEvent& evt);
  void OnButtonClicked_Thursday(wxCommandEvent& evt);
  void OnButtonClicked_Friday(wxCommandEvent& evt);
  void OnButtonClicked_Saturday(wxCommandEvent& evt);
  void OnButtonClicked_Sunday(wxCommandEvent& evt);

  void OnCreateTaskClick(wxCommandEvent& evt);

  void InitializeDayButtons(wxPanel* parent_panel);
};


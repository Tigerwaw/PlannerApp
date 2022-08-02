#include "Task.h"

Task::Task(wxWindow* parent_panel, const wxSize& size, wxBoxSizer* sizer) : wxPanel(parent_panel, wxID_ANY, wxDefaultPosition, size)
{
  this->SetBackgroundColour(wxColor(197, 197, 197));
  sizer->Add(this, 0, wxEXPAND | wxALL, 10);

  timePicker = new wxTimePickerCtrl(this, wxID_ANY, wxDateTime(0, 0, 0), wxPoint(20, 20));
  textEntry = new wxTextCtrl(this, wxID_ANY, "Task", wxPoint(200, 20));

  wxBoxSizer* itemSizer = new wxBoxSizer(wxHORIZONTAL);
  itemSizer->Add(timePicker, 1, wxEXPAND | wxALL, 10);
  itemSizer->Add(textEntry, 2, wxEXPAND | wxALL, 10);
  itemSizer->SetMinSize(800, -1);

  this->SetSizerAndFit(itemSizer);
  parent_panel->SetSizerAndFit(sizer);
}
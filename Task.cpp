#include "Task.h"

Task::Task(wxWindow* parent_panel, const wxSize& size, wxBoxSizer* sizer) : wxPanel(parent_panel, wxID_ANY, wxDefaultPosition, size)
{
  this->SetBackgroundColour(wxColor(197, 197, 197));
  sizer->Add(this, 0, wxEXPAND | wxALL, 10);

  timePicker = new wxTimePickerCtrl(this, wxID_ANY, wxDateTime(0, 0, 0));
  textEntry = new wxTextCtrl(this, wxID_ANY, "Task");
  deleteButton = new wxButton(this, wxID_ANY, "X");
  deleteButton->Bind(wxEVT_BUTTON, &Task::OnDeleteTaskClick, this);

  wxBoxSizer* itemSizer = new wxBoxSizer(wxHORIZONTAL);
  itemSizer->SetMinSize(800, -1);
  itemSizer->Add(timePicker, 1, wxEXPAND | wxALL, 10);
  itemSizer->Add(textEntry, 2, wxEXPAND | wxALL, 10);
  itemSizer->Add(deleteButton, 0.25, wxEXPAND | wxALL, 10);

  this->SetSizerAndFit(itemSizer);
  parent_panel->SetSizerAndFit(sizer);

  this->Hide();
  this->ShowWithEffect(wxSHOW_EFFECT_SLIDE_TO_RIGHT);
}

void Task::OnDeleteTaskClick(wxCommandEvent& evt)
{
  this->HideWithEffect(wxSHOW_EFFECT_SLIDE_TO_LEFT);
  this->Destroy();
}
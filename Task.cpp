#include "Task.h"

Task::Task(wxWindow* parent_panel, const wxSize& size, wxBoxSizer* sizer) : wxPanel(parent_panel, wxID_ANY, wxDefaultPosition, size)
{
  this->SetBackgroundColour(wxColor(197, 197, 197));
  sizer->Add(this, 0, wxEXPAND | wxALL, 10);

  timePicker = new wxTimePickerCtrl(this, wxID_ANY, wxDateTime(0, 0, 0));
  timePicker->Bind(wxEVT_TIME_CHANGED, &Task::OnTimeUpdate, this);

  textEntry = new wxTextCtrl(this, wxID_ANY, "Task", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
  textEntry->Bind(wxEVT_TEXT, &Task::OnTextUpdate, this);

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

void Task::OnTimeUpdate(wxDateEvent& evt)
{
  time = timePicker->GetValue().Format(wxT("%H:%M"));
  wxLogStatus(wxString("Saved Time: " + time));
}

void Task::OnTextUpdate(wxCommandEvent& evt)
{
  text = textEntry->GetValue();
  wxLogStatus(wxString("Saved Text: " + text));
}

string Task::GetTime()
{
  return time;
}

string Task::GetText()
{
  return text;
}
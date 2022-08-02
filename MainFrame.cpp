#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
  wxPanel* daytab_panel = new wxPanel(this, wxID_ANY);
  daytab_panel->SetBackgroundColour(wxColor(197, 197, 197));

  task_panel = new wxPanel(this, wxID_ANY);
  task_panel->SetBackgroundColour(wxColor(237, 237, 237));

  mainframe_sizer = new wxBoxSizer(wxVERTICAL);
  mainframe_sizer->Add(daytab_panel, 0, wxALL | wxEXPAND, 10);
  mainframe_sizer->Add(task_panel, 1, wxALL | wxEXPAND, 10);
  mainframe_sizer->SetMinSize(-1, 600);
  daytab_sizer = new wxBoxSizer(wxHORIZONTAL);
  task_sizer = new wxBoxSizer(wxVERTICAL);

  wxButton* addNewTask_button = new wxButton(task_panel, wxID_ANY, "Add New Task", wxDefaultPosition, wxSize(800, -1));
  addNewTask_button->Bind(wxEVT_BUTTON, &MainFrame::OnCreateTaskClick, this);
  task_sizer->Add(addNewTask_button, 0, wxEXPAND | wxALL, 10);

  InitializeDayButtons(daytab_panel);

  daytab_panel->SetSizerAndFit(daytab_sizer);
  task_panel->SetSizerAndFit(task_sizer);
  this->SetSizerAndFit(mainframe_sizer);

  CreateStatusBar();
}

void MainFrame::InitializeDayButtons(wxPanel* parent_panel)
{
  const wxString days[7] = { "M", "T", "W", "Th", "F", "Sa", "S" };
  wxButton* day_buttons[7];

  for (int i = 0; i < 7; i++)
  {
    day_buttons[i] = new wxButton(parent_panel, wxID_ANY, days[i], wxDefaultPosition, wxSize(-1, 50));
    daytab_sizer->Add(day_buttons[i], 1, wxEXPAND | wxALL, 5);
  }

  day_buttons[0]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Monday, this);
  day_buttons[1]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Tuesday, this);
  day_buttons[2]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Wednesday, this);
  day_buttons[3]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Thursday, this);
  day_buttons[4]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Friday, this);
  day_buttons[5]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Saturday, this);
  day_buttons[6]->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked_Sunday, this);
}

void MainFrame::ReloadFrames()
{
  this->SetSizerAndFit(mainframe_sizer);
  task_panel->SetSizerAndFit(task_sizer);
}

// ---
// EVENT FUNCTIONS ---
// --

void MainFrame::OnCreateTaskClick(wxCommandEvent& evt)
{
  Task* task = new Task(task_panel, wxSize(-1, 50), task_sizer);
  tasks.push_back(task);
  task->Bind(wxEVT_DESTROY, &MainFrame::OnDeleteTask, this);

  wxLogStatus("Created Task!");
  ReloadFrames();
}

void MainFrame::OnDeleteTask(wxWindowDestroyEvent& evt)
{
  wxLogStatus("Deleted Task!");
  ReloadFrames();
}

void MainFrame::OnButtonClicked_Monday(wxCommandEvent& evt)
{
  selected_day = "Monday";
  wxLogStatus(wxString::Format("Monday Selected"));
}

void MainFrame::OnButtonClicked_Tuesday(wxCommandEvent& evt)
{
  selected_day = "Tuesday";
  wxLogStatus(wxString::Format("Tuesday Selected"));
}

void MainFrame::OnButtonClicked_Wednesday(wxCommandEvent& evt)
{
  selected_day = "Wednesday";
  wxLogStatus(wxString::Format("Wednesday Selected"));
}

void MainFrame::OnButtonClicked_Thursday(wxCommandEvent& evt)
{
  selected_day = "Thursday";
  wxLogStatus(wxString::Format("Thursday Selected"));
}

void MainFrame::OnButtonClicked_Friday(wxCommandEvent& evt)
{
  selected_day = "Friday";
  wxLogStatus(wxString::Format("Friday Selected"));
}

void MainFrame::OnButtonClicked_Saturday(wxCommandEvent& evt)
{
  selected_day = "Saturday";
  wxLogStatus(wxString::Format("Saturday Selected"));
}

void MainFrame::OnButtonClicked_Sunday(wxCommandEvent& evt)
{
  selected_day = "Sunday";
  wxLogStatus(wxString::Format("Sunday Selected"));
}
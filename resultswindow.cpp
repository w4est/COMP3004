#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <string>

ResultsWindow::ResultsWindow(vectorTotal _results, int groupSize, string _projectName, QWidget *parent, int _x, int _y) :
    QWidget(parent),
    ui(new Ui::ResultsWindow)
{
    maxSize = groupSize;
    string title = "Results";
    string subTitle = "Project " + _projectName + ": Results";

    this->move(_x, _y - 28);

    ui->setupUi(this);
    this->setWindowTitle(title.c_str());
    ui->page_title->setText(subTitle.c_str());
    buildSubLists(_results);
}

ResultsWindow::~ResultsWindow()
{
    delete ui;
}

void ResultsWindow::buildSubLists(vectorTotal _rand)
{
    QWidget *form;
    widget = new QWidget();

    layout = new QVBoxLayout();

    int groupAmount = _rand.size();

    for(int i = 0; i < groupAmount; i++)
    {
        form = buildResultFrame(_rand.at(i), i+1);
        layout->addWidget(form);
    }

    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
}

QWidget* ResultsWindow::buildResultFrame(vectorIntern _rand, int _teamNum)
{
      ResultFrame* frame = new ResultFrame(0, _teamNum);

      int studentAmount = _rand.size();
      QString styleSheet = "";

      if(studentAmount < maxSize)
      {
          styleSheet = "background-color: rgb(0, 102, 153); color: white;"; //blue
      }
      else{
          styleSheet = "background-color: rgb(0, 204, 51); color: black;"; //green
      }


      for(int i = 0; i < studentAmount; i++)
      {
          ProfileEntity* temp = &(_rand.at(i));
        QString name = temp->getUsername().c_str();
        frame->setStyleSheet(styleSheet);
        frame->addStudent(name);
      }
      frameList.push_back(frame);
      return frame;
}

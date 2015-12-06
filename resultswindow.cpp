#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <string>

ResultsWindow::ResultsWindow(vectorTotal _results, QWidget *parent, int _x, int _y) :
    QWidget(parent),
    ui(new Ui::ResultsWindow)
{
    ui->setupUi(this);
    buildSubLists(7);
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

    for(int i = 0; i < _rand; i++)
    {
        form = buildResultFrame(10);
        layout->addWidget(form);
    }

    widget->setLayout(layout);

    scrollBoxLayout = new QVBoxLayout();
    scrollBoxLayout->setSpacing(25);

    ui->scrollArea->setWidget(widget);
    ui->scrollArea->setLayout(scrollBoxLayout);
}

QWidget* ResultsWindow::buildResultFrame(vectorIntern _rand)
{
      ResultFrame* frame = new ResultFrame(0);
      for(int i = 0; i < 2*_rand; i++)
      {
        QString name = "Name";
        name.append(std::to_string(i).c_str());
        frame->addStudent(name);
      }
      frameList.push_back(frame);
      return frame;
}

#include "stuprojectframe.h"
#include "ui_stuprojectframe.h"
#include <iostream>

  stuProjectFrame::stuProjectFrame(StudentControl* _control, QWidget *parent) :
      QFrame(parent),
      ui(new Ui::stuProjectFrame)
  {
      control = _control;
      ui->setupUi(this);
  }

  stuProjectFrame::~stuProjectFrame()
  {
      control = 0;
      delete ui;
  }

  /*
   * change description
   */
  void stuProjectFrame::setDescription(QString _desc)
  {
      ui->label->setText(_desc);
  }



  void stuProjectFrame::setId(int _id){
      id = _id;
  }

  int stuProjectFrame::getId()
  {
      return id;
  }

  /*
   * when mouse on current frame, change self color and set StudentControl's current frame placeholder to this
   */
  void stuProjectFrame::mousePressEvent(QMouseEvent *_event)
  {
      if(_event){};
      this->setStyleSheet("stuProjectFrame { background: rgb(204, 153, 51); selection-background-color: rgb(0, 0, 0)}");
      control->setCurrentFrame(this);
  }

#pragma once

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include "ui_QmlCppRegister.h"

class QmlCppRegister : public QWidget {
  Q_OBJECT

 public:
  QmlCppRegister(QWidget *parent = nullptr);
  ~QmlCppRegister();

 private:
  Ui::QmlCppRegisterClass ui;
  void Func1();
  void Func2();
  void Func2_();
  void Func_ext();
};

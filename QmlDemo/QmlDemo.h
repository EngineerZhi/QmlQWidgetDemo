#pragma once

#include <QtWidgets/QWidget>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include "ui_QmlDemo.h"

class QmlDemo : public QWidget {
  Q_OBJECT

 public:
  QmlDemo(QWidget *parent = nullptr);
  ~QmlDemo();

 private slots:
  void on_btn_left_clicked();
  void on_btn_right_clicked();

 private:
  void Func1();
  void Func2();
  void Func3();
  void Func4();

  Ui::QmlDemoClass ui;
  QQuickWidget *cpp_qml_widget_ = nullptr;
  QQmlApplicationEngine *engine_ = nullptr;

};

#pragma once

#include <QQuickItem>
#include <QWidget>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickWidget>
#include "ui_CppCallQml.h"

class CppCallQml : public QWidget {
  Q_OBJECT

 public:
  CppCallQml(QWidget *parent = nullptr);
  ~CppCallQml();
 private slots:
  void on_btn_left_clicked();
  void on_btn_right_clicked();

signals:
  void NotifySendMsg(const QVariant &arg1);
 private:
  Ui::CppCallQmlClass ui;
  void InitView();
  QQuickWidget *cpp_qml_widget_ = nullptr;
};

#pragma once

#include <QtWidgets/QWidget>
#include "ui_QmlDemo.h"

class QmlDemo : public QWidget
{
    Q_OBJECT

public:
    QmlDemo(QWidget *parent = nullptr);
    ~QmlDemo();

private:
    void Func1();
    void Func2();
    Ui::QmlDemoClass ui;
};

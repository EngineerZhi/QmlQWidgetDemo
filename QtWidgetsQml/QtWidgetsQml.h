#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsQml.h"

class QtWidgetsQml : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsQml(QWidget *parent = nullptr);
    ~QtWidgetsQml();

private:
    Ui::QtWidgetsQmlClass ui;
 void LoadFunc();
};

#pragma once

#include <QObject>
class QmlControl : public QObject {
  Q_OBJECT

 public:
  QmlControl(QObject *parent = nullptr);
  ~QmlControl();
  int cur_count_{888};
  //Q_SLOT void AddData(int a, int b);
  //Q_SLOT QString UpdateBackground();

  // Q_INVOKABLE void AddData(int a, int b);
  // Q_INVOKABLE QString UpdateBackground();
 public slots:
 void AddData(int a, int b);
 QString UpdateBackground();


 private:
  int count_ = 0;

};



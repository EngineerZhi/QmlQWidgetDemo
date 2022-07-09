#pragma once

#include <QObject>

class QTestData : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString name READ getName WRITE setName NOTIFY NameChanged)
 public:
  QTestData(QObject *parent=nullptr);
  ~QTestData();
  QString getName();

  void setName(QString name);

 signals:
  void NameChanged(QString name);
 private:
  QString name_;
};

#include "QTestData.h"

#include <QDebug>
QTestData::QTestData(QObject *parent) : QObject(parent) {
  connect(this, &QTestData::NameChanged, this, [this](QString name) {
    qDebug() << "sigNameChanged new_name=" << name;
  });
}

QTestData::~QTestData() {}

QString QTestData::getName() {
  qDebug() << __FUNCTION__;
 return name_;
}

void QTestData::setName(QString name) {
  qDebug() << __FUNCTION__;
  if (name_ == name) {
    return;
  }
  name_ = name;
  emit NameChanged(name);
}

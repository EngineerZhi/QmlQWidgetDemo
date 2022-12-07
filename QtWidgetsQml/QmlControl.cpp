#include "QmlControl.h"

#include <QDebug>
QmlControl::QmlControl(QObject *parent) : QObject(parent) {}

QmlControl::~QmlControl() {}

void QmlControl::AddData(int a, int b) {
  count_++;
  qDebug() << "a=" << a << "b=" << b;
  qDebug() << "a+b=" << a + b;
  qDebug() << "count_=" << count_;
}

QString QmlControl::UpdateBackground() {
  return QString("http://image.nbd.com.cn/uploads/articles/images/673466/500352700_banner.jpg");
}

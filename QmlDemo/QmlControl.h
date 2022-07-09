#pragma once

#include <QObject>
class QmlControl  : public QObject
{
	Q_OBJECT

public:
	QmlControl(QObject *parent=nullptr);
	~QmlControl();
 public slots:
    void AddData(int a, int b);
    QString UpdateBackground();

   private:
    int count_ = 0;
};

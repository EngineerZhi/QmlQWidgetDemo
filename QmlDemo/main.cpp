#include "QmlDemo.h"
#include <QtWidgets/QApplication>
#include "QmlControl.h"
#include <QQuickWidget>
#include <QQmlApplicationEngine>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QmlDemo w;
    w.show();
    return a.exec();
}

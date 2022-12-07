#include "QtWidgetsQml.h"
#include <QQuickWidget>
#include <QQmlApplicationEngine>
#include <QQuickView>
QtWidgetsQml::QtWidgetsQml(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
  LoadFunc();

}

QtWidgetsQml::~QtWidgetsQml() {}

void QtWidgetsQml::LoadFunc() {
  //方式一
  /*
  QQuickView *qml_view = new QQuickView();
  qml_view->setResizeMode(QQuickView::SizeRootObjectToView);
  qml_view->setSource(QUrl("load_test.qml"));
  QWidget *widget = QWidget::createWindowContainer(qml_view, nullptr);
  ui.verticalLayout->addWidget(widget);
  qml_view->show();
  */
  //方式二 推荐
  QQuickWidget *qml_widget = new QQuickWidget();
  qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qml_widget->setSource(QUrl("load_test.qml"));
  qml_widget->show();
  ui.verticalLayout->addWidget(qml_widget);
}

#include "QmlDemo.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QQuickWidget>

#include "QmlControl.h"
#include "QTestData.h"
QmlControl qml_control;
QmlDemo::QmlDemo(QWidget *parent) : QWidget(parent) {
  ui.setupUi(this);
  // Func2();
  //Func1();
  Func3();
  //QTestData data;
  //data.name = "2022";
}

QmlDemo::~QmlDemo() {}

void QmlDemo::Func1() {
  /*
   *template<typename T>
   *int qmlRegisterType(const char *uri, int versionMajor, int versionMinor,
   *const char *qmlName) uri:qml中的包名 versionMajor：主版本号
   *versionMinor：副版本号
   *qmlName：qml中类型名称
   */
  qmlRegisterType<QmlControl>("test.conrtrol", 1, 0, "QmlControl");
  QQuickWidget *qml_widget = new QQuickWidget();
  qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qml_widget->setSource(QUrl("register_type_qml.qml"));
  qml_widget->show();
  ui.verticalLayout->addWidget(qml_widget);
}

void QmlDemo::Func2() {
  //注册方式二(写法1)
  // QQmlApplicationEngine *engine = new QQmlApplicationEngine();
  // engine->rootContext()->setContextProperty("qml_ctrl", &qml_control);
  // QQuickWidget *qml_widget = new QQuickWidget(engine,nullptr);
  //注册方式二(写法2)
  QQuickWidget *qml_widget = new QQuickWidget();
  qml_widget->rootContext()->setContextProperty("qml_ctrl", &qml_control);

  qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qml_widget->setSource(QUrl("set_context_qml.qml"));
  qml_widget->show();
  ui.verticalLayout->addWidget(qml_widget);
}

void QmlDemo::Func3() {
  qmlRegisterType<QTestData>("test.conrtrol", 1, 1, "CppTestData");
  QQuickWidget *qml_widget = new QQuickWidget();
  qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qml_widget->setSource(QUrl("signal_qml.qml"));
  qml_widget->show();
  ui.verticalLayout->addWidget(qml_widget);
}

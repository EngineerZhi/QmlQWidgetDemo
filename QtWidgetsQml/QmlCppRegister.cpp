#include "QmlCppRegister.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickWidget>
#include <QTimer>
#include <QDebug>


#include "QmlControl.h"
#include "QTestData.h"

static QObject *cpp_qobject_singletontype_provider(
    QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)

  QmlControl *cpp_obj = new QmlControl();
  return cpp_obj;
}
static QJSValue getCountStatic(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine)
  Q_UNUSED(scriptEngine)
  static int test_value = 0;
  QJSValue value_example = scriptEngine->newObject();
  value_example.setProperty("addProperty", ++test_value);
  return value_example;
}

QmlCppRegister::QmlCppRegister(QWidget *parent) : QWidget(parent) {
  ui.setupUi(this);
  Func1();
  //Func2();
  // Func2_();
 // Func_ext();
}

QmlCppRegister::~QmlCppRegister() {}

void QmlCppRegister::Func1() {
  /*
   *template<typename T>
   *int qmlRegisterType(const char *uri, int versionMajor, int versionMinor,
   *const char *qmlName) uri:qml中的包名 versionMajor：主版本号
   *versionMinor：副版本号
   *qmlName：qml中类型名称
   */
  qmlRegisterType<QmlControl>("test.conrtrol", 1, 0, "QmlControl");
  //qmlRegisterSingletonType<QmlControl>("test.conrtrol", 1, 0, "Qmlctrl",
  //                                     cpp_qobject_singletontype_provider );

  // qmlRegisterSingletonType("test.conrtrol", 1, 0,"Qmlctrl" ,getCountStatic);

   for (int i = 0; i < 2; i++) {
    QQuickWidget *qml_widget = new QQuickWidget();
    qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qml_widget->setSource(QUrl("register_type_qml.qml"));
    qml_widget->show();
    ui.verticalLayout->addWidget(qml_widget);
  }

 // QQmlApplicationEngine *engine = new QQmlApplicationEngine();
 // for (int i = 0; i < 2; i++) {
 //   QQuickWidget *qml_widget = new QQuickWidget(engine, nullptr);
 //   qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
 //   qml_widget->setSource(QUrl("register_type_qml.qml"));
 //   qml_widget->show();
 //   ui.verticalLayout->addWidget(qml_widget);
 // }
}

void QmlCppRegister::Func2() {
  QmlControl *qml_control = new QmlControl;
  QQmlApplicationEngine *engine = new QQmlApplicationEngine();
  engine->rootContext()->setContextProperty("qml_ctrl", qml_control);
  for (int i = 0; i < 1; i++) {
    QQuickWidget *qml_widget = new QQuickWidget(engine, nullptr);
    qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qml_widget->setSource(QUrl("set_context_qml.qml"));
    qml_widget->show();
    ui.verticalLayout->addWidget(qml_widget);
  }
}

void QmlCppRegister::Func2_() {
  QmlControl *qml_control = new QmlControl;
  //暴漏方式二(写法2)
  for (int i = 0; i < 1; i++) {
    QQuickWidget *qml_widget = new QQuickWidget();
    qml_widget->rootContext()->setContextProperty("qml_ctrl", qml_control);
    qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    qml_widget->setSource(QUrl("set_context_qml.qml"));
    qml_widget->show();
    ui.verticalLayout->addWidget(qml_widget);
  }
  // QTimer::singleShot(5000, [qml_control]() mutable {
  //  delete qml_control;
  //  qml_control = nullptr;
  //});
}

void QmlCppRegister::Func_ext() {
  qmlRegisterType<QTestData>("test.conrtrol", 1, 1, "CppTestData");
  QQuickWidget *qml_widget = new QQuickWidget();
  qml_widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
  qml_widget->setSource(QUrl("signal_qml.qml"));
  qml_widget->show();
  ui.verticalLayout->addWidget(qml_widget);
}

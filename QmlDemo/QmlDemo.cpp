#include "QmlDemo.h"
#include<qobject>
#include "QTestData.h"
#include "QmlControl.h"
QmlControl qml_control;
QmlDemo::QmlDemo(QWidget *parent) : QWidget(parent) {
  ui.setupUi(this);
  // Func2();
  // Func1();
  // Func3();
  Func4();
}

QmlDemo::~QmlDemo() {}

void QmlDemo::on_btn_left_clicked() {
  auto obj_image =
    cpp_qml_widget_->rootObject()->findChild<QObject *>("image_test_obj");
  QMetaObject::invokeMethod(
     obj_image, "updateSource",
      Q_ARG(QVariant,
           QString("http://image.nbd.com.cn/uploads/articles/images/673466/500352700_banner.jpg")));

  QMetaObject::invokeMethod(
      obj_image, "updateSay", Q_ARG(QVariant, 50));

}
void QmlDemo::on_btn_right_clicked() {
  auto obj_image = cpp_qml_widget_->rootObject()->findChild<QObject *>("image_test_obj");
  obj_image->setProperty(
      "source",
      "http://image.nbd.com.cn/uploads/articles/images/673466/500352700_banner.jpg");
  auto enable_see= obj_image->property("enable_see").toInt();
}

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

void QmlDemo::Func4() {
  engine_ = new QQmlApplicationEngine();
  //QQuickWidget *qml_widget = new QQuickWidget(engine,nullptr);
  cpp_qml_widget_ = new QQuickWidget(engine_, nullptr);
  cpp_qml_widget_->setResizeMode(QQuickWidget::SizeRootObjectToView);
  cpp_qml_widget_->setSource(QUrl("cpp_to_qml.qml"));
  cpp_qml_widget_->show();
  ui.verticalLayout->addWidget(cpp_qml_widget_);

}

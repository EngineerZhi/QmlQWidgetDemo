#include "CppCallQml.h"

#include <qDebug>
#include <qobject>
CppCallQml::CppCallQml(QWidget *parent) : QWidget(parent) {
  ui.setupUi(this);
  InitView();
}

CppCallQml::~CppCallQml() {}

void CppCallQml::on_btn_left_clicked() {
  auto obj_image =
      cpp_qml_widget_->rootObject()->findChild<QObject *>("image_test_obj");
  obj_image->setProperty("source",
                         "http://image.nbd.com.cn/uploads/articles/images/"
                         "673466/500352700_banner.jpg");
  auto enable_see = obj_image->property("enable_see").toInt();
  { QQuickItem *item = qobject_cast<QQuickItem *>(obj_image); }
  qDebug() << "enable_see=" << enable_see;
}

void CppCallQml::on_btn_right_clicked() {
  auto obj_image =
      cpp_qml_widget_->rootObject()->findChild<QObject *>("image_test_obj");
  QMetaObject::invokeMethod(obj_image, "updateSource",
                            Q_ARG(QVariant,
                                  "http://image.nbd.com.cn/uploads/articles/"
                                  "images/673466/500352700_banner.jpg"));
  {
    connect(this, SIGNAL(NotifySendMsg(QVariant)), obj_image,
            SLOT(updateSource(QVariant)), Qt::UniqueConnection);

    emit NotifySendMsg(
        "http://image.zhangxinxu.com/image/study/s/s256/mm6.jpg");
  }
}

void CppCallQml::InitView() {
  cpp_qml_widget_ = new QQuickWidget();
  cpp_qml_widget_->setResizeMode(QQuickWidget::SizeRootObjectToView);
  cpp_qml_widget_->setSource(QUrl("cpp_to_qml.qml"));
  cpp_qml_widget_->show();
  ui.verticalLayout->addWidget(cpp_qml_widget_);
  auto obj_image =
      cpp_qml_widget_->rootObject()->findChild<QObject *>("image_test_obj");
}

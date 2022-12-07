#include "QtWidgetsQml.h"
#include <QtWidgets/QApplication>
#include "QmlCppRegister.h"
#include "CppCallQml.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //{
  //  QtWidgetsQml w;
  //  w.show();
  //}

 QmlCppRegister w;
 w.show();

  //CppCallQml w;
  //w.show();

    return a.exec();
}

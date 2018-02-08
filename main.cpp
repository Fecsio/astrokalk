#include "View/astrokalk.h"
#include <QApplication>
#include <QFile>
#include <QDesktopWidget>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Astrokalk k;

    QFile stylesheet(":/style/View/style.qss");
    stylesheet.open(QFile::ReadOnly);
    QString style(stylesheet.readAll());
    k.setStyleSheet(style);
    k.setGeometry(0,0,1,1);
    k.setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    k.show();
    return a.exec();
}

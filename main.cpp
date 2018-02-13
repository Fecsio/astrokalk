#include "View/finestra.h"
#include <QApplication>
#include <QFile>
#include <QDesktopWidget>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Finestra k;

    QFile stylesheet(":/style/View/style.qss");
    stylesheet.open(QFile::ReadOnly);
    QString style(stylesheet.readAll());
    k.setStyleSheet(style);
    k.setMaximumSize(k.getSizeKalk());
    k.show();
    return a.exec();
}

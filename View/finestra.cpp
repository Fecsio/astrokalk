#include "finestra.h"

Finestra::Finestra(QWidget *parent) : QMainWindow(parent)
{
    sa = new QScrollArea(this);
    a = new Astrokalk;
    sa->setWidget(a);
    setCentralWidget(sa);

}

QSize Finestra::getSizeKalk() const{
    return QSize(a->width()+50, a->height()+50);
}

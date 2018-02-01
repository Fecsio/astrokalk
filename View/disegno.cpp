#include "disegno.h"
#include <QLabel>
#include <QGridLayout>

Disegno::Disegno(QWidget *parent) : QWidget(parent){
    QLabel* top = new QLabel("Disegno");
    top->setStyleSheet("font-weight: bold;");
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(top,0,0);

}

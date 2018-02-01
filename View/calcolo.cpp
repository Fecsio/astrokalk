#include "calcolo.h"
#include <QLabel>
#include <QGridLayout>

Calcolo::Calcolo(Model *m, QWidget *parent) : QWidget(parent), model(m){
    QLabel* top = new QLabel("Calcolo");

    top->setStyleSheet("font-weight: bold;");

    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(top,0,0);
}

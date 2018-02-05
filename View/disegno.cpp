#include "disegno.h"
#include <QLabel>
#include <QGridLayout>
#include <QImage>

Disegno::Disegno(QWidget *parent) : QWidget(parent){
    QLabel* top = new QLabel("Disegno");
    top->setStyleSheet("font-weight: bold; border: none; background-color: none;");
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(top,0,0);
    layout->setSpacing(0);

    QImage img(":/immagini/View/immagini/asteroide.png");

    QLabel *myLabel = new QLabel;
    myLabel->setPixmap(QPixmap::fromImage(img));
    layout->addWidget(myLabel,1,0);

}

#include "pulsanteconinput.h"
#include "QGridLayout"
#include "QLabel"

PulsanteConInput::PulsanteConInput(const QString& placeH, const QString& title, QWidget *parent) : QPushButton(parent){
    input = new QLineEdit;
    QLabel *titolo = new QLabel(title);
    input->setPlaceholderText(placeH);
    QGridLayout *aux = new QGridLayout(this);
    aux->addWidget(titolo,0,0);
    aux->addWidget(input,1,0);
    aux->setSpacing(0);
}

QString PulsanteConInput::getText() const{
    return input->text();
}

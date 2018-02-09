#include "pulsanteconinput.h"
#include "QGridLayout"

PulsanteConInput::PulsanteConInput(const QString& placeH, const QString& title, QWidget *parent) : QPushButton(parent){
    QGridLayout *aux = new QGridLayout(this);
    input = new QLineEdit;
    titolo = new QLabel(title);
    input->setPlaceholderText(placeH);
    aux->addWidget(titolo,0,0);
    aux->addWidget(input,1,0);
    aux->setSpacing(0);
}

QString PulsanteConInput::getText() const{
    return input->text();
}

QString PulsanteConInput::text() const{
    return titolo->text();
}

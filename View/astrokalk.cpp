#include "astrokalk.h"

Astrokalk::Astrokalk(QWidget *parent) : QWidget(parent){
    model = new Model();
    creazione = new Creazione(model);
    disegno = new Disegno();
    calcolo = new Calcolo(model);
    creati = new Creati(model);

    layoutbase = new QGridLayout(this);
    layoutbase->addWidget(creazione,0,0);
    layoutbase->addWidget(disegno,1,1);
    layoutbase->addWidget(calcolo,1,0);
    layoutbase->addWidget(creati,0,1);

    layoutbase->setAlignment(creazione,Qt::AlignTop);
    layoutbase->setAlignment(disegno,Qt::AlignTop);
    layoutbase->setAlignment(calcolo,Qt::AlignTop);
    layoutbase->setAlignment(creati,Qt::AlignTop);

    disegno->setStyleSheet("border: 1px solid #000; background-color: white;");
    disegno->setMinimumSize(200,100);

    layoutbase->setRowStretch(0,1);
    layoutbase->setRowStretch(1,2);
    layoutbase->setRowMinimumHeight(1,500);

    connect(creazione, SIGNAL(oggAggiunto()),
            this, SLOT(aggOgg()));

    connect(calcolo, SIGNAL(oggAggiunto()),
            this, SLOT(aggOgg()));
}

void Astrokalk::aggOgg(){
    Creati* aux = new Creati(model);
    layoutbase->addWidget(aux,1,1);
    delete creati;
    creati = new Creati(model);
    layoutbase->removeWidget(aux);
    layoutbase->addWidget(creati,0,1);
    delete aux;
    aux = 0;
}

#include "calcolo.h"
#include <QLabel>
#include <QGridLayout>

Calcolo::Calcolo(Model *m, QWidget *parent) : QWidget(parent), model(m){
    QLabel* top = new QLabel("Calcolo");
    top->setStyleSheet("font-weight: bold;");
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(top,0,0);

    QIcon a(":/icone/View/Icone/asteroide.png");
    QIcon s(":/icone/View/Icone/stella.png");
    QIcon p(":/icone/View/Icone/pianeta.png");
    QIcon sa(":/icone/View/Icone/satellite.png");

    display = new QLineEdit;
    display->setReadOnly(true);

    //result = new QPushButton("=");

    tipo1 = new QComboBox;
    tipo1->addItem("Tipo operando");
    tipo1->addItem(a,"Asteroide");
    tipo1->addItem(s,"Stella");
    tipo1->addItem(p,"Pianeta");
    tipo1->addItem(sa,"Satellite");

    tipo2 = new QComboBox;
    tipo2->addItem("Tipo operando");
    tipo2->addItem(a,"Asteroide");
    tipo2->addItem(s,"Stella");
    tipo2->addItem(p,"Pianeta");
    tipo2->addItem(sa,"Satellite");

    primoOperando = new QLineEdit;
    primoOperando->setPlaceholderText("Indice (es. '0')");
    primoOperando->setDisabled(true);
    secondoOperando = new QLineEdit;
    secondoOperando->setPlaceholderText("Indice (es. '0')");
    secondoOperando->setDisabled(true);
    tipo2->setDisabled(true);

    /*add1 = new QPushButton;
    add1->setIcon(QIcon(":/icone/View/Icone/frecciasu.png"));
    add2 = new QPushButton;
    add2->setIcon(QIcon(":/icone/View/Icone/frecciasu.png"));*/

    operazUn = new QGroupBox("Operazioni unarie (operatore 1)");
    operazBin = new QGroupBox("Operazioni binarie ");

    QGridLayout *layout1 = new QGridLayout;

    layout1->addWidget(tipo1,0,0);
    layout1->addWidget(primoOperando,0,1);
    layout1->addWidget(tipo2,0,4);
    layout1->addWidget(secondoOperando,0,5);

    layout1->setSpacing(0);
    layout1->setColumnStretch(0,1);
    layout1->setColumnStretch(1,1);
    layout1->setColumnStretch(2,0.5);
    layout1->setColumnStretch(3,1);
    layout1->setColumnStretch(4,1);
    layout1->setColumnStretch(5,1);
    layout1->setColumnStretch(6,0.5);

    somma = new QPushButton("Somma");
    rapportaV = new QPushButton("Rapporto volume");
    collisione = new QPushButton("Collisione");

    volume = new QPushButton("Volume");
    superficie = new QPushButton("Superficie");
    massa = new QPushButton("Massa");
    velFuga = new QPushButton("Vel. di fuga");
    calcPeso = new PulsanteConInput("Peso","PesoExtraterrestre");
    giorno = new QPushButton("Durata giorno");
    distTerra = new QPushButton("Distanza dalla Terra");
    distSole = new QPushButton("Distanza dalla stella");
    perOrb = new QPushButton("Durata anno");
    isAbitabile = new QPushButton("Abitabile?");
    etaET = new PulsanteConInput("Nascita(gg/mm/yyyy)","Eta extraterrestre");
    velOrbitale = new QPushButton("Vel. orbitale");
    hasRotSincrona = new QPushButton("Rotazione sincrona?");
    rivol1Anno = new QPushButton("Rivoluzioni in un anno");

    QVBoxLayout *layout_opB = new QVBoxLayout;
    layout_opB->addWidget(somma);
    layout_opB->addWidget(rapportaV);
    operazBin->setLayout(layout_opB);

    QGridLayout *layout_opU = new QGridLayout;
    layout_opU->addWidget(volume,0,0);
    layout_opU->addWidget(superficie,1,0);
    layout_opU->addWidget(massa,2,0);
    layout_opU->addWidget(velFuga,3,0);

    layout_opU->addWidget(calcPeso,0,1);
    layout_opU->addWidget(distTerra,2,1);
    layout_opU->addWidget(distSole,3,1);
    layout_opU->addWidget(collisione,1,1);

    layout_opU->addWidget(perOrb,0,2);
    layout_opU->addWidget(isAbitabile,1,2);
    layout_opU->addWidget(etaET,2,2,2,1);

    layout_opU->addWidget(hasRotSincrona,0,3);
    layout_opU->addWidget(rivol1Anno,1,3);
    layout_opU->addWidget(giorno,3,3);
    layout_opU->addWidget(velOrbitale,2,3);

    operazUn->setLayout(layout_opU);

    layout->addWidget(display,1,0,1,5);
    //layout->addWidget(result,1,4);
    layout->addLayout(layout1,2,0,1,5);
    layout->addWidget(operazBin,3,0);
    layout->addWidget(operazUn,3,1,1,4);

    foreach (QPushButton* b, this->findChildren<QPushButton*>()) {
       b->setDisabled(true);
    }

    connect(tipo1, SIGNAL(currentIndexChanged(int)),
            this, SLOT(cambiaKeyboard1(int)));

    connect(tipo2, SIGNAL(currentIndexChanged(int)),
            this, SLOT(cambiaKeyboard2(int)));

    connect(volume, SIGNAL(clicked(bool)),
            this, SLOT(calcVol()));
    connect(superficie, SIGNAL(clicked(bool)),
            this, SLOT(calcSup()));
    connect(massa, SIGNAL(clicked(bool)),
            this, SLOT(calcMass()));

}


void Calcolo::cambiaKeyboard1(int i){
    primoOperando->clear();
    if(i == 0){
        foreach (QPushButton *b, this->findChildren<QPushButton*>()) {
            b->setDisabled(true);
        }
        primoOperando->setDisabled(true);
        secondoOperando->setDisabled(true);
        tipo2->setDisabled(true);

    }

    else{
        primoOperando->setDisabled(false);
        tipo2->setDisabled(false);
        volume->setDisabled(false);
        superficie->setDisabled(false);
        massa->setDisabled(false);

        if(tipo2->currentIndex() != 0){
            rapportaV->setDisabled(false);
        }

        else{
            rapportaV->setDisabled(true);
        }

        if(i == tipo2->currentIndex()){
            somma -> setDisabled(false);
        }

        else{
            somma->setDisabled(true);
        }

        switch(i){
        case 1:
            calcPeso->setDisabled(true);
            velFuga->setDisabled(true);
            distTerra->setDisabled(true);
            distSole->setDisabled(true);
            perOrb->setDisabled(true);
            isAbitabile->setDisabled(true);
            etaET->setDisabled(true);
            hasRotSincrona->setDisabled(true);
            rivol1Anno->setDisabled(true);
            velOrbitale->setDisabled(true);
            giorno->setDisabled(true);
            collisione->setDisabled(false);

            break;

        case 2:
            calcPeso->setDisabled(false);
            giorno->setDisabled(false);
            velFuga->setDisabled(false);
            distTerra->setDisabled(false);

            distSole->setDisabled(true);
            perOrb->setDisabled(true);
            isAbitabile->setDisabled(true);
            etaET->setDisabled(true);
            hasRotSincrona->setDisabled(true);
            rivol1Anno->setDisabled(true);
            velOrbitale->setDisabled(true);
            collisione->setDisabled(true);
            break;

        case 3:
            calcPeso->setDisabled(false);
            giorno->setDisabled(false);
            velFuga->setDisabled(false);
            distSole->setDisabled(false);
            perOrb->setDisabled(false);
            isAbitabile->setDisabled(false);
            etaET->setDisabled(false);
            velOrbitale->setDisabled(false);

            distTerra->setDisabled(true);
            hasRotSincrona->setDisabled(true);
            rivol1Anno->setDisabled(true);
            collisione->setDisabled(true);
            break;

        case 4:
            calcPeso->setDisabled(false);
            giorno->setDisabled(false);
            velFuga->setDisabled(false);
            distSole->setDisabled(false);
            perOrb->setDisabled(false);
            hasRotSincrona->setDisabled(false);
            rivol1Anno->setDisabled(false);
            velOrbitale->setDisabled(false);

            distTerra->setDisabled(true);
            isAbitabile->setDisabled(true);
            etaET->setDisabled(true);
            collisione->setDisabled(true);
            break;
        }
    }
}

void Calcolo::cambiaKeyboard2(int i){
    secondoOperando->clear();
    if(i == 0){
        somma->setDisabled(true);
        rapportaV->setDisabled(true);
        collisione->setDisabled(true);
    }

    else{
        rapportaV->setDisabled(false);

        if(i == tipo1->currentIndex()){
            somma->setDisabled(false);
        }

        else{
            somma->setDisabled(true);
        }
     }
}

void Calcolo::calcVol(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Volume");
    display->setText(model->getResult());
}

void Calcolo::calcSup(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Superficie");
    display->setText(model->getResult());
}

void Calcolo::calcMass(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Massa");
    display->setText(model->getResult());
}


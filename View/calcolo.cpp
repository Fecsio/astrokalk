#include "calcolo.h"
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>

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

    operazUn = new QGroupBox("Operazioni unarie (primo operando)");
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
    peso = new PulsanteConInput("Peso","Peso Extraterrestre");
    giorno = new QPushButton("Durata giorno");
    distTerra = new QPushButton("Distanza dalla Terra");
    distSole = new QPushButton("Distanza dalla stella");
    perOrb = new QPushButton("Durata anno");
    isAbitabile = new QPushButton("Abitabile?");
    etaET = new PulsanteConInput("Nascita(gg/mm/yyyy)","Eta extraterrestre");
    etaET->setToolTip("Giorno di nascita - (gg/mm/yyyy)");
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

    layout_opU->addWidget(peso,0,1);
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

    connect(volume, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(superficie, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(massa, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(velFuga, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(peso, SIGNAL(clicked()),
            this, SLOT(calcUnParam()));

    connect(collisione, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(giorno, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(distTerra, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(distSole, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(perOrb, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(isAbitabile, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(etaET, SIGNAL(clicked()),
            this, SLOT(calcUnParam()));

    connect(velOrbitale, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(hasRotSincrona, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(rivol1Anno, SIGNAL(clicked()),
            this, SLOT(calcUn()));

    connect(somma, SIGNAL(clicked()),
            this, SLOT(calcBin()));

    connect(rapportaV, SIGNAL(clicked()),
            this, SLOT(calcBin()));

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
            peso->setDisabled(true);
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
            peso->setDisabled(false);
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
            peso->setDisabled(false);
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
            peso->setDisabled(false);
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
        secondoOperando->setDisabled(false);
        rapportaV->setDisabled(false);

        if(i == tipo1->currentIndex()){
            somma->setDisabled(false);
        }

        else{
            somma->setDisabled(true);
        }
     }
}

void Calcolo::calcUn(){
    int indice = primoOperando->text().toInt();
    int tipo = tipo1->currentIndex();

    if(primoOperando->text().isEmpty() || indice >= model->getSizeCreati(tipo-1)){
        QMessageBox err;
        QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout* layoutmsg = (QGridLayout*)err.layout();
        err.setWindowTitle("Errore");
        err.setInformativeText("Indice per il primo operando non valido");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
    }

    else{
        const OggettoCeleste *aux = model->getObj(tipo,indice);
        model->calcola(aux,qobject_cast<QPushButton*>(sender())->text());
        display->setText(model->getResult());
    }
}

void Calcolo::calcUnParam(){
    int indice = primoOperando->text().toInt();
    int tipo = tipo1->currentIndex();
    QString op = qobject_cast<PulsanteConInput*>(sender())->text();
    QMessageBox err;
    QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layoutmsg = (QGridLayout*)err.layout();
    err.setWindowTitle("Errore");

    if(primoOperando->text().isEmpty() || indice >= model->getSizeCreati(tipo-1)){
        err.setInformativeText("<p align='center'> Indice per il primo operando non valido </p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
    }

    else if(op == "Peso Extraterrestre" && peso->getText().toDouble() <= 0){
        err.setInformativeText("<p align='center'>Il peso deve essere >0 </p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
        }

    else if(op == "Eta extraterrestre" && !((QRegularExpression("^[0-9]{2}/[0-9]{2}/[0-9]{4}$").match(etaET->getText())).hasMatch())){
       /* QString pattern("^[0-9]{2}/[0-9]{2}/[0-9]{4}$");
        QRegularExpression re(pattern);
        QRegularExpressionMatch match = re.match(etaET->getText());

        if(!match.hasMatch()){*/
            err.setInformativeText("<p align='center'>La data non ha il formato corretto</p>");
            layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
            err.exec();
        }

    else{
        const OggettoCeleste *aux = model->getObj(tipo,indice);
        model->calcola(aux,op, qobject_cast<PulsanteConInput*>(sender())->getText());
        display->setText(model->getResult());
    }
}

void Calcolo::calcBin(){
    int indice_p = primoOperando->text().toInt();
    int tipo_p = tipo1->currentIndex();
    int indice_s = secondoOperando->text().toInt();
    int tipo_s = tipo2->currentIndex();

    QString op = qobject_cast<QPushButton*>(sender())->text();

    if(primoOperando->text().isEmpty() || indice_p >= model->getSizeCreati(tipo_p-1) || secondoOperando->text().isEmpty() || indice_s >= model->getSizeCreati(tipo_s -1)){
        QMessageBox err;
        QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout* layoutmsg = (QGridLayout*)err.layout();
        err.setWindowTitle("Errore");
        err.setInformativeText("<p align='center'> Indice per il primo o secondo operando non valido</p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
    }

    else{
        const OggettoCeleste *aux1 = model->getObj(tipo_p, indice_p);
        const OggettoCeleste *aux2 = model->getObj(tipo_s, indice_s);

        model->calcola(aux1, aux2, op);
        if(op == "Somma") {
            emit oggAggiunto();
        }
        display->setText(model->getResult());
    }
}
/*
void Calcolo::calcVol(){
    int indice = primoOperando->text().toInt();
    int tipo = tipo1->currentIndex();

    if(primoOperando->text().isEmpty() || indice >= model->getSizeCreati(tipo-1)){
        QMessageBox err;

    }
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

void Calcolo::calcVelFuga(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "VelFuga");
    display->setText(model->getResult());
}

void Calcolo::calcPeso(){
    QMessageBox opImpossibile;
    QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layoutmsg = (QGridLayout*)opImpossibile.layout();
    opImpossibile.setWindowTitle("Attenzione");
    opImpossibile.setInformativeText("<p align='center'>Il peso deve essere >0 </p>");
    layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());

    double p = peso->getText().toDouble();

    if(p<=0) opImpossibile.exec();

    else{
        OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
        model->calcola(aux, "Peso", peso->getText());
        display->setText(model->getResult());
    }
}

void Calcolo::calcColl(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Collisione");
    display->setText(model->getResult());
}

void Calcolo::calcDistTerra(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "DistTerra");
    display->setText(model->getResult());
}

void Calcolo::calcDistSole(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "DistSole");
    display->setText(model->getResult());
}

void Calcolo::calcAnno(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Anno");
    display->setText(model->getResult());
}

void Calcolo::calcAbitabile(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Abitabile");
    display->setText(model->getResult());
}

void Calcolo::calcEta(){
    QMessageBox opImpossibile;
    QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layoutmsg = (QGridLayout*)opImpossibile.layout();
    opImpossibile.setWindowTitle("Attenzione");

    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    QString pattern("^[0-9]{2}/[0-9]{2}/[0-9]{4}$");
    QRegularExpression re(pattern);
    QRegularExpressionMatch match = re.match(etaET->getText());

    if(!match.hasMatch()){
        opImpossibile.setInformativeText("<p align='center'>La data non ha il formato corretto</p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        opImpossibile.exec();
    }

    else{
        model->calcola(aux, "Eta", etaET->getText());
        display->setText(model->getResult());
    }
}

void Calcolo::calcRotSin(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "RotSincrona");
    display->setText(model->getResult());
}

void Calcolo::calcRivolAnno(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "RivolAnno");
    display->setText(model->getResult());
}

void Calcolo::calcGiorno(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "Giorno");
    display->setText(model->getResult());
}

void Calcolo::calcVelOrb(){
    OggettoCeleste *aux = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    model->calcola(aux, "VelOrb");
    display->setText(model->getResult());
}

void Calcolo::calcSomma(){
    OggettoCeleste *aux1 = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    OggettoCeleste *aux2 = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());

    model->calcola(aux1, aux2, "Somma");
    emit oggAggiunto();
    display->setText(model->getResult());
}

void Calcolo::calcRappV(){
    OggettoCeleste *aux1 = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());
    OggettoCeleste *aux2 = model->getObj(tipo1->currentIndex(), primoOperando->text().toInt());

    model->calcola(aux1, aux2, "RapportaV");
    display->setText(model->getResult());

}
*/


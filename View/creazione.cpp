#include "creazione.h"
#include <QLabel>
#include <QMessageBox>

Creazione::Creazione(Model *m, QWidget *parent) : QWidget(parent), model(m){
    QGridLayout* layout = new QGridLayout(this);

    QLabel* top = new QLabel("Creazione oggetti");
    top->setStyleSheet("font-weight: bold;");

    QIcon a(":/icone/View/Icone/asteroide.png");
    QIcon s(":/icone/View/Icone/stella.png");
    QIcon p(":/icone/View/Icone/pianeta.png");
    QIcon sa(":/icone/View/Icone/satellite.png");

    scelta = new QComboBox;
    scelta->addItem("Scegli un oggetto");
    scelta->addItem(a,"Asteroide");
    scelta->addItem(s,"Stella");
    scelta->addItem(p,"Pianeta");
    scelta->addItem(sa,"Satellite");


    input = new InputCreazione(model);

    layout->addWidget(top,0,0);
    layout->addWidget(scelta,1,0);
    layout->addWidget(input,2,0);


    scelta->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    layout->setAlignment(scelta,Qt::AlignLeft);

    connect(scelta,SIGNAL(currentIndexChanged(int)),
            input,SLOT(cambiaInput(int)));

    connect(input, SIGNAL(cAsteroide()),
            this,SLOT(creaAsteroide()));

    connect(input,SIGNAL(cStella()),
            this,SLOT(creaStella()));

    connect(input,SIGNAL(cPianeta()),
            this,SLOT(creaPianeta()));

    connect(input,SIGNAL(cSatellite()),
            this, SLOT(creaSatellite()));

    connect(input, SIGNAL(setScelta(char)),
            this, SLOT(settaScelta(char)));

    connect(this, SIGNAL(erroreI(QString)),
            this, SLOT(erroreInput(QString)));
}

void Creazione::erroreInput(QString s){
    QMessageBox err;
    err.setWindowTitle("Errore!");
    err.setText(s);
    err.setIconPixmap(QPixmap(":/icone/View/Icone/bad.svg"));
    err.exec();
}


void Creazione::creaAsteroide(){
    double r = input->getRaggio().toDouble();
    double t = input->getTemp().toDouble();
    double d = input->getDens().toDouble();
    unsigned int e = (int)input->getEta().toDouble();
    double v = input->getVel().toDouble();
    if(r <= 0 || d <= 0 || v <= 0){
        emit erroreI("Raggio, densità e velocità devono essere maggiori di 0, età maggiore o uguale a 0");
    }
    else{

        foreach(QLineEdit* le, input->findChildren<QLineEdit*>()) {
            le->clear();
        }

        model->newAsteroide(r,t,d,e,v);
        emit oggAggiunto();
    }
}

void Creazione::creaStella(){
    double r = input->getRaggio().toDouble();
    double t = input->getTemp().toDouble();
    double d = input->getDens().toDouble();
    unsigned int e = (int)input->getEta().toDouble();
    double v = input->getVrot().toDouble();
    double mass = input->getMAss().toDouble();
    double mapp = input->getMApp().toDouble();

    if(r <= 0 || d <= 0 || v <= 0){
        emit erroreI("Raggio, densità e velocità di rotazione devono essere maggiori di 0, età maggiore o uguale a 0");
    }

    else if(mass < -30 || mass >30 || mapp < -38 || mapp > 35){
        emit erroreI("I valori per le magnitudini non sono validi");
    }

    else{

        foreach(QLineEdit* le, input->findChildren<QLineEdit*>()) {
            le->clear();
        }

        model->newStella(r,t,d,e,v,mass,mapp);
        emit oggAggiunto();
    }
}

void Creazione::creaPianeta(){
    double r = input->getRaggio().toDouble();
    double t = input->getTemp().toDouble();
    double d = input->getDens().toDouble();
    int e = (int)input->getEta().toDouble();
    double v = input->getVrot().toDouble();
    double asse = input->getAsse().toDouble();
    double az  = input->getAz().toDouble();
    double o = input->getOss().toDouble();
    double ar = input->getAr().toDouble();
    int index_stella = input->getSole().toInt();

    if(r <= 0 || d <= 0 || v <= 0 || asse <= 0 || e<0){
        emit erroreI("Raggio, densità, velocità di rotazione e semiasse devono essere maggiori di 0, età maggiore o uguale a 0");
    }

    else if(az + o + ar != 100){
        emit erroreI("La somma dei valori per l' atmosfera deve essere esattemente 100");
    }

    else if(index_stella >= model->getSizeCreati(1) || index_stella < 0){
        emit erroreI("L'indice per il sole non è valido");
    }

    else{

        foreach(QLineEdit* le, input->findChildren<QLineEdit*>()) {
            le->clear();
        }

        const Stella& stella = *(model->getStella(index_stella));
        model->newPianeta(r,t,d,e,v,asse,o,az,ar,const_cast<Stella&>(stella));
        emit oggAggiunto();
    }
}

void Creazione::creaSatellite(){
    double r = input->getRaggio().toDouble();
    double t = input->getTemp().toDouble();
    double d = input->getDens().toDouble();
    unsigned int e = (int)input->getEta().toDouble();
    double v = input->getVrot().toDouble();
    double asse = input->getAsse().toDouble();
    int index_pianeta = input->getPia().toInt();

    if(r <= 0 || d <= 0 || v <= 0 || asse <= 0){
        emit erroreI("Raggio, densità, velocità di rotazione e semiasse devono essere maggiori di 0, età maggiore o uguale a 0");
    }

    else if(index_pianeta >= model->getSizeCreati(2) || index_pianeta < 0){
        emit erroreI("L'indice per il pianeta non è valido");
    }

    else{

        foreach(QLineEdit* le, input->findChildren<QLineEdit*>()) {
            le->clear();
        }

        const Pianeta& pianeta = *(model->getPianeta(index_pianeta));
        model->newSatellite(r,t,d,e,v,asse,const_cast<Pianeta&>(pianeta));
        emit oggAggiunto();
    }



}

void Creazione::settaScelta(char x){
    if(x == 's') scelta->setCurrentIndex(2);

    else if(x == 'p') scelta->setCurrentIndex(3);
}

#include "inputcreazione.h"
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>

InputCreazione::InputCreazione(Model* m, QWidget *parent) : QWidget(parent), model(m){

    QLabel *rLabel = new QLabel("Raggio:");
    raggio = new QLineEdit;
    //raggio->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *tLabel = new QLabel("Temperatura:");
    tempSuperficiale = new QLineEdit;
    //tempSuperficiale->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *dLabel = new QLabel("Densità:");
    densita = new QLineEdit;
    //densita->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *eLabel = new QLabel("Età:");
    eta = new QLineEdit;
    //eta->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *vRotLabel = new QLabel("Vel. rotazione:");
    velRot = new QLineEdit;
   // velRot->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *sAsseLabel = new QLabel("Semiasse:");
    sAsseLabel->setToolTip("1 UA = 150.000 km");
    semiAsse = new QLineEdit;
    //semiAsse->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    atmosfera = new QGroupBox("Atmosfera:");
    QHBoxLayout *layoutAtm = new QHBoxLayout(atmosfera);
    atmosfera->setStyleSheet("font-weight: normal;");
    azoto = new QLineEdit;
    ossigeno = new QLineEdit;
    argon = new QLineEdit;
    layoutAtm->addWidget(azoto);
    layoutAtm->addWidget(ossigeno);
    layoutAtm->addWidget(argon);
    QLabel *atmUnitLabel = new QLabel("%");
    layoutAtm->addWidget(atmUnitLabel);

    QLabel *sLabel = new QLabel("Sole:");
    sole = new QLineEdit;
    //sole->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *pLabel = new QLabel("Pianeta:");
    pianeta = new QLineEdit;
    //pianeta->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *vLabel = new QLabel("Velocità:");
    velocita = new QLineEdit;
    //velocita->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *magnAssLabel= new QLabel("M. assoluta:");
    magnAssLabel->setToolTip("Magnitudine assoluta, da -20 a 10");
    mAss = new QLineEdit;
    //mAss->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    QLabel *magnAppLabel= new QLabel("M. apparente:");
    magnAppLabel->setToolTip("Magnitudine apparente, da -26.74 a 10");
    mApp = new QLineEdit;
    //mApp->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    crea = new QPushButton("Crea");
    crea->setDisabled(true);

    QGridLayout *inputs = new QGridLayout(this);

    //label per unita di misura

    QLabel *rUnitLabel = new QLabel("km");
    QLabel *tUnitLabel = new QLabel("C°");
    QLabel *dUnitLabel = new QLabel("g/cm^3");
    QLabel *vRotUnitLabel = new QLabel("km/h");
    QLabel *sAsseUnitLabel = new QLabel("UA");
    QLabel *vUnitLabel = new QLabel("km/s");

    //label per aiutare l' utente

    QLabel *dHelpLabel = new QLabel;
    dHelpLabel->setToolTip("Densità media");
    dHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *tHelpLabel = new QLabel;
    tHelpLabel->setToolTip("Temperatura media superficiale");
    tHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));


    QLabel *eHelpLabel = new QLabel;
    eHelpLabel->setToolTip("Età dell' oggetto celeste in milioni di anni");
    eHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *vRHelpLabel = new QLabel;
    vRHelpLabel->setToolTip("Velocità di rotazione");
    vRHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *sAHelpLabel = new QLabel;
    sAHelpLabel->setToolTip("Semiasse maggiore dell'orbita, 1 UA = 150 milioni di km");
    sAHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *aHelpLabel = new QLabel;
    aHelpLabel->setToolTip("Azoto, ossigeno e argon (la somma deve essere <strong>100</strong>)");
    aHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *pHelpLabel = new QLabel;
    pHelpLabel->setToolTip("Pianeta attorno a cui orbita, usa l'indice corrispondente nel riquadro 'Pianeti'");
    pHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *sHelpLabel = new QLabel;
    sHelpLabel->setToolTip("Stella attorno a cui ruota, usa l'indice corrispondente nel riquadro 'Stelle'");
    sHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *vHelpLabel = new QLabel;
    vHelpLabel->setToolTip("Velocità a cui viaggia");
    vHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *mAssHelpLabel = new QLabel;
    mAssHelpLabel->setToolTip("Magnitudine assoluta, compresa tra -20 e 10");
    mAssHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    QLabel *mAppHelpLabel = new QLabel;
    mAppHelpLabel->setToolTip("Magniudine apparente, compresa tra -26.74 e 10");
    mAppHelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.png"));

    inputs->addWidget(rLabel,0,1);
    inputs->addWidget(raggio,1,1,1,1);
    inputs->addWidget(rUnitLabel,1,2,1,1);

    inputs->addWidget(tLabel,2,1);
    inputs->addWidget(tHelpLabel,2,0);
    inputs->addWidget(tempSuperficiale,3,1,1,1);
    inputs->addWidget(tUnitLabel,3,2,1,1);

    inputs->addWidget(dLabel,4,1);
    inputs->addWidget(dHelpLabel,4,0);
    inputs->addWidget(densita,5,1,1,1);
    inputs->addWidget(dUnitLabel,5,2);

    inputs->addWidget(eLabel,6,1);
    inputs->addWidget(eHelpLabel,6,0);
    inputs->addWidget(eta,7,1,1,1);

    inputs->addWidget(vRotLabel,0,4);
    inputs->addWidget(vRHelpLabel,0,3);
    inputs->addWidget(velRot,1,4,1,1);
    inputs->addWidget(vRotUnitLabel,1,5);

    inputs->addWidget(sAsseLabel,2,4);
    inputs->addWidget(sAHelpLabel,2,3);
    inputs->addWidget(semiAsse,3,4,1,1);
    inputs->addWidget(sAsseUnitLabel,3,5);

    inputs->addWidget(atmosfera,4,4,2,2);
    inputs->addWidget(aHelpLabel,4,3);

    inputs->addWidget(vLabel,6,4);
    inputs->addWidget(vHelpLabel,6,3);
    inputs->addWidget(velocita,7,4,1,1);
    inputs->addWidget(vUnitLabel,7,5);

    inputs->addWidget(sLabel,0,7);
    inputs->addWidget(sHelpLabel,0,6);
    inputs->addWidget(sole,1,7,1,1);

    inputs->addWidget(pLabel,2,7);
    inputs->addWidget(pHelpLabel,2,6);
    inputs->addWidget(pianeta,3,7,1,1);

    inputs->addWidget(magnAssLabel,4,7);
    inputs->addWidget(mAssHelpLabel,4,6);
    inputs->addWidget(mAss,5,7,1,1);

    inputs->addWidget(magnAppLabel,6,7);
    inputs->addWidget(mAppHelpLabel,6,6);
    inputs->addWidget(mApp,7,7,1,1);

    inputs->addWidget(crea,8,1,1,7);


    foreach(QLineEdit* le, this->findChildren<QLineEdit*>()) {
        le->setDisabled(true);
    }

}

void InputCreazione::cambiaInput(int selezione){

    QMessageBox creazImpossibile;
    QSpacerItem* horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layoutmsg = (QGridLayout*)creazImpossibile.layout();
    creazImpossibile.setWindowTitle("Attenzione");

    bool stop = false, stopS = false;

    if(selezione == 0){
        foreach(QLineEdit* le, this->findChildren<QLineEdit*>()) {
            le->setDisabled(true);
        }
     crea->setDisabled(true);
    }

    else{
        raggio->setDisabled(false);
        tempSuperficiale->setDisabled(false);
        densita->setDisabled(false);
        eta->setDisabled(false);
        crea->setDisabled(false);

        switch(selezione){
        case 1:
            velocita->setDisabled(false);

            velRot->setDisabled(true);
            semiAsse->setDisabled(true);
            azoto->setDisabled(true);
            ossigeno->setDisabled(true);
            argon->setDisabled(true);
            pianeta->setDisabled(true);
            sole->setDisabled(true);
            mAss->setDisabled(true);
            mApp->setDisabled(true);

            disconnect(crea,0,0,0);
            connect(crea,SIGNAL(clicked(bool)),
                    this,SIGNAL(cAsteroide()));
            break;
        case 2:
            velRot->setDisabled(false);
            mAss->setDisabled(false);
            mApp->setDisabled(false);

            semiAsse->setDisabled(true);
            azoto->setDisabled(true);
            ossigeno->setDisabled(true);
            argon->setDisabled(true);
            pianeta->setDisabled(true);
            sole->setDisabled(true);
            velocita->setDisabled(true);

            disconnect(crea,0,0,0);
            connect(crea,SIGNAL(clicked(bool)),
                    this,SIGNAL(cStella()));
            break;
        case 3:
            if(model->getSizeCreati(1) < 1){
                stop = true;
                creazImpossibile.setInformativeText("<p align='center'>Impossibile creare un pianeta senza prima aver creato una stella da associarci</p>");
                layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
                emit setScelta('s');
                break;
            }

            velRot->setDisabled(false);
            azoto->setDisabled(false);
            ossigeno->setDisabled(false);
            argon->setDisabled(false);
            sole->setDisabled(false);
            semiAsse->setDisabled(false);

            mAss->setDisabled(true);
            mApp->setDisabled(true);
            pianeta->setDisabled(true);

            disconnect(crea,0,0,0);
            connect(crea,SIGNAL(clicked(bool)),
                    this,SIGNAL(cPianeta()));
            break;
        case 4:
            if(model->getSizeCreati(2) < 1){
                stop = true;
                stopS = true;
                creazImpossibile.setInformativeText("<p align = 'center' >Impossibile creare un satellite senza prima aver creato un pianeta da associarci</p>");
                layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
                break;
            }

            velRot->setDisabled(false);
            semiAsse->setDisabled(false);
            pianeta->setDisabled(false);

            mAss->setDisabled(true);
            mApp->setDisabled(true);
            sole->setDisabled(true);
            velocita->setDisabled(true);
            azoto->setDisabled(true);
            ossigeno->setDisabled(true);
            argon->setDisabled(true);

            disconnect(crea,0,0,0);
            connect(crea,SIGNAL(clicked(bool)),
                    this,SIGNAL(cSatellite()));
            break;
            }
        }

    if(stop) {
        creazImpossibile.exec();
        if(stopS) emit setScelta('p');
    }
}

QString InputCreazione::getRaggio() const{
    return raggio->text();
}

QString InputCreazione::getTemp() const{
    return tempSuperficiale->text();
}

QString InputCreazione::getDens() const{
    return densita->text();
}

QString InputCreazione::getEta() const{
    return eta->text();
}

QString InputCreazione::getVrot() const{
    return velRot->text();
}

QString InputCreazione::getAsse() const{
    return semiAsse->text();
}

QString InputCreazione::getAz() const{
    return azoto->text();
}

QString InputCreazione::getOss() const{
    return ossigeno->text();
}

QString InputCreazione::getAr() const{
    return argon->text();
}

QString InputCreazione::getSole() const{
    return sole->text();
}

QString InputCreazione::getVel() const{
    return velocita->text();
}

QString InputCreazione::getPia() const{
    return pianeta->text();
}

QString InputCreazione::getMAss() const{
    return mAss->text();
}

QString InputCreazione::getMApp()const{
    return mApp->text();
}




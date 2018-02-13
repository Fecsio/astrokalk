#include "selezione.h"
#include "Model/dettagli.h"
#include <QGridLayout>
#include <QLabel>

Selezione::Selezione(Model* m, QWidget *parent): QGroupBox("Dettagli selezionato",parent), model(m){

    QGridLayout *layout = new QGridLayout;

    raggio = new QLineEdit;
    temp = new QLineEdit;
    dens = new QLineEdit;
    eta = new QLineEdit;
    velRot = new QLineEdit;
    asse = new QLineEdit;
    az = new QLineEdit;
    oss = new QLineEdit;
    alt = new QLineEdit;
    vel = new QLineEdit;
    sole = new QLineEdit;
    pianeta = new QLineEdit;
    mAss = new QLineEdit;
    mApp = new QLineEdit;

    QLabel *rLabel = new QLabel("Rag:");
    QLabel *tLabel = new QLabel("Tem:");
    QLabel *dLabel = new QLabel("Den:");
    QLabel *eLabel = new QLabel("Eta:");
    QLabel *vRotLabel = new QLabel("vRot:");
    QLabel *asseLabel = new QLabel("Asse:");
    QLabel *azLabel = new QLabel("Azo:");
    QLabel *ossLabel = new QLabel("Oss:");
    QLabel *arLabel = new QLabel("Alt:");
    QLabel *velLabel = new QLabel("Vel:");
    QLabel *sLabel = new QLabel("Sole:");
    QLabel *pLabel = new QLabel("Pian:");
    QLabel *mAssLabel = new QLabel("mAs:");
    QLabel *mAppLabel = new QLabel("mAp:");

    layout->addWidget(rLabel,0,0);
    layout->addWidget(tLabel,1,0);
    layout->addWidget(dLabel,2,0);
    layout->addWidget(eLabel,3,0);
    layout->addWidget(vRotLabel,4,0);
    layout->addWidget(sLabel,5,0);
    layout->addWidget(pLabel,6,0);
    layout->addWidget(asseLabel,0,2);
    layout->addWidget(azLabel,1,2);
    layout->addWidget(ossLabel,2,2);
    layout->addWidget(arLabel,3,2);
    layout->addWidget(velLabel,4,2);
    layout->addWidget(mAssLabel,5,2);
    layout->addWidget(mAppLabel,6,2);

    layout->addWidget(raggio,0,1);
    layout->addWidget(temp,1,1);
    layout->addWidget(dens,2,1);
    layout->addWidget(eta,3,1);
    layout->addWidget(velRot,4,1);
    layout->addWidget(sole,5,1);
    layout->addWidget(pianeta,6,1);
    layout->addWidget(asse,0,3);
    layout->addWidget(az,1,3);
    layout->addWidget(oss,2,3);
    layout->addWidget(alt,3,3);
    layout->addWidget(vel,4,3);
    layout->addWidget(mAss,5,3);
    layout->addWidget(mApp,6,3);

    this->setLayout(layout);

    foreach (QLineEdit* le, this->findChildren<QLineEdit*>()) {
        le->setStyleSheet("width: 1em;");
       le->setDisabled(true);
       le->setReadOnly(true);
    }
}

void Selezione::dettagliAst(QListWidgetItem * q){
    foreach (QLineEdit *le, this->findChildren<QLineEdit*>()) {
        le->clear();
        le->setDisabled(true);
    }

    int indice = q->text().toInt();

    Dettagli d(model, model->getAsteroide(indice));

    raggio->setDisabled(false);
    temp->setDisabled(false);
    dens->setDisabled(false);
    eta->setDisabled(false);
    vel->setDisabled(false);

    raggio->setText(QString::number(d.getRaggio()));
    temp->setText(QString::number(d.getTemp()));
    dens->setText(QString::number(d.getDens()));
    eta->setText(QString::number(d.getEta()));
    vel->setText(QString::number(d.getVel()));

}

void Selezione::dettagliSte(QListWidgetItem * q){
    foreach (QLineEdit *le, this->findChildren<QLineEdit*>()) {
        le->clear();
        le->setDisabled(true);
    }
    int indice = q->text().toInt();

    Dettagli d(model, model->getStella(indice));


    raggio->setDisabled(false);
    temp->setDisabled(false);
    dens->setDisabled(false);
    eta->setDisabled(false);
    velRot->setDisabled(false);
    mApp->setDisabled(false);
    mAss->setDisabled(false);

    raggio->setText(QString::number(d.getRaggio()));
    temp->setText(QString::number(d.getTemp()));
    dens->setText(QString::number(d.getDens()));
    eta->setText(QString::number(d.getEta()));
    velRot->setText(QString::number(d.getVelRot()));
    mAss->setText(QString::number(d.getMAss()));
    mApp->setText(QString::number(d.getMApp()));
}

void Selezione::dettagliPia(QListWidgetItem * q){
    foreach (QLineEdit *le, this->findChildren<QLineEdit*>()) {
        le->clear();
        le->setDisabled(true);
    }
    int indice = q->text().toInt();

    Dettagli d(model, model->getPianeta(indice));


    raggio->setDisabled(false);
    temp->setDisabled(false);
    dens->setDisabled(false);
    eta->setDisabled(false);
    velRot->setDisabled(false);
    az->setDisabled(false);
    oss->setDisabled(false);
    alt->setDisabled(false);
    sole->setDisabled(false);
    asse->setDisabled(false);

    raggio->setText(QString::number(d.getRaggio()));
    temp->setText(QString::number(d.getTemp()));
    dens->setText(QString::number(d.getDens()));
    eta->setText(QString::number(d.getEta()));
    velRot->setText(QString::number(d.getVelRot()));
    asse->setText(QString::number(d.getSemiA()));
    az->setText(QString::number(d.getAz()));
    oss->setText(QString::number(d.getOss()));
    alt->setText(QString::number(d.getAl()));
    sole->setText(QString::number(d.getSole()));
}

void Selezione::dettagliSat(QListWidgetItem * q){
    foreach (QLineEdit *le, this->findChildren<QLineEdit*>()) {
        le->clear();
        le->setDisabled(true);
    }
    int indice = q->text().toInt();

    Dettagli d(model, model->getSatellite(indice));

    raggio->setDisabled(false);
    temp->setDisabled(false);
    dens->setDisabled(false);
    eta->setDisabled(false);
    velRot->setDisabled(false);
    pianeta->setDisabled(false);
    asse->setDisabled(false);

    raggio->setText(QString::number(d.getRaggio()));
    temp->setText(QString::number(d.getTemp()));
    dens->setText(QString::number(d.getDens()));
    eta->setText(QString::number(d.getEta()));
    velRot->setText(QString::number(d.getVelRot()));
    asse->setText(QString::number(d.getSemiA()));
    pianeta->setText(QString::number(d.getPia()));

}



#ifndef INPUTCREAZIONE_H
#define INPUTCREAZIONE_H

#include <QWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QPushButton>
#include "Model/model.h"

class InputCreazione : public QWidget
{
    Q_OBJECT
private:

public:
    InputCreazione(Model* , QWidget *parent = nullptr);
    QString getRaggio() const;
    QString getTemp() const;
    QString getDens() const;
    QString getEta() const;
    QString getVrot() const;
    QString getAsse() const;
    QString getAz() const;
    QString getOss() const;
    QString getAr() const;
    QString getSole() const;
    QString getVel() const;
    QString getPia() const;
    QString getMAss() const;
    QString getMApp() const;
private:
    Model *model;

    QLineEdit *raggio;
    QLineEdit *tempSuperficiale;
    QLineEdit *densita;
    QLineEdit *eta;
    QLineEdit *velRot;
    QLineEdit *semiAsse;
    QGroupBox *atmosfera;
    QLineEdit *azoto;
    QLineEdit *ossigeno;
    QLineEdit *argon;
    QLineEdit *sole;
    QLineEdit *velocita;
    QLineEdit *pianeta;
    QLineEdit *mAss;
    QLineEdit *mApp;
    QPushButton *crea;
signals:
    void cAsteroide();
    void cStella();
    void cPianeta();
    void cSatellite();
    void setScelta(char );
public slots:
    void cambiaInput(int);
};

#endif // INPUTCREAZIONE_H

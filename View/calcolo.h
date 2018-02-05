#ifndef CALCOLO_H
#define CALCOLO_H

#include <QWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include "Model/model.h"
#include "Model/dettagli.h"
#include "pulsanteconinput.h"

class Calcolo : public QWidget
{
    Q_OBJECT

private:
    Model *model;
    QLineEdit *display;
    QComboBox *tipo1;
    QComboBox *tipo2;
    QLineEdit *primoOperando;
    QLineEdit *secondoOperando;
    QGroupBox *operazBin;
    QGroupBox *operazUn;

    QPushButton *somma;
    QPushButton *rapportaV;

    QPushButton *volume;
    QPushButton *superficie;
    QPushButton *massa;
    QPushButton *velFuga;
    PulsanteConInput *peso;
    QPushButton *collisione;
    QPushButton *giorno;
    QPushButton *distTerra;
    QPushButton *distSole;
    QPushButton *perOrb;
    QPushButton *isAbitabile;
    PulsanteConInput *etaET;
    QPushButton *velOrbitale;
    QPushButton *hasRotSincrona;
    QPushButton *rivol1Anno;

public:
    Calcolo(Model *,QWidget *parent = nullptr);

signals:
    void oggAggiunto();

public slots:
   void cambiaKeyboard1(int);
   void cambiaKeyboard2(int);
   /*void calcVol();
   void calcSup();
   void calcMass();
   void calcVelFuga();
   void calcPeso();
   void calcColl();
   void calcDistTerra();
   void calcDistSole();
   void calcAnno();
   void calcAbitabile();
   void calcEta();
   void calcRotSin();
   void calcRivolAnno();
   void calcGiorno();
   void calcVelOrb();
   void calcSomma();
   void calcRappV();*/
   void calcUn();
   void calcUnParam();
   void calcBin();
};

#endif // CALCOLO_H

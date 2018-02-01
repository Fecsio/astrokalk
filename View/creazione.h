#ifndef CREAZIONE_H
#define CREAZIONE_H

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include "inputcreazione.h"
#include "Model/model.h"

class Creazione : public QWidget
{
    Q_OBJECT
public:
   Creazione(Model*, QWidget *parent = nullptr);
signals:
   void oggAggiunto();
   void erroreI(QString);
public slots:
   void erroreInput(QString);
   void creaAsteroide();
   void creaStella();
   void creaPianeta();
   void creaSatellite();
   void settaScelta(char);
private:
    InputCreazione *input;
    Model *model;
    QComboBox *scelta;
};

#endif // CREAZIONE_H

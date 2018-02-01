#ifndef SELEZIONE_H
#define SELEZIONE_H
#include <QGroupBox>
#include <QLineEdit>
#include <QListWidget>
#include "Model/model.h"

class Selezione : public QGroupBox
{
    Q_OBJECT

public:
    Selezione(Model *, QWidget *parent = nullptr);
private:
    Model *model;
    QLineEdit *raggio;
    QLineEdit *temp;
    QLineEdit *dens;
    QLineEdit *eta;
    QLineEdit *velRot;
    QLineEdit *asse;
    QLineEdit *az;
    QLineEdit *oss;
    QLineEdit *arg;
    QLineEdit *vel;
    QLineEdit *sole;
    QLineEdit *pianeta;
    QLineEdit *mAss;
    QLineEdit *mApp;

signals:

public slots:
    void dettagliAst(QListWidgetItem*);
    void dettagliSte(QListWidgetItem*);
    void dettagliPia(QListWidgetItem*);
    void dettagliSat(QListWidgetItem*);


};

#endif // SELEZIONE_H

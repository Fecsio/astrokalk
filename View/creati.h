#ifndef CREATI_H
#define CREATI_H

#include <QGroupBox>
#include <QListWidget>
#include "Model/model.h"
#include "selezione.h"

class Creati : public QGroupBox
{
    Q_OBJECT
public:
    Creati(Model*, QGroupBox *parent = nullptr);
private:
    Model* model;
    QListWidget *listaAst;
    QListWidget *listaSte;
    QListWidget *listaPia;
    QListWidget *listaSat;
    Selezione *selezione;
signals:
public slots:
};

#endif // CREATI_H

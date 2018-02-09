#ifndef ASTROKALK_H
#define ASTROKALK_H

#include <QWidget>
#include "Model/model.h"
#include "creazione.h"
#include "disegno.h"
#include "calcolo.h"
#include "creati.h"

class Astrokalk : public QWidget
{
    Q_OBJECT
public:
    Astrokalk(QWidget * = nullptr);
    ~Astrokalk();
private:
    QGridLayout* layoutbase;
    Model* model;
    Creazione* creazione;
    Disegno* disegno;
    Calcolo* calcolo;
    Creati* creati;

signals:

public slots:
    void aggOgg();
};



#endif // ASTROKALK_H

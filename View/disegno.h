#ifndef DISEGNO_H
#define DISEGNO_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include "pulsanteconinput.h"
#include "Model/model.h"

class Disegno : public QWidget
{
    Q_OBJECT
public:
    Disegno(Model*, QWidget *parent = nullptr);
    void disegna(const QString&, double, int);

private:
    QGridLayout *layout;
    QGridLayout *layoutimg;
    PulsanteConInput *disegnaInScalaD;
    PulsanteConInput *disegnaInScalaE;
    Model *model;
    QWidget *centrale;
    QLabel *ordinati;
    QLabel *spiegaLabel;

signals:

public slots:
    void disegnaS();
};

#endif // DISEGNO_H

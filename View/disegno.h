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
    PulsanteConInput *disegnaInScalaD;
    PulsanteConInput *disegnaInScalaE;
    Model *model;
    QGridLayout *layout;
    QGridLayout *layoutimg;
    QWidget *centrale;
    QLabel *ordinati;
    QLabel *spiegaLabel;

signals:

public slots:
    void disegnaS();
};

#endif // DISEGNO_H

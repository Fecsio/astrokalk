#ifndef CALCOLO_H
#define CALCOLO_H

#include <QWidget>
#include <QLineEdit>
#include "Model/model.h"
#include "Model/dettagli.h"

class Calcolo : public QWidget
{
    Q_OBJECT

private:
    Model *model;
    QLineEdit *lineaOp1;
    QLineEdit *lineaOp2;


public:
    Calcolo(Model *,QWidget *parent = nullptr);

signals:

public slots:
};

#endif // CALCOLO_H

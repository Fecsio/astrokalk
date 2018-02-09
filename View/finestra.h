#ifndef FINESTRA_H
#define FINESTRA_H

#include <QMainWindow>
#include <QScrollArea>
#include "astrokalk.h"

class Finestra : public QMainWindow
{
    Q_OBJECT
public:
    explicit Finestra(QWidget *parent = nullptr);
    QSize getSizeKalk() const;

private:
    QScrollArea *sa;
    Astrokalk *a;
signals:

public slots:
};

#endif // FINESTRA_H

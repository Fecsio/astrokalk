#ifndef PULSANTECONINPUT_H
#define PULSANTECONINPUT_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class PulsanteConInput : public QPushButton
{
    Q_OBJECT
public:
    explicit PulsanteConInput(const QString&, const QString&, QWidget *parent = nullptr);
    QString getText() const;
    QString text() const;

private:
    QLineEdit *input;
    QLabel *titolo;
signals:

public slots:
};

#endif // PULSANTECONINPUT_H

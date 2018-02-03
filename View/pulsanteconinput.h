#ifndef PULSANTECONINPUT_H
#define PULSANTECONINPUT_H

#include <QPushButton>
#include <QLineEdit>

class PulsanteConInput : public QPushButton
{
    Q_OBJECT
public:
    explicit PulsanteConInput(const QString&, const QString&, QWidget *parent = nullptr);
    QString getText() const;

private:
    QLineEdit *input;
signals:

public slots:
};

#endif // PULSANTECONINPUT_H

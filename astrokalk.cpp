#include "astrokalk.h"
#include "ui_astrokalk.h"

astrokalk::astrokalk(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::astrokalk)
{
    ui->setupUi(this);
}

astrokalk::~astrokalk()
{
    delete ui;
}

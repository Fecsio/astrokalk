#include "disegno.h"
#include "Model/eccinput.h"
#include <QLabel>
#include <QImage>
#include <QScrollArea>
#include <QRegularExpression>
#include <QMessageBox>

Disegno::Disegno(Model* m, QWidget *parent) : QWidget(parent), model(m){
    layout = new QGridLayout(this);

    QLabel* top = new QLabel("Disegno");
    top->setStyleSheet("font-weight: bold;");

    QLabel *HelpLabel = new QLabel;
    HelpLabel->setToolTip("<p> A = asteroide, S = stella, P = pianeta, SA = satellite.</p> <p>Il numero si riferisce all' indice corrispondente in creati^.</p> <p>Seguire la sintassi del placeholder.</p>");
    HelpLabel->setPixmap(QPixmap(":/icone/View/Icone/help.svg"));

    disegnaInScalaD = new PulsanteConInput("Lettera - numero, es: 'A-0, S-3, SA-4.'", "Disegna in scala");
    disegnaInScalaE = new PulsanteConInput("Lettera - numero, es: 'A-0, S-3, SA-4.'", "Disegna in ordine di età");
    ordinati = new QLabel;
    ordinati->setMinimumWidth(this->width()/3);
    ordinati->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    QScrollArea *sa = new QScrollArea;
    sa->setStyleSheet("background-color: white; height: 1em;");
    sa->setWidget(ordinati);

    layout->addWidget(disegnaInScalaD,1,0);
    layout->addWidget(HelpLabel,1,1);
    layout->addWidget(disegnaInScalaE,1,2);

    centrale = new QWidget;
    layoutimg = new QGridLayout;

    layoutimg->setSpacing(0);
    layoutimg->setRowStretch(0,2);
    layoutimg->setRowStretch(1,1);

    centrale->setLayout(layoutimg);

    QScrollArea *scrollarea = new QScrollArea;
    scrollarea->setStyleSheet("background-color: white; ");
    scrollarea->setWidget(centrale);
    centrale->setMinimumHeight(400);
    scrollarea->setMinimumHeight(300);

    layout->addWidget(scrollarea,3,0,1,3);
    layout->addWidget(top,0,0);
    layout->addWidget(sa,2,0,1,2);
    spiegaLabel = new QLabel;
    spiegaLabel->setToolTip("<p>Indica gli indici degli oggetti disegnati ordinati secondo l'ordine richiesto.</p> <p>Se ad esempio 'indici in ordine: 0 1', allora il più piccolo (secondo il criterio di ordinamento) ha indice 0 ed ha tipo uguale al primo oggetto disegnato, 1 è l'indice del secondo piu piccolo e cosi via.</p>");
    spiegaLabel->setPixmap(QPixmap(":/icone/View/Icone/help.svg"));
    layout->addWidget(spiegaLabel, 2,2);
    spiegaLabel->setVisible(false);
    layout->setSpacing(0);

    connect(disegnaInScalaD,SIGNAL(clicked()),
            this, SLOT(disegnaS()));

    connect(disegnaInScalaE,SIGNAL(clicked()),
            this, SLOT(disegnaS()));
}

void Disegno::disegna(const QString& t, double r, int pos){
        QImage img;

        if(t == "Asteroide"){
            img.load(":/immagini/View/immagini/asteroide.png");
        }

        else if(t == "Stella"){
            img.load(":/immagini/View/immagini/stella.png");
        }

        else if(t == "Pianeta"){
            img.load(":/immagini/View/immagini/pianeta.png");
        }

        else if(t == "Satellite"){
            img.load(":/immagini/View/immagini/satellite.png");
        }

        if(r>100){
            r = 100;
        }
        img = img.scaled(r*5,r*5,Qt::AspectRatioMode::KeepAspectRatio, Qt::SmoothTransformation);
        QLabel *labelImg = new QLabel;
        labelImg->setPixmap(QPixmap::fromImage(img));
        centrale->resize(centrale->width()+r*5, centrale->height());
        if(r*10 > centrale->height()){
            centrale->resize(centrale->width(),r*5);
        }
        layoutimg->addWidget(labelImg,0,pos);

}



void Disegno::disegnaS(){
    QString tipo = qobject_cast<PulsanteConInput*>(sender())->text();
    QString s = qobject_cast<PulsanteConInput*>(sender())->getText();

    QMessageBox err;
    QGridLayout* layoutmsg = (QGridLayout*)err.layout();
    QSpacerItem* horizontalSpacer = new QSpacerItem(600, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    if(s.isEmpty()){
        err.setInformativeText("<p align='center'>Input vuoto </p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
    }

    else if(!((QRegularExpression("^([A|S|P|SA]{1}(\\-){1}[0-9]{1,3}[,|.]{1}){1,}$").match(s)).hasMatch())){
        err.setInformativeText("<p align = 'center'> L'input non ha il formato corretto </p>");
        layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
        err.exec();
    }

    else{
        try{
            vector<array<QString, 2>> aux = model->disegna(tipo, s);

            QLayoutItem *item;
                while((item = layoutimg->takeAt(0))) {
                    if (item->widget()) {
                        delete item->widget();
                    }
                    delete item;
                }
              centrale->resize(200,200);


            if(tipo == "Disegna in scala"){
                double min = (aux.front()[1]).toDouble();
                disegna(aux.front()[0],1,0);
                auto it = aux.begin();
                int pos = 1;
                for(++it; it!=aux.end(); ++it, ++pos){
                    disegna(it->at(0), (it->at(1).toDouble())/min, pos);
                }
            }

            else{
               auto it = aux.begin();
               int pos = 0;
               for(; it!=aux.end(); ++it, ++pos){
                    disegna(it->at(0), 5,pos);
               }
            }

            spiegaLabel->setVisible(true);
            ordinati->setMinimumWidth((model->getResult().size())*8);
            ordinati->setText(model->getResult());
        }
        catch(EccInput& ){
            err.setInformativeText("<p align='center'> Uno o più indici di oggetto non sono validi</p>");
            layoutmsg->addItem(horizontalSpacer,layoutmsg->rowCount(),0,1,layoutmsg->columnCount());
            err.exec();
        }
    }
}







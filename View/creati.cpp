#include "creati.h"
#include <QLabel>
#include <QGridLayout>

Creati::Creati(Model* m, QWidget *parent) : QGroupBox(parent), model(m){
        listaAst = new QListWidget();
        listaSte = new QListWidget();
        listaPia = new QListWidget();
        listaSat = new QListWidget();
        selezione = new Selezione(model);

        listaAst->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listaSte->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listaPia->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listaSat->setSelectionMode(QAbstractItemView::ExtendedSelection);

        QLabel* labelA = new QLabel(tr("Asteroidi"));
        QLabel* labelS = new QLabel(tr("Stelle"));
        QLabel* labelP = new QLabel(tr("Pianeti"));
        QLabel* labelSa = new QLabel(tr("Satelliti"));


        for(int i=0; i<(model->getSizeCreati(0)); ++i){
            listaAst->addItem(QString::number(i));
        }

        for(int i=0; i<(model->getSizeCreati(1)); ++i){
            listaSte->addItem(QString::number(i));
        }

        for(int i=0; i<(model->getSizeCreati(2)); ++i){
            listaPia->addItem(QString::number(i));
        }

        for(int i=0; i<(model->getSizeCreati(3)); ++i){
            listaSat->addItem(QString::number(i));
        }

        QGridLayout *layout = new QGridLayout(this);
        QGridLayout *layoutliste = new QGridLayout;

        layoutliste->addWidget(labelA,0,0);
        layoutliste->addWidget(labelS,0,1);
        layoutliste->addWidget(labelP,2,0);
        layoutliste->addWidget(labelSa,2,1);
        layoutliste->addWidget(listaAst,1,0);
        layoutliste->addWidget(listaSte,1,1);
        layoutliste->addWidget(listaPia,3,0);
        layoutliste->addWidget(listaSat,3,1);
        layout->addWidget(selezione,0,1);
        layout->addLayout(layoutliste,0,0);

        int w = this->size().width()/6;
        int h = this->size().height()/3.5;

        listaAst->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        listaAst->setMaximumSize(w,h);

        listaSte->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        listaSte->setMaximumSize(w,h);

        listaSat->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        listaSat->setMaximumSize(w,h);

        listaPia->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        listaPia->setMaximumSize(w,h);

        connect(listaAst, SIGNAL(itemClicked(QListWidgetItem*)),
                selezione, SLOT(dettagliAst(QListWidgetItem*)));

        connect(listaSte, SIGNAL(itemClicked(QListWidgetItem*)),
                selezione, SLOT(dettagliSte(QListWidgetItem*)));

        connect(listaPia, SIGNAL(itemClicked(QListWidgetItem*)),
                selezione, SLOT(dettagliPia(QListWidgetItem*)));

        connect(listaSat, SIGNAL(itemClicked(QListWidgetItem*)),
                selezione, SLOT(dettagliSat(QListWidgetItem*)));


}


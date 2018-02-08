#-------------------------------------------------
#
# Project created by QtCreator 2018-01-20T14:27:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = astrokalk
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Model/asteroide.cpp \
    Model/atmosfera.cpp \
    Model/conseguenzacollisione.cpp \
    Model/corpoceleste.cpp \
    Model/dataoraterrestre.cpp \
    Model/dataterrestre.cpp \
    Model/oggettoceleste.cpp \
    Model/orbitante.cpp \
    Model/pianeta.cpp \
    Model/satellite.cpp \
    Model/stella.cpp \
    View/astrokalk.cpp \
    Model/model.cpp \
    View/creazione.cpp \
    View/disegno.cpp \
    View/calcolo.cpp \
    View/inputcreazione.cpp \
    View/creati.cpp \
    View/selezione.cpp \
    Model/dettagli.cpp \
    View/pulsanteconinput.cpp \
    Model/eccinput.cpp

HEADERS += \
    Model/asteroide.h \
    Model/atmosfera.h \
    Model/conseguenzacollisione.h \
    Model/corpoceleste.h \
    Model/dataoraterrestre.h \
    Model/dataterrestre.h \
    Model/oggettoceleste.h \
    Model/orbitante.h \
    Model/pianeta.h \
    Model/satellite.h \
    Model/stella.h \
    View/astrokalk.h \
    Model/model.h \
    View/creazione.h \
    View/disegno.h \
    View/calcolo.h \
    View/inputcreazione.h \
    View/creati.h \
    View/selezione.h \
    Model/dettagli.h \
    View/pulsanteconinput.h \
    Model/eccinput.h

FORMS +=

CONFIG += c++11

DISTFILES += \
    View/style.qss

RESOURCES += \
    risorse.qrc


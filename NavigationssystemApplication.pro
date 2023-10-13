QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adresse.cpp \
    anzeigen.cpp \
    graph.cpp \
    information.cpp \
    main.cpp \
    navigationssystem.cpp \
    ort.cpp \
    poi.cpp \
    qdynamicbutton.cpp \
    route.cpp \
    showroute.cpp \
    test.cpp

HEADERS += \
    ImagePixel.h \
    adresse.h \
    anzeigen.h \
    graph.h \
    information.h \
    navigationssystem.h \
    ort.h \
    poi.h \
    qdynamicbutton.h \
    route.h \
    showroute.h \
    test.h

FORMS += \
    anzeigen.ui \
    information.ui \
    navigationssystem.ui \
    showroute.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

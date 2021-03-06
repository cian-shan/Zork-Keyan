QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Character.cpp \
    Food.cpp \
    Gameplay.cpp \
    Item.cpp \
    Room.cpp \
    Zork.cpp \
    main.cpp

HEADERS += \
    Character.h \
    Food.h \
    Gameplay.h \
    Item.h \
    Room.h \
    Zork.h

FORMS += \
    zork.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ZorkCopy5.pro

RESOURCES += \
    resources.qrc

DISTFILES += \
    Zork-Keyan-GUI.pro.user \
    ZorkCopy5.pro.user

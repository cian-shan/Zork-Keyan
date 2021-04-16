TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Character.cpp \
    Command.cpp \
    CommandWords.cpp \
    Parser.cpp \
    Room.cpp \
    ZorkUL.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

DISTFILES += \
    ZorkProject-Key-An.pro.user

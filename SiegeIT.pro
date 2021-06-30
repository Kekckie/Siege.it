TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        block.cpp \
        blockmenu.cpp \
        game.cpp \
        machine.cpp \
        machinechangemenu.cpp \
        machineupgrademenu.cpp \
        main.cpp \
        projectiles.cpp \
        tower.cpp \
        towerupgrademenu.cpp

INCLUDEPATH += "G:/SFML/include"
DEPENDPATH += "G:/SFML/include"

LIBS += -L"G:/SFML/lib" -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

HEADERS += \
    block.h \
    blockmenu.h \
    game.h \
    machine.h \
    machinechangemenu.h \
    machineupgrademenu.h \
    projectiles.h \
    tower.h \
    towerupgrademenu.h

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        block.cpp \
        game.cpp \
        main.cpp \
        tower.cpp

INCLUDEPATH += "G:/SFML/include"
DEPENDPATH += "G:/SFML/include"

LIBS += -L"G:/SFML/lib" -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

HEADERS += \
    block.h \
    game.h \
    tower.h

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


LIBS += -LC:/SFML-2.4.2/lib

CONFIG(release, debug|release): LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lOpengl32 -lglut
CONFIG(debug, debug|release): LIBS += -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lOpengl32 -lglut

SOURCES += main.cpp

INCLUDEPATH += C:/SFML-2.4.2/include
DEPENDPATH += C:/SFML-2.4.2/include

DISTFILES += \
    Images/arial.ttf \
    Images/arialbd.ttf \
    Images/arialbi.ttf \
    Images/ariali.ttf \
    Images/ARIALN.TTF \
    Images/ARIALNB.TTF \
    Images/ARIALNBI.TTF \
    Images/ARIALNI.TTF \
    Images/ariblk.ttf \
    Images/1001.png \
    Images/1002.png \
    Images/1003.png \
    Images/1004.png \
    Images/1005.png

HEADERS += \
    head.h \
    menu.h

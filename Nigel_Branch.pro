QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BuildEngineerIcon.cpp \
    BuildFRECIcon.cpp \
    BuildFroshIcon.cpp \
    Bullet.cpp \
    Button.cpp \
    Character.cpp \
    Drink.cpp \
    Engineer.cpp \
    FREC.cpp \
    Frosh.cpp \
    Game.cpp \
    Screens.cpp \
    beer.cpp \
    buildBackground.cpp \
    buildpausebutton.cpp \
    keg.cpp \
    main.cpp \
    mainwindow.cpp \
    shot.cpp

HEADERS += \
    BuildEngineerIcon.h \
    BuildFRECIcon.h \
    BuildFroshIcon.h \
    Bullet.h \
    Button.h \
    Character.h \
    Drink.h \
    Engineer.h \
    FREC.h \
    Frosh.h \
    Game.h \
    Screens.h \
    beer.h \
    buildBackground.h \
    buildpausebutton.h \
    enums.h \
    keg.h \
    mainwindow.h \
    shot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Test1.pro \
    Test1.pro \
    Test1.pro

RESOURCES += \
    Resources.qrc \
    Resources.qrc \
    Resources.qrc

DISTFILES += \
    .gitignore \
    NIGEL.txt \
    Nigel_Branch.pro.user \
    Test1.pro.user \
    Test1.pro.user.d0073b6 \
    Test1.pro.user.eac9d33 \
    nigeltest.txt \
    supertest.txt \
    testtest.txt

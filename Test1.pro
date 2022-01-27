QT -= gui
QT += widgets

CONFIG += c++11 console
CONFIG -= app_bundle

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
        coins.cpp \
        keg.cpp \
        legend.cpp \
        main.cpp \
        mainwindow.cpp \
        shop.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
    coins.h \
    keg.h \
    legend.h \
    mainwindow.h \
    shop.h \
    shot.h

DISTFILES += \
    images/BrownTowerBullet.png \
    images/Enemy.png \
    images/Engineer.png \
    images/FREC.png \
    images/Frosh.png \
    images/engineerDrink.png \
    images/frecDrink.png \
    images/froshDrink.png \
    images/Shot Empty.png \
    images/Shot Empty.png \
    images/Shot Empty.png \
    images/Shot Full.png \
    images/Shot Full.png \
    images/Shot Full.png \
    images/engineerIcon.png \
    images/frecIcon.png \
    images/froshIcon.png \
    images/logo.png \
    images/background.png \
    images/blank.png \
    images/keg.png \
    images/logo.png \
    images/shot.png \
    images/PauseButton.png \
    images/goodPauseButton.png \

RESOURCES += \
    Resources.qrc

FORMS += \
    mainwindow.ui

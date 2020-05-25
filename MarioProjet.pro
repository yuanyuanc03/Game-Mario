QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/gamecontroller.cpp \
    Model/background.cpp \
    Model/blood.cpp \
    Model/brick.cpp \
    Model/darkeater.cpp \
    Model/flame.cpp \
    Model/floor.cpp \
    Model/gold.cpp \
    Model/label.cpp \
    Model/mario.cpp \
    Model/model.cpp \
    Model/modellist.cpp \
    Model/mushroom.cpp \
    Model/paint.cpp \
    Model/player.cpp \
    Model/princess.cpp \
    Model/score.cpp \
    Model/shock.cpp \
    Model/splashscreen.cpp \
    Model/time.cpp \
    Model/tree.cpp \
    View/view.cpp \
    main.cpp

HEADERS += \
    Controller/gamecontroller.h \
    Model/background.h \
    Model/blood.h \
    Model/brick.h \
    Model/darkeater.h \
    Model/flame.h \
    Model/floor.h \
    Model/gold.h \
    Model/label.h \
    Model/mario.h \
    Model/model.h \
    Model/modellist.h \
    Model/mushroom.h \
    Model/paint.h \
    Model/player.h \
    Model/princess.h \
    Model/score.h \
    Model/shock.h \
    Model/splashscreen.h \
    Model/time.h \
    Model/tree.h \
    View/view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    files/sounds/background.mp3 \
    files/sounds/blockbreak.wav \
    files/sounds/blockhit.wav \
    files/sounds/boom.wav \
    files/sounds/bowserfall.wav \
    files/sounds/bridgebreak.wav \
    files/sounds/bulletbill.wav \
    files/sounds/castle-fast.wav \
    files/sounds/castle.wav \
    files/sounds/castleend.wav \
    files/sounds/coin.wav \
    files/sounds/death.wav \
    files/sounds/fire.wav \
    files/sounds/fireball.wav \
    files/sounds/gameover.wav \
    files/sounds/intermission.wav \
    files/sounds/jump.wav \
    files/sounds/jumpbig.wav \
    files/sounds/levelend.wav \
    files/sounds/lowtime.wav \
    files/sounds/mushroomappear.wav \
    files/sounds/mushroomeat.wav \
    files/sounds/oneup.wav \
    files/sounds/overworld-fast.wav \
    files/sounds/overworld.wav \
    files/sounds/pause.wav \
    files/sounds/pipe.wav \
    files/sounds/princessmusic.wav \
    files/sounds/rainboom.wav \
    files/sounds/scorering.wav \
    files/sounds/shot.wav \
    files/sounds/shrink.wav \
    files/sounds/starmusic-fast.wav \
    files/sounds/starmusic.wav \
    files/sounds/stomp.wav \
    files/sounds/swim.wav \
    files/sounds/underground-fast.wav \
    files/sounds/underground.wav \
    files/sounds/underwater-fast.wav \
    files/sounds/underwater.wav \
    files/sounds/vine.wav \
    files/ModelMap.txt

RESOURCES += \
    res.qrc

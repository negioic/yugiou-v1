QT       += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BattlePhase.cpp \
    CardInfo.cpp \
    DrawPhase.cpp \
    EndPhase.cpp \
    EnemyBattlePhase.cpp \
    EnemyDrawPhase.cpp \
    EnemyEndPhase.cpp \
    EnemyMainPhase.cpp \
    EnemyStandbyPhase.cpp \
    GameStart.cpp \
    MainPhase.cpp \
    StandbyPhase.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BasePhase.h \
    BattlePhase.h \
    CardInfo.h \
    DrawPhase.h \
    EndPhase.h \
    EnemyBattlePhase.h \
    EnemyDrawPhase.h \
    EnemyEndPhase.h \
    EnemyMainPhase.h \
    EnemyStandbyPhase.h \
    GameStart.h \
    MainPhase.h \
    StandbyPhase.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

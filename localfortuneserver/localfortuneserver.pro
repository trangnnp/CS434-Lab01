HEADERS       = \
    mainwindow.h \
    msglist.h \
    msgmodel.h \
    pack.h \
    packbank.h \
    packnew.h \
    player.h \
    playerlist.h \
    playermodel.h \
    room.h \
    singletondata.h
SOURCES       = \
                main.cpp \
                mainwindow.cpp \
                msglist.cpp \
                msgmodel.cpp \
                pack.cpp \
                packbank.cpp \
                packnew.cpp \
                player.cpp \
                playerlist.cpp \
                playermodel.cpp \
                room.cpp \
                singletondata.cpp
QT += network widgets
QT += quick qml
QT += qml quick core quickcontrols2
#LIBS += -framework IOK it

# install
target.path = $$[QT_INSTALL_EXAMPLES]/corelib/ipc/localfortuneserver
INSTALLS += target

FORMS += \
    mainwindow.ui

RESOURCES += \
    qml.qrc

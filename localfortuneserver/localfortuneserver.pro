HEADERS       = \
    mainwindow.h \
    pack.h \
    packbank.h \
    packnew.h \
    player.h \
    room.h
SOURCES       = \
                main.cpp \
                mainwindow.cpp \
                pack.cpp \
                packbank.cpp \
                packnew.cpp \
                player.cpp \
                room.cpp
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

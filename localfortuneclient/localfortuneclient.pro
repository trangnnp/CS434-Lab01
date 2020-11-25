HEADERS       = client.h \
    mainwindow.h \
    pack.h \
    playerlist.h \
    playermodel.h
SOURCES       = client.cpp \
                main.cpp \
                mainwindow.cpp \
                pack.cpp \
                playerlist.cpp \
                playermodel.cpp

FORMS += \
    mainwindow.ui \
    mainwindow.ui

QT           += network widgets
QT += quick qml
QT += qml quick core quickcontrols2

# install
target.path = $$[QT_INSTALL_EXAMPLES]/corelib/ipc/localfortuneclient
INSTALLS += target

RESOURCES += \
    qml.qrc

DISTFILES +=

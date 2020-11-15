HEADERS       = client.h \
    mainwindow.h \
    pack.h
SOURCES       = client.cpp \
                main.cpp \
                mainwindow.cpp \
                pack.cpp

FORMS += \
    mainwindow.ui \
    mainwindow.ui

QT           += network widgets

# install
target.path = $$[QT_INSTALL_EXAMPLES]/corelib/ipc/localfortuneclient
INSTALLS += target

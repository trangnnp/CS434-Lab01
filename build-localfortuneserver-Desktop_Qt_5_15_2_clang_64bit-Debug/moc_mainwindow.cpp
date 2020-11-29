/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../localfortuneserver/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "resultUpdated"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "playerInfoUpdated"
QT_MOC_LITERAL(4, 44, 8), // "initRoom"
QT_MOC_LITERAL(5, 53, 16), // "onCurPackChanged"
QT_MOC_LITERAL(6, 70, 15), // "onNewConnection"
QT_MOC_LITERAL(7, 86, 20), // "onSocketStateChanged"
QT_MOC_LITERAL(8, 107, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(9, 136, 11), // "socketState"
QT_MOC_LITERAL(10, 148, 11), // "onReadyRead"
QT_MOC_LITERAL(11, 160, 8), // "sendData"
QT_MOC_LITERAL(12, 169, 10), // "updatePack"
QT_MOC_LITERAL(13, 180, 10), // "createRoom"
QT_MOC_LITERAL(14, 191, 5), // "packq"
QT_MOC_LITERAL(15, 197, 5), // "packa"
QT_MOC_LITERAL(16, 203, 5), // "packb"
QT_MOC_LITERAL(17, 209, 5), // "packc"
QT_MOC_LITERAL(18, 215, 5), // "packd"
QT_MOC_LITERAL(19, 221, 7) // "correct"

    },
    "MainWindow\0resultUpdated\0\0playerInfoUpdated\0"
    "initRoom\0onCurPackChanged\0onNewConnection\0"
    "onSocketStateChanged\0QAbstractSocket::SocketState\0"
    "socketState\0onReadyRead\0sendData\0"
    "updatePack\0createRoom\0packq\0packa\0"
    "packb\0packc\0packd\0correct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       6,   76, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   68,    2, 0x0a /* Public */,
       7,    1,   69,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      13,    0,   75,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00495003,
      15, QMetaType::QString, 0x00495003,
      16, QMetaType::QString, 0x00495003,
      17, QMetaType::QString, 0x00495003,
      18, QMetaType::QString, 0x00495003,
      19, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       3,
       3,
       3,
       3,
       3,
       3,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultUpdated(); break;
        case 1: _t->playerInfoUpdated(); break;
        case 2: _t->initRoom(); break;
        case 3: _t->onCurPackChanged(); break;
        case 4: _t->onNewConnection(); break;
        case 5: _t->onSocketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 6: _t->onReadyRead(); break;
        case 7: _t->sendData(); break;
        case 8: _t->updatePack(); break;
        case 9: _t->createRoom(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::resultUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::playerInfoUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initRoom)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::onCurPackChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->packq; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->packa; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->packb; break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->packc; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->packd; break;
        case 5: *reinterpret_cast< int*>(_v) = _t->correct; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->packq != *reinterpret_cast< QString*>(_v)) {
                _t->packq = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        case 1:
            if (_t->packa != *reinterpret_cast< QString*>(_v)) {
                _t->packa = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        case 2:
            if (_t->packb != *reinterpret_cast< QString*>(_v)) {
                _t->packb = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        case 3:
            if (_t->packc != *reinterpret_cast< QString*>(_v)) {
                _t->packc = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        case 4:
            if (_t->packd != *reinterpret_cast< QString*>(_v)) {
                _t->packd = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        case 5:
            if (_t->correct != *reinterpret_cast< int*>(_v)) {
                _t->correct = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->onCurPackChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainWindow::resultUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::playerInfoUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::initRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::onCurPackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

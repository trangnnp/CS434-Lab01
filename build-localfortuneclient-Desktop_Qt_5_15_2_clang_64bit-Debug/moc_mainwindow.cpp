/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../localfortuneclient/mainwindow.h"
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
    QByteArrayData data[32];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "curPackChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "resultUpdated"
QT_MOC_LITERAL(4, 41, 17), // "playerInfoUpdated"
QT_MOC_LITERAL(5, 59, 8), // "initRoom"
QT_MOC_LITERAL(6, 68, 16), // "packTimerTrigged"
QT_MOC_LITERAL(7, 85, 11), // "onReadyRead"
QT_MOC_LITERAL(8, 97, 12), // "printMessage"
QT_MOC_LITERAL(9, 110, 3), // "txt"
QT_MOC_LITERAL(10, 114, 8), // "createMe"
QT_MOC_LITERAL(11, 123, 4), // "name"
QT_MOC_LITERAL(12, 128, 10), // "sendAnswer"
QT_MOC_LITERAL(13, 139, 6), // "answer"
QT_MOC_LITERAL(14, 146, 12), // "skipThisTurn"
QT_MOC_LITERAL(15, 159, 5), // "packq"
QT_MOC_LITERAL(16, 165, 5), // "packa"
QT_MOC_LITERAL(17, 171, 5), // "packb"
QT_MOC_LITERAL(18, 177, 5), // "packc"
QT_MOC_LITERAL(19, 183, 5), // "packd"
QT_MOC_LITERAL(20, 189, 7), // "aResult"
QT_MOC_LITERAL(21, 197, 7), // "bResult"
QT_MOC_LITERAL(22, 205, 7), // "cResult"
QT_MOC_LITERAL(23, 213, 7), // "dResult"
QT_MOC_LITERAL(24, 221, 5), // "kotae"
QT_MOC_LITERAL(25, 227, 7), // "skipped"
QT_MOC_LITERAL(26, 235, 12), // "playerStatus"
QT_MOC_LITERAL(27, 248, 13), // "totalQuestion"
QT_MOC_LITERAL(28, 262, 11), // "totalPlayer"
QT_MOC_LITERAL(29, 274, 8), // "roomName"
QT_MOC_LITERAL(30, 283, 11), // "timeLimited"
QT_MOC_LITERAL(31, 295, 14) // "packTimerValue"

    },
    "MainWindow\0curPackChanged\0\0resultUpdated\0"
    "playerInfoUpdated\0initRoom\0packTimerTrigged\0"
    "onReadyRead\0printMessage\0txt\0createMe\0"
    "name\0sendAnswer\0answer\0skipThisTurn\0"
    "packq\0packa\0packb\0packc\0packd\0aResult\0"
    "bResult\0cResult\0dResult\0kotae\0skipped\0"
    "playerStatus\0totalQuestion\0totalPlayer\0"
    "roomName\0timeLimited\0packTimerValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
      17,   80, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    1,   70,    2, 0x02 /* Public */,
      10,    1,   73,    2, 0x02 /* Public */,
      12,    1,   76,    2, 0x02 /* Public */,
      14,    0,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::QString, 0x00495001,
      18, QMetaType::QString, 0x00495001,
      19, QMetaType::QString, 0x00495001,
      20, QMetaType::Int, 0x00495003,
      21, QMetaType::Int, 0x00495003,
      22, QMetaType::Int, 0x00495003,
      23, QMetaType::Int, 0x00495003,
      24, QMetaType::Int, 0x00495003,
      25, QMetaType::Int, 0x00495003,
      26, QMetaType::Int, 0x00495003,
      27, QMetaType::Int, 0x00495003,
      28, QMetaType::Int, 0x00495003,
      29, QMetaType::QString, 0x00495003,
      30, QMetaType::Int, 0x00495003,
      31, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       1,
       1,
       1,
       1,
       1,
       2,
       2,
       3,
       3,
       3,
       3,
       4,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curPackChanged(); break;
        case 1: _t->resultUpdated(); break;
        case 2: _t->playerInfoUpdated(); break;
        case 3: _t->initRoom(); break;
        case 4: _t->packTimerTrigged(); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->printMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->createMe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sendAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->skipThisTurn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::curPackChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::resultUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::playerInfoUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::initRoom)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::packTimerTrigged)) {
                *result = 4;
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
        case 0: *reinterpret_cast< QString*>(_v) = _t->getQ(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getA(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getB(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getC(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getD(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->aResult; break;
        case 6: *reinterpret_cast< int*>(_v) = _t->bResult; break;
        case 7: *reinterpret_cast< int*>(_v) = _t->cResult; break;
        case 8: *reinterpret_cast< int*>(_v) = _t->dResult; break;
        case 9: *reinterpret_cast< int*>(_v) = _t->kotae; break;
        case 10: *reinterpret_cast< int*>(_v) = _t->skipped; break;
        case 11: *reinterpret_cast< int*>(_v) = _t->playerStatus; break;
        case 12: *reinterpret_cast< int*>(_v) = _t->totalQuestion; break;
        case 13: *reinterpret_cast< int*>(_v) = _t->totalPlayer; break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->roomName; break;
        case 15: *reinterpret_cast< int*>(_v) = _t->timeLimited; break;
        case 16: *reinterpret_cast< int*>(_v) = _t->packTimerValue; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 5:
            if (_t->aResult != *reinterpret_cast< int*>(_v)) {
                _t->aResult = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->resultUpdated();
            }
            break;
        case 6:
            if (_t->bResult != *reinterpret_cast< int*>(_v)) {
                _t->bResult = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->resultUpdated();
            }
            break;
        case 7:
            if (_t->cResult != *reinterpret_cast< int*>(_v)) {
                _t->cResult = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->resultUpdated();
            }
            break;
        case 8:
            if (_t->dResult != *reinterpret_cast< int*>(_v)) {
                _t->dResult = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->resultUpdated();
            }
            break;
        case 9:
            if (_t->kotae != *reinterpret_cast< int*>(_v)) {
                _t->kotae = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->resultUpdated();
            }
            break;
        case 10:
            if (_t->skipped != *reinterpret_cast< int*>(_v)) {
                _t->skipped = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->playerInfoUpdated();
            }
            break;
        case 11:
            if (_t->playerStatus != *reinterpret_cast< int*>(_v)) {
                _t->playerStatus = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->playerInfoUpdated();
            }
            break;
        case 12:
            if (_t->totalQuestion != *reinterpret_cast< int*>(_v)) {
                _t->totalQuestion = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->initRoom();
            }
            break;
        case 13:
            if (_t->totalPlayer != *reinterpret_cast< int*>(_v)) {
                _t->totalPlayer = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->initRoom();
            }
            break;
        case 14:
            if (_t->roomName != *reinterpret_cast< QString*>(_v)) {
                _t->roomName = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->initRoom();
            }
            break;
        case 15:
            if (_t->timeLimited != *reinterpret_cast< int*>(_v)) {
                _t->timeLimited = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->initRoom();
            }
            break;
        case 16:
            if (_t->packTimerValue != *reinterpret_cast< int*>(_v)) {
                _t->packTimerValue = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->packTimerTrigged();
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MainWindow::curPackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::resultUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::playerInfoUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::initRoom()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::packTimerTrigged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

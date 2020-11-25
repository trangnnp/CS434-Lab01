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
    QByteArrayData data[21];
    char stringdata0[186];
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
QT_MOC_LITERAL(4, 41, 11), // "onReadyRead"
QT_MOC_LITERAL(5, 53, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 75, 12), // "printMessage"
QT_MOC_LITERAL(7, 88, 3), // "txt"
QT_MOC_LITERAL(8, 92, 8), // "createMe"
QT_MOC_LITERAL(9, 101, 4), // "name"
QT_MOC_LITERAL(10, 106, 10), // "sendAnswer"
QT_MOC_LITERAL(11, 117, 6), // "answer"
QT_MOC_LITERAL(12, 124, 5), // "packq"
QT_MOC_LITERAL(13, 130, 5), // "packa"
QT_MOC_LITERAL(14, 136, 5), // "packb"
QT_MOC_LITERAL(15, 142, 5), // "packc"
QT_MOC_LITERAL(16, 148, 5), // "packd"
QT_MOC_LITERAL(17, 154, 7), // "aResult"
QT_MOC_LITERAL(18, 162, 7), // "bResult"
QT_MOC_LITERAL(19, 170, 7), // "cResult"
QT_MOC_LITERAL(20, 178, 7) // "dResult"

    },
    "MainWindow\0curPackChanged\0\0resultUpdated\0"
    "onReadyRead\0on_pushButton_clicked\0"
    "printMessage\0txt\0createMe\0name\0"
    "sendAnswer\0answer\0packq\0packa\0packb\0"
    "packc\0packd\0aResult\0bResult\0cResult\0"
    "dResult"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       9,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   53,    2, 0x02 /* Public */,
       8,    1,   56,    2, 0x02 /* Public */,
      10,    1,   59,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,
      14, QMetaType::QString, 0x00495001,
      15, QMetaType::QString, 0x00495001,
      16, QMetaType::QString, 0x00495001,
      17, QMetaType::Int, 0x00495003,
      18, QMetaType::Int, 0x00495003,
      19, QMetaType::Int, 0x00495003,
      20, QMetaType::Int, 0x00495003,

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
        case 2: _t->onReadyRead(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->printMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->createMe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

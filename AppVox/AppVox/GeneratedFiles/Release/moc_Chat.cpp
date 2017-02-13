/****************************************************************************
** Meta object code from reading C++ file 'Chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_setUsername_t {
    QByteArrayData data[3];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setUsername_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setUsername_t qt_meta_stringdata_setUsername = {
    {
QT_MOC_LITERAL(0, 0, 11), // "setUsername"
QT_MOC_LITERAL(1, 12, 8), // "username"
QT_MOC_LITERAL(2, 21, 0) // ""

    },
    "setUsername\0username\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setUsername[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void setUsername::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setUsername *_t = static_cast<setUsername *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->username(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject setUsername::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_setUsername.data,
      qt_meta_data_setUsername,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *setUsername::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setUsername::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_setUsername.stringdata0))
        return static_cast<void*>(const_cast< setUsername*>(this));
    return QDialog::qt_metacast(_clname);
}

int setUsername::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_Chat_t {
    QByteArrayData data[13];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 10), // "newMessage"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "message"
QT_MOC_LITERAL(4, 25, 7), // "newUser"
QT_MOC_LITERAL(5, 33, 4), // "user"
QT_MOC_LITERAL(6, 38, 16), // "userDisconnected"
QT_MOC_LITERAL(7, 55, 11), // "clientIndex"
QT_MOC_LITERAL(8, 67, 6), // "Submit"
QT_MOC_LITERAL(9, 74, 10), // "AppendText"
QT_MOC_LITERAL(10, 85, 10), // "AppendUser"
QT_MOC_LITERAL(11, 96, 8), // "userName"
QT_MOC_LITERAL(12, 105, 16) // "DisconnectClient"

    },
    "Chat\0newMessage\0\0message\0newUser\0user\0"
    "userDisconnected\0clientIndex\0Submit\0"
    "AppendText\0AppendUser\0userName\0"
    "DisconnectClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   58,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chat *_t = static_cast<Chat *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->newUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->userDisconnected((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->Submit(); break;
        case 4: _t->AppendText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->AppendUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->DisconnectClient((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Chat::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chat::newMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Chat::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chat::newUser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Chat::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Chat::userDisconnected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Chat::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Chat.data,
      qt_meta_data_Chat,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(const_cast< Chat*>(this));
    if (!strcmp(_clname, "Essentials"))
        return static_cast< Essentials*>(const_cast< Chat*>(this));
    return QDialog::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void Chat::newMessage(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Chat::newUser(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Chat::userDisconnected(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

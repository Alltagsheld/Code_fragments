/****************************************************************************
** Meta object code from reading C++ file 'hanoitowers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Aufgabe5/Hanoi/hanoitowers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hanoitowers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_hanoiTowers_t {
    QByteArrayData data[16];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hanoiTowers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hanoiTowers_t qt_meta_stringdata_hanoiTowers = {
    {
QT_MOC_LITERAL(0, 0, 11), // "hanoiTowers"
QT_MOC_LITERAL(1, 12, 9), // "setupDisc"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "moveDisc"
QT_MOC_LITERAL(4, 32, 6), // "Tower&"
QT_MOC_LITERAL(5, 39, 2), // "Ts"
QT_MOC_LITERAL(6, 42, 2), // "Tg"
QT_MOC_LITERAL(7, 45, 16), // "rulesNotViolated"
QT_MOC_LITERAL(8, 62, 15), // "on_T1T2_clicked"
QT_MOC_LITERAL(9, 78, 15), // "on_T1T3_clicked"
QT_MOC_LITERAL(10, 94, 21), // "on_restartBtn_clicked"
QT_MOC_LITERAL(11, 116, 18), // "on_exitBtn_clicked"
QT_MOC_LITERAL(12, 135, 15), // "on_T2T3_clicked"
QT_MOC_LITERAL(13, 151, 15), // "on_T2T1_clicked"
QT_MOC_LITERAL(14, 167, 15), // "on_T3T1_clicked"
QT_MOC_LITERAL(15, 183, 15) // "on_T3T2_clicked"

    },
    "hanoiTowers\0setupDisc\0\0moveDisc\0Tower&\0"
    "Ts\0Tg\0rulesNotViolated\0on_T1T2_clicked\0"
    "on_T1T3_clicked\0on_restartBtn_clicked\0"
    "on_exitBtn_clicked\0on_T2T3_clicked\0"
    "on_T2T1_clicked\0on_T3T1_clicked\0"
    "on_T3T2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hanoiTowers[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    2,   70,    2, 0x08 /* Private */,
       7,    2,   75,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Bool, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void hanoiTowers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hanoiTowers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setupDisc(); break;
        case 1: _t->moveDisc((*reinterpret_cast< Tower(*)>(_a[1])),(*reinterpret_cast< Tower(*)>(_a[2]))); break;
        case 2: { bool _r = _t->rulesNotViolated((*reinterpret_cast< Tower(*)>(_a[1])),(*reinterpret_cast< Tower(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->on_T1T2_clicked(); break;
        case 4: _t->on_T1T3_clicked(); break;
        case 5: _t->on_restartBtn_clicked(); break;
        case 6: _t->on_exitBtn_clicked(); break;
        case 7: _t->on_T2T3_clicked(); break;
        case 8: _t->on_T2T1_clicked(); break;
        case 9: _t->on_T3T1_clicked(); break;
        case 10: _t->on_T3T2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hanoiTowers::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_hanoiTowers.data,
    qt_meta_data_hanoiTowers,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hanoiTowers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hanoiTowers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hanoiTowers.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int hanoiTowers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

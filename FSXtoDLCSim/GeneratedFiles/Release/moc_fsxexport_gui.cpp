/****************************************************************************
** Meta object code from reading C++ file 'fsxexport_gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../fsxexport_gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fsxexport_gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_fsxexport_gui_t {
    QByteArrayData data[9];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_fsxexport_gui_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_fsxexport_gui_t qt_meta_stringdata_fsxexport_gui = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 17),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 9),
QT_MOC_LITERAL(4, 43, 9),
QT_MOC_LITERAL(5, 53, 13),
QT_MOC_LITERAL(6, 67, 7),
QT_MOC_LITERAL(7, 75, 12),
QT_MOC_LITERAL(8, 88, 4)
    },
    "fsxexport_gui\0slot_started_slot\0\0"
    "readyRead\0connected\0login_clicked\0"
    "timeOut\0selectedData\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_fsxexport_gui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    0,   47,    2, 0x08,
       6,    0,   48,    2, 0x08,
       7,    1,   49,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    8,

       0        // eod
};

void fsxexport_gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        fsxexport_gui *_t = static_cast<fsxexport_gui *>(_o);
        switch (_id) {
        case 0: _t->slot_started_slot(); break;
        case 1: _t->readyRead(); break;
        case 2: _t->connected(); break;
        case 3: _t->login_clicked(); break;
        case 4: _t->timeOut(); break;
        case 5: { QString _r = _t->selectedData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject fsxexport_gui::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fsxexport_gui.data,
      qt_meta_data_fsxexport_gui,  qt_static_metacall, 0, 0}
};


const QMetaObject *fsxexport_gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *fsxexport_gui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fsxexport_gui.stringdata))
        return static_cast<void*>(const_cast< fsxexport_gui*>(this));
    return QDialog::qt_metacast(_clname);
}

int fsxexport_gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

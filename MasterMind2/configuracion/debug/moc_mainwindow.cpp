/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Configuracion_de_mastermind/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[389];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "on_cpjugada_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "on_cpjuego_clicked"
QT_MOC_LITERAL(4, 51, 14), // "on_rsi_clicked"
QT_MOC_LITERAL(5, 66, 14), // "on_rno_clicked"
QT_MOC_LITERAL(6, 81, 24), // "on_dificultadop1_clicked"
QT_MOC_LITERAL(7, 106, 24), // "on_dificultadop2_clicked"
QT_MOC_LITERAL(8, 131, 24), // "on_dificultadop3_clicked"
QT_MOC_LITERAL(9, 156, 21), // "on_horas_valueChanged"
QT_MOC_LITERAL(10, 178, 4), // "arg1"
QT_MOC_LITERAL(11, 183, 23), // "on_minutos_valueChanged"
QT_MOC_LITERAL(12, 207, 24), // "on_segundos_valueChanged"
QT_MOC_LITERAL(13, 232, 16), // "on_repsi_clicked"
QT_MOC_LITERAL(14, 249, 16), // "on_repno_clicked"
QT_MOC_LITERAL(15, 266, 24), // "on_elementocolor_clicked"
QT_MOC_LITERAL(16, 291, 24), // "on_elementoletra_clicked"
QT_MOC_LITERAL(17, 316, 25), // "on_elementonumero_clicked"
QT_MOC_LITERAL(18, 342, 27), // "on_elementodefinido_clicked"
QT_MOC_LITERAL(19, 370, 18) // "on_guardar_clicked"

    },
    "MainWindow\0on_cpjugada_clicked\0\0"
    "on_cpjuego_clicked\0on_rsi_clicked\0"
    "on_rno_clicked\0on_dificultadop1_clicked\0"
    "on_dificultadop2_clicked\0"
    "on_dificultadop3_clicked\0on_horas_valueChanged\0"
    "arg1\0on_minutos_valueChanged\0"
    "on_segundos_valueChanged\0on_repsi_clicked\0"
    "on_repno_clicked\0on_elementocolor_clicked\0"
    "on_elementoletra_clicked\0"
    "on_elementonumero_clicked\0"
    "on_elementodefinido_clicked\0"
    "on_guardar_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    1,  106,    2, 0x08 /* Private */,
      11,    1,  109,    2, 0x08 /* Private */,
      12,    1,  112,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cpjugada_clicked(); break;
        case 1: _t->on_cpjuego_clicked(); break;
        case 2: _t->on_rsi_clicked(); break;
        case 3: _t->on_rno_clicked(); break;
        case 4: _t->on_dificultadop1_clicked(); break;
        case 5: _t->on_dificultadop2_clicked(); break;
        case 6: _t->on_dificultadop3_clicked(); break;
        case 7: _t->on_horas_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_minutos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_segundos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_repsi_clicked(); break;
        case 11: _t->on_repno_clicked(); break;
        case 12: _t->on_elementocolor_clicked(); break;
        case 13: _t->on_elementoletra_clicked(); break;
        case 14: _t->on_elementonumero_clicked(); break;
        case 15: _t->on_elementodefinido_clicked(); break;
        case 16: _t->on_guardar_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
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
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

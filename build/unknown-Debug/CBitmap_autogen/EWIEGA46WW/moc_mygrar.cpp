/****************************************************************************
** Meta object code from reading C++ file 'mygrar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../mygrar.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygrar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MyGraphicsArea_t {
    uint offsetsAndSizes[14];
    char stringdata0[15];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[10];
    char stringdata5[12];
    char stringdata6[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyGraphicsArea_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyGraphicsArea_t qt_meta_stringdata_MyGraphicsArea = {
    {
        QT_MOC_LITERAL(0, 14),  // "MyGraphicsArea"
        QT_MOC_LITERAL(15, 11),  // "zoomChanged"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 9),  // "zoomLevel"
        QT_MOC_LITERAL(38, 9),  // "resetView"
        QT_MOC_LITERAL(48, 11),  // "setViewZoom"
        QT_MOC_LITERAL(60, 4)   // "zoom"
    },
    "MyGraphicsArea",
    "zoomChanged",
    "",
    "zoomLevel",
    "resetView",
    "setViewZoom",
    "zoom"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MyGraphicsArea[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   35,    2, 0x0a,    3 /* Public */,
       5,    1,   36,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyGraphicsArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_MyGraphicsArea.offsetsAndSizes,
    qt_meta_data_MyGraphicsArea,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MyGraphicsArea_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyGraphicsArea, std::true_type>,
        // method 'zoomChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'resetView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setViewZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>
    >,
    nullptr
} };

void MyGraphicsArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGraphicsArea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zoomChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 1: _t->resetView(); break;
        case 2: _t->setViewZoom((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGraphicsArea::*)(qreal );
            if (_t _q_method = &MyGraphicsArea::zoomChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MyGraphicsArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsArea.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MyGraphicsArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsArea::zoomChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

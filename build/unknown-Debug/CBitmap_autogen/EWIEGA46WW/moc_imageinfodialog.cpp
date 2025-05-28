/****************************************************************************
** Meta object code from reading C++ file 'imageinfodialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../imageinfodialog.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageinfodialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ImageInfoDialog_t {
    uint offsetsAndSizes[18];
    char stringdata0[16];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[7];
    char stringdata5[20];
    char stringdata6[20];
    char stringdata7[25];
    char stringdata8[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ImageInfoDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ImageInfoDialog_t qt_meta_stringdata_ImageInfoDialog = {
    {
        QT_MOC_LITERAL(0, 15),  // "ImageInfoDialog"
        QT_MOC_LITERAL(16, 16),  // "updateUIElememts"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 7),  // "onApply"
        QT_MOC_LITERAL(42, 6),  // "onExit"
        QT_MOC_LITERAL(49, 19),  // "onSizeSpinChange_ni"
        QT_MOC_LITERAL(69, 19),  // "onSizeSpinChange_ad"
        QT_MOC_LITERAL(89, 24),  // "onAdjustAlignmentChanged"
        QT_MOC_LITERAL(114, 2)   // "id"
    },
    "ImageInfoDialog",
    "updateUIElememts",
    "",
    "onApply",
    "onExit",
    "onSizeSpinChange_ni",
    "onSizeSpinChange_ad",
    "onAdjustAlignmentChanged",
    "id"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ImageInfoDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    1,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject ImageInfoDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ImageInfoDialog.offsetsAndSizes,
    qt_meta_data_ImageInfoDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ImageInfoDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImageInfoDialog, std::true_type>,
        // method 'updateUIElememts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onApply'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSizeSpinChange_ni'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSizeSpinChange_ad'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAdjustAlignmentChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ImageInfoDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageInfoDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateUIElememts(); break;
        case 1: _t->onApply(); break;
        case 2: _t->onExit(); break;
        case 3: _t->onSizeSpinChange_ni(); break;
        case 4: _t->onSizeSpinChange_ad(); break;
        case 5: _t->onAdjustAlignmentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ImageInfoDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageInfoDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageInfoDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ImageInfoDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

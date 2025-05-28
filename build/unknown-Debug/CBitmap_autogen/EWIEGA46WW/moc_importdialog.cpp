/****************************************************************************
** Meta object code from reading C++ file 'importdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../importdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'importdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ImportDialog_t {
    uint offsetsAndSizes[24];
    char stringdata0[13];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[16];
    char stringdata5[14];
    char stringdata6[16];
    char stringdata7[5];
    char stringdata8[15];
    char stringdata9[18];
    char stringdata10[8];
    char stringdata11[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ImportDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ImportDialog_t qt_meta_stringdata_ImportDialog = {
    {
        QT_MOC_LITERAL(0, 12),  // "ImportDialog"
        QT_MOC_LITERAL(13, 13),  // "onSizeChanged"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 13),  // "onOpenClicked"
        QT_MOC_LITERAL(42, 15),  // "onImportClicked"
        QT_MOC_LITERAL(58, 13),  // "updatePreview"
        QT_MOC_LITERAL(72, 15),  // "generatePreview"
        QT_MOC_LITERAL(88, 4),  // "Mode"
        QT_MOC_LITERAL(93, 14),  // "ByTransparency"
        QT_MOC_LITERAL(108, 17),  // "ByTransparency50p"
        QT_MOC_LITERAL(126, 7),  // "ByColor"
        QT_MOC_LITERAL(134, 14)   // "ByColorReverse"
    },
    "ImportDialog",
    "onSizeChanged",
    "",
    "onOpenClicked",
    "onImportClicked",
    "updatePreview",
    "generatePreview",
    "Mode",
    "ByTransparency",
    "ByTransparency50p",
    "ByColor",
    "ByColorReverse"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ImportDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       1,   49, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       7,    7, 0x0,    4,   54,

 // enum data: key, value
       8, uint(ImportDialog::ByTransparency),
       9, uint(ImportDialog::ByTransparency50p),
      10, uint(ImportDialog::ByColor),
      11, uint(ImportDialog::ByColorReverse),

       0        // eod
};

Q_CONSTINIT const QMetaObject ImportDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ImportDialog.offsetsAndSizes,
    qt_meta_data_ImportDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ImportDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ImportDialog, std::true_type>,
        // method 'onSizeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onOpenClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onImportClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updatePreview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generatePreview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ImportDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImportDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSizeChanged(); break;
        case 1: _t->onOpenClicked(); break;
        case 2: _t->onImportClicked(); break;
        case 3: _t->updatePreview(); break;
        case 4: _t->generatePreview(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ImportDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImportDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImportDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ImportDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

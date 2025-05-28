/****************************************************************************
** Meta object code from reading C++ file 'codeexportdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../codeexportdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeexportdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CodeHighlighter_t {
    uint offsetsAndSizes[2];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CodeHighlighter_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CodeHighlighter_t qt_meta_stringdata_CodeHighlighter = {
    {
        QT_MOC_LITERAL(0, 15)   // "CodeHighlighter"
    },
    "CodeHighlighter"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CodeHighlighter[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject CodeHighlighter::staticMetaObject = { {
    QMetaObject::SuperData::link<QSyntaxHighlighter::staticMetaObject>(),
    qt_meta_stringdata_CodeHighlighter.offsetsAndSizes,
    qt_meta_data_CodeHighlighter,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CodeHighlighter_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CodeHighlighter, std::true_type>
    >,
    nullptr
} };

void CodeHighlighter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *CodeHighlighter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeHighlighter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CodeHighlighter.stringdata0))
        return static_cast<void*>(this);
    return QSyntaxHighlighter::qt_metacast(_clname);
}

int CodeHighlighter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSyntaxHighlighter::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_stringdata_CodeExportDialog_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[20];
    char stringdata5[5];
    char stringdata6[11];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CodeExportDialog_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CodeExportDialog_t qt_meta_stringdata_CodeExportDialog = {
    {
        QT_MOC_LITERAL(0, 16),  // "CodeExportDialog"
        QT_MOC_LITERAL(17, 18),  // "onCopyPasteClicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 17),  // "onSaveLoadClicked"
        QT_MOC_LITERAL(55, 19),  // "onExitImportClicked"
        QT_MOC_LITERAL(75, 4),  // "Mode"
        QT_MOC_LITERAL(80, 10),  // "ExportMode"
        QT_MOC_LITERAL(91, 10)   // "ImportMode"
    },
    "CodeExportDialog",
    "onCopyPasteClicked",
    "",
    "onSaveLoadClicked",
    "onExitImportClicked",
    "Mode",
    "ExportMode",
    "ImportMode"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CodeExportDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       1,   35, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    0,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
       5,    5, 0x0,    2,   40,

 // enum data: key, value
       6, uint(CodeExportDialog::ExportMode),
       7, uint(CodeExportDialog::ImportMode),

       0        // eod
};

Q_CONSTINIT const QMetaObject CodeExportDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CodeExportDialog.offsetsAndSizes,
    qt_meta_data_CodeExportDialog,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CodeExportDialog_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CodeExportDialog, std::true_type>,
        // method 'onCopyPasteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSaveLoadClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onExitImportClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CodeExportDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CodeExportDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCopyPasteClicked(); break;
        case 1: _t->onSaveLoadClicked(); break;
        case 2: _t->onExitImportClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *CodeExportDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodeExportDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CodeExportDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CodeExportDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

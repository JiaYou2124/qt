/****************************************************************************
** Meta object code from reading C++ file 'document.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../document.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'document.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDocumentENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDocumentENDCLASS = QtMocHelpers::stringData(
    "Document",
    "on_createdir_pb_clicked",
    "",
    "on_flushFile_pb_clicked",
    "on_deldir_pb_clicked",
    "on_rename_pb_clicked",
    "enterDir",
    "QModelIndex",
    "index",
    "on_back_pb_clicked",
    "on_upload_pb_clicked",
    "uploadFiledata",
    "on_delFile_pb_clicked",
    "on_download_pb_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDocumentENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[9];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[24];
    char stringdata4[21];
    char stringdata5[21];
    char stringdata6[9];
    char stringdata7[12];
    char stringdata8[6];
    char stringdata9[19];
    char stringdata10[21];
    char stringdata11[15];
    char stringdata12[22];
    char stringdata13[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDocumentENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDocumentENDCLASS_t qt_meta_stringdata_CLASSDocumentENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Document"
        QT_MOC_LITERAL(9, 23),  // "on_createdir_pb_clicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 23),  // "on_flushFile_pb_clicked"
        QT_MOC_LITERAL(58, 20),  // "on_deldir_pb_clicked"
        QT_MOC_LITERAL(79, 20),  // "on_rename_pb_clicked"
        QT_MOC_LITERAL(100, 8),  // "enterDir"
        QT_MOC_LITERAL(109, 11),  // "QModelIndex"
        QT_MOC_LITERAL(121, 5),  // "index"
        QT_MOC_LITERAL(127, 18),  // "on_back_pb_clicked"
        QT_MOC_LITERAL(146, 20),  // "on_upload_pb_clicked"
        QT_MOC_LITERAL(167, 14),  // "uploadFiledata"
        QT_MOC_LITERAL(182, 21),  // "on_delFile_pb_clicked"
        QT_MOC_LITERAL(204, 22)   // "on_download_pb_clicked"
    },
    "Document",
    "on_createdir_pb_clicked",
    "",
    "on_flushFile_pb_clicked",
    "on_deldir_pb_clicked",
    "on_rename_pb_clicked",
    "enterDir",
    "QModelIndex",
    "index",
    "on_back_pb_clicked",
    "on_upload_pb_clicked",
    "uploadFiledata",
    "on_delFile_pb_clicked",
    "on_download_pb_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDocumentENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    1 /* Private */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    1,   78,    2, 0x08,    5 /* Private */,
       9,    0,   81,    2, 0x08,    7 /* Private */,
      10,    0,   82,    2, 0x08,    8 /* Private */,
      11,    0,   83,    2, 0x08,    9 /* Private */,
      12,    0,   84,    2, 0x08,   10 /* Private */,
      13,    0,   85,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Document::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSDocumentENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDocumentENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDocumentENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Document, std::true_type>,
        // method 'on_createdir_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_flushFile_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deldir_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rename_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'enterDir'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_back_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_upload_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'uploadFiledata'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delFile_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_download_pb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Document::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Document *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_createdir_pb_clicked(); break;
        case 1: _t->on_flushFile_pb_clicked(); break;
        case 2: _t->on_deldir_pb_clicked(); break;
        case 3: _t->on_rename_pb_clicked(); break;
        case 4: _t->enterDir((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->on_back_pb_clicked(); break;
        case 6: _t->on_upload_pb_clicked(); break;
        case 7: _t->uploadFiledata(); break;
        case 8: _t->on_delFile_pb_clicked(); break;
        case 9: _t->on_download_pb_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *Document::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Document::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDocumentENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Document::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP

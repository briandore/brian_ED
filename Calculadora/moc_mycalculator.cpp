/****************************************************************************
** Meta object code from reading C++ file 'mycalculator.h'
**
** Created: Fri Jun 3 14:12:50 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mycalculator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyCalculator[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      38,   13,   13,   13, 0x08,
      59,   13,   13,   13, 0x08,
      82,   13,   13,   13, 0x08,
     104,   13,   13,   13, 0x08,
     122,   13,   13,   13, 0x08,
     143,   13,   13,   13, 0x08,
     165,   13,   13,   13, 0x08,
     186,   13,   13,   13, 0x08,
     205,   13,   13,   13, 0x08,
     224,   13,   13,   13, 0x08,
     244,   13,   13,   13, 0x08,
     264,   13,   13,   13, 0x08,
     286,   13,   13,   13, 0x08,
     304,   13,   13,   13, 0x08,
     325,   13,   13,   13, 0x08,
     345,   13,   13,   13, 0x08,
     364,   13,   13,   13, 0x08,
     381,   13,   13,   13, 0x08,
     398,   13,   13,   13, 0x08,
     415,   13,   13,   13, 0x08,
     432,   13,   13,   13, 0x08,
     449,   13,   13,   13, 0x08,
     466,   13,   13,   13, 0x08,
     483,   13,   13,   13, 0x08,
     500,   13,   13,   13, 0x08,
     517,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyCalculator[] = {
    "MyCalculator\0\0on_btNegative_clicked()\0"
    "on_btGraph_clicked()\0on_updateVrs_clicked()\0"
    "on_btSolve1_clicked()\0on_btFx_clicked()\0"
    "on_btPower_clicked()\0on_btDelete_clicked()\0"
    "on_btClean_clicked()\0on_btCos_clicked()\0"
    "on_btSin_clicked()\0on_btPar2_clicked()\0"
    "on_btPar1_clicked()\0on_btDivide_clicked()\0"
    "on_btBy_clicked()\0on_btMinus_clicked()\0"
    "on_btPlus_clicked()\0on_btDot_clicked()\0"
    "on_bt0_clicked()\0on_bt9_clicked()\0"
    "on_bt8_clicked()\0on_bt7_clicked()\0"
    "on_bt6_clicked()\0on_bt5_clicked()\0"
    "on_bt4_clicked()\0on_bt3_clicked()\0"
    "on_bt2_clicked()\0on_bt1_clicked()\0"
};

const QMetaObject MyCalculator::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyCalculator,
      qt_meta_data_MyCalculator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyCalculator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyCalculator))
        return static_cast<void*>(const_cast< MyCalculator*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btNegative_clicked(); break;
        case 1: on_btGraph_clicked(); break;
        case 2: on_updateVrs_clicked(); break;
        case 3: on_btSolve1_clicked(); break;
        case 4: on_btFx_clicked(); break;
        case 5: on_btPower_clicked(); break;
        case 6: on_btDelete_clicked(); break;
        case 7: on_btClean_clicked(); break;
        case 8: on_btCos_clicked(); break;
        case 9: on_btSin_clicked(); break;
        case 10: on_btPar2_clicked(); break;
        case 11: on_btPar1_clicked(); break;
        case 12: on_btDivide_clicked(); break;
        case 13: on_btBy_clicked(); break;
        case 14: on_btMinus_clicked(); break;
        case 15: on_btPlus_clicked(); break;
        case 16: on_btDot_clicked(); break;
        case 17: on_bt0_clicked(); break;
        case 18: on_bt9_clicked(); break;
        case 19: on_bt8_clicked(); break;
        case 20: on_bt7_clicked(); break;
        case 21: on_bt6_clicked(); break;
        case 22: on_bt5_clicked(); break;
        case 23: on_bt4_clicked(); break;
        case 24: on_bt3_clicked(); break;
        case 25: on_bt2_clicked(); break;
        case 26: on_bt1_clicked(); break;
        default: ;
        }
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** myFileStat meta object code from reading C++ file 'filestat.h'
**
** Created: Wed Oct 23 10:21:43 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "filestat.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *myFileStat::className() const
{
    return "myFileStat";
}

QMetaObject *myFileStat::metaObj = 0;
static QMetaObjectCleanUp cleanUp_myFileStat( "myFileStat", &myFileStat::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString myFileStat::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "myFileStat", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString myFileStat::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "myFileStat", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* myFileStat::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QVGroupBox::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "JavShared", QUParameter::In }
    };
    static const QUMethod slot_0 = {"updateName", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "JavShared", QUParameter::In }
    };
    static const QUMethod slot_1 = {"updateSize", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "updateName(JavShared*)", &slot_0, QMetaData::Public },
	{ "updateSize(JavShared*)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"myFileStat", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_myFileStat.setMetaObject( metaObj );
    return metaObj;
}

void* myFileStat::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "myFileStat" ) )
	return this;
    return QVGroupBox::qt_cast( clname );
}

bool myFileStat::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: updateName((JavShared*)static_QUType_ptr.get(_o+1)); break;
    case 1: updateSize((JavShared*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QVGroupBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool myFileStat::qt_emit( int _id, QUObject* _o )
{
    return QVGroupBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool myFileStat::qt_property( int id, int f, QVariant* v)
{
    return QVGroupBox::qt_property( id, f, v);
}

bool myFileStat::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

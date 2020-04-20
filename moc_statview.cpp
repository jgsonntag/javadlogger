/****************************************************************************
** Statview meta object code from reading C++ file 'statview.h'
**
** Created: Wed Oct 23 10:21:47 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "statview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Statview::className() const
{
    return "Statview";
}

QMetaObject *Statview::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Statview( "Statview", &Statview::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Statview::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Statview", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Statview::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Statview", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Statview::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGrid::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "JavShared", QUParameter::In }
    };
    static const QUMethod slot_0 = {"update", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "update(JavShared*)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Statview", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Statview.setMetaObject( metaObj );
    return metaObj;
}

void* Statview::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Statview" ) )
	return this;
    return QGrid::qt_cast( clname );
}

bool Statview::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: update((JavShared*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QGrid::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Statview::qt_emit( int _id, QUObject* _o )
{
    return QGrid::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Statview::qt_property( int id, int f, QVariant* v)
{
    return QGrid::qt_property( id, f, v);
}

bool Statview::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

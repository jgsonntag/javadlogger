/****************************************************************************
** javadFSUsage meta object code from reading C++ file 'javadfsusage.h'
**
** Created: Wed Oct 23 10:46:27 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "javadfsusage.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *javadFSUsage::className() const
{
    return "javadFSUsage";
}

QMetaObject *javadFSUsage::metaObj = 0;
static QMetaObjectCleanUp cleanUp_javadFSUsage( "javadFSUsage", &javadFSUsage::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString javadFSUsage::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "javadFSUsage", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString javadFSUsage::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "javadFSUsage", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* javadFSUsage::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QHGroupBox::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "JavShared", QUParameter::In }
    };
    static const QUMethod slot_0 = {"update", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "update(JavShared*)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"javadFSUsage", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_javadFSUsage.setMetaObject( metaObj );
    return metaObj;
}

void* javadFSUsage::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "javadFSUsage" ) )
	return this;
    return QHGroupBox::qt_cast( clname );
}

bool javadFSUsage::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: update((JavShared*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QHGroupBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool javadFSUsage::qt_emit( int _id, QUObject* _o )
{
    return QHGroupBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool javadFSUsage::qt_property( int id, int f, QVariant* v)
{
    return QHGroupBox::qt_property( id, f, v);
}

bool javadFSUsage::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

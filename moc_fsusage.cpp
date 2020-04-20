/****************************************************************************
** myFSUsage meta object code from reading C++ file 'fsusage.h'
**
** Created: Wed Oct 23 10:46:27 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fsusage.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *myFSUsage::className() const
{
    return "myFSUsage";
}

QMetaObject *myFSUsage::metaObj = 0;
static QMetaObjectCleanUp cleanUp_myFSUsage( "myFSUsage", &myFSUsage::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString myFSUsage::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "myFSUsage", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString myFSUsage::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "myFSUsage", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* myFSUsage::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QHGroupBox::staticMetaObject();
    static const QUMethod slot_0 = {"update", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "update()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"myFSUsage", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_myFSUsage.setMetaObject( metaObj );
    return metaObj;
}

void* myFSUsage::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "myFSUsage" ) )
	return this;
    return QHGroupBox::qt_cast( clname );
}

bool myFSUsage::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: update(); break;
    default:
	return QHGroupBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool myFSUsage::qt_emit( int _id, QUObject* _o )
{
    return QHGroupBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool myFSUsage::qt_property( int id, int f, QVariant* v)
{
    return QHGroupBox::qt_property( id, f, v);
}

bool myFSUsage::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

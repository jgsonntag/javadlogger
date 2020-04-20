/****************************************************************************
** Skyview meta object code from reading C++ file 'skyview.h'
**
** Created: Wed Oct 23 10:21:46 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "skyview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Skyview::className() const
{
    return "Skyview";
}

QMetaObject *Skyview::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Skyview( "Skyview", &Skyview::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Skyview::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Skyview", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Skyview::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Skyview", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Skyview::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"updatesky", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "updatesky()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Skyview", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Skyview.setMetaObject( metaObj );
    return metaObj;
}

void* Skyview::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Skyview" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool Skyview::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: updatesky(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Skyview::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Skyview::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Skyview::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

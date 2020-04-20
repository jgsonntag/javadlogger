/****************************************************************************
** Javadloggui meta object code from reading C++ file 'javadloggui.h'
**
** Created: Fri Mar 28 10:04:36 2014
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "javadloggui.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Javadloggui::className() const
{
    return "Javadloggui";
}

QMetaObject *Javadloggui::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Javadloggui( "Javadloggui", &Javadloggui::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Javadloggui::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Javadloggui", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Javadloggui::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Javadloggui", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Javadloggui::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QVBox::staticMetaObject();
    static const QUMethod slot_0 = {"about", 0, 0 };
    static const QUMethod slot_1 = {"startdata", 0, 0 };
    static const QUMethod slot_2 = {"stopdata", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setrate", 1, param_slot_3 };
    static const QUMethod slot_4 = {"genupdate", 0, 0 };
    static const QUMethod slot_5 = {"satupdate", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "about()", &slot_0, QMetaData::Private },
	{ "startdata()", &slot_1, QMetaData::Private },
	{ "stopdata()", &slot_2, QMetaData::Private },
	{ "setrate(int)", &slot_3, QMetaData::Private },
	{ "genupdate()", &slot_4, QMetaData::Private },
	{ "satupdate()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"Javadloggui", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Javadloggui.setMetaObject( metaObj );
    return metaObj;
}

void* Javadloggui::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Javadloggui" ) )
	return this;
    return QVBox::qt_cast( clname );
}

bool Javadloggui::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: about(); break;
    case 1: startdata(); break;
    case 2: stopdata(); break;
    case 3: setrate((int)static_QUType_int.get(_o+1)); break;
    case 4: genupdate(); break;
    case 5: satupdate(); break;
    default:
	return QVBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Javadloggui::qt_emit( int _id, QUObject* _o )
{
    return QVBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Javadloggui::qt_property( int id, int f, QVariant* v)
{
    return QVBox::qt_property( id, f, v);
}

bool Javadloggui::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

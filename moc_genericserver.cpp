/****************************************************************************
** GenericServer meta object code from reading C++ file 'genericserver.h'
**
** Created: Wed Oct 23 16:47:43 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "genericserver.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *GenericServer::className() const
{
    return "GenericServer";
}

QMetaObject *GenericServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GenericServer( "GenericServer", &GenericServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString GenericServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GenericServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GenericServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GenericServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GenericServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QVBox::staticMetaObject();
    static const QUMethod slot_0 = {"slotNewConnectA", 0, 0 };
    static const QUMethod slot_1 = {"slotNewConnectB", 0, 0 };
    static const QUMethod slot_2 = {"slotNewConnectC", 0, 0 };
    static const QUMethod slot_3 = {"slotNewConnectD", 0, 0 };
    static const QUMethod slot_4 = {"slotDisConnectA", 0, 0 };
    static const QUMethod slot_5 = {"slotDisConnectB", 0, 0 };
    static const QUMethod slot_6 = {"slotDisConnectC", 0, 0 };
    static const QUMethod slot_7 = {"slotDisConnectD", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotNewConnectA()", &slot_0, QMetaData::Private },
	{ "slotNewConnectB()", &slot_1, QMetaData::Private },
	{ "slotNewConnectC()", &slot_2, QMetaData::Private },
	{ "slotNewConnectD()", &slot_3, QMetaData::Private },
	{ "slotDisConnectA()", &slot_4, QMetaData::Private },
	{ "slotDisConnectB()", &slot_5, QMetaData::Private },
	{ "slotDisConnectC()", &slot_6, QMetaData::Private },
	{ "slotDisConnectD()", &slot_7, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"GenericServer", parentObject,
	slot_tbl, 8,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GenericServer.setMetaObject( metaObj );
    return metaObj;
}

void* GenericServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GenericServer" ) )
	return this;
    return QVBox::qt_cast( clname );
}

bool GenericServer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotNewConnectA(); break;
    case 1: slotNewConnectB(); break;
    case 2: slotNewConnectC(); break;
    case 3: slotNewConnectD(); break;
    case 4: slotDisConnectA(); break;
    case 5: slotDisConnectB(); break;
    case 6: slotDisConnectC(); break;
    case 7: slotDisConnectD(); break;
    default:
	return QVBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GenericServer::qt_emit( int _id, QUObject* _o )
{
    return QVBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool GenericServer::qt_property( int id, int f, QVariant* v)
{
    return QVBox::qt_property( id, f, v);
}

bool GenericServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

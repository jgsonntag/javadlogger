/****************************************************************************
** SimpleSocket meta object code from reading C++ file 'simplesocket.h'
**
** Created: Wed Oct 23 10:21:46 2013
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "simplesocket.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SimpleSocket::className() const
{
    return "SimpleSocket";
}

QMetaObject *SimpleSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SimpleSocket( "SimpleSocket", &SimpleSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SimpleSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SimpleSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SimpleSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SimpleSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SimpleSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QSocket::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotSendText", 1, param_slot_0 };
    static const QUMethod slot_1 = {"slotCloseConnection", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotSendText(QString)", &slot_0, QMetaData::Public },
	{ "slotCloseConnection()", &slot_1, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"closingConnection", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "closingConnection()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"SimpleSocket", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SimpleSocket.setMetaObject( metaObj );
    return metaObj;
}

void* SimpleSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SimpleSocket" ) )
	return this;
    return QSocket::qt_cast( clname );
}

// SIGNAL closingConnection
void SimpleSocket::closingConnection()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool SimpleSocket::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotSendText((QString)static_QUType_QString.get(_o+1)); break;
    case 1: slotCloseConnection(); break;
    default:
	return QSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SimpleSocket::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: closingConnection(); break;
    default:
	return QSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool SimpleSocket::qt_property( int id, int f, QVariant* v)
{
    return QSocket::qt_property( id, f, v);
}

bool SimpleSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES

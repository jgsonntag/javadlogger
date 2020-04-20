//
// GenericServer class definition
//

#ifndef GENERICSERVER_H
#define GENERICSERVER_H

#include <qvbox.h>
#include <qlabel.h>
#include <qstring.h>
#include <qlabel.h>
#include <qtextedit.h>

#include "simpleserver.h"

class GenericServer : public QVBox
{

  Q_OBJECT

  public:
    GenericServer(Q_UINT16 portA, Q_UINT16 portB, Q_UINT16 portC, Q_UINT16 portD, 
                  QWidget *parent=0, const char *name=0);  // Constructor
    ~GenericServer();  // Destructor
    void broadcast_thisA(QString text);
    void broadcast_thisB(QString text);
    void broadcast_thisC(QString text);
    void broadcast_thisD(QString text);

  private:
    int connectionsA;
    int connectionsB;
    int connectionsC;
    int connectionsD;
    SimpleServer *serverA;
    SimpleServer *serverB;
    SimpleServer *serverC;
    SimpleServer *serverD;
    QLabel *connectlabelA;
    QLabel *connectlabelB;
    QLabel *connectlabelC;
    QLabel *connectlabelD;
    QTextEdit *outtextA;
    QTextEdit *outtextB;
    QTextEdit *outtextC;
    QTextEdit *outtextD;

  private slots:
    void slotNewConnectA();
    void slotNewConnectB();
    void slotNewConnectC();
    void slotNewConnectD();
    void slotDisConnectA();
    void slotDisConnectB();
    void slotDisConnectC();
    void slotDisConnectD();

};

#endif // GENERICSERVER_H

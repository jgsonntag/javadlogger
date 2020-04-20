//
// GenericServer class implementation
//

#include "genericserver.h"
#include "simpleserver.h"

#include <iostream>
using namespace std;

GenericServer::GenericServer(Q_UINT16 portA, Q_UINT16 portB, Q_UINT16 portC, Q_UINT16 portD,
                             QWidget *parent, const char *name)
	: QVBox(parent,name)
{

  // Initialize connections counter
  connectionsA = 0;
  connectionsB = 0;
  connectionsC = 0;
  connectionsD = 0;

  // Create the server and connect its slots
  serverA = new SimpleServer(portA,this);
  connect(serverA,SIGNAL(newConnect()),this,SLOT(slotNewConnectA()));
  connect(serverA,SIGNAL(disConnect()),this,SLOT(slotDisConnectA()));
  serverB = new SimpleServer(portB,this);
  connect(serverB,SIGNAL(newConnect()),this,SLOT(slotNewConnectB()));
  connect(serverB,SIGNAL(disConnect()),this,SLOT(slotDisConnectB()));
  serverC = new SimpleServer(portC,this);
  connect(serverC,SIGNAL(newConnect()),this,SLOT(slotNewConnectC()));
  connect(serverC,SIGNAL(disConnect()),this,SLOT(slotDisConnectC()));
  serverD = new SimpleServer(portD,this);
  connect(serverD,SIGNAL(newConnect()),this,SLOT(slotNewConnectD()));
  connect(serverD,SIGNAL(disConnect()),this,SLOT(slotDisConnectD()));

  // Build the GUI
  QString stemp;
  stemp.sprintf("Serving on port %d",portA);
  new QLabel(stemp,this);
  connectlabelA = new QLabel("Active network listeners: 00",this);
  new QLabel("Current broadcast text:",this);
  QFont outfont("Courier",8);
  outtextA = new QTextEdit(this);
  outtextA->setFixedHeight(40);
  outtextA->setReadOnly(true);
  outtextA->setCurrentFont(outfont);

  stemp.sprintf("\nServing on port %d",portB);
  new QLabel(stemp,this);
  connectlabelB = new QLabel("Active network listeners: 00",this);
  new QLabel("Current broadcast text:",this);
  //QFont outfont("Courier",8);
  outtextB = new QTextEdit(this);
  outtextB->setFixedHeight(40);
  outtextB->setReadOnly(true);
  outtextB->setCurrentFont(outfont);

  stemp.sprintf("\nServing on port %d",portC);
  new QLabel(stemp,this);
  connectlabelC = new QLabel("Active network listeners: 00",this);
  new QLabel("Current broadcast text:",this);
  //QFont outfont("Courier",8);
  outtextC = new QTextEdit(this);
  outtextC->setFixedHeight(40);
  outtextC->setReadOnly(true);
  outtextC->setCurrentFont(outfont);

  stemp.sprintf("\nServing on port %d",portD);
  new QLabel(stemp,this);
  connectlabelD = new QLabel("Active network listeners: 00",this);
  new QLabel("Current broadcast text:",this);
  //QFont outfont("Courier",8);
  outtextD = new QTextEdit(this);
  outtextD->setFixedHeight(40);
  outtextD->setReadOnly(true);
  outtextD->setCurrentFont(outfont);

}

GenericServer::~GenericServer()
{
}

void GenericServer::slotNewConnectA()
{
  QString stemp;

  ++connectionsA;
  stemp.sprintf("Active network listeners: %02d",connectionsA);
  connectlabelA->setText(stemp);
}

void GenericServer::slotNewConnectB()
{
  QString stemp;

  ++connectionsB;
  stemp.sprintf("Active network listeners: %02d",connectionsB);
  connectlabelB->setText(stemp);
}

void GenericServer::slotNewConnectC()
{
  QString stemp;

  ++connectionsC;
  stemp.sprintf("Active network listeners: %02d",connectionsC);
  connectlabelC->setText(stemp);
}

void GenericServer::slotNewConnectD()
{
  QString stemp;

  ++connectionsD;
  stemp.sprintf("Active network listeners: %02d",connectionsD);
  connectlabelD->setText(stemp);
}

void GenericServer::slotDisConnectA()
{
  QString stemp;

  --connectionsA;
  stemp.sprintf("Active network listeners: %02d",connectionsA);
  connectlabelA->setText(stemp);
}

void GenericServer::slotDisConnectB()
{
  QString stemp;

  --connectionsB;
  stemp.sprintf("Active network listeners: %02d",connectionsB);
  connectlabelB->setText(stemp);
}

void GenericServer::slotDisConnectC()
{
  QString stemp;

  --connectionsC;
  stemp.sprintf("Active network listeners: %02d",connectionsC);
  connectlabelC->setText(stemp);
}

void GenericServer::slotDisConnectD()
{
  QString stemp;

  --connectionsD;
  stemp.sprintf("Active network listeners: %02d",connectionsD);
  connectlabelD->setText(stemp);
}

void GenericServer::broadcast_thisA(QString text)
{
  serverA->sendText(text);
  outtextA->clear();
  outtextA->append(text);
}

void GenericServer::broadcast_thisB(QString text)
{
  serverB->sendText(text);
  outtextB->clear();
  outtextB->append(text);
}

void GenericServer::broadcast_thisC(QString text)
{
  serverC->sendText(text);
  outtextC->clear();
  outtextC->append(text);
}

void GenericServer::broadcast_thisD(QString text)
{
  serverD->sendText(text);
  outtextD->clear();
  outtextD->append(text);
}


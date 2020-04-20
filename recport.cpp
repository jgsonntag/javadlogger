
#include <iostream>
using namespace std;

#include <qstring.h>
#include "recport.h"


myRecPort::myRecPort( QWidget *parent, const char *name )
    : QHGroupBox("GPS port",parent,name)
{
  gpsport = new QLabel(this);
}

myRecPort::~myRecPort()
{
}

void myRecPort::update(JavShared *shared)
{
  gpsport->setText(shared->getGPSPort());
}

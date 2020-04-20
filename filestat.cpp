
#include <iostream>
using namespace std;

#include <qvgroupbox.h>
#include <qstring.h>
#include "filestat.h"


myFileStat::myFileStat( QWidget *parent, const char *name )
    : QVGroupBox("Output file",parent,name)
{
  outname = new QLabel(this);
  outsize = new QLabel(this);
  outinfo = new QFileInfo();
}

myFileStat::~myFileStat()
{
  delete outname;
  delete outsize;
  delete outinfo;
}

void myFileStat::updateName(JavShared *shared)
{
  stemp = shared->getOutfile();
  outname->setText(stemp);
}

void myFileStat::updateSize(JavShared *shared)
{
  stemp = shared->getOutfile();
  outinfo->setFile(stemp);
  stemp.sprintf("Size: %.2lf Mb",
                 ((double)outinfo->size()/1048576.0));
  outsize->setText(stemp);

  // Inserted the following because filename was not always picked
  // up on the first try
  stemp = shared->getOutfile();
  outname->setText(stemp);
}

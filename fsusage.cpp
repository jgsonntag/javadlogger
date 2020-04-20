
#include <sys/vfs.h>
#include <iostream>
using namespace std;

#include <qhgroupbox.h>
#include <qprogressbar.h>
#include "fsusage.h"


myFSUsage::myFSUsage( QWidget *parent, const char *name )
    : QHGroupBox("Computer filesystem usage",parent,name)
{
  bar = new QProgressBar(this);
  bar->setTotalSteps(100);
  text = new QLabel(this);
  update();
}

myFSUsage::~myFSUsage()
{
  delete bar;
  delete text;
}

void myFSUsage::update()
{
  char temp[40];
  int used;
  double mbperblock,totalmb,availmb;
  struct statfs diskstats;

  if (statfs(".",&diskstats) == -1)
    cout << "problem with statfs\n";
  mbperblock = diskstats.f_bsize/1024/1000.0;
  totalmb = diskstats.f_blocks*mbperblock;
  availmb = diskstats.f_bavail*mbperblock;
  used = (int)(100.0*(totalmb-availmb)/totalmb);
  bar->setProgress(used);
  sprintf(temp,"%.0lf MB available",availmb);
  text->setText(temp);

}

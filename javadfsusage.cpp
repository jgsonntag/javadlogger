
//#include <sys/vfs.h>
#include <iostream>
using namespace std;

#include <qhgroupbox.h>
#include <qprogressbar.h>
#include "javadfsusage.h"
#include "javshared.h"


javadFSUsage::javadFSUsage( QWidget *parent, const char *name )
    : QHGroupBox("Javad filesystem usage",parent,name)
{
  bar = new QProgressBar(this);
  bar->setTotalSteps(100);
  text = new QLabel(this);
  //update(shared);
}

javadFSUsage::~javadFSUsage()
{
  delete bar;
  delete text;
}

void javadFSUsage::update(JavShared *shared)
//void javadFSUsage::update()
{
  char temp[40];
  //int used;
  //double mbperblock,totalmb,availmb;
  //struct statfs diskstats;

  //mbperblock = diskstats.f_bsize/1024/1000.0;
  //totalmb = diskstats.f_blocks*mbperblock;
  //availmb = diskstats.f_bavail*mbperblock;
  //used = (int)(100.0*(totalmb-availmb)/totalmb);
  bar->setProgress(50);
  sprintf(temp,"%.0lf MB available",1.0);
  text->setText(temp);

}


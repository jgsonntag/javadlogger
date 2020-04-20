#ifndef JAVADFSUSAGE_H
#define JAVADFSUSAGE_H

#include <qhgroupbox.h>
#include <qprogressbar.h>
#include <qlabel.h>
#include "javshared.h"

class javadFSUsage : public QHGroupBox
{
  Q_OBJECT

  public:
    javadFSUsage( QWidget *parent=0, const char *name=0 );
    ~javadFSUsage();
    
  public slots:
    void update(JavShared *);
    //void update();

  private:
    QProgressBar *bar;
    QLabel *text;
    
};

#endif // JAVADFSUSAGE_H

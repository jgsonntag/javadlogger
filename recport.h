#ifndef RECPORT_H
#define RECPORT_H

#include <qhgroupbox.h>
#include <qlabel.h>
#include "javshared.h"

class myRecPort : public QHGroupBox
{
  Q_OBJECT

  public:
    myRecPort( QWidget *parent=0, const char *name=0 );
    ~myRecPort();
    
  public slots:
    void update(JavShared *);
    
  private:
    QLabel *gpsport;
    
};

#endif // RECPORT_H

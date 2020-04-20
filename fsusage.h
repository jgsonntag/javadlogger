#ifndef FSUSAGE_H
#define FSUSAGE_H

#include <qhgroupbox.h>
#include <qprogressbar.h>
#include <qlabel.h>

class myFSUsage : public QHGroupBox
{
  Q_OBJECT

  public:
    myFSUsage( QWidget *parent=0, const char *name=0 );
    ~myFSUsage();
    
  public slots:
    void update();
    
  private:
    QProgressBar *bar;
    QLabel *text;
    
};

#endif // FSUSAGE_H

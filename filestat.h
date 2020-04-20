#ifndef FILESTAT_H
#define FILESTAT_H

#include <qvgroupbox.h>
#include <qlabel.h>
#include <qfileinfo.h>
#include "javshared.h"

class myFileStat : public QVGroupBox
{
  Q_OBJECT

  public:
    myFileStat( QWidget *parent=0, const char *name=0 );
    ~myFileStat();
    
  public slots:
    void updateName(JavShared *);
    void updateSize(JavShared *);
    
  private:
    QString stemp;
    QLabel *outname;
    QLabel *outsize;
    QFileInfo *outinfo;
    
};

#endif // FILESTAT_H

#ifndef STATVIEW_H
#define STATVIEW_H

#include <qgrid.h>
#include <qlabel.h>
#include "javshared.h"

class Statview : public QGrid
{
  Q_OBJECT

  public:
    Statview( QWidget *parent=0, const char *name=0 );
    ~Statview();
    
  private:
    QLabel *goodRE;
    QLabel *badRE;
    QLabel *goodGT;
    QLabel *badGT;
    QLabel *goodUO;
    QLabel *badUO;
    QLabel *goodRD;
    QLabel *badRD;
    QLabel *goodPG;
    QLabel *badPG;
    QLabel *goodVG;
    QLabel *badVG;
    QLabel *goodDP;
    QLabel *badDP;
    QLabel *goodGO;
    QLabel *badGO;
    
  public slots:
    void update(JavShared *);
    
};

#endif // STATVIEW_H

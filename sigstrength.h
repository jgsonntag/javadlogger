#ifndef SIGSTRENGTH_H
#define SIGSTRENGTH_H

#include <qwidget.h>
#include <qpainter.h>
#include <qpixmap.h>

#include "javshared.h"
#include "sats.h"

#define SSMAX 60
#define SSMIN 20

extern Sats *currentsats;

class SigStrength : public QWidget
{
  Q_OBJECT

  public:
    SigStrength( QWidget *parent=0, const char *name=0 );
    ~SigStrength();
    
  private:
    void paintEvent(QPaintEvent *);
    QPainter *paint;
    QString label;
      
};

#endif // SIGSTRENGTH_H

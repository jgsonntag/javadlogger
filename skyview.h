#ifndef SKYVIEW_H
#define SKYVIEW_H

#include <qwidget.h>
#include <qpainter.h>
#include <qpixmap.h>

#include "javshared.h"
#include "sats.h"

extern Sats *currentsats;

class Skyview : public QWidget
{
  Q_OBJECT

  public:
    Skyview( QWidget *parent=0, const char *name=0 );
    ~Skyview();
    
  private:
    void paintEvent(QPaintEvent *);
    QPainter *paint;
    QString label;

  public slots:
    void updatesky();
      
};

#endif // SKYVIEW_H

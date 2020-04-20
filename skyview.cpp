
#include <sys/time.h>
#include <math.h>
#include <iostream>
using namespace std;

#include <qwidget.h>
#include "skyview.h"
#include "utility.h"


Skyview::Skyview( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
  paint = new QPainter;
  setBackgroundMode(NoBackground);
}

Skyview::~Skyview()
{
  delete paint;
}

void Skyview::updatesky()
{
  update();
}

void Skyview::paintEvent(QPaintEvent *)
{
  int i,x,y;
  double theta,r,x1,y1;
  SV *sv;
  
  // Set up an off-screen drawing buffer and paint to it  
  QPixmap *drawbuffer = new QPixmap(width(),height());
  paint->begin(drawbuffer,this);
  paint->fillRect(0,0,width(),height(),
                  paletteBackgroundColor());
  
  //  Draw the sky and grid
  paint->setBrush(QBrush("SteelBlue3",SolidPattern));
  paint->drawArc(0,0,240,240,0,5760);
  paint->setPen(QPen(black,1,QPen::SolidLine));
  paint->drawChord(0,0,240,240,0,5760);
  paint->setPen(QPen(black,1,QPen::SolidLine));
  paint->drawChord(40,40,160,160,0,5760);
  paint->drawChord(80,80,80,80,0,5760);
  paint->drawLine(120,20,120,220);
  paint->drawLine(20,120,220,120);
  paint->drawText(120-7,10-7,14,14,AlignHCenter|AlignVCenter,
                    "N");
  paint->drawText(120-7,230-7,14,14,AlignHCenter|AlignVCenter,
                    "S");
  paint->drawText(10-7,120-7,14,14,AlignHCenter|AlignVCenter,
                    "W");
  paint->drawText(230-7,120-7,14,14,AlignHCenter|AlignVCenter,
                    "E");
  
  //  Draw the SVs
  paint->setFont(QFont("Helvetica",10));
  for (i=0;i<currentsats->getnsv();i++)
  {
    sv = currentsats->getsv(i);
    theta = 90.0-sv->az;
    theta *= PI/180.0;
    r = 120.0*(90.0-sv->el)/90.0;
    x1 = r*cos(theta);
    y1 = r*sin(theta);
    x = 120 + (int)x1;
    y = 120 - (int)y1;
    label.setNum(sv->prn);
    paint->setPen(QPen(black,1,QPen::SolidLine));
    paint->drawEllipse(x-10,y-10,20,20);
    if (sv->flagca&0x02) // SV used for real-time solution
      paint->setBrush(white);
    else
      paint->setBrush(gray);    
    paint->drawEllipse(x-10,y-10,20,20);
    paint->setPen(QPen(black,1,QPen::SolidLine));
    paint->drawText(x-8,y-8,16,16,AlignHCenter|AlignVCenter,
                    label);
  } 
  paint->end();
  
  // Copy the offscreen buffer to the onscreen widget
  bitBlt(this,0,0,drawbuffer);
  delete drawbuffer;
  
}

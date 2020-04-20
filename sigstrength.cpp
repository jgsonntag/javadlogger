#include <math.h>
#include <iostream>
using namespace std;

#include <qwidget.h>
#include "sigstrength.h"
#include "utility.h"


SigStrength::SigStrength( QWidget *parent, const char *name )
    : QWidget( parent, name )
{
  paint = new QPainter;
  setBackgroundMode(NoBackground);
}

SigStrength::~SigStrength()
{
  delete paint;
}

void SigStrength::paintEvent(QPaintEvent *)
{
  int i,x,ybase,ytop,ht;
  SV *sv;
  
  // Set up an off-screen drawing buffer and paint to it  
  QPixmap *drawbuffer = new QPixmap(width(),height());
  paint->begin(drawbuffer,this);
  paint->fillRect(0,0,width(),height(),
                  paletteBackgroundColor());
  
  //  Draw a bar for each of 12 possible SVs
  ybase = 70;
  paint->setBrush("SteelBlue3");
  paint->drawRect(0,10,268,ybase-10);
  paint->setPen(QPen(black,1,QPen::SolidLine));
  for (i=20;i<=60;i+=10)
  {  
    ht = (int)(60.0*((double)(i-SSMIN)/(double)(SSMAX-SSMIN)));
    paint->drawLine(0,ybase-ht,268,ybase-ht);
    if (i==20||i==40||i==60)
    {
      label.setNum(i);
      paint->drawText(268,ybase-ht-8,16,16,
                      AlignHCenter|AlignVCenter,label);
    }
  }
  for (i=0;i<currentsats->getnsv();i++)
  {
    x = 4+i*22;
    sv = currentsats->getsv(i);
    paint->setPen(QPen(black,1,QPen::SolidLine));
    label.setNum(sv->prn);
    paint->drawText(x,ybase,18,18,AlignHCenter|AlignVCenter,
                    label);
    
    // Draw the CA signal strength
    ht = (int)(60.0*((double)(sv->snrca-SSMIN)/
         (double)(SSMAX-SSMIN)));
    if (ht<0) ht=1;
    else if (ht>60) ht=60;
    ytop = ybase - ht;
    if (sv->flagca&0x80) // cycle slip
      paint->setBrush(red);
    else if (sv->flagca&0x40) // possible cycle slip
      paint->setBrush(yellow);
    else
      paint->setBrush(white);
    paint->drawRect(x+0,ytop,6,ht);
  
    // Draw the P1 signal strength
    ht = (int)(60.0*((double)(sv->snrp1-SSMIN)/
         (double)(SSMAX-SSMIN)));
    if (ht<0) ht=1;
    else if (ht>60) ht=60;
    ytop = ybase - ht;
    if (sv->flagp1&0x80) // cycle slip
      paint->setBrush(red);
    else if (sv->flagp1&0x40) // possible cycle slip
      paint->setBrush(yellow);
    else
      paint->setBrush(white);
    paint->drawRect(x+6,ytop,6,ht);

    // Draw the P2 signal strength
    ht = (int)(60.0*((double)(sv->snrp2-SSMIN)/
         (double)(SSMAX-SSMIN)));
    if (ht<0) ht=1;
    else if (ht>60) ht=60;
    ytop = ybase - ht;
    if (sv->flagp2&0x80) // cycle slip
      paint->setBrush(red);
    else if (sv->flagp2&0x40) // possible cycle slip
      paint->setBrush(yellow);
    else
      paint->setBrush(white);
    paint->drawRect(x+12,ytop,6,ht);
    
  }
  paint->end();
  
  // Copy the offscreen buffer to the onscreen widget
  bitBlt(this,0,0,drawbuffer);
  delete drawbuffer;

}


#include <qgrid.h>
#include <qlabel.h>
#include "statview.h"
#include "javshared.h"


Statview::Statview( QWidget *parent, const char *name )
    : QGrid( 3, parent, name )
{
  new QLabel("",this);
  QLabel *good = new QLabel("Good",this);
  good->setAlignment(AlignHCenter);
  QLabel *bad = new QLabel("Bad",this);
  bad->setAlignment(AlignHCenter);
  
  // RE row
  QLabel *re = new QLabel("RE",this);
  re->setAlignment(AlignHCenter);
  goodRE = new QLabel(this);
  goodRE->setFrameShape(Box);
  goodRE->setAlignment(AlignRight);
  goodRE->setPaletteBackgroundColor(white);
  badRE  = new QLabel(this);
  badRE->setFrameShape(Box);
  badRE->setAlignment(AlignRight);
  badRE->setPaletteBackgroundColor(yellow);
  
  // GT row
  QLabel *gt = new QLabel("GT",this);
  gt->setAlignment(AlignHCenter);
  goodGT = new QLabel(this);
  goodGT->setFrameShape(Box);
  goodGT->setAlignment(AlignRight);
  goodGT->setPaletteBackgroundColor(white);
  badGT = new QLabel(this);
  badGT->setFrameShape(Box);
  badGT->setAlignment(AlignRight);
  badGT->setPaletteBackgroundColor(yellow);
  
  // UO row
  QLabel *uo = new QLabel("UO",this);
  uo->setAlignment(AlignHCenter);
  goodUO = new QLabel(this);
  goodUO->setFrameShape(Box);
  goodUO->setAlignment(AlignRight);
  goodUO->setPaletteBackgroundColor(white);
  badUO = new QLabel(this);
  badUO->setFrameShape(Box);
  badUO->setAlignment(AlignRight);
  badUO->setPaletteBackgroundColor(yellow);
  
  // RD row
  QLabel *rd = new QLabel("RD",this);
  rd->setAlignment(AlignHCenter);
  goodRD = new QLabel(this);
  goodRD->setFrameShape(Box);
  goodRD->setAlignment(AlignRight);
  goodRD->setPaletteBackgroundColor(white);
  badRD = new QLabel(this);
  badRD->setFrameShape(Box);
  badRD->setAlignment(AlignRight);
  badRD->setPaletteBackgroundColor(yellow);

  // PG row
  QLabel *pg = new QLabel("PG",this);
  pg->setAlignment(AlignHCenter);
  goodPG = new QLabel(this);
  goodPG->setFrameShape(Box);
  goodPG->setAlignment(AlignRight);
  goodPG->setPaletteBackgroundColor(white);
  badPG = new QLabel(this);
  badPG->setFrameShape(Box);
  badPG->setAlignment(AlignRight);
  badPG->setPaletteBackgroundColor(yellow);

  // VG row
  QLabel *vg = new QLabel("VG",this);
  vg->setAlignment(AlignHCenter);
  goodVG = new QLabel(this);
  goodVG->setFrameShape(Box);
  goodVG->setAlignment(AlignRight);
  goodVG->setPaletteBackgroundColor(white);
  badVG = new QLabel(this);
  badVG->setFrameShape(Box);
  badVG->setAlignment(AlignRight);
  badVG->setPaletteBackgroundColor(yellow);

  // DP row
  QLabel *dp = new QLabel("DP",this);
  dp->setAlignment(AlignHCenter);
  goodDP = new QLabel(this);
  goodDP->setFrameShape(Box);
  goodDP->setAlignment(AlignRight);
  goodDP->setPaletteBackgroundColor(white);
  badDP = new QLabel(this);
  badDP->setFrameShape(Box);
  badDP->setAlignment(AlignRight);
  badDP->setPaletteBackgroundColor(yellow);

  // GO row
  QLabel *go = new QLabel("GO",this);
  go->setAlignment(AlignHCenter);
  goodGO = new QLabel(this);
  goodGO->setFrameShape(Box);
  goodGO->setAlignment(AlignRight);
  goodGO->setPaletteBackgroundColor(white);
  badGO = new QLabel(this);
  badGO->setFrameShape(Box);
  badGO->setAlignment(AlignRight);
  badGO->setPaletteBackgroundColor(yellow);

}

Statview::~Statview()
{
}


void Statview::update(JavShared *shared)
{
  goodRE->setText(shared->getGoodRE());
  badRE->setText(shared->getBadRE());
  goodGT->setText(shared->getGoodGT());
  badGT->setText(shared->getBadGT());
  goodUO->setText(shared->getGoodUO());
  badUO->setText(shared->getBadUO());
  goodRD->setText(shared->getGoodRD());
  badRD->setText(shared->getBadRD());
  goodPG->setText(shared->getGoodPG());
  badPG->setText(shared->getBadPG());
  goodVG->setText(shared->getGoodVG());
  badVG->setText(shared->getBadVG());
  goodDP->setText(shared->getGoodDP());
  badDP->setText(shared->getBadDP());
  goodGO->setText(shared->getGoodGO());
  badGO->setText(shared->getBadGO());
}

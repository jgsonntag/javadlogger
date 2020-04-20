//
// Javadloggui class implementation
//

#include "javadloggui.h"
#include "utility.h"
#include "sats.h"

#include <math.h>
#include <qlabel.h>
#include <qhbox.h>
#include <qvgroupbox.h>
#include <qhgroupbox.h>
#include <qpopupmenu.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qgrid.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <qlayout.h>

#include <iostream>
using namespace std;

Sats *currentsats;


Javadloggui::Javadloggui()
{

  // Build the main menubar and make connections
  mainmenu = new QMenuBar(this);
  filemenu = new QPopupMenu(mainmenu);
  helpmenu = new QPopupMenu(mainmenu);
  filemenu->insertItem("Quit",qApp,SLOT(quit()));
  helpmenu->insertItem("About",this,SLOT(about()));
  mainmenu->insertItem("File",filemenu);
  mainmenu->insertItem("Help",helpmenu);

  // Build the tabs
  tabs = new QTabWidget(this);
  setupLoggingTab();
  setupGenInfoTab();
  setupSatInfoTab();
  setupNetworkTab();
  currentsats = new Sats();

  // Initialize variables
  wksold = 0.0;
  
}


Javadloggui::~Javadloggui()
{
  delete mainmenu;
  delete tabs;
  delete tab1;
  delete tab2;
  delete tab3;
}


void Javadloggui::setupLoggingTab()
{
  
  // Setup the layout manager for the tab
  tab1 = new QVBox(this);
    
  // Setup the sitename editor
  QHGroupBox *siteframe = new QHGroupBox("Sitename",tab1);
  sitename = new QLineEdit(siteframe);
  sitename->setMaxLength(4);
  new QLabel("Enter a 4-character site name",siteframe);

  // Setup the serial port and data rate selectors
  QHBox *portandrate = new QHBox(tab1);
  QHGroupBox *portframe = new QHGroupBox("Computer USB port",
                                         portandrate);
  portbox = new QComboBox(portframe);
  portbox->insertItem("/dev/ttyUSB0",0);
  portbox->insertItem("/dev/ttyUSB1",1);
  portbox->insertItem("/dev/ttyUSB2",2);
  portbox->insertItem("/dev/ttyUSB3",3);
  portbox->setCurrentItem(0);
  QHGroupBox *rateframe = new QHGroupBox("Data rate in sec",
                                         portandrate);
  ratebox = new QComboBox(rateframe);
  ratebox->insertItem("30",0);
  ratebox->insertItem("1",1);
  ratebox->insertItem("0.5",2);
  ratebox->insertItem("0.2",3);
  ratebox->insertItem("0.1",4);
  ratebox->setCurrentItem(4);
  rate = 100;
  connect(ratebox,SIGNAL(activated(int)),SLOT(setrate(int)));
  ratebox->setEnabled(false);
  
  // Set up the gps port and baud indicators
  QHGroupBox *rec = new QHGroupBox("Receiver info",tab1);
  recinfo = new QLabel(rec);
  
  // Set up the output file indicator
  filestat = new myFileStat(tab1);
  
  // Set up the computer filesystem usage indicator
  filesysbar = new myFSUsage(tab1);
  QTimer *fstimer = new QTimer();
  connect(fstimer,SIGNAL(timeout()),filesysbar,SLOT(update()));
  fstimer->start(100*1000); // 100 sec update rate

  // Set up the Javad filesystem usage indicator
  javadfilesysbar = new javadFSUsage(tab1);
  QTimer *jfstimer = new QTimer();
  cout << "point A" << endl;
  connect(jfstimer,SIGNAL(timeout()),javadfilesysbar,SLOT(update(shared)));
  //connect(jfstimer,SIGNAL(timeout()),javadfilesysbar,SLOT(update()));
  cout << "point B" << endl;
  jfstimer->start(10*1000); // 10 sec update rate
  cout << "point C" << endl;

  // Set up the start and stop data buttons
  QHBox *startstop = new QHBox(tab1);
  start = new QPushButton(tr("Start"),startstop);
  stop = new QPushButton(tr("Stop"),startstop);
  stop->setEnabled(false);
  connect(start,SIGNAL(clicked()),SLOT(startdata()));
  connect(stop,SIGNAL(clicked()),SLOT(stopdata()));
    
  // Register the layout manager with the tab widget
  tabs->addTab(tab1,"Logging");
  
}

void Javadloggui::setupGenInfoTab()
{
  
  // Setup the layout manager for the tab
  tab2 = new QVBox(this);

  // Set up the time field
  QHGroupBox *time = new QHGroupBox("Time",tab2);
  timeview = new QLabel(time);
  
  // Set up the position field
  QHGroupBox *pos = new QHGroupBox("Position",tab2);
  poslabel = new QLabel(pos);
  
  // Set up the velocity field
  QHGroupBox *vel = new QHGroupBox("Velocity",tab2);
  vellabel = new QLabel(vel);
  
  // Set up the stats table
  QHGroupBox *stats = new QHGroupBox("Record transmission statistics",tab2);
  statview = new Statview(stats);
  
  // Set up a timer to update everything in this tab
  gentimer = new QTimer();
  connect(gentimer,SIGNAL(timeout()),SLOT(genupdate()));
  
  // Register the layout manager with the tab widget
  tabs->addTab(tab2,"GenInfo");
  tabs->setTabEnabled(tab2,true);

}

void Javadloggui::setupSatInfoTab()
{

  // Setup the layout manager for the tab
  tab3 = new QVBox(this);
    
  // Setup the skyview
  QHGroupBox *skyview = new QHGroupBox("Sky View",tab3);
  sky = new Skyview(skyview);
  sky->setMinimumSize(240,240);
  skytimer = new QTimer();
  connect(skytimer,SIGNAL(timeout()),SLOT(satupdate()));
  
  // Setup the signal strength indicators
  QHGroupBox *sigstrength =
      new QHGroupBox("Signal Strengths (CA/P1/P2)",tab3);
  signal = new SigStrength(sigstrength);
  signal->setMinimumSize(284,90);
  
  // Register the layout manager with the tab widget
  tabs->addTab(tab3,"SatInfo");
  tabs->setTabEnabled(tab3,false);

}


void Javadloggui::setupNetworkTab()
{
  int i;

  // Setup the layout manager for the tab
  tab4 = new QVBox(this);
    
  //  Add the network server
  networkserver = new GenericServer(4050,4051,4052,4053,tab4);
  
  // Register the layout manager with the tab widget
  tabs->addTab(tab4,"Network");
  tabs->setTabEnabled(tab4,false);

}


void Javadloggui::genupdate()
{
  recinfo->setText(shared->getRecInfo());
  timeview->setText(shared->getTime());
  poslabel->setText(shared->getXYZ());
  vellabel->setText(shared->getVel());
  statview->update(shared);
  //filestat->updateSize(shared);
  
  // Send network messages if the info is new
  newmsg10 = shared->getMessage10();
  newmsg11 = shared->getMessage11();
  wksnew = atof(newmsg10.section(',',1,1));
  if (wksnew>wksold)
  {

    // Broadcat the 10 Hz messages
    networkserver->broadcast_thisB(newmsg10);
    networkserver->broadcast_thisD(newmsg11);

    //  Broadcast the 2 Hz messages if on even half-second
    if (fabs(fmod(wksnew*10.0,5)) < 0.01)
    {
      networkserver->broadcast_thisA(newmsg10);
      networkserver->broadcast_thisC(newmsg11);
    }
  }
  wksold = wksnew;

  /*newmsg10 = shared->getMessage10();
  wksnew = atof(newmsg10.section(',',1,1));
  if (oldmsg10.compare(newmsg10)!=0)
  {
    networkserver->broadcast_thisB(newmsg10);
    oldmsg10 = newmsg10;
    double dtemp1 = atof(newmsg10.section(',',1,1));
    if (fabs(fmod(dtemp1*10.0,5)) < 0.01)
      networkserver->broadcast_thisA(newmsg10);
  }
  newmsg11 = shared->getMessage11();
  if (oldmsg11.compare(newmsg11)!=0)
  {
    networkserver->broadcast_thisD(newmsg11);
    oldmsg11 = newmsg11;
    double dtemp1 = atof(newmsg11.section(',',2,2));
    //cout << dtemp1 << endl;
    double dtemp2 = dtemp1-int(dtemp1);
    if (fabs(fmod(dtemp2*10.0,5.0)) < 0.01)
      networkserver->broadcast_thisC(newmsg11);
      //cout << dtemp1 << endl;
  } */
  
}


void Javadloggui::satupdate()
{

  // Find satellite currently being tracked
  //currentsats->update(shared,rate);

  // Update the skyview
  //sky->updatesky();
  //signal->update();
  
}


void Javadloggui::startdata()
{

  // Check for a non-null sitename
  QString name = sitename->text();
  if (name.isEmpty())
  {
    QMessageBox::warning(this,"","You must enter a sitename",
               1,0,0);
    return;
  }
    
  // Start the timers
  gentimer->start((int)rate/10);
  skytimer->start((int)rate/2);

  //  Enable/disable appropriate widgets
  start->setEnabled(false);
  stop->setEnabled(true);
  ratebox->setEnabled(false);
  sitename->setEnabled(false);
  portbox->setEnabled(false);
  filemenu->setEnabled(false);
  tabs->setTabEnabled(tab2,true);
  //tabs->setTabEnabled(tab3,true);
  tabs->setTabEnabled(tab4,true);

  // Start the external serial logging process
  QString *stemp = new QString("/usr/local/bin/javad ");
  cout << "Port: " << QString::number(portbox->currentItem()) << '\n';
  stemp->append(QString::number(portbox->currentItem()));
  stemp->append(" start ");
  //stemp->append(sitename->text());
  //stemp->append(" ");
  //stemp->append(ratebox->currentText());
  cout << "Constructed command line: " << stemp->latin1() << '\n';
  system(stemp->latin1());

  // Initialize the shared memory
  shared = new JavShared(portbox->currentText());

  // Update filename and serial port fields
  //filestat->updateName(shared);
  //recport->update(shared);
  informrc = false;

}


void Javadloggui::stopdata()
{

  // Stop the timers
  gentimer->stop();
  skytimer->stop();

  //  Enable/disable appropriate widgets
  start->setEnabled(true);
  stop->setEnabled(false);
  //ratebox->setEnabled(true);
  sitename->setEnabled(true);
  portbox->setEnabled(true);
  filemenu->setEnabled(true);
  tabs->setTabEnabled(tab2,false);
  tabs->setTabEnabled(tab3,false);
  tabs->setTabEnabled(tab4,false);

  //  Unattach the shared memory
  delete shared;

  // Stop the external serial logging process
  QString *stemp = new QString("/usr/local/bin/javad ");
  stemp->append(QString::number(portbox->currentItem()));
  stemp->append(" stop");
  cout << "Constructed command line: " << stemp->latin1() << '\n';
  system(stemp->latin1());
  delete stemp;

}


void Javadloggui::setrate(int index)
{
  switch(index)
  {
    case 0:
      rate = 30000;
      break;
    case 1:
      rate = 1000;
      break;
    case 2:
      rate = 500;
      break;
    case 3:
      rate = 200;
      break;
    case 4:
      rate = 100;
      break;
  }
}


void Javadloggui::about()
{
  QMessageBox::about(this,"About Javadlogger",
                     "JAVADLOGGER V1.0\n"
		     "Linux Javad Data Logger\n"
		     "Author: John G. Sonntag\n"
		     "Released: 1 November 2013\n");
}


// Javadloggui class definition
//

#ifndef JAVADLOGGUI_H
#define JAVADLOGGUI_H

#include <stdlib.h>

#include <qvbox.h>
#include <qtabwidget.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qmenubar.h>
#include <qlineedit.h>
#include <qtimer.h>

#include "fsusage.h"
#include "javadfsusage.h"
#include "filestat.h"
#include "skyview.h"
#include "sigstrength.h"
#include "javshared.h"
#include "statview.h"
#include "recport.h"
#include "genericserver.h"


class Javadloggui : public QVBox
{

  Q_OBJECT

  public:
    Javadloggui();  // Constructor
    ~Javadloggui();  // Destructor

  private:
    void setupLoggingTab();
    void setupGenInfoTab();
    void setupSatInfoTab();
    void setupNetworkTab();
    QTabWidget *tabs;
    QVBox *tab1,*tab2,*tab3,*tab4;
    QPushButton *start;
    QPushButton *stop;
    QComboBox *portbox;
    QComboBox *ratebox;
    QMenuBar *mainmenu;
    QPopupMenu *filemenu;
    QPopupMenu *helpmenu;
    QLineEdit *sitename;
    QLabel *recinfo;
    myFSUsage *filesysbar;
    javadFSUsage *javadfilesysbar;
    myFileStat *filestat;
    myRecPort *recport;
    JavShared *shared;
    int rate;
    QTimer *gentimer;
    QTimer *skytimer;
    QLabel *poslabel;
    QLabel *vellabel;
    QLabel *timeview;
    Statview *statview;
    Skyview *sky;
    SigStrength *signal;
    bool informrc;
    GenericServer *networkserver;
    QString oldmsg10;
    QString newmsg10;
    QString oldmsg11;
    QString newmsg11;
    double wksnew;
    double wksold;
  
  private slots:
    void about();
    void startdata();
    void stopdata();
    void setrate(int index);
    void genupdate();
    void satupdate();
    
};

#endif // JAVADLOGGUI_H

#ifndef JAVSHARED_H
#define JAVSHARED_H

#include <sys/time.h>
#include <qstring.h>

#include "javacquire.h"

#define PROJ_ID 1
#define AE 6378137.0
#define FLAT (1.0/298.257223563)
#define PI (4.0*atan((double)(1.0)))
#define C 299792458.0


class JavShared
{

  public:
    JavShared(QString port);
    ~JavShared();
    
  public:
    QString getRecInfo();
    QString getTime();
    QString getXYZ();
    QString getVel();
    QString getMessage10();
    QString getMessage11();
    QString getGoodRE();
    QString getBadRE();
    QString getGoodGT();
    QString getBadGT();
    QString getGoodUO();
    QString getBadUO();
    QString getGoodRD();
    QString getBadRD();
    QString getGoodPG();
    QString getBadPG();
    QString getGoodVG();
    QString getBadVG();
    QString getGoodDP();
    QString getBadDP();
    QString getGoodGO();
    QString getBadGO();
    QString getOutfile();
    QString getGPSPort();
    QString getRType();
    timeval getsatupdate(int prn);
    float getaz(int prn);
    float getel(int prn);
    int getsnrca(int prn);
    int getsnrp1(int prn);
    int getsnrp2(int prn);
    unsigned char getflagca(int prn);
    unsigned char getflagp1(int prn);
    unsigned char getflagp2(int prn);
      
  private:
    QString stemp1;
    QString stemp2;
    QString stemp3;
    GEN *gen;
    double lat;
    double lon;
    double ht;
    double hdg;
    double spdkts;
    double rcfpm;
    QString converttime(double sow);
    void cart2geod(double,double,double,double*,double*,double*,
                   double,double);
    void ef2lh(double*,double*,double,double);
    
};

#endif // JAVSHARED_H

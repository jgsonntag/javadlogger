
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <math.h>
#include <stdlib.h>

#include "javshared.h"
#include "utility.h"


JavShared::JavShared(QString port)
{
  int shmid;
  key_t key;

  // Generate the key
  QString *path = new QString;
  path->append(port);
  key = ftok(path->latin1(),PROJ_ID);
  delete path;

  // Get shmid if shared memory segment already exists
  if ((shmid=shmget(key,sizeof(GEN),0666)) == -1)
  {
    cout << "Cannot access shared memory - exiting\n";
    exit(-1);
  }

  // Attach to the shared memory
  if ( (gen=(GEN *)shmat(shmid,0,0)) < (GEN *)0)
  {
    cout << "Cannot attach shared memory - exiting\n";
    exit(-1);
  }

}

JavShared::~JavShared()
{

  // Unattach the shared memory
  shmdt(gen);

}

QString JavShared::getRecInfo()
{
  stemp2 = "Receiver ID: ";
  stemp2.append(gen->rcvid);
  stemp2 += "\nBoard version: ";
  stemp2.append(gen->boardver);
  stemp2 += "\nFirmware version: ";
  stemp2.append(gen->firmver);
  return(stemp2);
}


QString JavShared::getTime()
{
  double sowgps = gen->wks;
  double sowutc = sowgps-(gen->leapsecs);
  if (sowutc<0.0)
    sowutc+=604800.0;
  stemp1 = "UTC: ";
  stemp1 += converttime(sowutc);
  stemp1 += "\nGPS: ";
  stemp1 += converttime(sowgps);
  stemp1 += "\nGPS-UTC leap seconds: ";
  stemp2.sprintf("%02d",gen->leapsecs);
  stemp1 += stemp2;
  return(stemp1);
}
  
QString JavShared::converttime(double sec)
{

  double sow = sec;
  int dow = (int)(sow/86400.0);
  switch (dow)
  {
    case 0:
      stemp2="Sun ";
      break;
    case 1:
      stemp2="Mon ";
      break;
    case 2:
      stemp2="Tue ";
      break;
    case 3:
      stemp2="Wed ";
      break;
    case 4:
      stemp2="Thu ";
      break;
    case 5:
      stemp2="Fri ";
      break;
    case 6:
      stemp2="Sat ";
      break;
  }
  sow -= dow*86400;
  int hr = (int)(sow/3600.0);
  sow -= hr*3600;
  int min = (int)(sow/60.0);
  sow -= min*60.0;
  stemp3.sprintf("%02d:%02d:%04.1lf",hr,min,sow);
  stemp2.append(stemp3);
  return(stemp2);
}

QString JavShared::getXYZ()
{
  //cart2geod(gen->nav.navx,gen->nav.navy,gen->nav.navz,
  //          &lat,&lon,&ht,AE,FLAT);
  lat = gen->lat;
  lon = gen->lon;
  ht = gen->ellht;
  lat *= 180.0/PI;
  lon *= 180.0/PI;
  stemp2.sprintf("Lat: %10.6lf deg\nLon: %10.6lf deg\n",lat,lon);
  stemp3.sprintf("Ellipsoid height:%8.2lf m   %8.2lf ft\n",ht,ht*3.28);
  stemp2.append(stemp3);
  stemp3.sprintf("Clock error: %.2lf us\n",
                  1.0e6*gen->gpsclockerror);
  stemp2.append(stemp3);
  stemp3.sprintf("HDOP: %5.2lf  VDOP: %5.2lf  TDOP: %5.2lf",
                  (double)(gen->hdop),(double)(gen->vdop),
                  (double)(gen->tdop));
  stemp2.append(stemp3);
  return(stemp2);
}

QString JavShared::getVel()
{
  //double ref[3],rlh[3];

  // Convert cartesian velocity to local-horizontal
  //ref[0] = gen->evel;
  //ref[1] = gen->nvel;
  //ref[2] = gen->hvel;
  //ef2lh(ref,rlh,lat,lon);

  //double speed = sqrt(rlh[0]*rlh[0]+rlh[1]*rlh[1]);
  double speed = sqrt(gen->evel*gen->evel+gen->nvel*gen->nvel);
  spdkts = speed*1.94;
  stemp2.sprintf("Speed: %5.1lf m/s   %5.1lf knots\n",
                 speed,spdkts);
  double theta1 = atan2(gen->nvel,gen->evel)*180.0/PI;
  //if (theta1<0.0) theta1+=360;
  hdg = 90.0 - theta1;
  if (hdg<0.0) hdg += 360.0;
  stemp3.sprintf("Track: %6.1lf deg\n",hdg);
  stemp2.append(stemp3);

  rcfpm = gen->hvel*196.8;
  stemp3.sprintf("Vertical speed: %6.1lf m/s   %7.1lf ft/min",
                  gen->hvel,rcfpm);
  stemp2.append(stemp3);
  return(stemp2);
}


QString JavShared::getMessage10()
{
  double sowgps = gen->wks;
  double sowutc = gen->wks-gen->leapsecs;
  if (sowutc<0.0)
    sowutc+=604800.0;
  double elon = lon;
  if (elon<0.0) elon+=360.0;
  stemp2.sprintf("10,%8.1lf,%10.6lf,%10.6lf,%8.2lf,",
                 sowutc,lat,elon,ht*3.28);
  stemp3.sprintf("%8.2lf,%6.1lf,%5.0lf",hdg,spdkts,rcfpm);
  stemp2.append(stemp3);
  return(stemp2);
}


QString JavShared::getMessage11()
{
  int year,month,day,hour,min;
  double sec;

  double sowgps = gen->wks;
  double sowutc = gen->wks-gen->leapsecs;
  int wknutc = gen->wkn;
  if (sowutc<0.0)
  {
    sowutc+=604800.0;
    --wknutc;
  }
  gps2kal(wknutc,sowutc,&year,&month,&day,&hour,&min,&sec);
  double elon = lon;
  if (elon<0.0) elon+=360.0;
  double sod = double(hour)*3600.0+double(min)*60.0+sec;
  stemp2.sprintf("11,%04d%02d%02d,%02d%02d%04.1lf,%10.6lf,%10.6lf,%8.2lf,",
                 year,month,day,hour,min,sec,lat,elon,ht*3.28);
  stemp3.sprintf("%8.2lf,%6.1lf,%5.0lf",hdg,spdkts,rcfpm);
  stemp2.append(stemp3);
  return(stemp2);
}


QString JavShared::getGoodRE()
{
  stemp2.setNum(gen->REgood);
  return(stemp2);
}


QString JavShared::getBadRE()
{
  return("n/a");
}

QString JavShared::getGoodGT()
{
  stemp2.setNum(gen->GTgood);
  return(stemp2);
}


QString JavShared::getBadGT()
{
  stemp2.setNum(gen->GTbad);
  return(stemp2);
}

QString JavShared::getGoodUO()
{
  stemp2.setNum(gen->UOgood);
  return(stemp2);
}

QString JavShared::getBadUO()
{
  stemp2.setNum(gen->UObad);
  return(stemp2);
}

QString JavShared::getGoodRD()
{
  stemp2.setNum(gen->RDgood);
  return(stemp2);
}

QString JavShared::getBadRD()
{
  stemp2.setNum(gen->RDbad);
  return(stemp2);
}

QString JavShared::getGoodPG()
{
  stemp2.setNum(gen->PGgood);
  return(stemp2);
}

QString JavShared::getBadPG()
{
  stemp2.setNum(gen->PGbad);
  return(stemp2);
}

QString JavShared::getGoodVG()
{
  stemp2.setNum(gen->VGgood);
  return(stemp2);
}

QString JavShared::getBadVG()
{
  stemp2.setNum(gen->VGbad);
  return(stemp2);
}

QString JavShared::getGoodDP()
{
  stemp2.setNum(gen->DPgood);
  return(stemp2);
}

QString JavShared::getBadDP()
{
  stemp2.setNum(gen->DPbad);
  return(stemp2);
}

QString JavShared::getGoodGO()
{
  stemp2.setNum(gen->GOgood);
  return(stemp2);
}

QString JavShared::getBadGO()
{
  stemp2.setNum(gen->GObad);
  return(stemp2);
}

QString JavShared::getOutfile()
{
  //stemp2 = gen->outfile;
  //return(stemp2);
  return("unknown");
}

QString JavShared::getRType()
{
  //stemp2 = gen->rtype;
  //return(stemp2);
  return("unknown");
}

QString JavShared::getGPSPort()
{
  //stemp2 = gen->gpsport;
  //return(stemp2);
  return("unknown");
}

timeval JavShared::getsatupdate(int prn)
{
  //return(gen->sat[prn].satupdate);
}

float JavShared::getaz(int prn)
{
  //return(gen->sat[prn].az);
  return(0.0);
}

float JavShared::getel(int prn)
{
  //return(gen->sat[prn].el);
  return(0.0);
}

int JavShared::getsnrca(int prn)
{
  //return(gen->sat[prn].snrca);
  return(0);
}

int JavShared::getsnrp1(int prn)
{
  //return(gen->sat[prn].snrp1);
  return(0);
}

int JavShared::getsnrp2(int prn)
{
  //return(gen->sat[prn].snrp2);
  return(0);
}

unsigned char JavShared::getflagca(int prn)
{
  //return(gen->sat[prn].flagca);
  return(0);
}

unsigned char JavShared::getflagp1(int prn)
{
  //return(gen->sat[prn].flagp1);
  return(0);
}

unsigned char JavShared::getflagp2(int prn)
{
  //return(gen->sat[prn].flagp2);
  return(0);
}

void JavShared::cart2geod(double x, double y, double z,
                          double *lat, double *lon, double *ht,
			  double ae, double flat)
{  
  double p,b,theta,esq,e1sq,ctheta,stheta,clat,slat,n;

  b = ae*(1.0-flat);
  esq = (ae*ae-b*b)/(ae*ae);
  e1sq = (ae*ae-b*b)/(b*b);
  p = sqrt(x*x+y*y);
  theta = atan((z*ae)/(p*b));
  ctheta = cos(theta);
  stheta = sin(theta);
  *lat = atan((z+e1sq*b*stheta*stheta*stheta)/
         (p-esq*ae*ctheta*ctheta*ctheta));
  *lon = atan2(y,x);
  if (*lon < 0.0 )
    *lon += 2.0*PI;
  clat = cos(*lat);
  slat = sin(*lat);
  n = ae / sqrt(1.0-esq*slat*slat);
  *ht = (p/clat) - n;
  
}

void JavShared::ef2lh(double *ref, double *rlh, 
                      double lat, double lon)
{  
  double clat,slat,clon,slon;

  // Compute sine and cosine matrix elements
  clat = cos(lat*PI/180.0);  slat = sin(lat*PI/180.0);
  clon = cos(lon*PI/180.0);  slon = sin(lon*PI/180.0);

  // Transform the vector
  rlh[0] = -slat*clon*ref[0] - slat*slon*ref[1] + clat*ref[2];
  rlh[1] =  slon*ref[0] - clon*ref[1];
  rlh[2] =  clat*clon*ref[0] + clat*slon*ref[1] + slat*ref[2];

}

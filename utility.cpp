#include <iostream>
using namespace std;
#include "utility.h"

#define YR0  1972
#define MJD0 41317

double timediff(timeval t1, timeval t2)
{
  double secs,usecs;
  
  secs = (double)(t1.tv_sec - t2.tv_sec);
  usecs = (double)(t1.tv_usec - t2.tv_usec);
  return(secs+usecs/1.0e6);
}


void gps2kal(int wkn, double wks,int *year,int *month,int *day,int *hour,int *min,double *sec)
{
  long mjd;
  double mjs;

  /*  Convert first to MJD, then to calendar format  */
  gps2jul(wkn,wks,&mjd,&mjs);
  jul2kal(mjd,mjs,year,month,day,hour,min,sec);

}


void gps2jul(int wkn,double wks,long *mjd,double *mjs)
{
  long djd,sjd;

  sjd = (long)(wks/86400.0);
  djd = (long)wkn*7 + sjd;
  *mjd = (long)44244 + djd;
  *mjs = wks - (double)sjd*86400.0;
  if (*mjs >= 86400.0)
  {
    *mjs -= 86400.0;
    *mjd += 1;
  }

}


void jul2kal(long mjd,double mjs,int *year,int *month,int *day,int *hour,int *min,double *sec)
{
  int nyrs,i;
  int dmonth[12];
  long ndays;
  double temp;

  /*  Define number of days per month  */
  dmonth[ 0] = 31;  dmonth[ 1] = 28;  dmonth[ 2] = 31;
  dmonth[ 3] = 30;  dmonth[ 4] = 31;  dmonth[ 5] = 30;
  dmonth[ 6] = 31;  dmonth[ 7] = 31;  dmonth[ 8] = 30;
  dmonth[ 9] = 31;  dmonth[10] = 30;  dmonth[11] = 31;

  /*  Compute year  */
  ndays = mjd - MJD0;
  nyrs = int(double(ndays)/365.25);
  *year = YR0 + nyrs;
  temp = double(*year)/4.0 - double((*year)/4);

  /*  Adjust for leap day and compute month and day  */
  if (temp == 0.0)
  {
    dmonth[1] = 29;
    ndays += 1;
  }
  ndays -= long(nyrs*365.25);
  i = 0;
  while(ndays > dmonth[i])
  {
    ndays -= dmonth[i];
    i += 1;
  }
  *month = i+1;
  *day = ndays;

  /*  Compute hour, minute and second  */
  *hour = int(mjs/3600.0);
  *min = int((mjs - (*hour)*3600.0)/60.0);
  *sec = mjs - (*hour)*3600.0 - (*min)*60.0;

}


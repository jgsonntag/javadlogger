#include <sys/time.h>

double timediff(timeval, timeval);
void gps2kal(int wkn,double wks,int *year,int *month,int *day,int *hour,int *min,double *sec);
void gps2jul(int wkn,double wks,long *mjd,double *mjs);
void jul2kal(long mjd,double mjs,int *year,int *month,int *day,int *hour,int *min,double *sec);

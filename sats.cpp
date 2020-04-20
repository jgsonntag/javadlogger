
#include <math.h>

#include "sats.h"
#include "utility.h"

Sats::Sats()
{
}

Sats::~Sats()
{
}

void Sats::update(JavShared *shared, int rate)
{
  int i;
  double dt,ratesec;
  timeval now;

  // Find SVs currently being tracked
  nsv = 0;
  gettimeofday(&now,NULL);
  ratesec = (double)rate/1000.0;
  for (i=1;i<32;i++)
  {
    dt = fabs(timediff(now,shared->getsatupdate(i)));
    if (dt<ratesec)
    {
      sv[nsv].prn = i;
      sv[nsv].az = shared->getaz(i);
      sv[nsv].el = shared->getel(i);
      sv[nsv].snrca = shared->getsnrca(i);
      sv[nsv].snrp1 = shared->getsnrp1(i);
      sv[nsv].snrp2 = shared->getsnrp2(i);
      sv[nsv].flagca = shared->getflagca(i);
      sv[nsv].flagp1 = shared->getflagp1(i);
      sv[nsv].flagp2 = shared->getflagp2(i);
      ++nsv;
    }
  }
}

int Sats::getnsv()
{
  return(nsv);
}

SV  *Sats::getsv(int i)
{
  return(&sv[i]);
}

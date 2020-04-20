#ifndef SATS_H
#define SATS_H

#include "javshared.h"

struct SV
{
  int prn;
  float az;
  float el;
  int snrca;
  int snrp1;
  int snrp2;
  unsigned char flagca;
  unsigned char flagp1;
  unsigned char flagp2;
};

class Sats
{

  public:
    Sats();
    ~Sats();
    void update(JavShared *, int);
    int getnsv();
    SV *getsv(int);

  private:
    SV sv[12];
    int nsv;
      
};

#endif // SATS_H

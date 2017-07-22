#include <iostream>

#define ll uint64_t
#define fi cin
#define fo cout
using namespace std;
ll m,x,a,b,c,d,p,kq;
ll tinhmu(ll a, ll k , ll p)
{   ll r,t,tg;
r=1; t=a; tg=k;
    while ( tg>0)
    { if (tg%2==1) r=r*t%p;
      t=t*t%p;
      tg=tg/2;
    }
    return r;
}

int main()
{  fi>>m>>x>>a>>b>>c>>d>>p;
ll t1;
   t1=a;
   x=x%p;
   kq=tinhmu(x,a,p);
   for (int i=1; i<=m-1; i++){
    ll t2;
     t2=(t1*b+c) % d;
     kq= (kq + tinhmu(x,t2,p))%p;
     t1=t2;
   }
 fo<<kq;
}


#include <bits/stdc++.h>
using namespace std;
ifstream fi("digit.inp");
ofstream fo("digit.out");
int64_t a,b,k;
int64_t mpl(int64_t c,int64_t d,int64_t p)
{ int64_t t;
  if (d==1) return (c%p);
  t=(mpl(c,d/2,p)*2)%p;
  if (d%2==0) return t;
  return ((t+c)%p);


}
int64_t tinhmu(int64_t x,int64_t y, int64_t p)
{  int64_t r,t,tg;
    r=1; t=x; tg=y;
   while (tg>0)
   { if (tg%2==1) r=mpl(r,t,p);
     t=mpl(t,t,p);
     tg=tg/2;
   }
   return r;

}
int main()
{  fi>>a>>b>>k;
   int64_t m;
   m=tinhmu(10,k-1,b);

   fo<<(uint64_t)(mpl(a%b,m,b)*10)/b<<endl;
   //fo<<mpl(9,15,7);
  // fo<<a%b;

}

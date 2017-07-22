#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define Base 1000000000+7
using namespace std;
int64_t aa,n;
int x[4],y[4],z[4];
 void mpz( uint64_t &x[],uint64_t y[4] ,int p)
{   uint64_t z[4];
    z[0]=x[0]*y[0]+x[1]*y[2];
    z[1]=x[0]*y[1]+x[1]*y[3];
    z[2]=x[2]*y[0]+x[3]*y[2];
    z[3]=x[2]*y[0]+x[3]*y[3];
    for (int i=0; i<=3; i++) x[i]=z[i] % p;
}
void tinhmod(int k,int p)
{
    int tg=k,r[4]={ 1,1,1,1 },t[4]= { 1,1,1,0 } ,z[4];
    while ( tg>0 ){
        if ( tg % 2 == 1 )  mpz(r,t,p);
        mpz( t,t,p );
        tg/=2;
    }
    cout<<r[0];
}
int main()
{   freopen("rateequa.inp","r",stdin);
    freopen("rateequa.out","w",stdout);
    cin>>aa>>n;
    tinhmod(n+2,Base);
}

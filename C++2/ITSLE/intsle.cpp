#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define maxn 100+10
using namespace std;
int a1,b1,c1,a2,b2,c2,n;
int gcd(int a,int b)
{   int m=a,n=b,r=1;
    while ( n != 0 ) {
        r = m % n;
        m=n;
        n=r;
    }
    if ( m==0 ) return 1;
    return m;
}
void xuly()
{
    int d,dx,dy;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    if ( c1 % gcd(a1,b1) != 0 ) { cout<<"NO SOLUTION"<<endl; return; }
    if ( c2 % gcd(a2,b2) != 0 ) { cout<<"NO SOLUTION"<<endl; return; }
    //if ( (float)c1 / c2 == (float) b1 / b2 && (float)c1 / c2 ==(float) a1 / a2  ) { cout<<"INFINITE"<<endl; return; }
    d=a1*b2-b1*a2;
    dx=c1*b2-c2*b1;
    dy=a1*c2-c1*a2;
    if ( d == 0 )
        if ( dx!=0 || dy!=0 ) { cout<<"NO SOLUTION"<<endl; return; }
        else  { cout<<"INFINITE"<<endl; return; }
    cout<<dx/d<<" "<<dy/d<<endl;
}
int main()
{   freopen("intsle.inp","r",stdin);
    freopen("intsle.out","w",stdout);
    cin>>n;
      while ( n-- ) {
          xuly();
      }
}

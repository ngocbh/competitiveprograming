#include <iostream>
#include <stdio.h>
using namespace std;
int a1,a2,a3,b1,b2,b3,res=0;
int main()
{   freopen("computer.inp","r",stdin);
    freopen("computer.out","w",stdout);
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    if ( a1 > b1 ) { a1 = a1-b1; res+=b1; b1=0; }
    else { b1=b1-a1; res+=a1; a1=0; }

    if ( a2 > b2 ) { a2 = a2 - b2;  res += b2; b2 = 0; }
    else { b2=b2-a2; res += a2; a2=0; }

    if (a1+a2>b3) { res+=b3; b3=0; }
    else { res+=a1+a2;  b3=b3-a1-a2; }

    if (b1+b2>a3 ) { res+=a3; a3=0; }
    else { res+=b1+b2; a3=a3-b1-b2; }

    res+=min(a3,b3);
    ///res+=min( a1+ a2 , b3 );
    ///res+=min( b1 + b2 , a3 );

    cout<<res;
}

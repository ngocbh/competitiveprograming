#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int k;
int64_t res,ress;
int64_t round(float x)
{   int64_t xx;
    xx= ( int64_t ) x;
    if ( xx == x ) return xx; else return xx+1;
}
int main()
{   freopen("brick.inp","r",stdin);
    freopen("brick.out","w",stdout);
    cin>>k;
    res=0;
    for (int64_t i=3; i<=k/4+1; i++) {
        int64_t a; float aa;
        if ( i*i-k<=0 ) a=1;
        else {
        aa = sqrt( i*i-k ) ;
        a = round( aa);
        }
        res += ( i-a )/2;
    }
    cout<<res;

}

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int64_t n,k,p;
int64_t round( int64_t a,int b )
{
    if ( a % b == 0 ) return a/b;
    else return ( int64_t ) a/b+1;
}
int main()
{   freopen("sale.inp","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>n>>k>>p;
    cout<<round( k*n,k+1 )*p;
}

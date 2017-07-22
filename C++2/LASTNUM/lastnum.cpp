#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
int64_t n,k;
int64_t res=0;
int main()
{   freopen("lastnum.inp","r",stdin);
    freopen("lastnum.out","w",stdout);
    cin>>n>>k;
    if (n%10==0) { cout<<n; return 0; }
    if ( n%10==5 ) { cout<<n+5; return 0; }
    if ( n % 2 == 0 ) {
        res+=(k/4) * 20;    res+=n;
        for (int i=1; i<=k%4; i++) {res+=(res%10); }    cout<<res;  return 0;
    }
    res+=n%10;  --k;    res+=(k/4) * 20;    res+=n;
    for (int i=1; i<=k%4; i++) res+=res%10; cout<<res;      return 0;


}

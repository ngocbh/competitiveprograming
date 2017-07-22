#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
const long N = 1000+10;
using namespace std;
int m,n,y,x,cs=1;
int h,c;
int64_t k;
int main()
{   //freopen("BIDA.inp","r",stdin);
    cin>>n>>m>>y>>x>>k;
    --y; --x; --n; --m;
    h = (y+k)/n;
    c = (x+k)/m;
    if ( h % 2 == 0 ) cout<<(y+k)%n +1 <<" "; else cout<<n - (y+k) % n +1 <<" ";
    if ( c % 2 == 0 ) cout<<(x+k)%m +1 ; else cout<<m - (x+k) % m +1;
}

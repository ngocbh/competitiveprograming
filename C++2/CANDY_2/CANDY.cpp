#include <bits/stdc++.h>
const long N = 1000 + 10;
using namespace std;

int n=1,ci,ii=0;
float sum,ssum,res,cc = N*N*N*10;
int a[N],b[N],f[N*N*10],ca[N],cs[N],csi[N];

bool cmp(int i ,int j)
{
    return a[i] < a[j];
}
float optimus(int n,float sum)
{   ++ii;
    if ( n == 0 ) return sum;
    if ( a[n] > sum ) return sum;
    float c,aa,bb;
    aa = optimus(n-1,sum) ;
    bb = optimus(n-1,sum - a[n]) ;
    c = min(aa,bb);
    if ( c < cc ) { cc = c; ci = n; }
    return c;
}
void trace(int n,int sum)
{
    if ( n == 0 ) return;
    if ( a[n] > sum ) return;
    float c,aa,bb;

    aa = optimus(n-1,sum) ;
    bb = optimus(n-1,sum - a[n]) ;

    if ( aa < bb )
        { ca[n] = true; trace(n-1,sum); }
    else
        { ca[n] = false; trace(n-1,sum-a[n]); }
}
int main()
{   freopen("CANDY.inp","r",stdin);
    //freopen("CANDY.out","w",stdout);
    while ( scanf("%d ", &a[n]) == 1) {sum += a[n]; cs[n] = n; ++n;   }

    --n; sum /= 2; ssum = sum;

    sort(cs+1,cs+n+1,cmp);
    for (int i = 1; i <= n; i++) b[i] = a[i];

    for (int i = 1; i <= n; i++) a[i] = b[cs[i]];

    for (int i = 1; i <= n; i++) csi[i] = cs[i];

    memset(ca,true,sizeof(ca));

    res = optimus(n,sum) ;

    cout<<ssum + res<<" "<<ssum - res<<" "<<res*2<<endl;

    trace(n,sum);

    for (int i = 1; i <= n; i++) if ( ca[i] ) cout<<b[i]<<" "; cout<<endl;

    for (int i = 1; i <= n; i++) if ( !ca[i] ) cout<<b[i]<<" "; cout<<endl;

    cout<<ii;
}

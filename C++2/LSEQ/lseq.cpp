#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#define maxn 1000000+100
#define oo 1000000
#define maxa 1000000000+7
using namespace std;
int n,a[3*maxn],b[3*maxn],maxx=0,f[3*maxn],f0[3*maxn],ca[3*maxn],res=0,minx=maxa;
int tim(int x)
{   if ( x<0 ) x=0;
     int l=1,r=maxx,res=1;
    while ( l<=r ) {
        int mid;
        mid=(l+r)/2;
        if ( f0[mid] < x ) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}

int main()
{   freopen("lseq.inp","r",stdin);
    freopen("lseq.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            a[i]+=oo;
            ++ca[a[i]];
            maxx=max( a[i],maxx );
            minx=min( a[i],minx );
    }
    for (int i=1; i<=minx-2; i++) f0[i]=-100;
    for (int i=minx; i<=maxx; i++)
        if ( ca[i]==0 ) f0[i]=f0[i-1]+1;
        else f0[i]=f0[i-1];

    ///==========
    for (int i=minx; i<=maxx; i++) {
        int u;

        u=tim(f0[i]-ca[oo]);
        if ( i >= oo && u<oo )
        u=tim(f0[i]-ca[oo]+1);
       // ++u;
        res=max(res,i-u);
       // if ( i==maxx ) res=max( res,i-u+1 );
        cout<<i<<" "<<u<<" "<<f0[i]<<" "<<f0[u]<<" "<<f0[i]-ca[oo]<<" "<<i-u<<" "<<endl;

    }
cout<<res<<endl;
//cout<<tim(a[1]);
//cout<<minx<<" "<<maxx;


}

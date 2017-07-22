#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>
#define maxn 100000+100
using namespace std;
int n,m,b[2*maxn],c[2*maxn],cc=0,f[5*maxn],res=0;
pair <int,int> a[maxn];
int tim(int x)
{
    int l=1,r=cc,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if ( b[mid]<=x ) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void roirachoa()
{
    sort(c+1,c+2*n+1);
    b[0]=-1;
    for (int i=1;i<=2*n; i++)
        if ( b[cc] != c[i] ) b[++cc]=c[i];

    for (int i=1; i<=n; i++){
        int m=0;
        m=tim( a[i].first );
        a[i].first=m;
        m=tim( a[i].second );
        a[i].second=m;
    }
   // for (int i=1; i<=n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;

}
void xuly()
{   memset(f,0,sizeof(f));
    sort(a+1,a+n+1);
    for (int i=1; i<=n; i++){
          f[a[i].second]=max(f[a[i].second], f[a[i].first] + 1 );
          res=max(res,f[a[i].second]);
    }
    cout<<res;
}
int main()
{
   //freopen("dominoes.inp","r",stdin);
    //freopen("dominoes.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
            scanf("%d %d",&a[i].first,&a[i].second);
            c[i*2-1]=a[i].first;
            c[i*2]=a[i].second;
    }
    roirachoa();
    xuly();
}

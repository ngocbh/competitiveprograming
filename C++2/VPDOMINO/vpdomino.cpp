#include <bits/stdc++.h>

using namespace std;
const long maxn=100000+100;
int n,m,f[2*maxn],ta[2*maxn],t[2*maxn],la=1,kq=0;
pair <int,int> a[maxn];
int tim(int x)
{
    int l=1,r=la,res=0;
    while (l<=r){
        int mid;
        mid=(l+r)/2;
        if (t[mid]<=x) res=mid,l=mid+1;
        else r=mid-1;
    }
    return res;
}
void khoitao()
{ freopen("vpdomino.inp","r",stdin);
  freopen("vpdomino.out","w",stdout);
  scanf("%d",&n);
  for (int i=1; i<=n; i++) {
        scanf("%d%d",&a[i].first,&a[i].second);
        ta[2*i-1]=a[i].first;
        ta[2*i]=a[i].second;
  }
  sort(ta+1,ta+2*n+1);
  t[0]=-1;
  for (int i=1; i<=2*n; i++)
    if ( ta[i] != t[la-1] ) {
        t[la]=ta[i];
        ++la;
    }
    --la;
  //for (int i=1; i<=la; i++) printf("%d ",t[i]); printf("\n");
  //int m;m=tim(0);printf("%d ",m);
}
void roirachoa()
{
    for (int i=1; i<=n; i++){
       int m;
       m=tim(a[i].first);
       a[i].first=m;
       m=tim(a[i].second);
       a[i].second=m;
    }
    //for (int i=1; i<=n; i++) printf("%d %d\n",a[i].first,a[i].second);
}
void xuly()
{   sort(a+1,a+n+1);
    //for (int i=1; i<=n; i++) printf("%d %d\n",a[i].first,a[i].second);
    memset(f,0,sizeof(f));
    for (int i=1; i<=n; i++)
        { f[a[i].second]=f[a[i].first]+1;
          if (f[a[i].second]>=kq) kq=f[a[i].second];
        }
    printf("%d",kq);
}
int main()
{ khoitao();
  roirachoa();
  xuly();
}

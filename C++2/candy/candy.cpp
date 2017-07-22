#include <bits/stdc++.h>

using namespace std;
int n,m,a[1000100],f[1000100],r[1000];
pair <int,int> f1[1000100];
int64_t kq=0;
int main()
{ freopen("candy.inp","r",stdin);
  freopen("candy.out","w",stdout);
  scanf("%d%d",&m,&n);
  for (int i=1; i<=n; i++)
     scanf("%d",&a[i]);
  for (int i=1; i<=n; i++) f[i]=f[i-1]+a[i];
  r[0]=1;
  for (int i=1; i<=n; i++)  ++r[f[i]%m];

  for (int i=1; i<=n; i++) {f1[i].first=f[i]%m; f1[i].second=i; }
  sort(f1+1,f1+n+1);
  f1[0].first=0; f1[0].second=0;
  f1[n+1].first=1001;
  for (int i=0; i<=m; i++) //printf("%d ",r[i]);
    kq=kq+((r[i]*(r[i]-1))/2);
int i=0,maxn=0,nhoi,nhoj;
  while (i<=n){
    int j=i+1;
    while (f1[j].first==f1[i].first) ++j;
  //  printf("%d %d\n",i,j);
    if (f1[j-1].second-f1[i].second>maxn) {
        maxn=f1[j-1].second-f1[i].second;
        nhoi=f1[i].second;
        nhoj=f1[j-1].second;
    }
    i=j;
  }
// for (int i=0; i<=n; i++ ) printf("%d ",f1[i].first); printf("\n");

// for (int i=0; i<=n; i++ ) printf("%d ",f1[i].second);
  printf("%d\n",kq);
  if (kq>0)
  printf("%d %d",nhoi+1,nhoj);


}

#include <bits/stdc++.h>

using namespace std;
int n,a[550][550],t;
int64_t f1[550][550],f2[550][550];
bool l[550][550];
void khoitao()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++ ) scanf("%d",&a[i][j]);
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(l,false,sizeof(l));
    for (int i=1; i<=n; i++) { l[i][0]=true; l[0][i]=true; }
    //=======================
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++)  f1[i][j]=f1[i-1][j]+a[i][j];
    //=======================
    for (int i=1; i<=n; i++)
      for (int j=1; j<=n; j++) f2[i][j]=f2[i][j-1]+a[i][j];

}
void xuly()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
           if ((f2[i][j] %2==0 && !l[i-1][j]) || (f1[i][j]%2==0 && !l[i][j-1])) l[i][j]=true;
   if (l[n][n]) printf("YES\n");
   else printf("NO\n");
}
int main()
{  freopen("parigame.inp","r",stdin);
   freopen("parigame.out","w",stdout);
   scanf("%d",&t);
   //printf("%d",t);
   for (int i=1; i<=t; i++){
      scanf("%d",&n);
      khoitao();
      xuly();
   }

  return 0;
}

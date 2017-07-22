#include <bits/stdc++.h>

using namespace std;
int n,m,ta,f[1550][1550],a[1550],b[1550],kq[1000],cs=0,cc;
void khoitao()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(f,0,sizeof(f));
}

void nhap()
{
    scanf("%d%d",&m,&n);
    for (int i=1; i<=m; i++) scanf("%d",&a[i]);
    for (int i=1; i<=n; i++) scanf("%d",&b[i]);
    cc=max(m,n);
}
void xuly()
{    int maxt,maxn=0;
    for (int j=1; j<=n; j++){
        maxt=0;
        for (int i=1; i<=m; i++){
            if (a[i]!=b[j]) f[i][j]=f[i][j-1];
            else f[i][j]=max(f[i][j-1],maxt+1);
            if (2*a[i]<=b[j]) maxt=max(maxt,f[i][j-1]);
            if (maxn<f[i][j]) maxn=f[i][j];
        }
    }
    ++cs;
   // printf("%d\n",l[m][n]);
    //for (int i=1; i<=m; i++){  for (int j=1; j<=n; j++)printf("%d ",f[i][j]);printf("\n");}
    kq[cs]=maxn;
}
int main()
{ //freopen("lcs2x.inp","r",stdin);
  //freopen("lcs2x.out","w",stdout);
  scanf("%d" , &ta);
     for (int i=1; i<=ta; i++ ){
         khoitao();
         nhap();
         xuly();
     }
     for (int i=1; i<=cs; i++)
         printf("%d\n",kq[i]);
}

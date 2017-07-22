#include <bits/stdc++.h>

using namespace std;
ifstream fi("shakesh.inp");
ofstream fo("shakesh.out");
int r,s,ta[55][55],f[55][55],kq=0;;
bool ca[55][55][55][55];
int sha(int i, int j)
{  int res=0;
    if (f[i-1][j-1]==1) ++res;
    if (f[i-1][j]==1) ++res;
    if (f[i-1][j+1]==1) ++res;
    if (f[i][j-1]==1) ++res;
    if (f[i][j+1]==1) ++res;
    if (f[i+1][j-1]==1) ++res;
    if (f[i+1][j]==1) ++res;
    if (f[i+1][j+1]==1) ++res;
 return res;
}
int xet(int i, int j)
{    int res=0;
  if (f[i][j]==0) return 0;
    if (f[i-1][j-1]==1&&ca[i][j][i-1][j-1]&&ca[i-1][j-1][i][j]) {++res;     ca[i][j][i-1][j-1]=false;ca[i-1][j-1][i][j]=false;}
    if (f[i-1][j]==1&&ca[i][j][i-1][j]&&ca[i-1][j][i][j]) {++res;         ca[i][j][i-1][j]=false;ca[i-1][j][i][j]=false;}
    if (f[i-1][j+1]==1&&ca[i][j][i-1][j+1]&&ca[i-1][j+1][i][j]) {++res;     ca[i][j][i-1][j+1]=false;ca[i-1][j+1][i][j]=false;}
    if (f[i][j-1]==1&&ca[i][j][i][j-1]&&ca[i][j-1][i][j]) {++res;         ca[i][j][i][j-1]=false;ca[i][j-1][i][j]=false;}
    if (f[i][j+1]==1&&ca[i][j][i][j+1]&&ca[i][j+1][i][j]) {++res;         ca[i][j][i][j+1]=false;ca[i][j+1][i][j]=false;}
    if (f[i+1][j-1]==1&&ca[i][j][i+1][j-1]&&ca[i+1][j-1][i][j]) {++res; ca[i][j][i+1][j-1]=false;ca[i+1][j-1][i][j]=false;}
    if (f[i+1][j]==1&&ca[i][j][i+1][j]&&ca[i+1][j][i][j]) {++res;         ca[i][j][i+1][j]=false;ca[i+1][j][i][j]=false;}
    if (f[i+1][j+1]==1&&ca[i][j][i+1][j+1]&&ca[i+1][j+1][i][j]) {++res;     ca[i][j][i+1][j+1]=false;ca[i+1][j+1][i][j]=false;}
    return res;

}
void khoitao()
{  int maxn=0,maxi=0,maxj=0;
   for (int i=1; i<=r; i++)
    for (int j=1; j<=s; j++)
     if (f[i][j]==0)
     {  int mi;
        mi=sha(i,j);
        if (mi >=maxn ) {maxn=mi; maxi=i; maxj=j; }
     }
        if (maxn>0)  f[maxi][maxj]=1;
     //===================
    //printf("%d %d %d\n",maxn,maxi,maxj);
   // fo<<maxn<<maxi<<maxj;
     //  printf("%d\n",sha(1,2));
}
void xuly()
{
    for (int i=1; i<=r; i++)
      for (int j=1 ; j<=s; j++)
    {  int mi;
       mi=xet(i,j);
       kq=kq+mi;
    }

}
int main()
{ //freopen("shakes.inp","r",stdin);
  //freopen("shakes.out","w",stdout);
 // scanf("%d%d",&r,&s);
 fi>>r>>s;
  memset(f,0,sizeof(f));
  memset(ca,true,sizeof(ca));
  for (int i=1; i<=r; i++)
     for (int j=1; j<=s; j++)
       { char x;
         fi>>x;
        // scanf("%c",&x);
          //printf("%c ",x);
         if (x=='.') f[i][j]=0;
         else
            if (x=='o') f[i][j]=1;
       }
  khoitao();
  xuly();
  //printf("%d",kq);
  fo<<kq<<endl;
 /* for (int i=1; i<=r; i++)
  {for (int j=1; j<=s; j++)
      // printf("%d ",f[i][j]);
       // printf("\n");
       fo<<f[i][j]<<" ";
       fo<<endl;
  }*/
 // fo<<xet(1,3)<<endl;
  //fo<<xet(2,1);
 // fo<<xet(2,2);

}

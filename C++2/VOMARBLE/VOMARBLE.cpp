#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <vector>
#define Base 1000000000+7
#define maxm 2000
#define maxk 1000+10
#define maxh 70
using namespace std;
int m,k,mtt[maxh][maxh],mk[maxk],lo[maxk],vt[maxk],kt[maxk],cs[maxk];
int64_t n;
pair <int,int> mak[maxk];
pair <int,int> sl[3*maxk];
int ctn(char c)
{
    if ( '0' <= c && c <='9' ) return (int) (c - '0');
    if ( 'a' <= c && c <='z' ) return (int) (c - 'a') + 10 ;
    if ( 'A' <= c && c <='Z' ) return (int) (c - 'A') + 36 ;
}
int64_t tinhmu(int x,int64_t y, int p)
{  int64_t r,t,tg;
    r=1; t=x; tg=y;
   while (tg>0)
   { if (tg%2==1) r=r*t%p;
     t=t*t%p;
     tg=tg/2;
   }
   return r;
}
void xulyk()
{
    for (int i=1; i<=k; i++) {

    }
}
void nhap()
{
    freopen("VOMARBLE.inp","r",stdin);
    freopen("VOMARBLE.out","w",stdout);
    memset(mtt,true,sizeof(mtt));
    cin>>n>>m>>k;
    for (int i=1; i<=m; i++) {
        char u,v;
        cin>>u>>v;
        mtt[ctn(u)][ctn(v)]=false;
        mtt[ctn(u)][ctn(v)]=false;
    }
    for (int i=1; i<=k; i++) {
        int loai,x;
        char y;
        cin>>loai>>x>>y;
        lo[i]=loai;
        vt[i]=x;
        kt[i]=ctn(y);
    }
    if ( k == 0 ) { xulym(); return; }
    if ( m == 0 ) { xulyk(); return; }
}
void sort1()
{
     for (int i=1; i<=k; i++) cs[i]=i;
    int lo1[maxk],vt1[maxk],kt1[maxk];
    for (int i=1; i<=k; i++) lo1[i]=lo[i];
    for (int i=1; i<=k; i++) vt1[i]=vt[i];
    for (int i=1; i<=k; i++) kt1[i]=kt[i];
    sort(cs+1,cs+k+1,cmp);
    for (int i=1; i<=k ;i++) lo[i]=lo1[cs[i]];
    for (int i=1; i<=k; i++) vt[i]=vt1[cs[i]];
    for (int i=1; i<=k; i++) kt[i]=kt1[cs[i]];
    for (int i=1; i<=k ;i++) cout<<kt[i]<<" ";
}
void xuly()
{

}
int main()
{   nhap();
    sort1();+

}

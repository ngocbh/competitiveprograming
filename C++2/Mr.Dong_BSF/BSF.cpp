#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define maxn 1000+10
#define oo 1000000000000000000
#define st first
#define nd second
using namespace std;
typedef pair <int,int> ii;
int64_t n,m,f[maxn],c[maxn],h[maxn],width[maxn],res=oo,x[maxn],fa[maxn][maxn],ff[maxn],cs[maxn];
int64_t hh[maxn],fl[maxn],cc[maxn];
ii book[maxn];
void ktkq()
{   int64_t fsd=0;
    bool ca[maxn];
    memset( ca,true,sizeof(ca) );
    memset(width,0,sizeof(width));
    int64_t ress=0,min1=oo;
    for (int i=1; i<=m; i++)
        if ( x[i]==1 ) fsd+=f[i];

    for (int i=1; i<=n; i++) { min1=oo;
        for (int j=1; j<=m; j++)
            if ( x[j]==1 && book[i].st <= h[j] ){
                 if ( book[i].nd * c[j] < min1 )
                    min1 = book[i].nd * c[j];

            }
        if ( min1 == oo ) return;
            ress+=min1;

    }
    ress+=fsd;

    res=min(ress,res);

}
void duyet(int i)
{
    if ( i > m ) { ktkq(); return; }
    for (int j=0; j <= 1; j++ ){
        x[i]=j;
        duyet(i+1);
    }
}
bool cmp(int64_t i,int64_t j)
{
    return h[i] < h[j];
}
int main()
{   freopen("BSF.inp","r",stdin);
    freopen("BSF.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>book[i].first>>book[i].second;
    for (int i=1; i<=m; i++) cin>>h[i]>>f[i]>>c[i];
    ///======================
  ///sub 1+2;  duyet(1);
  ///sub 3;
        ///== sort
    for (int i=1; i<=m; i++) cs[i]=i;

    for (int i=1; i<=m; i++) hh[i]=h[i];

    for (int i=1; i<=m; i++) fl[i]=f[i];

    for (int i=1; i<=m; i++) cc[i]=c[i];

    sort(book+1,book+n+1);

    sort(cs+1,cs+m+1,cmp);

    for (int i=1; i<=m; i++) h[i]=hh[cs[i]];

    for (int i=1; i<=m; i++) f[i]=fl[cs[i]];

    for (int i=1; i<=m; i++) c[i]=cc[cs[i]];

   //for (int i=1; i<=m; i++) cout<<h[i]<<" "<<f[i]<<" "<<c[i]<<endl;
    ///...khoitao

  for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)  fa[i][j]=oo;
  for (int i=0; i<=n; i++) fa[i][0]=0;
  ff[0]=0;
  for (int i=1; i<=n; i++) ff[i]=ff[i-1]+book[i].nd;
  //for (int i=1; i<=n; i++) cout<<ff[i]<<" ";
  ///...qhd;
  for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) if ( book[j].st <= h[i] ) {
            fa[i][j]=fa[i-1][j];
            for (int h=0; h<=j-1; h++) fa[i][j]=min( fa[i][j],fa[i-1][h] + f[i]+( ff[j]-ff[h] ) * c[i] );
        }
    cout<<fa[m][n];
}

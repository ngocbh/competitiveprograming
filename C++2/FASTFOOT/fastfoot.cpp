#include <iostream>
#include <stdio.h>
#define maxn 1500+10
using namespace std;
int n,a[maxn][maxn];
void khoitao()
{
    for (int i=1; i<=100; i++){
        for (int j=0; j<=24; j++){
            int ii=i,dem=0;
            while ( ii % prm[j]==0  ){
                ++dem;
                ii=ii/prm[j];
            }
            ptab[i][j]=dem;
        }
    }
}
void update_t(int k,int l,int r, int ii,int xx,int u,int v)
{
    t[ii][k*2]+=t[ii][k];
    t[ii][k*2+1]+=t[ii][k];
    f[ii][k]+=t[ii][k];
    t[ii][k]=0;
    if ( l>v || r<u ) return;
    if ( l>=u && r<=v ) {
        f[ii][k]+=xx;
        t[ii][k*2+1]+=xx;
        t[ii][k*2]+=xx;
    }
    int mid;
    mid=(l+r)/2;
    update_t(k*2,l,mid,ii,xx,u,v);
    update_t(k*2+1,mid+1,r,ii,xx,u,v);
    f[ii][k]=f[ii][k*2]+f[ii][k*2+1];
}
void visit(int k,int l,int r,int ii,int base,int u,int v)
{
        t[ii][k*2]+=t[ii][k];
        t[ii][k*2+1]+=t[ii][k];
        f[ii][k]+=t[ii][k];
        t[ii][k]=0;
        if ( l>v || r<u ) return;
        if ( l>=u && r<=v ) {
            if ( f[ii][k]>=0 )
            res*=pow(prm[ii],f[ii][k]);
            else res*=pow(prm[ii],1/f[ii][k]);
            res=res % base;
            return;
        }
        int mid;
        mid=(l+r)/2;
        visit(k*2,l,mid,ii,base,u,v);
        visit(k*2+1,mid+1,r,ii,base,u,v);
}
int main()
{   freopen("fastfoot.inp","r",stdin);
    freopen("fastfoot.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) scanf("%d",&a[i][j]);


}

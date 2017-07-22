#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#define maxn 50000+100
using namespace std;
int prm[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},ptab[101][25]={0},f[25][4*maxn],t[25][4*maxn];
int64_t res;
int l,r,x,n,m,base;
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
void xuly1()
{
    cin>>l>>r>>x;
    for (int i=0; i<=24; i++)
        if ( ptab[x][i] ){
        update_t(1,1,n,i,ptab[x][i],l,r);
    }
}
void xuly2()
{
    cin>>l>>r>>x;
    for (int i=0; i<=24; i++)
        if ( ptab[x][i] ){
        update_t(1,1,n,i,-ptab[x][i],l,r);
    }
}
void xuly0()
{res=1;
        cin>>l>>r>>base;
        for (int i=0; i<=24; i++){
        visit(1,1,n,i,base,l,r);

        }
        cout<<res<<endl;
}
int main()
{   freopen("evalsys.inp","r",stdin);
    freopen("evalsys.out","w",stdout);
    khoitao();
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        int loai;
        cin>>loai;
        if (loai==0) xuly0();
        if (loai==1) xuly1();
        if (loai==2) xuly2();
    }
cout<<n;

}

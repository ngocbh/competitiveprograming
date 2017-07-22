#include <iostream>
#include <stdio.h>
#include <cmath>
#define maxn 100000+100
#define maxa 1000000000+10
#define x first
#define y second
using namespace std;
int n;
typedef pair <int,int> ii;
ii a[5][maxn],c[5];
void sxep(int i)
{   ii aa,bb,cc,dd;
    int m,nho;
    ///timA;
    m=maxa;
    for (int j=1; j<=4; j++) if ( m > a[j][i].x ) m=a[j][i].x,nho=j;
    aa.x=a[nho][i].x; aa.y=a[nho][i].y;
    ///timB;
    m=maxa;
    for (int j=1; j<=4; j++) if ( m > a[j][i].y ) m=a[j][i].y,nho=j;
    bb.x=a[nho][i].x; bb.y=a[nho][i].y;
    ///timC;
    m=0;
    for (int j=1; j<=4; j++) if ( m < a[j][i].x ) m=a[j][i].x,nho=j;
    cc.x=a[nho][i].x; cc.y=a[nho][i].y;
    ///timD;
    m=0;
    for (int j=1; j<=4; j++) if ( m < a[j][i].y ) m=a[j][i].y,nho=j;
    dd.x=a[nho][i].x; dd.y=a[nho][i].y;
    ///============
    a[1][i].x=aa.x; a[1][i].y=aa.y;
    a[2][i].x=bb.x; a[2][i].y=bb.y;
    a[3][i].x=cc.x; a[3][i].y=cc.y;
    a[4][i].x=dd.x; a[4][i].y=dd.y;

}
void dthang(ii sa,ii sb,int &aa,int &bb,int &cc)
{
    int d1,d2;
    d1=sb.y-sa.y;
    d2=sa.x-sb.x;
    aa=d1;
    bb=d2;
    cc=sa.x*d1 + sa.y*d2;
}
float dodai(int x0,int y0,int aa,int bb,int cc )
{
    return ( abs( aa*x0+bb*y0+cc ) / sqrt( aa*aa + bb*bb ) );
}
void timgiao(int aa1,int bb1,int cc1,int aa2,int bb2,int cc2 ,int &x,int &y)
{
    int d,dx,dy;
    d=aa1*bb2-aa2*bb1;
    dx=cc1*bb2-cc2*bb1;
    dy=aa1*cc2-aa2*cc1;
    x=(int)dx/x;
    y=(int)dy/y;

}
void timab()
{ int x0,y0;
  int sa[5],sb[5],sc[5];
    x0=0;
    y0=0;
    float minn,maxx;
    minn=4*maxa;
    maxx=-4*maxa;
    for ( int i=1; i<=n; i++ ){
            int aa=0,bb=0,cc=0;
            dthang(a[1][i],a[2][i],aa,bb,cc);
            if ( dodai(x0,y0,aa,bb,cc) < minn ) {
                    minn= dodai(x0,y0,aa,bb,cc);
                    sa[1]=aa;
                    sb[1]=bb;
                    sc[1]=cc;
            }

            dthang(a[3][i],a[4][i],aa,bb,cc);
            if ( dodai(x0,y0,aa,bb,cc) < maxx ) {
                    maxx= dodai(x0,y0,aa,bb,cc);
                    sa[2]=aa;
                    sb[2]=bb;
                    sc[2]=cc;
            }
    }
    ///============================
    x0=-100;
    y0=100;
    minn=4*maxa;
    maxx=-4*maxa;
    for ( int i=1; i<=n; i++ ){
            int aa=0,bb=0,cc=0;
            dthang(a[2][i],a[3][i],aa,bb,cc);
            if ( dodai(x0,y0,aa,bb,cc) < minn ) {
                    minn= dodai(x0,y0,aa,bb,cc);
                    sa[3]=aa;
                    sb[3]=bb;
                    sc[3]=cc;
            }

            dthang(a[1][i],a[4][i],aa,bb,cc);
            if ( dodai(x0,y0,aa,bb,cc) < maxx ) {
                    maxx= dodai(x0,y0,aa,bb,cc);
                    sa[4]=aa;
                    sb[4]=bb;
                    sc[4]=cc;
            }
    }
    ///============================
    /*for (int i=1; i<=4; i++){
       if (i<3){
        timgiao(sa[i],sb[i],sc[i],sa[i+1],sb[i+1],sc[i+1],c[i].x,c[i].y);
       }
       else timgiao(sa[1],sb[1],sc[1],sa[4],sb[4],sc[4],c[i].x,c[i].y);
    }*/
    for (int i=1; i<=4; i++) cout<<sa[i]<<" "<<sb[i]<<" "<<sc[i]<<endl;

}
int main()
{   freopen("pinpos.inp","r",stdin);
    freopen("pinpos.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=4; j++)
        scanf("%d",&a[j][i].x,&a[j][i].y);
        sxep(i);
    }
    timab();

}

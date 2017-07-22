#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
#include <memory.h>
#define maxn 100000+100
#define maxx 1000+100
#define st first
#define nd second
using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int n,m,s,t,xs,ys,fs,xt,yt,ft,res,kq[maxn],ca[2][maxx][maxx],ta[maxn],d[2][maxx][maxx];
int a[2][maxx][maxx];
int round( int x )
{
    if ( sqrt(x) == ( int ) sqrt(x) ) return sqrt(x);
    else return sqrt(x)+1;

}
void khoitao()
{
     int nho=0,nhoo=0;
    for (int i=1; i<=n; i++) {
        nho=i*2-1;

        int ns=(nho+1)/2,ii=0;
        while ( ns ) {
          ++ii;++nhoo;
          a[1][i][(nho+1)/2-ns+1]=nhoo;
          if ( s==nhoo ) { xs=i; ys=(nho+1)/2-ns+1; fs=1; }
          if ( t==nhoo ) { xt=i; yt=(nho+1)/2-ns+1; ft=1; }
          if ( ii==nho ) break;
        ++ii;++nhoo;
          a[0][i][(nho+1)/2-ns+1]=nhoo;
          if ( s==nhoo ) { xs=i; ys=(nho+1)/2-ns+1; fs=0; }
          if ( t==nhoo ) { xt=i; yt=(nho+1)/2-ns+1; ft=0; }
          --ns;
        }
    }
}
void bfs()
{
     queue < iii > qe;
    memset(ca,true,sizeof(ca));
    memset(d,0,sizeof(d));

    qe.push( iii( fs,ii( xs,ys ) ) );
    ca[fs][xs][ys]=false;
    while ( !qe.empty() ){
        int u,v,uv;
        uv=qe.front().st;
        u=qe.front().nd.st;
        v=qe.front().nd.nd;
        qe.pop();
        int i=u,j=v;
      //  if ( u==xt && v==yt ) cout<<d[1][u][v]<<" "<<d[0][u][v]<<" ";
        if ( uv == 1 ){
            if ( ca[1-uv][i][j-1] && a[1-uv][i][j-1] )
                {qe.push( iii( 1-uv, ii( i,j-1 ) ) ); ca[1-uv][i][j-1]=false;
                ta[a[1-uv][i][j-1]]=a[uv][u][v];
                d[1-uv][i][j-1]=d[uv][u][v]+1;
                                 }
            if ( ca[1-uv][i][j] && a[1-uv][i][j] )
                {qe.push( iii( 1-uv, ii( i,j ) ) ); ca[1-uv][i][j]=false;
                ta[a[1-uv][i][j]]=a[uv][u][v];
                d[1-uv][i][j]=d[uv][u][v]+1;
                }
        } else {
            if ( ca[1-uv][i-1][j] && a[1-uv][i-1][j] )
                {qe.push( iii( 1-uv, ii( i-1,j ) ) ); ca[1-uv][i-1][j]=false;
                ta[a[1-uv][i-1][j]]=a[uv][u][v];
                d[1-uv][i-1][j]=d[uv][u][v]+1;
                 }
            if ( ca[1-uv][i][j] && a[1-uv][i][j] )
                {qe.push( iii( 1-uv, ii( i,j) ) ); ca[1-uv][i][j]=false;
                ta[a[1-uv][i][j]]=a[uv][u][v];
                d[1-uv][i][j]=d[uv][u][v]+1;

                }
            if ( ca[1-uv][i][j+1] && a[1-uv][i][j+1] )
                {qe.push( iii( 1-uv, ii( i,j+1 ) ) ); ca[1-uv][i][j+1]=false;
                ta[a[1-uv][i][j+1]]=a[uv][u][v];
                d[1-uv][i][j+1]=d[uv][u][v]+1;
                }

        }

    }
    cout<<d[ft][xt][yt]<<endl;
    res=0;
    while ( t!=s ){
        kq[++res] = t;
        t=ta[t];
    }
    kq[++res]=t;
    if ( m!=-1 )
    for (int i=res; i>=1; i--) cout<<kq[i]<<endl;
    else
        for (int i=1; i<=res; i++) cout<<kq[i]<<endl;
}
int main()
{   freopen("TRENET.inp","r",stdin);
    freopen("TRENET.out","w",stdout);
    cin>>s>>t;
    n=round(max( s,t ));
    m=max( s,t );
    if ( s<t ) {swap(s,t); m=-1; }
    khoitao();
    bfs();
}

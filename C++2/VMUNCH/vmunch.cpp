#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <queue>
#define maxn 100+10
using namespace std;
typedef pair <int,int> ii;
int n,m,a[maxn][maxn],xb,yb,ca[maxn][maxn],d[maxn][maxn];
int abs1(int x)
{
    if ( x>=0 ) return x;
    else return -x;
}
void bfs()
{   memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) d[i][j]=10000000;
    queue <ii> qe;
    qe.push( ii( xb,yb ) );
    a[1][1]=1;
    d[xb][yb]=0;
    while (!qe.empty() ){
        int u,v;
        u=qe.front().first;
        v=qe.front().second;
        ca[u][v]=false;
        qe.pop();
        for (int oi=-1; oi<=1; oi++)
            for (int oj=-1; oj<=1; oj++)
                if (abs1(oi)==1 && abs1(oj)==1  ) continue;
            else {
                if ( u>0 && u<=n && v>0 && v<=m && a[u+oi][v+oj]==1 && ca[u+oi][v+oj] ) {
                    ca[u+oi][v+oj]=false;
                    //d[u+oi][v+oj]=min(d[u+oi][v+oj],d[u][v]+1);
                    d[u+oi][v+oj]=d[u][v]+1;
                    qe.push( ii( u+oi,v+oj ) );
                }
            }
    }

}
int main()
{  // freopen("vmunch.inp","r",stdin);
   // freopen("vmunch.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            char c;
            cin>>c;
            if ( c=='.' ) a[i][j]=1;
            else
                if ( c=='*' ) a[i][j]=0;
                    else {
                        a[i][j]=0;
                        xb=i;
                        yb=j;
                    }
        }
    bfs();
   // for (int i=1; i<=n; i++){
   //     for (int j=1; j<=m; j++) if ( d[i][j]== 10000000 ) cout<<0<<" "; else cout<<d[i][j]<<" "; cout<<endl;
   // }
   cout<<d[1][1];

}

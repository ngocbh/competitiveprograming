#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <vector>
#define st first
#define nd second
#define maxn 10000+100
#define maxc 1000+10
#define maxx 100000000
using namespace std;
typedef pair <int,int> ii;
int n,s,c[maxn],ca[maxn][maxn],camax,res=1000000000,ress=0;
vector <ii> a[maxn],aa[maxn];
void dfs(int u)
{   int v;
    if ( camax>=n-1 ) { res=min( ress,res );  return;  }
    int vang=0;
    for (int i=0; v=a[u][i].nd; i++ ) {

       if ( ca[u][v] == 0 && ress+a[u][i].st < res ) {
                int nho=0;
                if ( ca[u][v] == 0 )  { ++camax; nho=1; }
                ++ca[u][v];
                ++ca[v][u];
                ress+=a[u][i].st;
                dfs( v );
                if ( nho == 1 ) --camax;
                --ca[u][v];
                --ca[v][u];
                ress-=a[u][i].st;
                vang=1;
       }
    }
    if ( vang == 0 ) {
        for (int i=0; v=a[u][i].nd; i++ ) {
            if ( ca[u][v] == 1 && ress+a[u][i].st < res ) {
                int nho=0;
                if ( ca[u][v] == 0 )  { ++camax; nho=1; }
                ++ca[u][v];
                ++ca[v][u];
                ress+=a[u][i].st;
                dfs( v );
                if ( nho == 1 ) --camax;
                --ca[u][v];
                --ca[v][u];
                ress-=a[u][i].st;
            }
        }
    }
}
int main()
{   freopen("one.inp","r",stdin);
    freopen("one.out","w",stdout);
    scanf("%d%d",&n,&s);
    for (int i=1; i<=n-1; i++) {
        int u,v,k;
        cin>>u>>v>>k;
        a[u].push_back( ii( k,v ) );
        a[v].push_back( ii( k,u ) );
        aa[u].push_back( ii( 0,v ) );
        aa[v].push_back( ii( 0,u ) );
    }   camax = 0 ;
  //  memset(ca,0,sizeof(ca));
    for (int i=1; i<=n ;i++) a[i].push_back( ii(0,0) );
    for (int i=1; i<=n ;i++) aa[i].push_back( ii(0,0) );
    dfs(s);
    cout<<res;
}

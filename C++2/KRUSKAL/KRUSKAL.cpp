#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <queue>
#define maxn 100000+10
#define cs second
#define gt first
using namespace std;
typedef pair <int,int> ii;
int n,m,a[maxn],lab[maxn],uu[2*maxn],vv[2*maxn],kk[2*maxn],goc,ca[maxn],kq[2*maxn];
bool ok=false;
priority_queue <ii,vector<ii>,greater<ii> > qu;
void init()
{
    for ( int i=1; i<=m; i++ ) qu.push( ii( kk[i],i ) );
    for (int i=1; i<=n; i++) lab[i]=-1;
    memset(kq,false,sizeof(kq));
}
int getroot(int x)
{
    while ( lab[x] > 0 ) x=lab[x];
    return x;
}
void unify(int u,int v)
{  int x;
    x=lab[u]+lab[v];
    if ( lab[u] > lab[v] ){
        lab[u]=v;
        lab[v]=x;
       // if ( x == -( n-1 ) ) {ok = true; goc=v; }
    }   else {
        lab[v]=u;
        lab[u]=x;
       // if ( x == -( n-1 ) ) {ok = true; goc=u; }
    }

}
void ikq()
{   int res=0;
    for (int i=1; i<=m; i++)
    if ( kq[i] ) {//cout<<uu[i]<<" "<<vv[i]<<" "<<kk[i]<<endl;
                  res+=kk[i];
    }
    cout<<res;

}
void kruskal()
{   int sc=0;
    while ( !qu.empty() ) {
        int u1,v1,k1,i;
        k1=qu.top().gt;
        i=qu.top().cs;
        qu.pop();
        u1 = getroot(uu[i]); v1 =getroot(vv[i]);
        if ( u1 == v1 ) continue;
        unify(u1,v1);
        kq[i]=true;
        ++sc;
        if ( sc==n-1 ) { ikq(); break; }
        //if ( ok ) { ikq(); break; }

    }
}
int main()
{   //freopen("KRUSKAL.inp","r",stdin);
    //freopen("KRUSKAL.out","w",stdout);;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>uu[i]>>vv[i]>>kk[i];
    init();
    kruskal();

}

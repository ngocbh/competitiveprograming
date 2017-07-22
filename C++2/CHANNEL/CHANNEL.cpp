#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <vector>
#define maxn 100000+10
using namespace std;
typedef pair <int,int> ii;
int n,m,p,res,ca[maxn];
bool ok=false;
vector <ii> a[maxn];
void dfs(int u)
{   if ( ok ) return;
    int v;
    v = a[u][0].second;
    if ( v == 0 ) { cout<<res; ok=true; return; }
    if ( ca[v] ) {
            ++res;
            ca[v]=false;
            dfs(v);
    } else {
            cout<<-1; ok = true; return;
    }

}
int main()
{   freopen("CHANNEL.inp","r",stdin);
    freopen("CHANNEL.out","w",stdout);
    cin>>n>>m>>p;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin>>u>>v;
        a[v].push_back( ii( i,u ) );
    }
    memset(ca,true,sizeof(ca));
    for (int i=0; i<=m; i++) a[i].push_back(ii(0,0));
    ca[p]=false;
    dfs(p);
}

#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#define maxn 100000+10
using namespace std;
int n,m,lab[maxn];
int64_t res;
int getroot(int v)
{
    while ( lab[v] > 0 ) v = lab[v];
    return v;
}
int64_t sum(int n) { return ( int64_t ) n*(n-1)/2; }
void unify(int u,int v)
{
    int x;
    x=lab[u]+lab[v];
    res -= sum(-lab[u]);
    res -= sum(-lab[v]);
    res += sum(-x);
    if ( lab[u] > lab[v] ){
        lab[u]=v;
        lab[v]=x;
    } else {
        lab[v]=u;
        lab[u]=x;
    }
}
int main()
{   freopen("PAIRS.inp","r",stdin);
    freopen("PAIRS.out","w",stdout);
    memset(lab,-1,sizeof(lab));
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        int u,v,u1,v1;
        cin>>u>>v;
        u1=getroot(u); v1=getroot(v);
        if ( u1==v1 ) {cout<<res<<endl; continue;}
        unify(u1,v1);
        cout<<res<<endl;
    }

}

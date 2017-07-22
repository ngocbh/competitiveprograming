#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>
#include <memory.h>
#include <vector>
#define maxn 100000+100
using namespace std;
int n,lab[maxn],a[maxn],ca[maxn],d[maxn];
vector <int> aa[maxn];
void creattree(int u)
{   int v=0;
    ca[u]=false;
        for (int i=0; i<=aa[u].size()-1; i++)
            {
                v=aa[u][i];
                if ( !ca[v] || v==0 ) continue;
                lab[v]=u;
                creattree(v);
            }
}
int getroot(int u)
{   int res=0;
    while ( lab[u]  > 0 ) {
        if ( d[u] ) ++res;
        u=lab[u];

    }
    if ( d[1] ) ++res;
    cout<<res<<endl;
}
int main()
{   freopen("SLOW.inp","r",stdin);
    freopen("SLOW.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n-1; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    for (int i=0; i<=n; i++) aa[i].push_back(0);
    ca[0]=false;
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    memset(ca,true,sizeof(ca));
    memset(d,0,sizeof(d));
    creattree(1);
    lab[1]=-1;
    for (int i=1; i<=n ;i++) {
       // cout<<a[i]<<endl;
        getroot(a[i]);
        d[a[i]]=1;
    }
}

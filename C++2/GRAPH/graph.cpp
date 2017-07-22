#include <iostream>
#include <stdio.h>
#include <vector>
#define maxn 100+10
using namespace std;
int n,m,ca[maxn],ta[maxn],la[maxn],res=0,kq[maxn][maxn];
vector <int> a[maxn];
void dfs(int u)
{   int v;
    ca[u]=false;
    for (int i=0; v=a[u][i]; i++ )
        if ( ca[v] ){
            ta[v]=u;
            dfs(v);
        }
}
void ttplt()
{   memset(ca,true,sizeof(ca));
    for (int i=1; i<=n; i++)
        if ( ca[i] ) {
            memset(ta,0,sizeof(ta));
            dfs(i);
            for (int i=1; i<=n; i++)
                if (  )
        }
}
int main()
{   freopen("graph.inp","r",stdin);
    freopen("graph.out","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        int u,v;
        cin>>u>>u;
        a[u].push_back(v);
        a[v].push_back(u);
        ++la[u];
        ++la[v];
    }
    ttplt();

}

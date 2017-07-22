/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, s, t, len, ans;
int num[N], low[N], f[N], ta[N], ca[N];
vector <int> a[N];

void dfs(int u,int c)
{
    if ( len ) return;
    ca[u] = false;

    if ( u == t ) {
        len = c;
        return;
    }
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        ta[v] = u;
        dfs(v,c+1);
    }
}

void trace()
{
    int u = t;
    int l = len+1;
    while ( u != s ) {
        num[u] = l--;
        u = ta[u];
    }
    num[s] = 1;
}

void visit(int u)
{
    low[u] = num[u];

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( num[v] ) {
                low[u] = max(low[u],num[v]);
                continue;
        }
        if ( low[v] )
                low[u] = max(low[u],low[v]);
        else
            {
                visit(v);
                low[u] = max(low[u],low[v]);
        }
    }
}

int main()
{
    //freopen("STNODE.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    memset(ca,true,sizeof ca);
    dfs(s,0);
    trace();

    fill(low,low+N,0);

    for (int i = 1; i <= n; i++) ta[num[i]] = i;

    for (int i = 1; i <= len; i++) {
        visit(ta[i]);
    }

    int Max = low[ta[1]];

    for (int i = 2; i <= len; i++) {
        if ( Max <= num[ta[i]] ) ++ans;
        Max = max(Max,low[ta[i]]);
    }

    cout << ans;
}

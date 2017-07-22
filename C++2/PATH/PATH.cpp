#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
ifstream fi("PATH.inp");
ofstream fo("PATH.out");

int n, m, s, t ;
int ca[N], ta[N], res[N];
vector <int> a[N];

void print_ans()
{
    int u = t;
    int ss = 0;
    while ( u != s ) {
        res[++ss] = u;
        u = ta[u];
    }
    res[++ss] = s;
    for (int i = ss; i > 0; i--) fo << res[i] << " ";
    exit(0);
}

void dfs(int u)
{
    if ( u == t ) {
        print_ans();
        return;
    }
    ca[u] = false;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        ta[v] = u;
        dfs(v);
    }
}

int main()
{
    //freopen("PATH.inp","r",stdin);
    //freopen("PATH.out","w",stdout);
    fi >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        fi >> u >> v;
        a[u].push_back(v);
    }

    memset(ca,true,sizeof ca);
    dfs(s);
}

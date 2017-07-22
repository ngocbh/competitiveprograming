#include <bits/stdc++.h>

const long N = 2000 + 10;
using namespace std;

int n, m , ss;
int num[N], low[N], in[N], ca[N], b[N][N], p[N], dev[N], first, last, sfirst, slast;

vector <int> a[N];
stack <int> s;

void dfs(int u)
{
    num[u] = ++num[0];
    low[u] = num[u];
    s.push(u);

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( in[v] ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
    }

    if ( low[u] >= num[u] ) {
        ++ss;
        p[ss] = u;
        while ( !s.empty() ) {
            int k = s.top();
            in[k] = ss;
            s.pop();
            if ( k == u ) {
                return;
            }
        }
    }
}

void visit(int u)
{
    ca[u] = false;
    for (int i = 1; i <= ss; i++) {
        if ( b[u][i] && ca[i] ) visit(i);
    }

    cout << "YES" << endl;
    cout << p[u] << " " << first << endl;
    exit(0);
}

int main()
{   freopen("NKONEARC.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
         if ( !in[i] )
            dfs(i);

    memset(b,false,sizeof b);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            int v = a[i][j];
            if ( in[v] != in[i] ) b[in[i]][in[v]] = true, dev[in[v]]++;
        }
    }

    memset(ca,true,sizeof ca);
    for (int i = 1; i <= ss; i++) {
        if ( dev[i] == 0 ) first = p[i], visit(i);
    }


}

#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
int n,q, ans = 0, res;
int ca[N], c[N][N];
bool ok;
vector <int> a[N];

void dfs(int u,int cc)
{
    ca[u] = false;
    if ( u == cc ) {
        res = ans;
        ok = true;
    }
    if ( ok ) return;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( ca[v] ) {
            ans = ans + c[u][v];
            dfs(v,cc);
            ans = ans - c[u][v];
        }
    }
}

int main()
{   //freopen("PWALK.inp","r",stdin);
    cin >> n >> q;
    for (int i = 1; i <= n-1; i++) {
        int u,v,cc;
        cin >> u >> v >> cc;
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] = cc;
        c[v][u] = cc;
    }

    for (int i = 1; i <= q; i++) {
        memset(ca,true,sizeof(ca));
        int u , v;
        cin >> u >> v;
        ans = 0; ok = false;
        dfs(u,v);
        cout << res << endl;
    }

}

#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n, m, ans;
int ca[N], low[N], num[N];
vector <int> a[N];
stack <int> s;

void dfs(int u)
{
    num[u] = ++num[0];
    low[u] = num[u];
    s.push(u);

    for (int i = 0; i < a[u].size(); i++){
        int v = a[u][i];
        if ( !ca[v] ) continue;
        if ( num[v] ) {
            low[u] = min(low[u] , num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u] , low[v]);
        }
    }

    if ( low[u] == num[u] ) {
    ++ans;
    while (true){
        int v = s.top();
        s.pop();
        ca[v] = false;
        if ( v == u ) return;
    }
    }
}
int main()
{   //freopen("TJALG.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    memset(num,0,sizeof num);
    memset(ca,true,sizeof ca);

    for (int i = 1; i <= n; i++)
        if ( ca[i] ) {
                dfs(i);
        }

    cout << ans;
}

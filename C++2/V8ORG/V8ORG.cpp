#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n, k, ans;
int ca[N], d[N];
vector <int> a[N];

void dfs(int u)
{
    ca[u] = false;

    for (int i = 0; i < a[u].size(); i++) {
        int v = 0;
        v = a[u][i];
        if ( !ca[v] ) continue;
        dfs(v);
        d[u] += d[v] + 1;
    }

    if ( d[u] >= k-1 ) {
            ++ans;
            d[u] = -1;
    }
}

int main()
{   //freopen("V8ORG.inp","r",stdin);
    cin >> k >> n;
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u;
        a[u].push_back(i);
    }

    memset(ca,true,sizeof ca);

    dfs(1);

    cout << ans;

}

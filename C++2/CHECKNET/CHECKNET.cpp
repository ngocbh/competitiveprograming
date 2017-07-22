#include <bits/stdc++.h>
 #define cin fi
 #define cout fo
const long N = 400000 + 10;
using namespace std;
 ifstream fi("CHECKNET.inp");
 ofstream fo("CHECKNET.out");
typedef pair<int,int> ii;

int n, m, ans;
int ca[N], low[N], num[N], cs[N] , PA[N];

vector <int> a[N];

bool cmp(int i,int j)
{
    return num[i] > num[j];
}

void dfs(int u,int pa)
{
    num[u] = ++num[0];
    low[u] = num[u];
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( v == pa ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
        }
    }
    if ( low[u] >= num[u] && u != 1 && u != 0 ) {
        ++ans;
    }
}

void bfs(int u,int pa)
{
    stack <ii> s;
    s.push(ii(u,pa));
    int c = 0;
    while ( !s.empty() ) {
        int u, pa;
        u = s.top().first;
        pa = s.top().second;
        s.pop();
        if ( num[u] ) continue;
        num[u] = ++c;
        low[u] = num[u];
        for (int i = a[u].size()-1; i >= 0; i--) {
            int v = a[u][i];
            if ( v == pa || v == 0 ) continue;
            if ( num[v] ) continue;
            PA[v] = u;
            s.push(ii(v,u));
        }
    }

    for (int i = 1; i <= n; i++) cs[i] = i;
    sort(cs+1,cs+n+1,cmp);
    for (int i = 1; i <= n; i++) {
        int u = cs[i];
        for (int j = 0; j < a[u].size(); j++) {
            int v = a[u][j];
            if ( PA[u] == v ) continue;
            if ( num[v] < num[u] ) {
                low[u] = min(low[u],num[v]);
            }
            else
                low[u] = min(low[u],low[v]);
        }
    }

    for (int i = 2; i <= n; i++) {
        if ( low[i] >= num[i] ) ++ans;
    }
}

int main()
{   //freopen("CHECKNET.inp","r",stdin);
    cin >> n >> m;
    int nn = n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if ( u == v ) continue;
        a[u].push_back(++n);
        a[n].push_back(u);
        a[n].push_back(v);
        a[v].push_back(n);
    }
    //num[0] = n+1;
    //dfs(1,0);
    bfs(1,0);

    cout << nn - 1 - ans;
}

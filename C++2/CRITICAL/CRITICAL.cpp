#include <bits/stdc++.h>

const long N = 2 * 10000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, total = 0, ans, c = 0;
LL low[N], num[N], pa[N], child[N], khop[N], ca[N], nov[N];

vector <int> a[N];
vector <int> f[N];
stack <int> s;

bool cmp(int i,int j)
{
    return khop[i] < khop[j];
}

void visit(int u)
{
    num[u] = ++num[0];
    low[u] = N;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( v == pa[u] ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            pa[v] = u;
            visit(v);
            low[u] = min(low[u],low[v]);
        }
    }

}

int dfs(int u)
{
    ++c;
    int cc = 1;
    ca[u] = false;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        if ( khop[v] && f[v].size() == 0 ) {
            f[v].push_back(c);
        }
        int x = dfs(v);
        if ( khop[u] ) {
            if ( num[u] > low[v] )
                f[u][0] += x;
            else f[u].push_back(x);
        }
        cc += x;

    }
    return cc;
}

int main()
{   freopen("CRITICAL.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if ( !num[i] )
            ++total , visit(i);
    }

    for (int i = 1; i <= n; i++) {
        int u = pa[i];
        if ( u > 0 ) child[u]++;
    }


    for (int i = 1; i <= n; i++) {
        int u = pa[i];
        if ( u > 0 && pa[u] > 0 && low[i] >= num[u] ) khop[u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if ( pa[i] == 0 && child[i] >= 2 ) khop[i] = 1;
    }

    LL ans = 0;
    memset(ca,true,sizeof ca);

    for (int i = 1; i <= n; i++) {
        if ( !ca[i] || khop[i] ) continue;
        c = 0;
        dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        LL sum = 0;
        //cout << i << " -> ";
        for (int j = 0; j < f[i].size(); j++) {
            ans += f[i][j]*sum, sum +=  f[i][j];
            //cout << f[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << ans; return 0;
    double res = (double) ans / n;
    cout << fixed << setprecision(2) << res;
}


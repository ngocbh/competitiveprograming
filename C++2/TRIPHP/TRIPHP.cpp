/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, ans;
int d[N], ca[N], pa[N], lv[N], P[21][N], num[N];
vector <int> a[N], dis[N];
int f[N];

void find_par(int u)
{
    ca[u] = false;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        pa[v] = u;
        P[0][v] = u;
        find_par(v);
    }
}

int level(int u) {
    if ( u == 1 ) return 1;
    if ( lv[u] ) return lv[u];
    lv[u] = level(pa[u]) + 1;
    return lv[u];
}

void init()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (int)sqrt(i); j++)
            if ( i % j == 0 ) {
                dis[i].push_back(j);
                dis[i].push_back(i/j);
            }
        //sort(dis[i].begin(),dis[i].end());
        f[i] = 1;
    }

    memset(ca,true,sizeof ca);
    find_par(1);
    pa[1] = 1;
    P[0][1] = 1;
    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= n; i++) {
                P[k][i] = P[k-1][P[k-1][i]];
        }
}

int lca(int x,int y)
{
    #define k(x) P[k][x]
    for (int k=20; k>=0; k--) if (level(k(x))>=level(y)) x=k(x);
    for (int k=20; k>=0; k--) if (level(k(y))>=level(x)) y=k(y);
    for (int k=20; k>=0; k--) if (k(x)!=k(y)) x=k(x), y=k(y);
    while (x!=y) { x=P[0][x], y=P[0][y]; }
    #undef k
    return x;
}



void dfs(int u,int c)
{
    num[u] = c;
    ca[u] = false;

    for (int i = 0; i < dis[u].size(); i++) {
        int v = dis[u][i];
        d[v] += c - num[lca(u,f[v])];
        f[v] = u;
    }

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        dfs(v,c+1);
    }
}

int main()
{
    //freopen("TRIPHP.inp","r",stdin);
    //freopen("TRIPHP.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    init();

    memset(ca,true,sizeof ca);

    dfs(1,0);
    for (int i = 1; i <= n; i++) cout << 2*d[i] << endl;

}

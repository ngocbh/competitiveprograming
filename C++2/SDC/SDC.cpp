#include <bits/stdc++.h>

const long N = 1000 + 10;
const long long oo = 1000000000 + 7;

using namespace std;
typedef pair<int,int> ii;

int n, m;
int d[N], c[N][N];
ii M[N*10];
vector <int> a[N];


void bellmanford()
{

    ///init;
    for (int i = 1; i <= n; i++) d[i] = 0;
    d[0] = 0;

    ///ford;

    for (int o = 1; o < n; o++) {
            bool ok = true;
            for (int i <= 1; i <= m; i++) {
                if ( d[v] < d[u] + c[u][v] ) {
                    d[v] = d[u] + c[u][v];
                }
            }
    }
}

int main()
{   freopen("SDC.inp","r",stdin);
    cin >> n >> m >> A >> B;

    for (int i = 1; i <= n; i++) {
        a[0].push_back(i);
        M[i] = ii(0,i);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, C;
        cin >> u >> v >> C;
        M[i+n] = ii(u,v);
        a[u].push_back(v);
        c[u][v] = c;
    }



    bellmanford();
}

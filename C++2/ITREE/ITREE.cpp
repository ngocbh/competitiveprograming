/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, t;
LL pa[N];
double f[N][3], c[N][N];
vector <int> child[N];

void dfs(int u,int x)
{
    if ( f[u][x] ) return;

    if ( child[u].size() == 0 ) {
        if ( x == 1 )  f[u][x] = oo*oo;
        else f[u][x] = 0;
        return;
    }
    double X = 0;
    for (int i = 0; i < child[u].size(); i++) {
        int v = child[u][i];

        dfs(v,0);
        double c1 = f[v][0], c2 = oo*oo;
        if ( x == 1 )
            dfs(v,1), c2 = f[v][1];

        if ( c1 + (x-0)*c[u][v] < c2 + (x-1)*c[u][v] ) {
            X += (x-0)*c[u][v] + c1;
        }
        else {
            X += (x-1)*c[u][v] + c2;
        }
    }

    f[u][x] = X;
    return;
}

int main()
{
    //freopen("ITREE.inp","r",stdin);
    //freopen("ITREE.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> t;
    while ( t-- ) {
        cin >> n;

        for (int i = 1; i <= n; i++) child[i].clear();
        memset(c,0,sizeof c);

        for (int i = 2; i <= n; i++) {
            int u;
            double uv;
            cin >> u >> uv;
            pa[i] = u;
            c[u][i] = uv;
            c[i][u] = uv;
            child[u].push_back(i);
        }

        memset(f,0,sizeof f);

        dfs(1,1);

        cout << fixed << setprecision(2) << f[1][1] << endl;
    }

}

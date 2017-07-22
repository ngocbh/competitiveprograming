/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 503;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k;
int a[N][N];
LL d[N][N], ca[N][N];
vector <int> b[N*N+2*N];

LL calc(int u,int v)
{
    if ( !ca[u][v] ) return d[u][v];
    if ( u == 1 && v == 1 ) return 1;
    LL X = 0;
    for (int i = 0; i < b[u*N+v].size(); i++) {
        int ui = b[u*N+v][i] / N;
        int vi = b[u*N+v][i] % N;
        X = (X + calc(ui,vi)) % MOD;
    }

    ca[u][v] = false;
    d[u][v] = X;
    return X;
}

int main()
{
    freopen("BM.inp","r",stdin);
    //freopen("BM.out","w",stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int ii = i + 1; ii <= n; ii++)
                for (int jj = j + 1; jj <= m; jj++)
                    if ( a[i][j] != a[ii][jj] ) {
                        b[ii*N + jj].push_back(i*N + j);
                    }

    memset(ca,true,sizeof ca);
    LL ans = calc(n,m);

    cout << ans;

}

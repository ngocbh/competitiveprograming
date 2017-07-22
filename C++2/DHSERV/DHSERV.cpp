/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, t, k;
LL a[N][N], c[N][N], ca[N];
vector <int> b;

void solve1()
{
    int x;
    scanf("%d ", &x);
    if ( ca[x] ) return;
    ca[x] = true;
    b.push_back(x);

    for (int i = 0; i < b.size(); i++)
            c[b[i]][x] = min(c[b[i]][x],a[b[i]][x]);
    for (int i = 0; i < b.size(); i++)
            c[x][b[i]] = min(c[x][b[i]],a[x][b[i]]);

    for (int i = 0; i < b.size(); i++)
        for (int j = 0; j < b.size(); j++) {
            c[b[i]][b[j]] = min(c[b[i]][b[j]], c[b[i]][x] + c[x][b[j]]);
        }

    for (int j = 0; j < b.size(); j++)
        for (int i = 0; i < b.size(); i++)
            c[x][b[i]] = min(c[x][b[i]], c[x][b[j]] + c[b[j]][b[i]]);

    for (int j = 0; j < b.size(); j++)
        for (int i = 0; i < b.size(); i++)
            c[b[i]][x] = min(c[b[i]][x], c[b[i]][b[j]] + c[b[j]][x]);
}

void solve2()
{
    int u, v;
    scanf("%d %d ", &u, &v);

    LL ans = min(a[u][v],c[u][v]);

    for (int i = 0; i < b.size(); i++)
        for (int j = 0; j < b.size(); j++) {
            ans = min(ans,a[u][b[i]] + c[b[i]][b[j]] + a[b[j]][v]);
        }

    if ( ans != oo*oo ) {
        printf("%lld\n", ans);
    }
    else printf("-1\n");

}

int main()
{
    //freopen("DHSERV.inp","r",stdin);
    //freopen("DHSERV.out","w",stdout);

    //ios::sync_with_stdio(0);

    scanf("%d %d %d ", &n, &m, &k);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( i != j )
                c[i][j] = a[i][j] = oo*oo;

    for (int i = 1; i <= m; i++) {
        int u, v;
        LL C;
        scanf("%d %d %lld",&u, &v, &C);
        a[u][v] = min(a[u][v],C);
    }

    memset(ca,false,sizeof ca);

    for (int i = 1; i <= k; i++) {
        int type;
        scanf("%d ", &type);
        if ( type == 1 ) solve1();
        else solve2();
    }

}

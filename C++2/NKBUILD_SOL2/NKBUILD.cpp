/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100 + 10;
const long long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k, q, P;
LL ans = 0;
int x[7], p[10], h[N];
LL c[N][N], f[N][N];

void floyd()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if ( h[i] )
                f[i][j] |=  (1<<h[i]);
            if ( h[j] )
                f[i][j] |=  (1<<h[j]);
        }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if ( c[i][j] > c[i][k] + c[k][j] ) {
                    c[i][j] = c[i][k] + c[k][j];
                    f[i][j] = f[i][k] | f[k][j];
                }

            }
}

LL calc(int x[],int q)
{
    //if ( k == 5 ) P = f[x[1]][x[2]];
    if ( q < 3 ) return c[x[1]][x[2]];

    if ( q > 2 ) {
        LL res = oo*oo;
        for (int i = 1; i <= n; i++) {
                LL X = 0;
                int Q = 0;
                for (int j = 1; j <= q; j++)
                    X += c[x[j]][i], Q |= f[x[j]][i];
                if ( res > X ) {
                    res = X;
                    P = Q;
                }

        }
        return res;
    }
}

void ktkq()
{

    LL res = calc(x,q);

    for (int i = 1; i <= k - (k==7); i++)
    {
        if ( ((P>>i) & 1) ) continue;
        LL X = oo*oo;
        for (int j = 1; j <= q; j++)
            X = min(X,c[x[j]][p[i]]);
        res += X;
    }

    if ( k == 7 && ((P>>k) & 1) == 0 ) {
        LL X = oo*oo;
        for (int i = 1; i <= k-1; i++)
            X = min(X,c[p[i]][p[k]]);
        for (int i = 1; i <= q; i++)
            X = min(X,c[x[i]][p[k]]);
        res += X;
    }
    //cout << res << endl;
    ans = min(ans,res);
}

void duyet(int i)
{
    if ( i > q ) {
        ktkq();
        return;
    }
    for (int j = x[i-1]+1; j <= n; j++)
    {
        x[i] = j;
        duyet(i+1);
    }
}

int main()
{   //freopen("NKBUILD.inp","r",stdin);
    //freopen("","w",stdout);

    cin >> n >> m >> k;

    if ( n == 1 ) {
        cout << 0 ;
        return 0;
    }

    if ( k % 2 == 0 || k == 7 )
        q = k/2;
    else q = k/2+1;

    for (int i = 1; i <= k; i++) cin >> p[i], h[p[i]] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( i != j )
                c[i][j] = oo*oo;

    LL u, v, C;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> C;
        c[u][v] = min(c[u][v],C);
        c[v][u] = min(c[u][v],C);
    }

    ans = oo*oo;

    floyd();
    duyet(1);

    cout << ans;
}


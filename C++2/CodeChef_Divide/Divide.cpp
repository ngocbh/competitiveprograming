#include <bits/stdc++.h>

using namespace std;

const long N = 1000 + 10;
const long long MOD = 1000 * 1000 * 1000 + 7;
typedef long long LL;
typedef pair <int,int> ii;

int n, t;
int a[N][N], c[N], col[N];
vector <int> b[N];

LL Pow(int a,int b,int MOD)
{
    LL t = a, tg = b, r = 1;
    while ( tg > 0 )
    {
        if ( tg % 2 == 1 ) r = ( r * t ) % MOD;
        t = ( t * t ) % MOD;
        tg /= 2;
    }
    return r;
}

LL calc(int a,int b)
{
    return min(Pow(a,b,MOD), Pow(b,a,MOD));
}

bool Is_Bipartite(int s)
{
    queue <ii> qu;
    qu.push(ii(s,1));
    while ( !qu.empty() )
    {
        int u = qu.front().first;
        int du = qu.front().second;
        qu.pop();

        for (int i = 0; i < b[u].size(); i++)
        {
            int v = b[u][i];
            if ( col[v] )
            {
                if ( col[v] == du ) return false;
                continue;
            }
            col[v] = 3 - du;
            qu.push(ii(v,col[v]));
        }
    }
    return true;
}

bool check(int x)
{
    for (int i = 1; i <= n; i++) b[i].clear();
    memset(col,0,sizeof col);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( a[i][j] > x && i != j )
                b[i].push_back(j);

    int res = true;

    for (int i = 1; i <= n; i++)
        if ( !col[i] ) res &= Is_Bipartite(i);

    return res;
}

int main()
{
    //freopen("Divide.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while ( t-- )
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> c[i];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = calc(c[i],c[j]);

        int l = 0, r = MOD, mid;
        while ( l + 1 < r )
        {
            int mid = ( l + r ) / 2;
            if ( !check(mid) ) l = mid;
            else r = mid;
        }

        cout << r << endl;
    }
}

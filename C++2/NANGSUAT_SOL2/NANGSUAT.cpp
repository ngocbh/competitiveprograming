#include <bits/stdc++.h>

using namespace std;

const long N = 1000 + 10;
const long oo = 1000*1000*1000 + 7;
typedef pair <int,int> ii;

int n, m;
int c[N][N], col[N], match[N], t;
vector <int> a[2*N];

int dfs(int u)
{
    if ( col[u] == t ) return 0;
    col[u] = t;

    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if ( !match[v] || dfs(match[v]) ) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

bool check(int x)
{
    memset(col,0,sizeof col);
    memset(match,0,sizeof match);

    for (int i = 1; i <= n; i++) a[i].clear();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( c[i][j] >= x )
                a[i].push_back(j);

    int res = 0;

    for (int u = 1; u <= n; u++)
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if ( !match[v] && !col[u] ) {
                col[u] = 1;
                match[v] = u;
                ++res;
                break;
            }
        }

    t = 1;
    for (int i = 1; i <= n; i++)
        if ( !col[i] ) ++t, res += dfs(i);

    if ( res == n ) return true;
    else return false;
}

int main()
{
    freopen("NANGSUAT.inp","r",stdin);
    freopen("NANGSUAT.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    int l = 1, r = oo, mid;
    while ( l + 1 < r )
    {
        mid = ( l + r ) / 2;
        if ( check(mid) ) l = mid;
        else r = mid;
    }

    cout << l;
}

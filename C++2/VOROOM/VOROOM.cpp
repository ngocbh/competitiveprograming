#include <bits/stdc++.h>

using namespace std;

const long N = 1000 + 10;
typedef pair <int,int> ii;

int n, t = 0, res, check_t;
int col[N] , match[N], check_col[N],check_match[N];

vector <int> a[N];

int dfs(int u)
{
    if ( col[u] == t ) return 0;
    col[u] = t;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !match[v] || dfs(match[v]) ) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int check_dfs(int u)
{
    if ( check_col[u] == check_t ) return 0;
    check_col[u] = check_t;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !check_match[v] || check_dfs(match[v]) ) {
            check_match[v] = u;
            return 1;
        }
    }
    return 0;
}

bool check()
{
    for (int i = 1; i <= n; i++) check_col[i] = col[i], check_match[i] = match[i];

    check_t = t;
    int check_res = res;
        ++check_t, check_res += check_dfs(n);

    if ( check_res >= n ) return true;
    return false;
}

int main()
{
    //freopen("VOROOM.inp","r",stdin);
    cin >> n;
    if ( n > 1000 ) { cout << 0; return 0; }
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].push_back(y);
        a[i].push_back(x);
    }

    ++n;

    res = 0;
    t = 0;
    memset(col,0,sizeof col);
    for (int i = 1; i < n; i++)
        if ( !col[i] ) ++t, res += dfs(i);

    if ( res < n-1 ) {
        cout << 0;
        return 0;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            a[n].clear();
            a[n].push_back(i);
            a[n].push_back(j);
            if ( check() ) ++ans;
        }

    cout << ans;
}

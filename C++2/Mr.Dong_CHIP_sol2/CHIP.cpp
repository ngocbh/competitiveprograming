#include <bits/stdc++.h>

using namespace std;

const long N = 50;

int n, m, k, t = 0;
int col[N*N], match[N*N];
char a[N][N];
vector <int> b[N*N*2];

void repair(int x,int y,int u,int v)
{
    for (int i = x; i <= u; i++)
        for (int j = y; j <= v; j++)
            a[i][j] = '#' + '.' - a[i][j];
}

bool check(int x,int y,int u,int v)
{
    for (int i = x; i <= u; i++)
        for (int j = y; j <= v; j++)
            if ( a[i][j] != '.' ) return false;
    return true;
}

int dfs(int u)
{
    if ( col[u] == t ) return 0;
    col[u] = t;

    for (int i = 0; i < b[u].size(); i++)
    {
        int v = b[u][i];
        if ( !match[v] || dfs(match[v]) ) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve(int x,int y,int ans)
{
    memset(col,0,sizeof col);
    memset(match,0,sizeof match);

    for (int i = 1; i < N*N*2; i++) b[i].clear();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ( (i % 2) == (j % 2) ) {
                if ( a[i][j] == '.' && a[i][j+1] == '.' )
                    b[(i-1)*N+j].push_back((i-1)*N+j+1);
                if ( a[i][j] == '.' && a[i+1][j] == '.' )
                    b[(i-1)*N+j].push_back(i*N+j);
            }
            else {
                if ( a[i][j] == '.' && a[i][j+1] == '.' )
                    b[(i-1)*N+j+1].push_back((i-1)*N+j);
                if ( a[i][j] == '.' && a[i+1][j] == '.' )
                    b[i*N+j].push_back((i-1)*N+j);
            }
        }

    int res = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if ( (i % 2) != (j % 2) ) continue;
            int u = (i-1) * N + j;
            for (int o = 0; o < b[u].size(); o++)
            {
                int v = b[u][o];
                if ( !match[v] && !col[u] )
                    {
                        match[v] = u;
                        col[u] = 1;
                        ++res;
                    }
            }
        }


    t = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( i % 2 == j % 2 && !col[(i-1)*N+j] )
                ++t, res += dfs((i-1)*N+j);

    if ( res >= k )
    {
        //cout << ans << endl;
        for (int ki = 1; ki <= n; ki++) for (int kj = 1; kj <= m; kj++) {
            if ( k == 0 ) exit(0);
            int i = (ki-1)*N+kj;
            if ( ki % 2 == kj % 2 ) continue;
            int v = match[i];
            if ( !v ) continue;
            int u = min(i,v);
            v = max(i,v);
            if ( u == v-1 )
                cout << u / N + 1<< " " << u % N << " " << 1 << endl;
            else
                cout << u / N + 1 << " " << u % N << " " << 2 << endl;
            --k;

        }
    }
}

int main()
{
    freopen("CHIP.inp","r",stdin);
    freopen("CHIP.out","w",stdout);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int Edge = min(m,n);
    for (int o = Edge; o >= 0; o--)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if ( !check(i,j,i+o,j+o) ) continue;
                repair(i,j,i+o,j+o);
                solve(i,j,o);
                repair(i,j,i+o,j+o);
            }
}

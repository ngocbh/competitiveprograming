#include <bits/stdc++.h>

using namespace std;

const long N = 3000 + 10;

typedef long long LL;
typedef pair <int,int> ii;

int n;
int ans = 0;
LL p[N][N], d[N], spa[N], ca[N], schild[N], f[N], dd[N][N];
vector <ii> a[N];
vector <int> b[N];

void calc(int u,int start,LL len,int pa)
{
    p[start][u] = len;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].first;
        if ( v == pa ) continue;
        calc(v,start,len+a[u][i].second,u);
    }
}

void dfs(int u)
{
    ca[u] = true;
    for (int i = 0; i < b[u].size(); i++)
    {
        int v = b[u][i];
        if ( ca[v] ) continue;
        dfs(v);
    }
}

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if ( !dd[u][v] && dd[u][k] == 1 && dd[k][v] == 1 ) dd[u][v] = 1 ;
}

int main()
{
    freopen("ALARM.inp","r",stdin);
    freopen("ALARM.out","w",stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }

    for (int i = 1; i <= n; i++)
        calc(i,i,0,0);

    memset(dd,0,sizeof dd);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( p[i][j] <= d[i] && i != j )
            {
                b[i].push_back(j), ++spa[j], ++schild[i], dd[i][j] = true;
            }

    floyd();

    for (int i = 1; i <= n; i++)
        if ( spa[i] == 0 && !ca[i] ) {
            ++ans;
            dfs(i);
            for (int j = 1; j <= n; j++)
                if ( f[j] == 1 && dd[i][j] )
                    f[j] = 0, --ans;

            f[i] = 1;
        }

    for (int i = 1; i <= n; i++)
        if ( !ca[i] && schild[i] )
        {
            dfs(i);
            ++ans;
            for (int j = 1; j <= n; j++)
                if ( f[j] == 1 && dd[i][j] )
                    f[j] = 0, --ans;

            f[i] = 1;
        }

    cout << ans;
}

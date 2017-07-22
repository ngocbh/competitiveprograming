#include <bits/stdc++.h>

using namespace std;

const long N = 1000 + 10;
typedef pair <int,int> ii;

int n, m, k, t, ans;

int col[N], ta[N], nov[N];
ii c[N], save_c[N];
bool ca[N][N];
vector <int> a[N];
vector <ii> res;

void Update(int s,int t)
{
    int u = s, v = t;
    while ( u != t ) {
        --nov[u], --nov[v], ++ans;
        res.push_back(ii(u,v));
        ca[u][v] = ca[v][u] = false;
        v = u, u = ta[u];
    }
}

void bfs(int s)
{
    stack <ii> qu;
    qu.push(ii(s,0));

    while ( !qu.empty() )
    {
        int u = qu.top().first;
        int pa = qu.top().second;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if ( !ca[u][v] ) continue;
            ca[u][v] = false;
            ca[v][u] = false;
            res.push_back(ii(u,v));
            qu.push(ii(v,u));
        }
    }
}

void BrowseGraph()
{
    memset(ca,true,sizeof ca);
    memset(col,true,sizeof col);
    ans = 0;
    res.clear();

    for (int i = 1; i <= n; i++)
        if ( nov[i] % 2 == 1 ) bfs(i);

    for (int i = 1; i <= n; i++)
        bfs(i);

    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << " ";
    cout << endl;
}

void CreateGraph()
{

    memset(nov,0,sizeof nov);

    while ( true ) {
        sort(c+1,c+n+1,greater<ii>() );
        if ( c[1].first == 0 ) break;
        int i = 1;
        for (int j = 1; j <= n; j++)
        {
            if ( i == j ) continue;
            if ( c[i].first == 0 ) break;
            if ( c[j].first == 0 ) continue;

            a[c[i].second].push_back(c[j].second);
            a[c[j].second].push_back(c[i].second);
            --c[i].first, --c[j].first; ++nov[c[i].second]; ++nov[c[j].second];
        }
        if ( c[1].first != 0 ) break;
    }

    if ( c[1].first != 0 ) { cout << -1 << endl; return; }
    BrowseGraph();
}

int main()
{
    freopen("FOOTBALL.inp","r",stdin);
    freopen("FOOTBALL.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while ( t-- )
    {
        cin >> n;
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i <= n; i++) cin >> c[i].first, c[i].second = i;
        CreateGraph();
    }

}

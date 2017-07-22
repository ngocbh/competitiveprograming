#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;
typedef pair <int,int> ii;

int n, m, k;
int col[N];
vector <int> a[N];

bool check(int s)
{
    queue <ii> qu;
    qu.push(ii(s,1));
    col[s] = 1;
    while ( !qu.empty() )
    {
        int u = qu.front().first;
        int du = qu.front().second;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if ( col[v] == du ) return false;
            if ( col[v] ) continue;
            col[v] = 3-du;
            qu.push(ii(v,col[v]));
        }
    }
    return true;
}

bool Is_Bipartite()
{
    bool res = true;
    for (int i = 1; i <= n; i++)
        if ( !col[i] ) res &= check(i);

    return res;
}

int main()
{
    freopen("BIPARTITE.inp","r",stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int u, v, c;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    cout << ( Is_Bipartite() ? "True" : "False" );

}

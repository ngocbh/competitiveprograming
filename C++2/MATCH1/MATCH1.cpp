#include  <bits/stdc++.h>

using namespace std;

const long N = 100 + 10;

int t, n, m;
int Assign[N], ca[N];
vector <int> a[N];

int visit(int u)
{
    if ( ca[u] != t )
        ca[u] = t;
    else return 0;

    for (int v, i = 0; i < a[u].size(); i++) {
        v = a[u][i];
        if ( !Assign[v] || visit(Assign[v]) )
        {
            Assign[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    //freopen("MATCH1.inp","r",stdin);
    cin >> n >> m;
    int u, v;
    while ( scanf("%d %d", &u, &v) > 0 )
        a[u].push_back(v);

    int ans = 0;
    for (int i = 1; i <= n; i++)
         {
            ++t;
            ans += visit(i);
        }

    cout << ans << endl;
    for (int i = 1; i <= m; i++) {
        int v = Assign[i];
        if ( v ) cout << v << " " << i << endl;
    }
}

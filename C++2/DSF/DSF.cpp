#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int n, m;
int f[N], ca[N];
vector <int> a[N];
int main()
{   freopen("DSF.inp","r",stdin);
    freopen("DSF.out","w",stdout);
    cin >> n >> m;

    int ans = n;
    for (int i = 1; i <= n; i++) f[i] = i, a[i].push_back(i);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if ( f[u] != f[v] ) {
            --ans;
            u = f[u];
            v = f[v];
            if ( a[u].size() < a[v].size() ) {
                while ( !a[u].empty() ) {
                    int x = a[u][a[u].size() - 1];
                    f[x] = v;
                    a[u].pop_back();
                    a[v].push_back(x);
                }
            } else {

                while ( !a[v].empty() ) {
                    int x = a[v][a[v].size() - 1];
                    f[x] = u;
                    a[v].pop_back();
                    a[u].push_back(x);
                }
            }
        }
        cout << ans << endl;
    }

}

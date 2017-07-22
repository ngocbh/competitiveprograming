#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef pair <int,int> ii;
int n;
int p[N];
vector <int> a[N];
ii b[N];

int main()
{   freopen("TERMITE.inp","r",stdin);
    freopen("TERMITE.out","w",stdout);
    cin >> n;

    for (int i = 1; i <= n-1; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);  ++b[u].first;
        a[v].push_back(u);  ++b[v].first;
        b[i].second = i;
    }

    b[n].second = n;

    sort(b+1,b+n+1);

    for (int i = 1; i <= n; i++) {
        int v = b[i].second;
        for (int j = 0; j < a[v].size(); j++) {
            int t = 0;
            t = a[v][j];
            if ( p[v] == 0 && p[t] != v ) p[v] = t;
        }
    }

    for (int i = 1; i <= n; i++) cout << p[i] << " ";



}

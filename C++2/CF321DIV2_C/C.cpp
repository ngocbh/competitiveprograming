#include <bits/stdc++.h>

const long N = 200000 + 10;
using namespace std;

int n, m;
int c[N], ca[N], f[N], cf[N];
vector <int> a[N];
int ans = 0, k = 1;

void dfs(int u)
{
    ca[u] = false;
    //cout << u << " " << k << " " << f[k] << " " << cf[k] << endl;
    if ( a[u].size() <= 1 && u != 1 ) {
        if ( cf[k] )
                ++ans;
        //cout << u << " " << ans << endl;
        return;
    }

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        ++k;
        if ( c[v] ) f[k] = f[k-1] + 1;
        else f[k] = 0;

        if ( f[k] > m ) cf[k] = false;
        else cf[k] = cf[k-1];

        dfs(v);
        --k;
    }
}

int main()
{   //freopen("C.inp","r",stdin);
    cin >> n >> m;
   // if ( m == 1 && n == 1 ) {
  //      cout << 1 ;
   //     return 0;
  //  }
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n-1; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(ca,true,sizeof ca);
    memset(cf,true,sizeof cf);
    if ( c[1] ) f[1] = 1;
    if ( f[1] > m ) cf[1] = false;
    dfs(1);
    cout << ans;
}

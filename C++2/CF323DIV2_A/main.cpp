#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, h[N], c[N];
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n;
    memset(h,true,sizeof h);
    memset(c,true,sizeof c);

    for (int i = 1; i <= n*n; i++) {
        int u,v;
        cin >> u >> v;
        if ( h[u] && c[v] ) {
            cout << i << " " ;
            h[u] = false;
            c[v] = false;
        }
    }

}

#include <bits/stdc++.h>

const long N = 400 + 10;
using namespace std;
int n;
int a[2*N][2*N], ca[2*N], res[2*N];
int main()
{  // freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 2; i <= 2*n; i++)
        for (int j = 1; j <= i-1; j++)
            cin >> a[i][j];
    n*=2;
    memset(ca,true,sizeof ca);
    for (int o = 1; o <= n/2; o++) {
        int _max = 0,u,v;
        for (int i = 2; i <= n; i++)
            if ( ca[i] )
                for (int j = 1; j <= i-1; j++)
                    if ( ca[j] ){
                        if ( _max < a[i][j] ) {
                            _max = a[i][j];
                            u = i;
                            v = j;
                        }
                    }

        res[u] = v;
        res[v] = u;
        ca[u] = false;
        ca[v] = false;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}

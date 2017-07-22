#include <bits/stdc++.h>

const long N = 500 + 10;
using namespace std;
int n;
int g[N*N], a[N];
map <int,int> M;
int main()
{   //freopen("C.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n*n; i++){
        cin >> g[i];
        M[g[i]]++;
    }

    sort(g+1,g+n*n+1);
    int sz = 0;
    for (int i = n*n; i > 0; i--)   {
        if ( sz >= n ) break;
        if ( M[g[i]] ) a[++sz] = g[i], --M[g[i]];
        else continue;
        for (int j = 1; j <= sz; j++) {
            int x = __gcd(g[i],a[j]);
            if ( M[x] >= 2 ) M[x] -= 2;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";


}

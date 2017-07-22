#include <bits/stdc++.h>

const long N = 6*10000 + 10;
using namespace std;
typedef long long LL;
struct data{
    int u, c, du;
};

int n, t;
int a[N], ca[N], b[N], f[N];

void solve()
{
    queue <data> qu;
    for (int i = 1; i <= n; i++) qu.push(data{a[i],i,1});

    while ( !qu.empty() ) {
        int u, du, c;
        u = qu.front().u;
        du = qu.front().du;
        c = qu.front().c;
        qu.pop();

        if ( u == 1 ) {
            cout << du << endl;
            return;
        }

        for (int i = c + 1; i <= n; i++) {
            qu.push(data{__gcd(u,a[i]),i,du+1});
        }
    }
}

int main()
{   //freopen("RTF.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        memset(ca,true,sizeof ca);
        cin >> n;
        int M = 0;
        for (int i = 1; i <= n; i++) cin >> b[i];
        sort(b+1,b+n+1);

        int nn = 0;
        for (int i = 1; i <= n; i++) {
            if ( !ca[i] ) continue;
            a[++nn] = b[i];
            for (int j = i+1; j <= n; j++)
                if ( b[j] % b[i] == 0 ) ca[j] = false;
        }

        if ( n == 1 ) {
            cout << 1 << endl;
            continue;
        }

        int g = a[1];
        for (int i = 2; i <= n; i++) g = __gcd(g,a[i]);
        for (int i = 1; i <= n; i++) a[i] = a[i] / g;

        solve();

    }

}

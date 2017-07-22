#include <bits/stdc++.h>

using namespace std;

const long N = 30 + 1;

int t, n, m, l, r, b, z, ans;
int x[N*N], a[N][N], kt[N];

bool check(int x,int y)
{
    if ( x == 3 && ( y == 4 || y == 2 ) ) return true;
    if ( x == 4 && ( y == 4 || y == 2 ) ) return true;
    return false;
}

void ktkq()
{
    ans = max(ans,a[0][0]);
}

void duyet(int i)
{
    if ( i > n*m ) {
        ktkq();
        return;
    }
    for (int u, v, j = 0; j < 5; j++) {
        u = i / m + 1 - (i%m == 0);
        v = i % m + (i%m == 0)*m;
        a[u][v] = j;
        if ( check(a[u][v-1],a[u][v]) ) continue;
        ++kt[j];
        a[0][0] += ( j > 0 );
        if ( kt[j] <= x[j] )
            duyet(i+1);
        --kt[j];
        a[0][0] -= ( j > 0 );
    }
}

int main()
{
    //freopen("CHCINEMA.inp","r",stdin);
    //freopen("CHCINEMA.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while ( t-- )
    {
        cin >> n >> m >> x[1] >> x[2] >> x[3] >> x[4];
        ans = 0; x[0] = (int) 1e9 + 7;
        duyet(1);
        cout << ans << endl;
    }
}

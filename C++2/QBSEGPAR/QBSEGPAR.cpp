#include <bits/stdc++.h>

const long N = 15000 + 10;
const long long oo = 1000000000 + 10;
using namespace std;
int n, k;
int a[N];
int f_max[N], f_min[N], sum[N];

bool check(int m)
{
        for (int i = 1; i <= n; i++) f_max[i] = -oo, f_min[i] = oo;

        for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++)
                    if ( sum[i] - sum[j] <= m ) {
                            f_max[i] = max(f_max[i] , f_max[j] + 1);
                            f_min[i] = min(f_min[i] , f_min[j] + 1);
                    }
        }

        if ( f_min[n] <= k && k <= f_max[n] )
            return false;
        else return true;
}

int main()
{   //freopen("QBSEGPAR.inp","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i-1] + a[i];;

    int l = -oo, r = oo, m, ans = 0;

    while ( l <= r ) {
        m = ( l + r ) / 2;
        if ( check(m) ) {
            l = m+1;
        }
        else r = m-1, ans = m;
    }

    cout << ans;
}

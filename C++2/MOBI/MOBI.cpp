#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
int n, k;
ii a[N];
LL sum[N];

int main()
{   //freopen("MOBI.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
    }

    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i].second;

    LL ans = 0;
    int ci = 1;

    for (int i = 1; i <= n; i++) {
        while ( a[i].first - a[ci].first > 2*k ) ++ci;
        ans = max(ans , sum[i] - sum[ci-1]);
    }

    cout << ans ;
}

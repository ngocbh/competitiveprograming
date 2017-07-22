#include <bits/stdc++.h>

const long N = 100000 + 10;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;
LL n, c1, c2, m, ca[N];
ii a[N] , p[2*N];

int main()
{
    freopen("BESTBUY.inp","r",stdin);
    freopen("BESTBUY.out","w",stdout);
    cin >> c1 >> c2;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;

    cin >> m;
    for (int i = 1; i <=  m; i++) {
        int u,v;
        cin >> u >> v;
        p[i*2-1].first = u;
        p[i*2-1].second = -i;
        p[i*2].first = v;
        p[i*2].second = i;
    }
    sort(a+1,a+n+1);
    sort(p+1,p+2*m+1);

    int k = 1;
    LL sum = 0;
    int ans = 0;
    for (int i = 1; i <= 2*m; i++) {
        while ( a[k].first <= p[i].first && k <= n ) sum += a[k].second, ++k;
        if ( p[i].second < 0 && sum >= c1 ) sum-=c1,ca[-p[i].second] = 1, ++ans;
        if ( p[i].second > 0 && sum >= c2 && ca[p[i].second] == 0 ) sum-=c2,++ans;
    }
    cout << ans;
}

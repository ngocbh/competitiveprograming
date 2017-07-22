#include <bits/stdc++.h>

const long N = 100000 + 10;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;
LL n, k, ans = 0, res = 0;
ii a[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        LL x;
        cin >> x;
        a[i].first = 10 - (x % 10);
        a[i].second = x;
    }
    sort(a+1,a+n+1);

    for (int i = 1; i <= n; i++) {
        if ( a[i].second < 100 ) {
            LL u = a[i].first, v = a[i].second;
            a[i].first = a[i].first - min(k,a[i].first);
            a[i].second = a[i].second + min(k,u);
            k = k - min(k,u);
            res += 100 - a[i].second;
            ans += a[i].second / 10;
        }
        else ans += a[i].second / 10;
    }

    ans += min(k,res) / 10;
    cout << ans;
}

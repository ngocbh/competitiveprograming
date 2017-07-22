#include <bits/stdc++.h>

using namespace std;

const long N = 2*100000 + 10;
typedef pair <int,int> ii;

int n;
ii a[N];

int main()
{
    //freopen("B.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;

    sort(a+1,a+n+1);

    long long ans = 0;

    for (int i = 2; i <= n; i++)
        ans += abs(a[i].second - a[i-1].second);
    cout << ans;
}

#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, ans;
int f[N];
ii a[N];

bool cmp(ii A,ii B)
{
    return ( ( A.second < B.second ) || ( A.second == B.second && A.first < B.first ) ) ;
}

int main()
{
    freopen("DOAN2.inp","r",stdin);
    freopen("DOAN2.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first += 10000;
        a[i].second += 10000;
    }

    sort(a+1,a+n+1,cmp);

    for (int i = 1; i <= n; i++) {
        f[a[i].second] = max(f[a[i].second],f[a[i].first] + 1);
        ans = max(ans, f[a[i].second]);
    }

    cout << ans;

}

///O(n);

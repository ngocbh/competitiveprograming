#include <bits/stdc++.h>

using namespace std;

const long N = 220000 + 10;
const long long oo = 1000000000 + 7;
typedef pair <long long,int> ii;
typedef long long LL;

int n, m;
int a[N];
LL f[N], sum[N], _minf[2][N];

int main()
{
    freopen("STGAME.inp","r",stdin);
    freopen("STGAME.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i];

    long long ans = 0;
    deque <ii> qu;
    qu.push_back(ii(0*1LL,0));

    for (int i = 1; i <= n; i++)
    {
        while ( !qu.empty() && qu.front().second < i - m ) qu.pop_front();
        f[i] = sum[i] - qu.front().first;
        while ( !qu.empty() && qu.back().first >= f[i] ) qu.pop_back();

        qu.push_back(ii(f[i],i));
    }
    ans = f[n];

    cout << ans;
}

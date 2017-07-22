#include <bits/stdc++.h>
#define cin fi
#define cout fo

using namespace std;

ifstream fi("MINE.inp");
ofstream fo("MINE.out");

typedef long long LL;
typedef pair <LL,int> ii;
const long long inf = 1000000000 + 7;
const long N = 100000 + 10;

int n, m;
LL ans;
LL x[N], g[N], r[N];
vector <ii> a;

int Binary_Search(LL c)
{
    int l = 1, r = m, ans = m+1;
    while ( l <= r ) {
        int mid = (l + r) / 2;
        if ( a[mid].first <= c ) {
            r = mid - 1;
            ans = a[mid].second;
        }
        else l = mid + 1;
    }
    if ( ans == m+1 ) return -1;
    return ans;
}

int main()
{
    //freopen("MINE.inp","r",stdin);
    //freopen("MINE.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> g[i] >> r[i], g[i] = g[i-1] + g[i], r[i] = r[i-1] + r[i];

    LL sum = 0, prev = 0;
    a.push_back(ii(inf*4 , 0));
    m = 0;

    for (int i = 1; i <= n; i++) {
        prev = Binary_Search(r[i] - x[i]);

        if ( prev == -1 ) prev = i;
        ans = max(ans,g[i] - g[prev-1] );

        if ( a.back().first > r[i-1] - x[i] ) a.push_back(ii(r[i-1] - x[i],i)), ++m;
    }
    cout << ans;
}

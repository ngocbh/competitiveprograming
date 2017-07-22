#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, ans;
int f[N], b[N], ta[N], cs[N];
ii a[N];

bool cmp(ii A,ii B)
{
    return ( ( A.second < B.second ) || ( A.second == B.second && A.first < B.first ) ) ;
}

bool cmp_cs(int i,int j)
{
    return ( ( a[i].second < a[j].second ) || ( a[i].second == a[j].second && a[i].first < a[j].first ) ) ;
}

int main()
{
    freopen("DOAN3.inp","r",stdin);
    freopen("DOAN3.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first += 10000;
        a[i].second += 10000;
        cs[i] = i;
    }

    sort(cs+1,cs+n+1,cmp_cs);
    sort(a+1,a+n+1,cmp);
    int cur = 0;

    for (int i = 1; i <= n; i++) {
        if ( f[a[i].second] < f[a[i].first] + 1 ) {
            ta[i] = b[a[i].first];
            b[a[i].second] = i;
            f[a[i].second] = f[a[i].first] + 1;
        }
        if ( ans < f[a[i].second] ) {
            ans = f[a[i].second];
            cur = i;
        }
    }

    vector <int> res;

    while ( cur != 0 ) {
        res.push_back(cur);
        cur = ta[cur];
    }

    cout << ans << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << cs[res[i]] << endl;
    }
}

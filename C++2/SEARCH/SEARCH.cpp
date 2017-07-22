#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

int n, m, p, Nod_a, a[N], b[N], c[N],ca[N], cb[N], cc[N], visit[N];
vector <int> d;

int main()
{
    //freopen("SEARCH.inp","r",stdin);
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if ( !ca[a[i]] )
        {
            ++Nod_a;
            ca[a[i]]++;
        }
    }

    for (int i = 1; i <= m; i++) cin >> b[i], cb[b[i]] = 1;
    for (int i = 1; i <= p; i++) cin >> c[i];

    d.push_back(0);
    for (int i = 1; i <= p; i++) if ( cb[c[i]] ) d.push_back(i);
    d.push_back(p+1);

    int ans = 0, Nod_c;

    for (int i = 1; i < d.size(); i++) {
        int l = d[i-1], r = d[i];
        Nod_c = 0;

        for (int j = l+1; j <= r-1; j++) {
            ++cc[c[j]];
            if ( cc[c[j]] >= ca[c[j]] && !visit[c[j]] && ca[c[j]] ) ++Nod_c, visit[c[j]] = 1;
        }

        if ( Nod_c == Nod_a ) ans = max(ans,r-l-1);
        for (int j = l+1; j <= r-1; j++)
            cc[c[j]] = visit[c[j]] = 0;
    }

    cout << ans;
}

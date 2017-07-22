#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

const long N = 100000 + 10;
const long long oo = 2*1000*1000*1000 + 7;
typedef pair <long long ,long long> ii;

struct data
{
    ii p[5];
};

int n;
data a[N];

long long calc(long long x,long long y, data A)
{
    long long res = oo;
    for (int i = 1; i <= 4; i++)
        res = min(res, max(abs(A.p[i].X - x),abs(A.p[i].Y - y)) );
    return res;
}

void solve()
{
    long long max_x = -oo ,min_x = oo ,max_y = -oo ,min_y = oo;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 4; j++) {
            max_x = max(max_x,a[i].p[j].X);
            min_x = min(min_x,a[i].p[j].X);
            max_y = max(max_y,a[i].p[j].Y);
            min_y = min(min_y,a[i].p[j].Y);
        }

    long long x = (max_x + min_x)/2 , y = (max_y + min_y)/2;

    long long ans = oo, res;
    res = 0;
    for (int i = 1; i <= n; i++)
        {
            res = max(res,calc(x,y,a[i]) );
        }
    ans = min(ans,res);

    cout << ans << "\n";
}

int main()
{
    freopen("VOMOVREC.inp","r",stdin);
    //freopen("VOMOVREC.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << (12345678^69) << endl;

    for (int i = 1; i <= n; i++) {
        long long x, y, u, v;
        cin >> x >> y >> u >> v;
        ++x, ++y;
        a[i].p[1] = ii(x,v), a[i].p[2] = ii(u,v), a[i].p[3] = ii(u,y), a[i].p[4] = ii(x,y);
    }

    if ( n > 0 ) {
        solve();
        return 0;
    }

    long long ans = oo;
    for (int i = -100; i <= 101; i++)
        for (int j = -100; j <= 101; j++)
        {
            long long res = 0;
            for (int o = 1; o <= n; o++) {
                res = max(res,calc(i,j,a[o]));
                //if ( res == 8 ) cout << i << " " << j << " " << o << endl;
            }
            ans = min(ans, res);
        }

    cout << ans;
}

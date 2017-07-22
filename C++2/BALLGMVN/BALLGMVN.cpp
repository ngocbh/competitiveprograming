#include <bits/stdc++.h>

const long N = 1000 + 10;
const long long oo = 10000000 + 7;
using namespace std;
typedef pair <int,int> point;

int n;
point px[N], pd[N];
point d[N];
map<point,int> dxd[N],ddx[N];

point slope(point A,point B)
{
    int dx = A.first - B.first;
    int dy = A.second - B.second;
    int k = __gcd(dx,dy);
    return point(dx / k, dy / k);
}

int main()
{   //freopen("BALLGMVN.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> px[i].first >> px[i].second;
    }

    for (int i = 1; i <= n; i++) {
        cin >> pd[i].first >> pd[i].second;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                dxd[i][slope(px[i],pd[j])] = j+n;
                ddx[i][slope(pd[i],px[j])] = j;
            }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ( i == j ) continue;
            point x;
            x = slope(px[i],px[j]);
            if ( dxd[i][x] ) {
                cout << i << " " << j << " " << dxd[i][x];
                return 0;
            }
            x = slope(pd[i],pd[j]);
            if ( ddx[i][x] ) {
                cout << i+n << " " << j+n << " " << ddx[i][x];
                return 0;
            }
        }
    }
    cout << -1;

}

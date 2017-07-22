#include <bits/stdc++.h>

const long N = 2000 + 10;
const double Eps = 1e-6;
using namespace std;
typedef long long LL;
struct point{
    int x,y;
};

struct data{
    int h, c;
    double val;
};

LL n;
point p[N];
point d[N];

point slope(point A,point B)
{
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    int k = __gcd(dx,dy);
    point c;
    c.x = dx / k;
    c.y = dy / k;
    return c;
}

bool cmp(point A,point B)
{
    return (A.x < B.x || (A.x == B.x && A.y < B.y));
}

LL calc(int n)
{
    return (1LL*n*(n-1)) / 2;
}

int main()
{   //freopen("QBPOINT.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            d[j] = slope(p[i],p[j]);
        }

        sort(d+1,d+i,cmp);
        d[i].x = 100000000 + 7;
        d[i].y = 100000000 + 7;
        int ci = 1;

        for (int j = 1; j <= i; j++) {
                if ( d[j].x == d[ci].x && d[j].y == d[ci].y ) continue;
                    ans += calc(j-ci);
                    ci = j;
        }
    }

    cout << ans;

}

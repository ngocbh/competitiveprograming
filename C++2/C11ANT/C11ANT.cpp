#include <bits/stdc++.h>

const long N = 100000 + 10;
const long long oo = 100000000 * 2  + 10;
using namespace std;
struct data{
    double a,v;
};
int n, sz = 0;
double t[N];
data a[N], aa[N],bb[N];

bool cmp(data A,data B)
{
    return A.a < B.a;
}

void solve(data a[N],data b[N])
{
    int prevm = 1,cur, prevn = n;
    double prevtn = 0,prevtm = 0;
    for (int o = 1; o <= 100; o++) {
        double tmax = oo*oo, tmin = oo*oo;
        for (int i = 1; i <= n; i++)
            if ( a[i].v < 0 && a[prevm].v != a[i].v ){
                if ( tmin > (a[i].a-a[prevm].a) / (a[prevm].v - a[i].v) && (a[i].a-a[prevm].a) / (a[prevm].v - a[i].v) > 0 ) {
                    tmin = (a[i].a-a[prevm].a) / (a[prevm].v - a[i].v);
                    cur = i;
                }
            }

        if ( tmin != oo*oo ) {
        prevm = cur;
        t[++sz] = tmin + prevtm;
        prevtm += tmin;
        for (int i = 1; i <= n; i++) a[i].a = a[i].a + a[i].v * tmin;
        }

        for (int i = 1; i <= n; i++)
            if ( b[i].v > 0 && b[i].v != b[prevn].v ) {
                if ( tmax > (b[i].a-b[prevn].a) / (b[prevn].v - b[i].v) && (b[i].a-b[prevn].a) / (b[prevn].v - b[i].v) > 0 ) {
                    tmax = (b[i].a-b[prevn].a) / (b[prevn].v - b[i].v);
                    cur = i;
                }
        }

        if ( tmax != oo*oo ) {
        prevn = cur;
        t[++sz] = tmax + prevtn;
        prevtn += tmax;
        for (int i = 1; i <= n; i++) b[i].a = b[i].a + b[i].v * tmax;
        }
    }



}

int main()
{   //freopen("C11ANT.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].a;
    for (int i = 1; i <= n; i++) cin >> a[i].v;
    sort(a+1,a+n+1,cmp);
    for (int i = 1; i <= n; i++) aa[i] = a[i], bb[i] = a[i];

    solve(aa,bb);
    double ans = oo*oo;
    t[++sz] = 0;
    for (int o = 1; o <= sz; o++) {
    double _min = oo*oo, _max = -oo*oo;
    for (int i = 1; i <= n; i++) {
        double x;
        x = a[i].a + t[o]*a[i].v;
        _min = min(_min , x);
        _max = max(_max , x);
    }
    ans = min(ans,_max - _min);

    }
    cout << fixed << setprecision(3) << ans / 2;
}

#include <bits/stdc++.h>

const long N = 10000;
using namespace std;

int n;
int x, dx, t, dt, d, dd, v, dv;

int main()
{   freopen("XDTV2.inp","r",stdin);
    cin >> n;
    cin >> dx >> dd >> dt >> dv;

    int bh, bw;
    bh = dx*dt / __gcd(dx,dt);
    bw = dd*dv / __gcd(dd,dv);

    int nx, nd, nv, nt;
    nx = bh / dx;
    nd = bw / dd;
    nt = bh / dt;
    nv = bw / dv;

    if ( n < nx + nd + nt + nv ) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    int resx, resd, rest, resv;
    for (int i = 1; i <= n; i++) {
        int h = i, w = (n - (h*(nx+nt))) / (nd+nv);
        if ( w < 1 ) break;
        if ( ans < bh*h*bw*w ) {
            ans = bh*h*bw*w;
            resx = nx*h;
            resd = nd*w;
            rest = nt*h;
            resv = nv*w;
        }
    }

    cout << ans << endl;
    cout << resx << " " << resd << " " << rest << " " << resv;

}

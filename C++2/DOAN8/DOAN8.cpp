#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int x, d, t, v, dx, dd, dt, dv;
int height, width;

int gcd(int a,int b)
{
    int m = a, n = b;
    while ( n != 0 ) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{   freopen("DOAN8.inp","r",stdin);
    //freopen("DOAN8.out","w",stdout);
    cin >> x >> dx;
    cin >> d >> dd;
    cin >> t >> dt;
    cin >> v >> dv;

    if ( x*d*t*v == 0 ) {
        cout << -1;
        return 0;
    }

    int bh, bw;
    bh = dx*dt / gcd(dx,dt) ;
    bw = dv*dd / gcd(dv,dd);

    height = min( x / (bh/dx) , t / (bh/dt) );
    width = min( d / (bw/dd)  , v / (bw/dv) ) ;

    cout << height * bh * width * bw << endl;
    cout << height * bh / dx << " " << width * bw / dd << " " << height * bh / dt << " " << width * bw / dv ;
}

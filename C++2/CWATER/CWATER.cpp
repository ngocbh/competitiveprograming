#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
typedef long long LL;

typedef pair<LL,LL> ii;

LL n, t, A, B , C, X, Y, g, res;

ii gcd(LL a,LL b)
{
    if ( b % a ) {
        LL t = a/b;
        ii cur = gcd(b,a % b);
        LL x = cur.second;
        LL y = cur.first - t*cur.second;
        return ii(x,y);
    }
    else {
        g = a;
        return ii(1,0);
    }
}

void solve(LL a,LL b,LL c)
{
    b = -b;
    ii S = gcd(a,b);
    g = abs(g);
    LL x0 = S.first*(c/g);
    LL y0 = S.second*(c/g);
    LL t1 = (-x0*g) / b;
    LL t2 = (y0*g) / a;

    if ( (-x0*g) % b != 0 && (-x0*g) > 0 ) ++t1;
    if ( (y0*g) % a != 0 && (y0*g) > 0 ) ++t2;

    LL  t = max(t1,t2);
    res = min(res , abs(x0 + (b/g)*t) + abs(- ( y0 - (a/g)*t )));
}

int main()
{  freopen("CWATER.inp","r",stdin);
   freopen("CWATER.out","w",stdout);
    cin >> t;
    while ( t-- ) {
        LL D;
        res = 1000000000 + 10;
        cin >> A >> B >> C;
        for (int i = -1; i <= 1; i+=2)
            for (int j = -1; j <= 1; j+= 2)
                for (int k = -1; k <= 1; k += 2)
                    solve(i*A,j*B,C*k);
        if ( C % g != 0 ) cout << -1 << endl;
        else cout <<res << endl;
    }

}

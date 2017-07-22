#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;
typedef uint64_t it;
it T, b, w;

it mutil(it a,it b)
{
    it tg = b;
    it r = 0;
    it t = a;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = r+t;
        t = t+t;
        if ( r > T ) return -1;
        tg /= 2;
    }
    return r;
}

it gcd(it a,it b)
{
    it m = a, n = b, r;
    while ( n != 0 ) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main()
{
    freopen("C.inp","r",stdin);
    cin >> T >> b >> w;

    it bb = b,ww = w;

    bb /= gcd(bb,w);

    if ( b == w ) {
        cout << 1 << "/" << 1;
        return 0;
    }

    it bc = mutil(bb,ww);


    if ( bc < 0 ) {
        it ans = T;
        ans = min(ans,min(b-1,w-1));
        it g = gcd(ans,T);

        cout << ans/g << "/" << T/g;
        return 0;
    }

    it x = T / bc;

    if ( T % bc == 0 ) {
        it ans;
        ans = (x-1)*min(b,w);
        ans += min(b-1,w-1);
        ans += 1;
        it g = gcd(ans,T);
        cout << ans/g << "/" << T/g;
        return 0;
    }

    it ans;

    ans = x*min(b,w);
    ans += min(b-1,w-1);

    it g = gcd(ans,T);
    cout << ans/g << "/" << T/g;

}

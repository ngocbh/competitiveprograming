#include <bits/stdc++.h>

const long N = 10000;
using namespace std;
typedef long long LL;
LL a, b;

double kc(LL a,LL b,LL c,LL d)
{
    return sqrt(1LL*(a-c)*(a-c) + 1LL*(b-d)*(b-d));
}

int main()
{       //freopen("C.inp","r",stdin);
        cin >> a >> b;

        double ans = 10000000000000;
        LL c = a-b;
        if ( a == c ) {

        }
        LL ck;
        if ( a == c ) {
            ans = 0;
            cout << fixed << setprecision(9) << ans ;
            return 0;
        }
        ck = (LL) (c / abs(c-a));

        if ( ck != 0 )
        if ( ck % 2 == 0 ) {
            double x = (double) c / ck ;
            ans = min(ans, x);
        }   else {
            double x = (double) c / (ck-1);
            ans = min(ans, x);
        }

        c = a + b;
        ck = (LL) (c / abs(c-a));

        if ( ck != 0 )
        if ( ck % 2 == 0 ) {
            double x = (double) c / ck ;
            ans = min(ans, x);
        }   else {
            double x = (double) c / (ck-1) ;
            ans = min(ans, x);
        }

        if ( ans !=  10000000000000)
                cout << fixed << setprecision(9) << ans ;
        else cout << -1;
}

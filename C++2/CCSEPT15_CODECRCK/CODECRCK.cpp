#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef long long LL;

int i, k, s;
double a_i, b_i, a_i1, b_i1;
LL pow2[N];
int main()
{   //freopen("CODECRCK.inp","r",stdin);
    //freopen("CODECRCK.out","w",stdout);
    cin >> i >> k >> s;
    cin >> a_i >> b_i;
    double x = sqrt(2), y = sqrt(3);
    if ( k < i ) {
        for (int o = 1; o <= i-k; o++) {
                b_i1 = (y*a_i + y*b_i + a_i - b_i) / ( 2*x + 2*x*y*y );
                a_i1 = (a_i + b_i - a_i*y + b_i*y) / ( 2*x + 2*x*y*y );
                a_i = a_i1;
                b_i = b_i1;
        }
    }   else {
        for (int o = 1; o <= k-i; o++) {
                a_i1 = x*(a_i + b_i) - x*y*(a_i - b_i);
                b_i1 = x*(a_i - b_i) + x*y*(a_i + b_i);
                a_i = a_i1;
                b_i = b_i1;
        }
    }
    //cout << a_i << " " << b_i << endl;
    double ans = ( a_i + b_i );
    if ( s <= 2000 && s >= -2000 ) {
            if ( s > 0 ) {
                    for (int i = 1; i <= s; i++) ans = ans / 2;
            }
            else {
                    for (int i = 1; i <= -s; i++) ans = ans * 2;
            }
    }
    cout << fixed << setprecision(5) << ans ;
}

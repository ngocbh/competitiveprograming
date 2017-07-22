#include <bits/stdc++.h>

const long N = 10000;
using namespace std;
int t, n, m;
double sum, A, B, p;

double calc_powp(const double p,const int m)
{
    double r = 1, t = p;
    int tg = m;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = t*r;
        t = t*t;
        tg /= 2;
    }
    return r;
}

int main()
{      // freopen("BANROB.inp","r",stdin);
        ios::sync_with_stdio(0);
        cin >> t;
        while ( t-- ) {
                cin >>  m >> p;
                sum = 1000000000;
                if ( m == 1 ) {
                    cout << fixed << setprecision(2) << sum << " " << "0.0" << endl;
                    continue;
                }

                double powp;
                if ( m % 2 == 1 )
                        powp = 1 - (calc_powp(p,m) + 1) / (p+1);
                else
                        powp = 1 - (calc_powp(p,m-1) + 1) / (p+1) + calc_powp(p,m-1);
                cout << fixed << setprecision(2) << sum - sum*powp << " " << sum*powp << endl;
        }

}

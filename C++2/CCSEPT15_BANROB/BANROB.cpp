#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
struct data{
    double valA = 0, valB = 0;
    int cs = 0;
};
int n, m ,t;
double sum, p;
int main()
{  //freopen("BANROB.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
            cin >> m >> p;
            sum = 1000000000;
            if ( m == 1 ) {
                cout << fixed << setprecision( 1 ) << sum << " " << 0.0 << endl;
                continue;
            }
            if ( p == 1 ) {
                if ( m % 2 == 1 ) {
                    cout << fixed << setprecision( 1 ) << sum << " " << 0.0 << endl;
                }
                else {
                    cout << fixed << setprecision( 1 ) << 0.0 << " " << sum << endl;
                }
                continue;
            }
            if ( p <= 0.5 ) {
                cout << fixed << setprecision( 1 ) << sum*(1-p) << " " << sum*p << endl;
                continue;
            }


    }

}

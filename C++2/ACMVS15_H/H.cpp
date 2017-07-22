#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
double t, a[4], k;

bool check(double a,double b,double c)
{
            if ( a+b+c == k ||
                 a+b-c == k ||
                 a-b-c == k ||
                 a*b*c == k ||
                 a*b/c == k ||
                 a/b*c == k ||
                 a/b/c == k ||
                 a*b+c == k ||
                 abs(a*b-c) == k ||
                 a/b+c == k ||
                 abs(a/b-c) == k ||
                 (a+b)*c == k ||
                 (a-b)*c == k ||
                 (a+b)/c == k ||
                 (a-b)/c == k ||
                  a/(b+c) == k ||
                  a/(b-c) == k ||
                  a/(b*c) == k ||
                  a/(b/c) == k
               )
               return true;
        return false;
}

int main()
{   //freopen("H.inp","r",stdin);
    cin >> t;
    while ( t-- ) {

        cin >> a[1] >> a[2] >> a[3] >> k;
        bool ok = false;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                for (int k = 1; k <= 3; k++ ) {
                        if ( i == j || i == k || k == j ) continue;
                        if ( check(a[i],a[j],a[k]) ) ok = true;
                }

        if ( ok ) cout << "Possible" << endl;
        else cout << "Impossible" << endl;

    }

}

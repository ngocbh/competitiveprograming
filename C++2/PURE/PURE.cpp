#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;

int n, m;
int Z[N];
char s[N];

int main()
{   freopen("PURE.inp","r",stdin);
    freopen("PURE.out","r",stdout);
    scanf("%s", &m);
    scanf("%s", s+1);
    n = strlen(s+1);

    ///CALC_Z_FUNCTION
    int L = 0, R = 0;
    Z[1] = n;
    for (int i = 2; i <= n; i++)
    {
        if ( i > R ) {
            L = R = i;

            while ( s[R] == s[R-i+1] && R <= n ) ++R;

            Z[i] = R - L; --R;
        }
        else {

            if ( Z[i-L+1] <= R-i+1 ) {
                        Z[i] = Z[i-L+1];
            }
            else {
                        while ( s[R] == s[R-L+1] && R <= n ) ++R;

                        Z[i] = R - i; --R;
            }
        }

    }

    for (int i = 2; i <= n; i++)
        if ( Z[i] == n-i+1 ) {
            for (int j = 1; j < i; j++) cout << s[j];
            return 0;
        }
    cout << "NO";
}

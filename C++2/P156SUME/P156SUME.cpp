#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

string s1,s2,s;
int n1,n2,n;
int Z1[N],Z2[N];
int gcd(int n1,int n2)
{
    int r;
    while ( n2 != 0 ){
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    return n1;
}
void calc_Z(int Z[],string s)
{
    int n;
    n = s.size()-1;
    Z[0] = n+1;
    int L = -1 , R = -1;
    for (int i = 1; i <= n; i++) {
            if ( i > R ) {
                L = R = i;
                while ( R <= n && s[R] == s[R-i] ) ++R;
                --R;
                Z[i] = R - L + 1;
            }
            else {
                int k = i - L;
                if ( Z[k] < R - i + 1 ) {
                    Z[i] = Z[k];
                }
                else {
                    L = i;
                    while ( R <= n && s[R] == s[R-i] ) ++R;
                    Z[i] = R -L; --R;
                }
            }
    }
}
int main()
{   //freopen("P156SUME.inp","r",stdin);
    cin >> s1; n1 = s1.size();
    cin >> s2; n2 = s2.size();
    calc_Z(Z1,s1);
    calc_Z(Z2,s2);
    n = gcd(n1,n2);
    string ss1,ss2;
    ss1 = s1.substr(0,n);
    ss2 = s2.substr(0,n);
    if ( ss1 == ss2 && Z1[n] == n1 - n && Z2[n] == n2 - n ) {
        int Z[N];
        calc_Z(Z,ss1);
        Z[n] = 0;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if ( Z[i+1] == n - i - 1 && (n % (i+1)) == 0 ) {
                ++ans;
            }
        }
        cout << ans;
    } else cout << 0;
}

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long long MOD = 1000000000;
using namespace std;

int n, t, h = 29;
int hashT[N],hashP[N], P[N];
char s[N];

int gethashT(int i,int j)
{
    if ( i > j ) return 0;
    return ( hashT[j] - hashT[i-1]*P[j-i+1] + MOD ) % MOD;
}

int gethashP(int i,int j)
{
    if ( i > j ) return 0;
    return ( hashP[i] - hashP[j+1]*P[j-i+1] + MOD ) % MOD;
}

int main()
{   freopen("MAKPALIN.inp","r",stdin);
    ios::sync_with_stdio(false);
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%s", s + 1);
        n = strlen(s+1);
        hashT[0] = 0;
        P[0] = 1;
        for (int i = 1; i <= n; i++) {
            hashT[i] = ( hashT[i-1]*h + s[i] - 'a' ) % MOD;
            P[i] = ( P[i-1] * h ) % MOD;
        }
        for (int i = n; i >= 1; i--)
            hashP[i] = ( hashP[i+1]*h + s[i] - 'a' ) % MOD;

        int midl,midr, ans = 0;
        if ( (n+1) % 2 == 0 ) { midl = (n+1)/2; midr = midl+1; }
        else { midl = (n+1)/2; midr = midl + 2; }

        for (int i = 1; i <= n+1; i++)
            if ( i <= midl ) {
                    if ( gethashT(i,midl-1) == gethashP(midr-1,midr + midl - i -2) && gethashT(1,i-1) == gethashP(midr + midl - i, n) ) {++ans; cout << i << " " << s[i] << endl; }
            }
            else {
                    if ( gethashT(midr,i-1) == gethashP(midl + midr - i + 1,midl) && gethashT(i,n) == gethashP(1, midl + midr - i - 1) ) {++ans; cout << i << " " << s[i] << endl; }
            }
        cout << ans << endl;
    }

}

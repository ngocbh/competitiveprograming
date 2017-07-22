#include <bits/stdc++.h>

const long N = 100000 * 4 + 10;
const long MOD = 1000000000 + 7;
using namespace std;
typedef long long LL;

int n;
LL res[N], h[N], p[N];
string s, s1, s2;

void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
        p[i] = ( 1LL*p[i-1] * 29 ) % MOD;
}

LL get(int l,int r)
{
    if ( l == 0 ) return h[r];
    return ( h[r] - 1LL*h[l-1]*p[r-l+1] + 1LL*MOD*MOD) % MOD;
}

bool check(int x)
{
    int l = n/x;
    s1 = s.substr(0,l);
    s1 = s1 + s1;

    h[0] = s1[0] - '0';
    for (int i = 1; i < 2*l; i++)
        h[i] = ( 1LL*h[i-1]*29 + s1[i] - '0') % MOD;

    for (int i = 1; i < x; i++) {

        s2 = s.substr(i*l,l);
        LL h2 = 0;
        for (int i = 0; i < l; i++)
            h2 = ( 1LL*h2*29 + s2[i] - '0' ) % MOD;

        bool ok = false;
        for (int i = 0; i < l; i++) {
            if ( get(i,i+l-1) == h2 ) {
                ok = true;
                break;
            }
        }
        if ( !ok ) return false;
    }

    return true;
}

int main()
{   freopen("S_CYCLE.inp","r",stdin);
    freopen("S_CYCLE.out","w",stdout);

    cin >> s;
    n = s.size();
    init();
    int sz = 0;
    for (int i = 1; i*i <= n; i++)
        if ( n%i == 0 ) {
            if ( check(i) ) res[++sz] = i;
            if ( i != n/i && check(n/i) ) res[++sz] = n/i;
        }

    sort(res+1,res+sz+1);
    cout << sz << endl;
    for (int i = 1; i <= sz; i++)
        if ( res[i] != res[i-1] ) cout << res[i] << " ";

}

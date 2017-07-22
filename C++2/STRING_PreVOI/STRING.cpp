#include <bits/stdc++.h>

using namespace std;

const long N = 200 + 10;
const long long MOD = 1000000000 + 7;
long long n, nres = N, h = 29, Hash[N], Pow[N];
string s, res;

long long get(int i,int j)
{
    return ( Hash[j] - Hash[i-1]*Pow[j-i+1] + MOD*MOD ) % MOD;
}

bool check(string ss,int m)
{
    memset(Hash,0,sizeof Hash);
    long long ss_hash = 0;
    for (int i = 0; i < ss.size(); i++)
        ss_hash = (ss_hash*h + ss[i] - 'a' + 1) % MOD;

    int prev = 0;
    for (int i = 1; i <= n; i++) {
        ++prev;
        Hash[prev] = (Hash[prev-1] * h + s[i] - 'a' + 1) % MOD;
        if ( get(prev-m+1,prev) == ss_hash )
            prev = prev - m;
    }

    if ( prev == 0 )
        return true;
    return false;
}

int main()
{
    //freopen("STRING.inp","r",stdin);
    //freopen("STRING.out","w",stdout);

    cin >> s;
    n = s.size();

    s = '0' + s;

    Pow[0] = 1;
    for (int i = 1; i <= n; i++) Pow[i] = Pow[i-1] * h % MOD;

    for (int i = 1; i <= n; i++) {
        if ( n % i == 0 ) {
            for (int j = 1; j <= n-i+1; j++)
                if ( check(s.substr(j,i), i) ) {
                    if ( nres != i ) res = s.substr(j,i), nres = i;
                    else {
                        nres = i;
                        if ( res > s.substr(j,i) ) res = s.substr(j,i);
                    }
                }
        }
        if ( nres != N ) break;
    }

    cout << res;
}

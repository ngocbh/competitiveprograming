#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 50;
const long long MOD = 1000000000 + 7;

int n, t, st;
long long f[N][2], a[N], c[N], Fibo[N], Pow[N];
string s, w;

int calc(string s)
{
    int  rs = 0;
    for (int i = 0; i < s.size(); i++)
        rs = rs*2 + ( s[i] == 'b' || s[i] == '+' );
    return rs;
}

int main()
{
    //freopen("CHEFFILT.inp","r",stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    Fibo[1] = Fibo[0] = 1; Pow[0] = 1; Pow[1] = 2;

    for (int i = 2; i < N; i++) {
        Fibo[i] = (Fibo[i-1] + Fibo[i-2]) % MOD;
        Pow[i] = (Pow[i-1] * 2) % MOD;
    }

    while ( t-- ) {
        memset(f,0,sizeof f);
        memset(c,0,sizeof c);
        memset(a,0,sizeof a);

        cin >> s; int l = s.size();
        cin >> n;

        st = calc(s);
        for (int i = 1; i <= n; i++)
        {
            cin >> w;
            a[i] = calc(w);
            ++c[a[i]];
        }

        int mask = (1<<l) - 1, rem = 0;
        rem = (st == mask);
        st = st ^ mask;
        int cur = 1, prev = 1 - cur;

        for (int i = 0; i <= mask; i++) {
            if ( c[i] == 0 ) continue;
            for (int j = 0; j <= mask; j++)
            {
                f[i^j][cur] = ( (Pow[c[i]-1]*f[i^j][prev] % MOD) + (Pow[c[i]-1]*f[j][prev]) % MOD ) % MOD;
                //f[j][cur] = ( Fibo[c[i]]*f[i^j][prev] + Fibo[c[i]]*f[j][prev] ) % MOD;
            }
            f[i][cur] = ( f[i][cur] + Pow[c[i]-1] ) % MOD;
            f[0][cur] = ( f[0][cur] + Pow[c[i]-1] - 1 ) % MOD;
            cur ^= 1, prev ^= 1;
        }

        cout << (f[st][prev] + rem) % MOD << endl;
    }
}

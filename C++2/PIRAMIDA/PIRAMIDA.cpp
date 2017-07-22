#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;

LL n, l;
char s[N];
int f[30][N];

LL get(LL a,LL b,LL c,LL p)
{
    if ( a % c == 0 ) {
        a /= c;
        return (1LL*(a%l)*(b%l)) % l;
    }   else {
        b /= c;
        return (1LL*(a%l)*(b%l)) % l;
    }
}

int main()
{
    freopen("PIRAMIDA.inp","r",stdin);
    freopen("PIRAMIDA.out","w",stdout);
    cin >> n;
    scanf("%s", s+1);
    l = strlen(s+1);

    for (int i = 1; i <= l; i++)
        for (int j = 0; j <= 26; j++)
            if ( s[i] - 'A' == j )
                f[j][i] = f[j][i-1] + 1;
            else
                f[j][i] = f[j][i-1];

    LL k;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        LL a;
        char c;
        cin >> a >> c;
        int cc = c-'A';

        LL c1 = get(a,a-1,2,l), c2 = get(a,a+1,2,l);
        if ( c2 == 0 ) c2 = l;

        LL ans = 0;

        if ( l > a && c1 < c2 )
                ans = f[cc][c2] - f[cc][c1];
        else {
            if ( c2 == l ) c2 = 0;

            ans += f[cc][l] - f[cc][c1]; a -= l-c1;

            ans += (a/l) * f[cc][l];

            ans += f[cc][c2];
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

const long N = 100 + 10;

int n, p, q;
char s[N];

int main()
{
    //freopen("A.inp","r",stdin);
    cin >> n >> p >> q;
    scanf("%s", s+1);

    for (int i = 0; i <= n; i++) if ( (n - i*p) % q == 0  && i*p <= n ) {
        cout << i + (n-i*p)/q << endl;
        int x = 0;
        for (int j = 1; j <= i; j++) {
            for (int o = 1; o <= p; o++) cout << s[++x];
            cout << endl;
        }
        for (int j = 1; j <= (n-i*p)/q; j++) {
            for (int o = 1; o <= q; o++)
                cout << s[++x];
            cout << endl;
        }
        return 0;
    }
    cout << -1;
}

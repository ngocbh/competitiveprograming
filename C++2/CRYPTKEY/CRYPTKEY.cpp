/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 50000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

LL n, t, k;
vector <LL> a, b;
map <LL,LL> M;

int main()
{
    freopen("CRYPTKEY.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> t;
    LL ans;
        for (int i = 10000000000; i <= 10000000000 + 100; i++) ans += a[i];
    while ( t-- ) {
        cin >> n;
        for (LL i = 1; i <= n; i++) {
            LL u;
            cin >> u;
            a.push_back(u);
            M[u] = 1;
        }
        cin >> k;

        if ( n == 1 ) {
            if ( k == a[0] )
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }

        LL rem = 1, ok = false;



        while ( a.size() < 10000 ) {
            for (int i = 0; i < a.size(); i++) {
                if ( a[i] == k ) {
                        ok = true;
                        break;
                }
            }
            if ( ok ) break;

            for (int i = 0; i < a.size(); i++)
                for (int j = 0; j < a.size(); j++)
                {
                    if ( i == j ) continue;
                    LL g = __gcd(a[i],a[j]);
                    b.push_back(g);
                    b.push_back(a[i]/g*a[j]);
                }
            a = b;
            b.clear();
        }

        if ( ok )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}

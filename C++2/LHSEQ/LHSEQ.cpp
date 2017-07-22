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
typedef pair <int,int> ii;

int t, n, m;
int f[N], a[N];
map <int,int> M1;

int main()
{
    freopen("LHSEQ.inp","r",stdin);
    freopen("LHSEQ.out","w",stdout);

    cin >> t;
    while ( t-- ) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        M1.clear();
        for (int i = 1; i <= n; i++) {
            M1[a[i]] = max(M1[a[i]],M1[a[i]-1]+1);
            f[i] = M1[a[i]];
        }

        M1.clear();
        for (int i = n; i >= 1; i--) {
            M1[a[i]] = max(M1[a[i]],M1[a[i]-1]+1);
            f[i] = min(f[i],M1[a[i]]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans,f[i]);

        if ( ans == 1 ) {
            cout << -1 << endl;
            continue;
        }

        cout << n+1 - ans*2 << endl;
    }



}

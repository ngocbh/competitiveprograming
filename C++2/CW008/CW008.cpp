#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, k, q;
int a[2*N], ck[4*N], ca[N];

int main()
{   //freopen("CW008.inp","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    for (int i = 1; i <= k; i++) cin >> ck[i];
    for (int i = 1; i <= k; i++) ck[k+i] = ck[i];
    cin >> q;
    while ( q-- ) {
        int u,v;
        cin >> u >> v;
        memset(ca,true,sizeof(ca));
        LL ans = 0;
        for (int i = u; i <= u+v-1; i++) {
               if ( ca[ck[i]] ) {
                    ans += a[ck[i]];
                    ca[ck[i]] = false;
               }
        }
        cout << ans << endl;
    }

}

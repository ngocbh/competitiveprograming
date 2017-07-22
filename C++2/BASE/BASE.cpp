/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
int a[N];
LL ans, k, sum;
LL f[N];

int main()
{
    freopen("BASE.inp","r",stdin);
    freopen("BASE.out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++) f[i] = f[i-1] + a[i];

    for (int i = 1; i <= m; i++) {
        cin >> k;
        int c = upper_bound(a+1,a+n+1,k) - a;
        --c;
        cout << k*c - f[c] + f[n] - f[c] - k*(n-c) << endl;
    }
}

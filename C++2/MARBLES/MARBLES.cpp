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

LL n, m, u, v, r;
LL nom_bom, nom_cuoi;
LL x[N], y[N];
int main()
{
    freopen("MARBLES.inp","r",stdin);
    freopen("MARBLES.out","w",stdout);

    cin >> n >> m >> u >> v >> r;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> y[i];

    sort(x+1,x+n+1);
    sort(y+1,y+m+1);

    for (int i = 1; i <= m; i++) {
        double delta = u*u - ( y[i]*y[i] - 2*v*y[i] + u*u + v*v - r*r ) ;

        if ( delta < 0 ) continue;

        LL forward_point = (LL) ceil(u - sqrt(delta));
        LL behind_point = (LL) trunc(u + sqrt(delta));

        int forward_index = lower_bound(x+1,x+n+1,forward_point) - x;
        int behind_index = upper_bound(x+1,x+n+1,behind_point) - x;

        nom_bom += behind_index - forward_index;
    }

    nom_cuoi = 1LL*n*m - nom_bom;

    LL ans;
    ans = abs(nom_bom - nom_cuoi);

    cout << ans;
}

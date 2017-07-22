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
typedef pair <LL,int> ii;

LL h, n;
int a[3];
LL  ca[N], d[N];

int main()
{
    freopen("MELE2.inp","r",stdin);
    //freopen("MELE2.out","w",stdout);

    cin >> h;
    cin >> a[1] >> a[2] >> a[3];

    sort(a+1,a+3+1);
    n = a[3];

    priority_queue <ii,vector<ii>,greater<ii> > qu;
    qu.push(ii(1,1));
    fill(d,d+N,oo*oo);
    d[1] = 1;

    while ( !qu.empty() ) {
        LL du = qu.top().first;
        int u = qu.top().second;
        qu.pop();
        if ( d[u] != du ) continue;

        for (int i = 1; i <= 3; i++) {
            int v = (u+a[i]) % n;
            if ( d[v] > du + a[i]) {
                d[v] = du + a[i];
                qu.push(ii(d[v],v));
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i < n; i++)
        if ( d[i] <= h ) {
                ans += ( (h-d[i]) / n ) + 1;
        }

    cout << ans << endl;
}

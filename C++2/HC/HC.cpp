/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 200 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

int n, m;
int a[N][N], ca[N][N];
LL d[N][N];

int main()
{   freopen("HC.inp","r",stdin);
    freopen("HC.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }

    priority_queue <ii,vector<ii>,greater<ii> > qu;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = oo;
    for (int i = 1; i <= n; i++) d[i][1] = a[i][1];

    for (int i = 1; i <= n; i++)
        qu.push(ii(a[i][1],i*211+1));

    while ( !qu.empty() ) {
        LL u, v, du;
        du = qu.top().first;
        v = qu.top().second % 211;
        u = qu.top().second / 211;
        qu.pop();

        if ( v == m ) {
            cout << du;
            return 0;
        }

        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ( u+i > 0 && u+i <= n && v+j > 0 && v+j <= m ){
                        if ( i == 0 && j == 0 ) continue;
                        if ( i != 0 && j != 0 ) continue;

                        if ( d[u+i][v+j] > du + a[u+i][v+j] ) {
                            d[u+i][v+j] = du + a[u+i][v+j];
                            qu.push(ii(d[u+i][v+j],(u+i)*211+v+j));
                        }
                }
    }

    cout << 0;
    return 0;
}

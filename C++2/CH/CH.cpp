/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500 + 100;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int n,m, A, B;
int b[N][N], d[N*20], c[N*20];
vector <ii> a[N*20];
int main()
{
    freopen("CH.inp","r",stdin);
    freopen("CH.out","w",stdout);
    m = 0;
    cin >> A >> B >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> b[i][0];
        for (int j = 1; j <= b[i][0]; j++) {
                cin >> b[i][j];
                a[b[i][j]].push_back(ii(i,j));
                m = max(m,b[i][j]);
        }
    }

    for (int i = 1; i <= m; i++) d[i] = oo;
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    for (int i = 0; i < a[A].size(); i++) {
        int u = a[A][i].first;
        int v = a[A][i].second;
        for (int j = v; j <= b[u][0]; j++)
        {
            d[b[u][j]] = c[u];
            qu.push(ii(c[u],b[u][j]));
        }
    }

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
            int x = a[u][i].first;
            int ci = a[u][i].second;
            for (int j = ci; j <= b[x][0]; j++) {
                int v = b[x][j];
                if ( d[v] > du + c[x] ) {
                    d[v] = du + c[x];
                    qu.push(ii(d[v],v));
                }
            }
        }
    }

    int ans = d[B];

    if ( ans == oo ) {
        cout << -1;
        return 0;
    }

    cout << ans;

}

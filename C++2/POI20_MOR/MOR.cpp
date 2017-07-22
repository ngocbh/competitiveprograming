/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 5000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 30000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k;
short d[N][N][2];
vector <int> a[N];

void dijkstra(int s)
{
    queue <ii> qu;
    qu.push(ii(0,s));
    d[s][s][0] = 0;

    while ( !qu.empty() ) {
        int du = qu.front().first;
        int u = qu.front().second % N;
        int k = qu.front().second / N;
        qu.pop();

        if ( du != d[s][u][k] ) continue;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if ( d[s][v][(k+1)%2] > d[s][u][k] + 1 ) {
                d[s][v][(k+1)%2] = d[s][u][k] + 1;
                qu.push(ii(d[s][v][(k+1)%2],v + ((k+1)%2)*N ));
            }
        }
    }
}

int main()
{
    //freopen("MOR.inp","r",stdin);
    //freopen("MOR.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> n >> m >> K;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            d[i][j][0] = d[i][j][1] = oo;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    for (int i = 1; i <= K; i++) {
        int s,t, dd;
        cin >> s >> t >> dd;
        if ( s == t && a[s].size() == 0 ) {
            if ( dd == 0 ) cout << "TAK" << endl;
            else cout << "NIE" << endl;
            continue;
        }

        if ( dd >= d[s][t][dd%2] && d[s][t][dd%2] != oo ) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
}

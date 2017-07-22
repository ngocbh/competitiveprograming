#include <bits/stdc++.h>

const long N = 10000 + 10;
const long oo = 100000000 + 10;
using namespace std;

typedef long long LL;
typedef pair <int,int> ii;

int n, m, s;
int ca[N], d[N], f[N];

vector <int> a[N];
ii p[N*10];

void bfs()
{
    queue <ii> qu;
    memset(ca,0,sizeof(ca));
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[s] = 0;
    qu.push(ii(s,0));
    ca[s] = 2;

    while ( !qu.empty() ) {
        int u,du, v;
        u = qu.front().first;
        du = qu.front().second;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
            v= a[u][i];
            if ( d[v] < d[u] + 1 ) continue;
            if ( ca[v] == 2 && d[v] == d[u] + 1 ) {
                    f[v] = true;
                    continue;
            }
            if ( d[v] == d[u] + 1 && ca[v] == 1 ) {
                f[v] = true;
                ca[v]++;
                qu.push(ii(v,d[v]));

            }
            if ( d[v] > d[u] + 1 ) {
                f[v] = false;
                ca[v] = 1;
                d[v] = d[u] + 1;
                qu.push(ii(v,d[v]));
                continue;
            }
        }
    }
}

int main()
{
    freopen("STABLE.inp","r",stdin);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p+1,p+m+1);
    for (int i = 1; i <= m; i++) {
        if ( p[i].first == p[i-1].first && p[i].second == p[i-1].second ) continue;
        a[p[i].first].push_back(p[i].second);
    }

    for (int i = 1; i <= n; i++) a[i].push_back(0);

    memset(f,false,sizeof f);
    bfs();

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if ( f[i] && i != s ) {
                ++ans;
        }
    cout << ans;
}

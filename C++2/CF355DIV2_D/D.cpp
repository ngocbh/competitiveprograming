#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

typedef pair <int,long long> ii;

int n, m;
int a[N], b[N], f[N];
ii M[N], c[N];

int main()
{
    freopen("D.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int u = 1;
    int cm = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        if ( b[i] ) f[u] = a[i], M[i] = ii(u,u+1), ++u;
        else c[++cm] = ii(a[i],i);
    }
    sort(c+1,c+cm+1,greater<ii>());

    priority_queue <ii> qu;

    int _max = f[1], cn = 0;
    for (int i = 2; i <= min(n-1,m-n+2); i++) {
        _max = max(_max,f[i]);
        qu.push(ii(_max,1*N + i+1));
        ++cn;
    }

    for (int i = 2; i < n-1; i++) {
        _max = f[i];
        int j = i+1;
        while ( true ) {
            if ( j == n ) break;
            _max = max(f[j],_max);
            if ( cn < cm ) {
                qu.push(ii(_max,i*N+j+1));
                ++j;
                continue;
            }
            int cs = qu.top().first;
            if ( cs > _max ) {
                qu.pop();
                qu.push(ii(_max,i*N+j+1));
            }
            else break;
            ++j;
        }
    }

    int i = 1;

    while ( !qu.empty() ) {
        ii A = qu.top();
        if ( A.first <= c[i].first ) {
            M[c[i].second] = ii(A.second/N,A.second%N);
            qu.pop();
            ++i;
        }
        else {
            cout << -1;
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) cout << M[i].first << " " << M[i].second << endl;

}

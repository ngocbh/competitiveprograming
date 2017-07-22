#include <bits/stdc++.h>

using namespace std;

const long N = 500 + 10;
const long oo = 1000000000 + 7;

typedef pair <int,int> ii;
typedef pair <ii,ii> iii;

int n, m;
int a[N][N], d[N][N];
ii p[N][N];
int h[5] = {1,0,-1,0};
int c[5] = {0,1,0,-1};

struct compare
{
    bool operator () ( const iii &A, const iii &B)
    {
        return min(A.first.first,A.first.second ) < min(B.first.first,B.first.second);
    }
};

ii calc(int x)
{
    int sl2 = 0, sl5 = 0;
    while ( x % 2 == 0 ) x/=2, ++sl2;
    while ( x % 5 == 0 ) x/=5, ++sl5;

    return ii(sl2,sl5);
}

void solve()
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    qu.push(ii(p[1][1].first,1*N+1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = oo;
    d[1][1] = p[1][1].first;

    while ( !qu.empty() )
    {
        int u = qu.top().second / N;
        int v = qu.top().second % N;
        int du = qu.top().first;
        qu.pop();

        if ( d[u][v] != du ) continue;

        for (int i = 0; i < 4; i++) {
            int ui = u + h[i];
            int vi = v + c[i];
            if ( ui < 1 || ui > n || vi < 1 || vi > m ) continue;
            if ( d[ui][vi] > d[u][v] + p[ui][vi].first ) {
                d[ui][vi] = d[u][v] + p[ui][vi].first;
                qu.push(ii(d[ui][vi],ui*N+vi));
            }
        }
    }

    cout << d[n][m];
    return;
}

int main()
{
    freopen("SC.inp","r",stdin);
    freopen("SC.out","w",stdout);

    cin >> n >> m;
    bool ok = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            p[i][j] = calc(a[i][j]);
            if ( p[i][j].first != p[i][j].second ) ok = false;
        }

    if ( ok ) { solve(); return 0; }

    priority_queue <iii,vector<iii>,compare > qu;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = oo;

    qu.push(iii(p[1][1],ii(1,1)));
    d[1][1] = min(p[1][1].first,p[1][1].second);

    while ( !qu.empty() ) {
        iii A = qu.top();
        int u = A.second.first;
        int v = A.second.second;
        int sl2 = A.first.first;
        int sl5 = A.first.second;
        qu.pop();

        if ( d[u][v] != min(sl2,sl5) ) continue;
        for (int i = 0; i < 4; i++) {
            int ui = u + h[i];
            int vi = v + c[i];
            if ( ui < 1 || ui > n || vi < 1 || vi > m ) continue;
            if ( d[ui][vi] > min(sl2+p[ui][vi].first,sl5+p[ui][vi].second) ) {
                    d[ui][vi] = min(sl2+p[ui][vi].first,sl5+p[ui][vi].second);
                    qu.push(iii(ii(sl2+p[ui][vi].first,sl5+p[ui][vi].second),ii(ui,vi)));
            }
        }
    }

    cout << d[n][m] << endl;
}

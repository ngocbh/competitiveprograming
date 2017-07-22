#include <bits/stdc++.h>

const long N = 1000 + 5;
const long long oo = 1000000000 + 7;
using namespace std;
typedef pair <int,int> ii;
struct data{
    int u,v,du,ok;
};
int n, k;
int a[N][N], ca[N][N];
int f1_max[N][N], f1_min[N][N];
int f2_max[N][N], f2_min[N][N];

int h1[3] = {0,1,1};
int c1[3] = {1,0,1};
int h2[3] = {0,1,1};
int c2[3] = {-1,-1,0};

void loang_min()
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            f1_min[i][j] =  f2_min[i][j] = oo;

    qu.push(ii(0,1*N + 1));
    f1_min[1][1] = f2_min[1][n] = 0;

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second / N;
        int v = qu.top().second % N;
        qu.pop();

        for (int i = 0; i <= 2; i++) {
            int ui = u + h1[i];
            int vi = v + c1[i];
            if ( a[ui][vi] || ui > n || vi > n ) continue;
            if ( f1_min[ui][vi] > du + 1 ) {
                f1_min[ui][vi] = du + 1;
                qu.push(ii(f1_min[ui][vi],ui*N + vi));
            }
        }
    }

    qu.push(ii(0,1*N+n));

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second / N;
        int v = qu.top().second % N;
        qu.pop();

        for (int i = 0; i <= 2; i++) {
            int ui = u + h2[i];
            int vi = v + c2[i];
            if ( a[ui][vi] || ui > n || vi > n ) continue;
            if ( f2_min[ui][vi] > du + 1 ) {
                f2_min[ui][vi] = du + 1;
                qu.push(ii(f2_min[ui][vi],ui*N + vi));
            }
        }
    }
}

void loang_max()
{
    priority_queue <ii> qu;
    memset(f1_max,0,sizeof f1_max);
    memset(f2_max,0,sizeof f2_max);

    qu.push(ii(0,1*N + 1));
    f1_max[1][1] = f2_max[1][n] = 0;

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second / N;
        int v = qu.top().second % N;
        qu.pop();

        for (int i = 0; i <= 2; i++) {
            int ui = u + h1[i];
            int vi = v + c1[i];
            if ( a[ui][vi] || ui > n || vi > n ) continue;
            if ( f1_max[ui][vi] < du + 1 ) {
                f1_max[ui][vi] = du + 1;
                qu.push(ii(f1_max[ui][vi],ui*N + vi));
            }
        }
    }

    qu.push(ii(0,1*N+n));

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second / N;
        int v = qu.top().second % N;
        qu.pop();

        for (int i = 0; i <= 2; i++) {
            int ui = u + h2[i];
            int vi = v + c2[i];
            if ( a[ui][vi] || ui > n || vi > n ) continue;
            if ( f2_max[ui][vi] < du + 1 ) {
                f2_max[ui][vi] = du + 1;
                qu.push(ii(f2_max[ui][vi],ui*N + vi));
            }
        }
    }
}

int main()
{
    freopen("ROBOCON.inp","r",stdin);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int u,v;
        cin >> u >> v;
        a[u][v] = 1;
    }

    loang_min();
    loang_max();

    int ans = oo;

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << "(" << f1_min[i][j] << "," << f1_max[i][j] << ") ";
        cout << endl;
    }

    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << "(" << f2_min[i][j] << "," << f2_max[i][j] << ") ";
        cout << endl;
    }*/


    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int d , c;
            if ( f1_max[i][j] == 0 || f2_max[i][j] == 0 ) continue;

            d = max(f1_min[i][j],f2_min[i][j]);
            c = min(f2_max[i][j],f1_max[i][j]);

            if ( d > c ) continue;
            ans = min(ans,d);
        }

    cout << ans;
}

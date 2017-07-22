#include <bits/stdc++.h>

using namespace std;

const long N = 100 + 10;
typedef pair <int,int> ii;

int n, m;
int ca[N][N][5], col[N][N];
char a[N][N];
vector <ii> boom;

int h[5] = {0,-1,0,1,0};
int c[5] = {0,0,1,0,-1};
int chu1[5] = {0,4,1,2,3};
int chu2[5] = {0,2,3,4,1};

void duyet(int u,int v,int hu)
{
    col[u][v] = 1;
    ca[u][v][hu] = false;
    if ( u < 1 || u > n || v < 1 || v > m ) return;
    int ui = u + h[hu];
    int vi = v + c[hu];
    if ( a[ui][vi] != '#' ) { if ( ca[ui][vi][hu] ) duyet(ui,vi,hu); }
    else {
        if ( ca[u][v][chu1[hu]] ) duyet(u,v,chu1[hu]);
        if ( ca[u][v][chu2[hu]] ) duyet(u,v,chu2[hu]);
    }
}

int main()
{
    freopen("BOMBMAN.inp","r",stdin);
    freopen("BOMBMAN.out","w",stdout);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if ( a[i][j] == '*' )
                boom.push_back(ii(i,j));
    }

    for (int i = 0; i <= n; i++) a[i][0] = a[i][m+1] = '.';
    for (int i = 0; i <= m; i++) a[0][i] = a[n+1][i] = '.';

    memset(ca,true,sizeof ca);

    for (int i = 0; i < boom.size(); i++)
    {
        int u = boom[i].first;
        int v = boom[i].second;
        if ( ca[u][v][1] ) duyet(u,v,1);
        if ( ca[u][v][2] ) duyet(u,v,2);
        if ( ca[u][v][3] ) duyet(u,v,3);
        if ( ca[u][v][4] ) duyet(u,v,4);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( !col[i][j] && a[i][j] == '.' )
                ++ans;

    cout << ans;
}

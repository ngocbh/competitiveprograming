#include <bits/stdc++.h>

const long N = 700 + 10;
using namespace std;
int n , m;
int a[N][N], ca[N][N];
bool ok;

void dfs(int u,int v)
{
    ca[u][v] = false;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++) {
                if ( i == 0 && j == 0 ) continue;
                if ( a[u][v] < a[u+i][v+j] ) ok = false;
                if ( u + i > 0 && u + i <= n && v + j > 0 && v + j <= m && a[u][v] == a[u+i][v+j] && ca[u+i][v+j] ) {
                        dfs(u+i,v+j);
                }
        }
}

int main()
{   //freopen("NKGUARD.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];


    memset(ca,true,sizeof(ca));
    int ans = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
                if ( !ca[i][j] ) continue;
                ok = true;
                dfs(i,j);
                if ( ok ) ++ans;
        }

    cout << ans;

}

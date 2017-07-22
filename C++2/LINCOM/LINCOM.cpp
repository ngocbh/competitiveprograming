#include <bits/stdc++.h>

const long N = 500 + 10;
using namespace std;
int n ,m ,r , a[N][N], h[N],ans,cs[N];
bool cmp(int i,int j)
{
    return h[i] < h[j];
}
int main()
{   //freopen("LINCOM.inp","r",stdin);
    cin >> n >> m;
    memset(h,0,sizeof h);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
                char c;
            cin >> c;
            if ( c == '1' ) a[i][j] = 1;
            else a[i][j] = 0;
            h[i] += a[i][j];
        }
    }
    cin >> r;
    for (int i = 1; i <= r; i++) {
            int u , v;
        cin >> u >> v;
        if ( a[u][v] == 1 ) --h[u];
        else ++h[u];
        a[u][v] = 1 - a[u][v];
    }
    for (int i = 1; i <= n; i++) cs[i] = i;
    sort(cs+1,cs+n+1,cmp);

    if ( h[cs[n]] == h[cs[n-1]] ) {cout <<"Tie"; return 0; }
    cout << cs[n];
}

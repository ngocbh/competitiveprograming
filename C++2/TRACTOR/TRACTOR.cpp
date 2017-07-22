/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define mp(a,b,c) iii(a,ii(b,c))
const long N = 500 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int n, m, kt, ans = oo;
int a[N][N], lad[N][N], ca[N], p[N*N], d[N*N];
int h[5] = {0,0,1,-1};
int c[5] = {1,-1,0,0};

vector <ii> b[N*N];
map <ii,int> M;

void dfs(int u,int v)
{
    lad[u][v] = m;
    p[m]++;
    if ( a[u+1][v] == a[u][v] && !lad[u+1][v] ) dfs(u+1,v);
    if ( a[u-1][v] == a[u][v] && !lad[u-1][v] ) dfs(u-1,v);
    if ( a[u][v+1] == a[u][v] && !lad[u][v+1] ) dfs(u,v+1);
    if ( a[u][v-1] == a[u][v] && !lad[u][v-1] ) dfs(u,v-1);
}

void dfs1(int u,int c,int sv)
{
    if ( sv >= kt ) {
        ans = min(ans,c);
        return;
    }
    for (int i = 0; i < b[u].size(); i++) {
        int v = b[u][i].first;
        int uv = b[u][i].second;
        if ( !ca[v] ) continue;
        ca[v] = false;
        dfs1(v,max(c,uv),sv+p[v]);
        ca[v] = true;
    }
}

int main()
{
    freopen("TRACTOR.inp","r",stdin);
    freopen("TRACTOR.out","w",stdout);

    cin >> n;
    kt = (n*n+1) / 2;

    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= n+1; j++)
            a[i][j] = -1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( !lad[i][j] )
                m++,dfs(i,j);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
                for (int o = 1; o <= 4; o++) {
                    if ( i+h[o] < 1 || i + h[o] > n || j+c[o] < 1 || j+c[o] > n ) continue;
                    int r = lad[i][j];
                    int s = lad[i+h[o]][j+c[o]];
                    int x = abs(a[i][j] - a[i+h[o]][j+c[o]]);
                    if ( r != s && !M[ii(r,s)] ) {
                        b[r].push_back(ii(s,x));
                        b[s].push_back(ii(r,x));
                        M[ii(r,s)] = M[ii(s,r)] = 1;
                    }
                }
        }

    memset(ca,true,sizeof ca);

    for (int i = 1; i <= m; i++) {
        ca[i] = false;
        dfs1(i,0,p[i]);
    }

    cout << ans;
}

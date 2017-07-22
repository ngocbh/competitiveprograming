#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;

int n, m, ans;
char a[N][N];
int ca[N][N][N],s[N][N];
int h[4] = {0,1,0,-1};
int b[4] = {1,0,-1,0};

void dfs(int u, int v,int c)
{
    ca[u][v][c] = false;
    if ( s[u][v] ) {
        ++ans;
        s[u][v] = false;
    }
    int cc = (c+1) % 4;
    if ( !ca[u+h[c]][v+b[c]][c] && a[u+h[c]][v+b[c]] != '/') return;
    if ( a[u+h[c]][v+b[c]] != '*' && ca[u+h[c]][v+b[c]][c] ) {
        dfs(u+h[c],v+b[c],c);
        return;
    }

    if ( a[u+h[cc]][v+b[cc]] != '*' && ca[u+h[cc]][v+b[cc]][cc] )    {
        dfs(u+h[cc],v+b[cc],cc);
        return;
    }
    if ( a[u+h[cc]][v+b[cc]] == '*' && ca[u][v][cc] )    {
        dfs(u,v,cc);
        return;
    }
}

int main()
{   //freopen("J.inp","r",stdin);
    cin >> n >> m;

    int ci,cj,c;
    string s1;
    getline(cin,s1);
    for (int i = 1; i <= n; i++) {
    getline(cin,s1);
    for (int j = 1; j <= m; j++) {
                a[i][j] = s1[j-1];
                if (a[i][j] == 'U') {
                    ci = i;
                    cj = j;
                    c = 3;
                }
                if ( a[i][j] == 'R') {
                    ci = i;
                    cj = j;
                    c = 0;
                }
                if ( a[i][j] == 'D' ) {
                    ci = i;
                    cj = j;
                    c = 1;
                }
                if ( a[i][j] == 'L' ) {
                    ci = i;
                    cj = j;
                    c = 2;
                }
        }
    }
    for (int i = 0; i <= n+1; i++) a[i][0] = a[i][m+1] = '*';
    for (int i = 0; i <= m+1; i++) a[0][i] = a[n+1][i] = '*';

    memset(s,true,sizeof s);
    memset(ca,1,sizeof ca);
    dfs(ci,cj,c);
    cout << ans;
}

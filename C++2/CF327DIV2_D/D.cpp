#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, m;
int d[4][4];
char a[N][N];
int ca[N][N];

int bfs(int U,int V,int x,int y)
{
    memset(ca,true,sizeof ca);
    ca[u][v] = 0;
    queue <ii> qu;
    while ( !qu.empty() ) {
        int u, v;
        u = qu.front().first;
        v = qu.front().second;
        qu.pop();

        for (int )
    }
}

int solve(int x,int y)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if ( a[i][j] == '0' + x )
                return bfs(i,j,x,y);
    }
}

int main()
{   freopen("D.inp","r",stdin);
    cin >> n >> m;
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        string s;
        getline(cin,s);
        for (int j = 0; j < m; j++) {
            a[i][j+1] = s[j];
        }
    }

    for (int i = 1; i <= 2; i++)
        for (int j = i + 1; j <= 3; j++)
            d[i][j] = solve(i,j);
}

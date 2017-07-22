#include <bits/stdc++.h>

const long N = 25;
using namespace std;
typedef pair <int,int> point;
int n, m, x, y, hhm;
int ca[5][N][N];
int h[] = {-1 ,  0 ,  0 , -1,  0, +1,  0, +1};
int c[] = {0  , -1 , +1 ,  0, +1,  0, -1,  0};
int hc[]= {1  , 4  ,  2 ,  1,  2,  3,  4,  3};
bool ok;
point trace[5][N][N],res[2000];
int traceh[5][N][N];

void ikq()
{   int ij = 0,xx,yy,hh= hhm;
    while ( x != 1 || y != 1 ) {
            ++ ij;
            res[ij].first = x;
            res[ij].second = y;
            xx = trace[hh][x][y].first;
            yy = trace[hh][x][y].second;
            hh = traceh[hh][x][y];
            x = xx;
            y = yy;
            if ( x == 0 && y == 0 ) break;
    }
    ij;
    cout << ij +1 << endl;
    cout<<1<<" "<<1<<endl;
    for ( int i = ij; i > 0; i-- )
        cout << res[i].first <<" "<< res[i].second << endl;
}
void dfs(int ii, int jj,int hh)
{       if ( ii == x && jj == y ) { hhm = hh; ikq(); ok = true; }
        //cout<< ii <<" "<<jj<<endl;
        if (ok == true) return;
        for  ( int i = 0; i <= 1; i++) {
                int u, v;
                u = ii + h[(hh-1) * 2 + i];
                v = jj + c[(hh-1) * 2 + i];
                if ( ca[hc[(hh-1) * 2 + i]][u][v] ) {
                        ca[hh][ii][jj] = false;
                        trace[hc[(hh-1) * 2 + i]][u][v].first = ii;
                        trace[hc[(hh-1) * 2 + i]][u][v].second = jj;
                        traceh[hc[(hh-1) * 2 + i]][u][v] = hh;
                        dfs(u,v,hc[(hh-1) * 2 + i]);
                        //ca[hh][ii][jj] = true;
                }
        }
}
int main()
{   //freopen("ROBOT4.inp","r",stdin);
    cin >> n >> m;
    memset(ca, false, sizeof ca);
    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)    {
                    int q;
                    cin >> q;
                    ca[1][i][j] = 1 - q;
                    ca[2][i][j] = 1 - q;
                    ca[3][i][j] = 1 - q;
                    ca[4][i][j] = 1 - q;
            }
    cin >> x >> y;
    ca[3][1][1] = false;
    ok = false;
    dfs(1,1,3);
    if (!ok) cout<<0;
}

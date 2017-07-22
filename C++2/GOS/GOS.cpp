/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define x first
#define y second
const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    ii d[3];
};
int n;
int a[N][N];
data p[N];

bool check(data A,data B)
{
    if ( A.d[1].x >= B.d[2].x || B.d[1].x >= A.d[2].x ) return false;
    if ( A.d[1].y <= B.d[2].y || B.d[1].y <= A.d[2].y ) return false;
    return true;
}

int main()
{
    freopen("GOS.inp","r",stdin);
    freopen("GOS.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if ( u > x ) u = u - 2*(u-x);
        if ( v < y ) v = v - 2*(v-y);
        p[i].d[1].x = u;    p[i].d[1].y = v;
        p[i].d[2].x = u - 2*(u-x);  p[i].d[2].y =  v - 2*(v-y);
        if ( p[i].d[1].y < p[i].d[2].y ) swap(p[i].d[1],p[i].d[2]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = check(p[i],p[j]);

    queue <ii> qu;
    qu.push(ii(1,0));
    while ( !qu.empty() ) {
        int u = qu.front().first;
        int c = qu.front().second;
        qu.pop();

        if ( u == n ) {
            cout << c ;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if ( a[u][i] ) {
                qu.push(ii(i,c+1));
                a[u][i] = false;
            }
        }
    }

    cout << -1;
}

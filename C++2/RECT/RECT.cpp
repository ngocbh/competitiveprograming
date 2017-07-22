#include <bits/stdc++.h>
#define x first
#define y second

const long N = 1000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    ii d[9];
};

int n;
int a[N][N], ca[N];
data p[N];

LL area(ii A,ii B,ii C)
{
    LL c;
    c = 1LL*(A.x + B.x)*(A.y - B.y) + 1LL*(B.x + C.x)*(B.y - C.y) + 1LL*(C.x + A.x)*(C.y - A.y);
    return abs(c);
}

bool check(data P,ii A)
{
    LL C = 0;
    for (int i = 1; i <= 4; i++)
        C += 1LL*(P.d[i].x + P.d[i+1].x)*(P.d[i].y - P.d[i+1].y);
    C = abs(C);
    LL c = 0;
    for (int i = 1; i <= 4; i++) {
        c += area(P.d[i],P.d[i+1],A);
    }
    if ( c == C ) return true;
    else return false;
}

int intersect(int u,int v)
{
    for (int i = 1; i <= 4; i++)
        if ( check(p[u],p[v].d[i]) ) return true;
    for (int i = 1; i <= 4; i++)
        if ( check(p[v],p[u].d[i]) ) return true;
    return false;
}

int dfs(int u)
{
    int c = 1;
    ca[u] = false;
    for (int i = 1; i <= n; i++)
        if ( ca[i] && a[u][i] )
            c += dfs(i);
    return c;
}

int main()
{   freopen("RECT.inp","r",stdin);
    //freopen("RECT.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++)
            cin >> p[i].d[j].x >> p[i].d[j].y;
        p[i].d[5] = p[i].d[1];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = intersect(i,j);

    memset(ca,true,sizeof(ca));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if ( !ca[i] ) continue;
        int t = dfs(i);
        ans = max(ans,t);
    }

    cout << ans;
}

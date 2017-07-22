#include<bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, ans = 111;
int a[N][N], ca[N][N];
int h[4] = {0,0,1,-1};
int c[4] = {1,-1,0,0};

bool check(int L,int R)
{
    ///=== BFS
    if ( a[1][1] < L || a[1][1] > R ) return false;
    memset(ca,true,sizeof ca);
    queue <ii> qu;
    qu.push(ii(1,1));
    ca[1][1] = false;
    while ( !qu.empty() )
    {
        int u, v;
        u = qu.front().first;
        v = qu.front().second;
        qu.pop();
        if ( u == n && v == n ) return true;

        for (int i = 0; i < 4; i++) {
            if (u + h[i] > 0 && u + h[i] <= n && v + c[i] > 0 && v + c[i] <= n && ca[u+h[i]][v+c[i]] && a[u+h[i]][v+c[i]] >= L && a[u+h[i]][v+c[i]] <= R ) {
                ca[u+h[i]][v+c[i]] = false;
                qu.push(ii(u+h[i],v+c[i]));
            }
        }
    }
    return false;
}

int main()
{
    //freopen("MTWALK.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i <= 111; i++)
    {
        int l = 1, r = i, m;
        if ( check(0,i) )   ans = min(ans,i - 0);
        while ( l <= r )
        {
            m = ( l + r ) / 2;
            if ( !check(m,i) )
                r = m - 1;
            else {
                    l = m + 1;
                    ans = min(ans,i - m);
            }
        }
    }

    cout << ans;
}

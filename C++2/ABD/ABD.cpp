#include <bits/stdc++.h>

using namespace std;

const long N = 5*10000 + 10;
const long long oo = 1000000000 + 7;
typedef long long LL;
typedef pair <LL,int> ii;

int nx, mx, ny, my;
int colx[N], coly[N];
LL d[N];
vector <ii> ax[N], ay[N];

void solve_sub1()
{
    LL ans = 0;
    fill(d,d+N,oo*oo);
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    qu.push(ii(0,1)); d[1] = 0;

    while ( !qu.empty() ) {
        int u = qu.top().second;
        int du = qu.top().first;
        qu.pop();

        if ( du != d[u] ) continue;
        for (int i = 0; i < ax[u].size(); i++)
        {
            int v = ax[u][i].first, uv = ax[u][i].second;
            if ( d[v] > du + uv )
            {
                d[v] = d[u] + uv;
                qu.push(ii(d[v],v));
            }
        }
    }

    ans += d[nx];

    fill(d,d+N,oo*oo);
    qu.push(ii(0,1)); d[1] = 0;
    while ( !qu.empty() )
    {
        int u = qu.top().second;
        int du = qu.top().first;
        qu.pop();

        if ( d[u] != du ) continue;
        if ( u == ny ) {
            ans += du;
            break;
        }

        for (int i = 0; i < ay[u].size(); i++)
        {
            int v = ay[u][i].first, uv = ay[u][i].second;
            if ( d[v] > du + uv )
            {
                d[v] = du + uv;
                qu.push(ii(d[v],v));
            }
        }
    }

    cout << ans;
}

void solve_sub2()
{

}

int main()
{
    freopen("ABD.inp","r",stdin);
    freopen("ABD.out","w",stdout);

    int type;

    cin >> type;
    cin >> nx >> mx;

    for (int i = 1; i <= mx; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ax[u].push_back(ii(v,c));
        ax[v].push_back(ii(u,c));
    }

    cin >> ny >> my;

    for (int i = 1; i <= my; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ay[u].push_back(ii(v,c));
        ay[v].push_back(ii(u,c));
    }

    if ( type == 1 ) solve_sub1();
    if ( type == 2 ) solve_sub2();
}

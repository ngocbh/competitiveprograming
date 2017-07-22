#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = 1000000000 + 10;

using namespace std;

typedef long long LL;
typedef pair <int,int> ii;
struct data{
    int color, vertex, length;
};

int n, m ;
int ca[N], ta[N], kq[N], d[N], f[N];

vector <ii> a[N];
struct cmp{

    bool operator()(const data& A,const data& B)
    {
        return ( A.length > B.length || (A.length == B.length && A.color > B.color ) );
    }
};

void bfs1()
{
    queue <ii> qu;
    memset(ca,true,sizeof ca);
    ca[n] = false;
    for (int i = 0; i <= n; i++) d[i] = oo, f[i] = oo;
    d[n] = 0;
    qu.push(ii(n,0));
    while ( !qu.empty()) {
        int u, du;
        u = qu.front().first;
        du = qu.front().second;
        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            if ( d[v] == du + 1)
                f[v] = min(f[v],a[u][i].first);
            if ( !ca[v] ) continue;
            ca[v] = false;
            if ( d[v] > du + 1 ) {
                d[v] = du + 1;
                f[v] = a[u][i].first;
                qu.push(ii(v,d[v]));
            }
        }
    }
}

void bfs2()
{
    int ans = 0;
    priority_queue <data,vector<data>, cmp > qu;
    memset(ca,true,sizeof(ca));
    ca[1] = false;
    qu.push(data{f[1],1,0});

    while ( !qu.empty() ) {

        int u, du, c;
        u = qu.top().vertex;
        du = qu.top().length;
        c = qu.top().color;
        qu.pop();
        if ( u == n ) {
            ans = du;
            break;
        }

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            if ( !ca[v] ) continue;
            ca[v] = false;
            qu.push(data{f[v],v,du+1});
            ta[v] = u;
        }

    }

    printf("%d\n", ans);

    int u = n, v;
    while ( u != 1 ) {
            v = ta[u];

            for (int i = 0;i < a[u].size(); i++)
                if ( a[u][i].second == v )
                    {
                        kq[ans--] = a[u][i].first;
                        break;
                    }
            u = v;
    }
    while ( kq[++ans] != 0 ) printf("%d ", kq[ans] );
}

int main()
{
    //freopen("MECUNG.inp","r",stdin);
    scanf("%d %d", &n,&m);
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u,&v,&c);
        a[u].push_back(ii(c,v));
        a[v].push_back(ii(c,u));
    }

    for (int i = 1; i <= n; i++) {
        //a[i].push_back(ii(0,0));
        sort(a[i].begin(),a[i].end());
    }

    bfs1();
    //for (int i = 1; i <= n; i++ ) cout << i << " " << f[i] << " " << d[i] << endl;
    bfs2();

}

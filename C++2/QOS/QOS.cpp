/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    int s;
    int d[100];

};

bool operator < (const data &A, const data &B)
{
        for (int i = 1; i <= max(A.s,B.s); i++) {
            if ( A.d[i] == B.d[i] ) continue;
            return A.d[i] < B.d[i];
        }
}

int n, m , t, k;
int c[N][N], ca[N], ta[N], x[100];
LL Tmin, Cmin = oo;
LL d[N];
vector <int> a[N];
vector <data> res;

void dijkstra()
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    qu.push(ii(0,1));
    fill(d,d+N,oo*oo);
    d[1] = 0;
    Tmin = d[t];

    while ( !qu.empty() ) {
        int du = qu.top().first;
        int u = qu.top().second;
        qu.pop();

        if ( u == t ) {
            Tmin = du;
            return;
        }

        if ( d[u] != du ) continue;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if ( d[v] > d[u] + c[u][v] ) {
                d[v] = d[u] + c[u][v];
                qu.push(ii(d[v],v));
            }
        }
    }
}

void ktkq()
{
    int u = t, ss = 0;
    while ( u != 1 ) {
        x[++ss] = u;
        u = ta[u];
    }
    x[++ss] = 1;
    data A;
    A.s = ss;
    for (int i = ss; i > 0; i--) A.d[ss-i+1] = x[i];
    res.push_back(A);
}

void dfs(int u,int C)
{
    if ( u == t && C <= Tmin + Cmin ) {
        ktkq();
        return;
    }
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        ca[v] = false;
        ta[v] = u;
        dfs(v,C+c[u][v]);
        ca[v] = true;
    }
}

int main()
{
    //freopen("QOS.inp","r",stdin);
    //freopen("QOS.inp","w",stdout);


    cin >> n >> m >> t >> k;

    if ( n > 10 ) return 0;

    for (int i = 1; i <= m; i++) {
        int u, v, uv;
        cin >> u >> v >> uv;
        a[u].push_back(v);
        c[u][v] = uv;
        Cmin = min(Cmin,1LL*uv);
    }

    dijkstra();

    if ( Tmin == oo*oo ) {
        cout << -1;
        return 0;
    }

    memset(ca,true,sizeof ca);
    dfs(1,0);

    sort(res.begin(),res.end());

    /*for (int i = 0; i < res.size(); i++) {
        data A = res[i];
        cout << A.s << " <---> " ;
        for (int j = 1; j <= A.s; j++) cout << A.d[j] << " ";
        cout << endl;
    }*/

    if ( k > res.size() ) {
        cout << -1;
        return 0;
    }
    cout << res[k-1].s << endl;
    for (int i = 1; i <= res[k-1].s; i++) cout <<res[k-1].d[i] << " " ;
}

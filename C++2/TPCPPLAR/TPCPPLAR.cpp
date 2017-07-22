/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 300000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, k, inter = 0;
int num[N], low[N], ca[N], lad[N], d[N], child[N], parent[N], res[N], ans = 0;
ii M[2*N], NUM[N];
vector <int> a[N], b[N];
stack <int> s;

void visit(int u)
{
    num[u] = ++num[0];
    low[u] = num[u];
    s.push(u);

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( lad[v] ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            visit(v);
            low[u] = min(low[u],low[v]);
        }
    }

    if ( low[u] == num[u] ) {
        ++inter;
        while ( true ) {
            int x = s.top();
            s.pop();
            lad[x] = inter;
            if ( x == u ) return;
        }
    }
}

void dfs(int u,int c)
{
    ca[u] = false;
    NUM[u] = ii(c,u);

    for (int i = 0; i < b[u].size(); i++) {
        int v = b[u][i];
        if ( !ca[v] ) continue;
        dfs(v,c+1);
    }
}

int main()
{
    freopen("TPCPPLAR.inp","r",stdin);
    //freopen("TPCPPLAR.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        M[i] = ii(u,v);
    }

    for (int i = 1; i <= n; i++)
        if ( !num[i] )
            visit(i);

    for (int i = 1; i <= n; i++) cout << lad[i] << " "; cout << endl;

    for (int i = 1; i <= m; i++) {
        int u, v;
        u = M[i].first;
        v = M[i].second;
        if ( lad[u] != lad[v] )
            b[lad[u]].push_back(lad[v]);
    }

    memset(ca,true,sizeof ca);
    memset(num,0,sizeof num);
    for (int i = inter; i >= 1; i--)
        if ( ca[i] )
            dfs(i,1);


    sort(NUM+1,NUM+inter+1);

    for (int i = 1; i <= inter; i++) cout << NUM[i].first << " " << NUM[i].second << endl;
    cout << endl;

    for (int i = 1; i <= inter; i++) {
        int u = NUM[i].second;
        for (int j = 0; j < b[u].size(); j++) {
            int v = b[u][j];
            parent[v] += parent[u]+1;
        }
    }

    for (int i = inter; i > 0; i--) {
        int u = NUM[i].second;
        child[u] = 1;
        for (int j = 0; j < b[u].size(); j++) {
            int v = b[u][j];
            child[u] += child[v];
        }
    }

    memset(ca,false,sizeof ca);
    for (int i = 1; i <= inter; i++)
        if ( parent[i] + child[i] == inter )
            ca[i] = true;

    for (int i = 1; i <= n; i++) cout << parent[i] << " "; cout << endl;
    for (int i = 1; i <= n; i++) cout << child[i] << " "; cout << endl;
    cout << endl;

    for (int i = 1; i <= n; i++)
        if ( ca[lad[i]] )
            res[++ans] = i;
    sort(res+1,res+ans+1);

    cout << ans << endl;
    for (int i = 1; i <= ans; i++) cout << res[i] << " ";
}

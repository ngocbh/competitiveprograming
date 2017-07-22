#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

const long N = 100000 + 10;

int n, m, k, cau;
int low[N], num[N], ca[N], f[N], pa[N], Aug[N], Node[N];
LL ans = 0;
vector <int> a[N], Edge[N];
map <int,int> M[N];
stack <int> s;

int visit(int u,int p)
{
   low[u] = num[u] = ++num[0];
   s.push(u);

   for (int v, i = 0; i < a[u].size(); i++)
   {
        v = a[u][i];
        if ( M[u][v] > 0 ) {
            --M[u][v];
            --M[v][u];
            if ( num[v] )
            {
                low[u] = min(low[u],num[v]);
            }
            else
            {
                pa[v] = u;
                visit(v,u);
                low[u] = min(low[u],low[v]);
            }
        }
   }

   if ( low[u] == num[u] ) {
        ++cau;
        for (;;) {
            int k = s.top();
            s.pop();
            Aug[k] = cau;
            if ( k == u ) break;
        }
   }
}

void dfs(int Start,int u,int c)
{
    ca[u] = false;
    if ( c >= k && !M[Start][u] ) {
        ans += Node[Start] * Node[u];
        M[Start][u] = M[u][Start] = 1;
    }
    for (int v, i = 0; i < Edge[u].size(); i++) {
        v = Edge[u][i];
        if ( !ca[v] ) continue;
        dfs(Start,v,c+1);
    }
}

int main()
{
    //freopen("TRAVEL.inp","r",stdin);
    //freopen("TRAVEL.out","w",stdout);

    cin >> n >> m >> k;
    for (int u, v, i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        M[u][v]++;
        M[v][u]++;

    }

    visit(1,0);

    if ( k > cau ) {
        cout << 0 ;
        return 0;
    }

    for (int i = 1; i <= n; i++) M[i].clear();
    for (int u = 1; u <= n; u++) {
        Node[Aug[u]]++;
        if ( low[u] == num[u] ) {
            Edge[Aug[u]].push_back(Aug[pa[u]]);
            Edge[Aug[pa[u]]].push_back(Aug[u]);
        }
    }


    for (int i = 1; i <= cau; i++)
        memset(ca,true,sizeof ca), dfs(i,i,0);

    cout << ans;
}

#include <bits/stdc++.h>

const long N = 100000+10;
const long oo = 1000000000+10;
using namespace std;
typedef pair<int,int> ii;

int n,m;
int d1[N],dn[N],c1[N],cn[N],res[N];
vector <ii> a[N];

void inp()
{
    freopen("MECUNG.INP","r",stdin);
    scanf("%d%d", &n, &m);
    int u,v,k;
    for (int i=1; i<=m; i++) {
        scanf("%d %d %d ", &u, &v, &k);
        a[u].push_back(ii(v,k));
        a[v].push_back(ii(u,k));
    }

}
void init()
{
    for (int i=1; i<=n; i++) a[i].push_back(ii(0,0));
    for (int i=1; i<=n; i++) d1[i] = dn[i] = oo;
    memset(c1,true,sizeof(c1));
    memset(cn,true,sizeof(cn));
}
void bfs()
{
    queue <ii> q1,qn;
    q1.push(ii(1,0)); c1[1] = false; d1[1] = 0;
    qn.push(ii(n,0)); cn[n] = false; dn[n] = 0;
        while ( !q1.empty() ) {
            int u,v,du;
                u = q1.front().first;
                du = q1.front().second;
                q1.pop();
                    for (int i=0; v=a[u][i].first; i++)
                        if ( c1[v] ){
                            c1[v] = false;
                            d1[v] = min( d1[v] , du+1 );
                            q1.push(ii(v,du+1));
                        }
        }

        while ( !qn.empty() ) {
            int u,v,du;
                u = qn.front().first;
                du = qn.front().second;
                qn.pop();
                    for (int i=0; v=a[u][i].first; i++)
                        if ( cn[v] ){
                            cn[v] = false;
                            dn[v] = min( dn[v] , du+1 );
                            qn.push(ii(v,du+1));
                        }
        }

}

void solve()
{       vector <int> s1,s2;
        int u,v,min1;
        s1.push_back(1);
        memset(c1,true,sizeof(c1));
        c1[1] = false;
        for (int o=1; o<=d1[n]; o++) {
                min1 = oo;
                s2.clear();
                for (int i=0; i<=s1.size()-1; i++){
                    u = s1[i];
                    for (int j=0; v=a[u][j].first; j++)
                        if ( d1[v] + dn[v] == d1[n] && c1[v] ){
                            min1 = min(min1 , a[u][j].second );
                        }
                }

                for (int i=0; i<=s1.size()-1; i++){
                    u = s1[i];
                    for (int j=0; v=a[u][j].first; j++)
                        if ( d1[v] + dn[v] == d1[n] && c1[v] && a[u][j].second == min1 ){
                                s2.push_back(v);
                                c1[v] = false;
                        }
                }

                s1 = s2;
                res[o] = min1;
        }
        printf("%d\n", d1[n]);
        for (int i=1; i<=d1[n]; i++) printf("%d ", res[i]);
}
int main()
{
    inp();
    init();
    bfs();
    solve();

}

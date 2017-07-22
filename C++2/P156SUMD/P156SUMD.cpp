#include <bits/stdc++.h>

const long N = 5 * 100* 1000 + 10;
using namespace std;
typedef pair<int,int> ii;
int n, q, v, ans = 0, max1 = 0,max2 = 0;
int d[2*N], lad[2*N], f[2*N], s[2*N];
int dem = 0;
void dfs(int u,int cv)
{
   // cout << u << "**" << cv << "^^^" << ans << endl;
    d[u] = max(d[u],d[cv] + 1);
    if ( u == 1 ) {
       // cout << ans << "&&&";
        for (int i = 2; i <= 4; i++)
            if ( i != cv ) {
                ans = max(ans,d[cv] + d[i] + 2);
                //cout << i << " " << ans << " &&&" << " ";
            }
        return;
    }
    int v ;
    v = lad[u];

    if ( cv % 2 == 0 ) ans = max(ans,d[cv] + d[cv-1] + 2);
    else ans = max(ans , d[cv] + d[cv+1] + 2);
    //cout << cv << " " << ans << endl;
    dfs(v,u);
}
int main()
{   //freopen("P156SUMD.inp","r",stdin);
    scanf("%d", &q);
    n = 4;
    d[2] = d[3] = d[4] = 0;
    lad[2] = lad[3] = lad[4] = 1;
    for (int i = 1; i <= q; i++) {
        int v;
        ans = 0;
        scanf("%d", &v);
        lad[++n] = v;
        lad[++n] = v;
        dfs(v,n);
        cout << ans << endl;
        //cout <<"&&&&&&&&&&&&&&&&&&&&" << endl;
    }
    //for (int i = 1; i <= 15; i++) cout  << d[i] << " ";
}

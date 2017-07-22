/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>
#define cout fo
#define cin fi
const long N = 1000000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
ifstream fi("LP.inp");
ofstream fo("LP.out");

typedef long long LL;
typedef pair <int,int> ii;

int n, ans = 0;
int  schild[N], ca[N], pa[N];
ii spar[N];
vector <int> a[N], child[N];

void solve()
{
    memset(ca,true,sizeof ca);
    queue <ii> qu;
    qu.push(ii(1,0));
    pa[1] = 0;  ca[1] = false;

    while ( !qu.empty() ) {
        int u = qu.front().first;
        int c = qu.front().second;
        qu.pop();

        spar[u].first = c;
        spar[u].second = u;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if ( !ca[v] ) continue;
            ca[v] = false;
            pa[v] = u;
            child[u].push_back(v);
            qu.push(ii(v,c+1));
        }
    }

    sort(spar+1,spar+n+1);
    for (int i = 1; i <= n; i++) schild[i] = 1;


    for (int i = n; i > 0; i--) {
        int u = spar[i].second;
        schild[pa[u]] = max(schild[pa[u]],schild[u]+1);
    }

    for (int i = 1; i <= n; i++) {
        if ( child[i].size() == 0 ) continue;
        if ( child[i].size() == 1 ) {
            int u = child[i][0];
            ans = max(schild[u]+1,ans);
        }

        int max1 = 0,max2 = 0;
        for (int j = 0; j < child[i].size(); j++) {
            int u = child[i][j];
            if ( schild[u] > max1 )
                max2 = max1 , max1 = schild[u];
            else
                if ( schild[u] > max2 )
                    max2 = schild[u];
        }

        ans = max(ans, max1+max2+1);
    }

    cout << ans;
}

int main()
{
    //freopen("LP.inp","r",stdin);
    //freopen("LP.out","w",stdout);

    cin >> n;
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    solve();

}

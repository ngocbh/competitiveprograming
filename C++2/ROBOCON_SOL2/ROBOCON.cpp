/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 500 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, k;
int a[N][N];
int ca[N][N], cb[N][N];

int h1[3] = {0,1,1};
int c1[3] = {1,0,1};
int h2[3] = {0,1,1};
int c2[3] = {-1,-1,0};

void solve()
{
    queue <ii> qu1, qun;
    map <ii,int> M,M1;
    qu1.push(ii(0,1*N + 1));
    qun.push(ii(0,1*N + n));

    int ans = 0;
    for (int ans = 0; ans <= n+n; ans++) {
        M.clear();
        //cout << qu1.size() << " " << qun.size() << endl;

        while ( !qu1.empty() ) {
            int du = qu1.front().first;
            int u = qu1.front().second / N;
            int v = qu1.front().second % N;

            if ( du != ans ) break;
            qu1.pop();

            for (int i = 0; i < 3; i++) {
                int ui = u + h1[i];
                int vi = v + c1[i];
                if ( a[ui][vi] || ui > n || vi > n ) continue;
                if ( ca[ui][vi] == du+1 ) continue;
                qu1.push(ii(du+1,ui*N + vi));
                ca[ui][vi] = du+1;
            }
        }
        M1.clear();
        while ( !qun.empty() ) {
            int du = qun.front().first;
            int u = qun.front().second / N;
            int v = qun.front().second % N;

            if ( du != ans ) break;
            qun.pop();

            for (int i = 0; i < 3; i++) {
                int ui = u + h2[i];
                int vi = v + c2[i];
                if ( a[ui][vi] || ui > n || vi > n ) continue;
                if ( cb[ui][vi] == du+1 ) continue;
                qun.push(ii(du+1,ui*N + vi));
                cb[ui][vi] = du + 1;
                if ( ca[ui][vi] == du+1 ) {
                    cout << ans + 1;
                    return;
                }
            }
        }
    }
}

int main()
{
    //freopen("ROBOCON.inp","r",stdin);
    //freopen("ROBOCON.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
    }

    solve();

}

#include <bits/stdc++.h>

using namespace std;

const long N = 50 + 5;
const long MOD = 1000000000 + 7;
int n, ans = 0;
bool ca[N];
string c[N];
vector <int> in[N], out[N];

void dfs(int u,int pa,int len)
{
    if ( len == n ) {
        ans = ( ans + 1 ) % MOD;
        return;
    }
    if ( in[u].size() == 1 ) {
        if ( in[u][0] != pa ) {

            if ( ca[in[u][0]] ) ca[in[u][0]] = false,dfs(in[u][0],u,len+1),ca[in[u][0]] = true;

            return;
        }
    }
    if ( in[u].size() == 2 ) {
        if ( pa == in[u][0] && ca[in[u][1]] ) ca[in[u][1]] = false, dfs(in[u][1],u,len+1), ca[in[u][1]] = true;
        if ( pa == in[u][1] && ca[in[u][0]] ) ca[in[u][0]] = false, dfs(in[u][0],u,len+1), ca[in[u][0]] = true;
        return;
    }
    for (int i = 0; i < out[u].size(); i++) {
        int v = out[u][i];
        if ( !ca[v] ) continue;
        ca[v] = false;
        dfs(v,u,len+1);
        ca[v] = true;
    }
}

int main()
{
    freopen("hamilton.inp","r",stdin);

    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i] , c[i] = '0' + c[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if ( c[i][j] == 'Y' )
                in[i].push_back(j);
            else
                out[i].push_back(j);
        if ( in[i].size() > 2 ) {
            cout << 0;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        memset(ca,true,sizeof ca);
        ca[i] = false;
        if ( in[i].size() > 1 ) continue;
        dfs(i,0,1);
    }

    cout << ans;
}

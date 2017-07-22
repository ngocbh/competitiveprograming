#include <bits/stdc++.h>
#define cin fi
#define cout fo
const long N  = 1000000 + 1;
using namespace std;
ifstream fi("COMNET.inp");
ofstream fo("COMNET.out");

int n, m, k;
bool ca[N];
vector <int> a[N];

int v;
void bfs(int u)
{
    queue <int> qu;
    qu.push(u);
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        ca[u] = true;
        for (int i = 0; i < a[u].size(); i++) {
            v = a[u][i];
            if ( ca[v] ) continue;
            qu.push(v);
        }
    }
}

int main()
{   //freopen("COMNET.inp","r",stdin);
    cin >> n >> m;
    ca[1] = true;
    int u, v;
    for (int i = 1; i <= m; i++) {
        k = i;
        cin >> u >> v;
        a[u].push_back(v);
        if ( ca[u] && !ca[v] ) {
            bfs(v);
        }
        if ( ca[n] ) {
            cout << i;
            return 0;
        }
    }
    cout << -1;

}

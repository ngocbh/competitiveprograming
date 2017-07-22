#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int,int> ii;

const long N = 5000 + 10;

int n, m;
int a[N][N];
map <ii,ii> M;
vector <int> a[N];

void bfs(int s)
{
    queue <ii> qu;
    qu.push(ii(0 * N + 0,s * N + 1));

    int cur = 0;
    while ( !qu.empty() ) {
        int d_char = qu.top().first / N;
        int d_aug = qu.top().first % N;
        int u = qu.top().second / N;
        int k = qu.top().second % N;
        qu.pop();


    }
}

int main()
{
    freopen("YINYANG.inp","r",stdin);

    cin >> n;
    for (int u, v, c,i = 1; i < n; i++)
    {
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
}

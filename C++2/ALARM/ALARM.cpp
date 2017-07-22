#include <bits/stdc++.h>

using namespace std;

const long N = 3000 + 10;

typedef long long LL;
typedef pair <int,int> ii;

int n;
LL p[N][N], d[N], spa[N], ca[N];
vector <ii> a[N];
vector <int> b[N];

void calc(int u,int start,int len,int pa)
{
    p[start][u] = len;
    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].first;
        if ( v == pa ) continue;
        calc(v,start,len+a[u][i].second,u);
    }
}

void dfs(int u)
{
    ca[u] = true;
    for (int i = 0; i < b[u].size(); i++)
    {
        int v = b[u][i];
        if ( ca[v] ) continue;
        dfs(v);
    }
}

int main()
{
    freopen("ALARM.inp","r",stdin);
    //freopen("ALARM.out","w",stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }

    for (int i = 1; i <= n; i++)
        calc(i,i,0,0);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( p[i][j] <= d[i] )
                b[i].push_back(j), ++spa[j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            //cout << i << " " << j << " ";
        cout << endl;
    }
    return 0;
    for (int i = 1; i <= n; i++) {
        //for (int j = 0; j < b[i].size(); j++)
            cout << b[i].size() << " ";
    cout << endl;
    }
    return 0;

    int ans = 0;

    for (int i = 1; i <= n; i++)
        if ( spa[i] == 0 && !ca[i] ) {
            ++ans;
            dfs(i);
        }

    for (int i = 1; i <= n; i++)
        if ( !ca[i] )
        {
            ++ans;
            dfs(i);
        }

    cout << ans;
}

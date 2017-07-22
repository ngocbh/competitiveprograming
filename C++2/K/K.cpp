#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n, t, k , u;

vector <int> a[N];
map <int,int> m1;
map < pair<int,int>, int > m;
int main()
{   freopen("K.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> t;

    for (int i = 1; i <= n; i++)
    {
            cin >> k;
            for (int j = 1; j <= k; j++) {
                cin >> u;
                a[i].push_back(u);
                m1[u]++;
            }
            sort(a[i].begin(),a[i].end());
            for (int j = 1; j < k; j++)
                if ( a[i][j] == a[i][j-1] ) --m1[a[i][j]];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i].size(); j++)
        if ( m1[a[i][j]] >= t )
            for (int k = j+1; k < a[i].size(); k++)
                if ( m1[a[i][k]] >= t ) {
                        if ( a[i][j] == a[i][k] ) continue;
                        ++m[make_pair(a[i][j],a[i][k])];
                }
    }

    for (map <pair<int,int> , int> ::iterator it = m.begin(); it != m.end(); it++)
        if ( it->second >= t ) ++ans;
    cout << ans;
}

/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 10000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, ans;
int low[N], num[N];
vector <int> a[N];

void visit(int u)
{
    low[u] = num[u] = ++num[0];

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            visit(v);
            low[u] = min(low[u],low[v]);
        }
    }

    if ( low[u] == num[u] ) {
        ++ans;
    }
}
int main()
{
    //freopen("1CHIEU.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
            char c;
            cin >> c;
            if ( c == 'R' )
                for (int j = 1; j < m; j++) {
                    a[(i-1)*m + j].push_back((i-1)*m + j+1);
                }
            else
                for (int j = 2; j <= m; j++)
                    a[(i-1)*m + j].push_back((i-1)*m + j-1);
    }

    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        if ( c == 'U' ) {
            for (int j = 2; j <= n; j++)
                a[(j-1)*m + i].push_back((j-2)*m + i);
        }
        else
            for (int j = 1; j < n; j++)
                a[(j-1)*m + i].push_back(j*m + i);
    }

    for (int i = 1; i <= m*n; i++)
        if ( !num[i] )
            visit(1);

    if ( ans == 1 )
        cout << "YES";
    else
        cout << "NO";
}

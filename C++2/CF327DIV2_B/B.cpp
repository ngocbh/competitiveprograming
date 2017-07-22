#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;

int n, m;
int a[N], b[N];
string s;

int main()
{   //freopen("B.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> s;

    for (int i = 'a'; i <= 'z'; i++)
        a[i] = i, b[i] = i;

    for (int i = 1; i <= m; i++) {
        char u, v;
        cin >> u >> v;
        a[b[u]] = v;
        a[b[v]] = u;
        swap(b[u],b[v]);
    }

    for (int i = 0; i < n; i++) cout << (char) a[s[i]];

}

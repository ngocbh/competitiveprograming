#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

int n, t;
int ca[N], c[N];
vector <int> a[N];

int main()
{
    //freopen("A.inp","r",stdin);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> c[i];
        a[i].push_back(i+x);
    }

    queue <int> qu;
    qu.push(1);

    while ( !qu.empty() ) {
        int u = qu.front();
        qu.pop();

        if ( ca[u] ) break;
        ca[u] = 1;

        if ( u == t ) {
            cout << "YES" ;
            return 0;
        }

        qu.push(u+c[u]);
    }

    cout << "NO";
    return 0;

}

#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, a[N], f[1000+10], ans = 0;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n;
    int pa;
    cin >> pa;
    priority_queue <int,vector<int> > qu;
    for (int i = 2; i <= n; i++) {
            cin >> a[i];
            qu.push(a[i]);
    }

    qu.push(-1);
    while ( pa <= qu.top() ) {
        ++pa;
        ++ans;
        int u = qu.top() - 1;
        qu.pop();
        qu.push(u);
    }
    cout << ans ;
}

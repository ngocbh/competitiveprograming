#include <bits/stdc++.h>

const long N = 1000;
using namespace std;
int a[N], f[N], n ,m;
int main()
{   //freopen("A.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int maxx = -1,ci = 0;
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            if ( c  > maxx ) maxx = c, ci = j;
        }
       // cout << ci << endl;
        f[ci] += 1;
    }
    //for (int i = 1; i <= n; i++) cout << f[i]<< " " ; cout << endl;
    int minn = -1, ci = 0;
    for (int i = 1; i <= n; i++) {
        if ( f[i] > minn ) {
            minn = f[i];
            ci = i;
        }
    }
    cout << ci ;

}

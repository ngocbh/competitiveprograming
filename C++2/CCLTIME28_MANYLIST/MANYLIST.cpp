#include <bits/stdc++.h>

const long N = 2500 + 10;
using namespace std;
int n, m;
set <int> ca[N];
int main()
{   //freopen("MANYLIST.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int type,l,r,x;
        cin >> type;
        if ( type == 1 ) {
            cin >> x;
            cout << ca[x].size() << endl;
        }
        else {
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++)
                ca[i].insert(x);
        }
    }

}

#include <bits/stdc++.h>

const long N = 1000 + 10;
using namespace std;
struct data{
    int a, b, id;
};

int n, x, y;
int ta[N];
data a[N];

bool cmp(data A,data B)
{
    return A.b < B.b;
}

int main()
{
        freopen("DOAN7.inp","r",stdin);
        freopen("DOAN7.out","w",stdout);
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b;
            a[i].id = i;
        }

        sort(a+1,a+n+1,cmp);

        int cur = x, k = 1;
        vector <int> res;

        while ( cur < y ) {
            bool ok = true;
            for (int i = n; i >= k; i--) {
                if ( a[i].a <= cur ) {
                    cur = a[i].b;
                    k = i+1;
                    res.push_back(a[i].id);
                    ok = false;
                    break;
                }
            }
            if ( ok ) {
                cout << 0;
                return 0;
            }
        }

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << endl;
}

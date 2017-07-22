#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;
struct data{
    int a, b, id;
};
int n;
data a[N];

bool cmp(data A,data B)
{
    return A.b < B.b;
}

int main()
{   freopen("DOAN1.inp","r",stdin);
    freopen("DOAN1.out","w",stdout);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].a >> a[i].b;
            a[i].id = i;
        }

        sort(a+1,a+n+1,cmp);

    vector <int> res;
    res.push_back(a[1].id);
    int cur = a[1].b;

    for (int i = 2; i <= n; i++) {
        if ( a[i].a > cur ) {
            res.push_back(a[i].id);
            cur = a[i].b;
        }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}

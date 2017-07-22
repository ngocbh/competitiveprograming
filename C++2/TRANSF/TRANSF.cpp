#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

struct data{
    int a,b,id;
};

int n;
ii res[N];
data a[N];

bool cmp(data A,data B)
{
    return A.a < B.a;
}

int bs(int l,int r,int x)
{
    int ans = 0;
    while ( l <= r ) {
        int m = (l+r) / 2;
        if ( a[m].a <= x ) {
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    if ( a[ans].a == x ) return ans;
    else return 0;
}

int main()
{
    freopen("TRANSF.inp","r",stdin);
    freopen("TRANSF.out","w",stdout);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i].a, a[i].id = i;
    for (int i = 1; i <= n; i++) cin >> a[i].b;

    sort(a+1,a+n+1,cmp);

    int sz = 0;
    for (int i = 1; i <= n; i++) {
        if ( a[i].a == a[i].b ) continue;

        int j = bs(i+1,n,a[i].b);
        if ( j == 0 || a[i].a > a[i].b ) {
            cout << "NO";
            return 0;
        }

        res[++sz].first = a[i].id;
        res[sz].second = a[j].id;
    }

    cout << "YES" << endl;
    cout << sz << endl;
    for (int i = 1; i <= sz; i++) cout << res[i].first << " " << res[i].second << endl;

}

#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
struct data {
    int pos, val;
};

int n, d;
data a[N];
LL sum[N];

bool cmp(const data A,const data B)
{
    return A.pos < B.pos;
}

int binarysearch(int x)
{
    int res =  0, l = 0, h = n, m;
    while ( l <= h ) {
        m = (l+h)/2;
        if ( a[m].pos <= x) {
            res = m;
            l = m+1;
        }
        else h = m-1;
    }
    return res;
}

int main()
{   //freopen("B.inp","r",stdin);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i].pos >> a[i].val;

    sort(a+1,a+n+1,cmp);

    a[0].pos = -1;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i].val;
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
            int x;
            x = binarysearch(a[i].pos-d);
            ans = max(ans, sum[i] - sum[x]);
    }
    cout << ans;
}
